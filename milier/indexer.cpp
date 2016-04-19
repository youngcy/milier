#include "indexer.h"



indexer::indexer()
{
	_docsdb = std::make_shared<docsdb>();
	_wseg = std::make_shared<wseg>();
}


indexer::~indexer()
{
	_docsdb.reset();
	_wseg.reset();
}

int indexer::total_create_index()
{
	size_t document_count = 0;;
	std::string document;
	_words_map_t words_map;

	_docsdb->get_total_document_count(&document_count);
	for (size_t i = 0; i < document_count; ++i) {
		_document_id_t document_id = _docsdb->get_total_document_id();
		_docsdb->get_document(document_id, document);
		_wseg->words_segment(document, words_map);
		words_to_inverted_index(document_id, words_map);
	}

	return 0;
}

int indexer::increase_create_index()
{
	size_t document_count = 0;;
	_words_map_t words_map;
	std::string document;

	_docsdb->get_increased_document_count(&document_count);
	for (size_t i = 0; i < document_count; ++i) {
		_document_id_t document_id = _docsdb->get_increased_document_id();
		_docsdb->get_document(document_id, document);
		_wseg->words_segment(document, words_map);
		words_to_inverted_index(document_id, words_map);
	}


	return 0;
}

size_t indexer::words_to_inverted_index(_document_id_t document_id, _words_map_t &words_map)
{
	for (auto &words_iter : words_map) {
		std::string words = words_iter.first;
		_index_dict_iter_t dict_iter = _index_dict.find(words);
		if (dict_iter != _index_dict.end()) {
			//words already in dict
			++(dict_iter->second.token_count);
			++(dict_iter->second.docu_count);
			size_t index = binary_search<_postings_list_iter_t, _document_id_t>(
				dict_iter->second.postings_list.begin(),
				dict_iter->second.postings_list.end(),
				document_id
				);
			if (index == -1) {
				//document_id not exist
				words_iter.second.doucument_id = document_id;
				dict_iter->second.postings_list.push_back(words_iter.second);
			}
			else {
				//already in vector
				dict_iter->second.postings_list[index].positions.insert(
					dict_iter->second.postings_list[index].positions.end(),
					words_iter.second.positions.begin(),
					words_iter.second.positions.end()
				);
				dict_iter->second.postings_list[index].positions_count += 
					words_iter.second.positions.size();
			}
		} else {
			//need insert the word
			inverted_index_iterm index_iterm;
			index_iterm.docu_count = 1;
			index_iterm.token_count = 1;
			words_iter.second.doucument_id = document_id;
			index_iterm.postings_list.push_back(words_iter.second);
			_index_dict.insert(
				std::pair<std::string, inverted_index_iterm>(words_iter.first, index_iterm)
			);
		}
	}

	return _index_dict.size();
}

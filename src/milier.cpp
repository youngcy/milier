#include "milier.h"



milier::milier()
{
	_wseg = std::make_shared<wseg>();
	_cachedb = std::make_shared<cachedb>();
}


milier::~milier()
{
}

int milier::search(std::string query, std::vector<_document_id_t> &document_ids)
{
	_index_dict_t index_dict;
	_words_map_t words_map;
	_wseg->words_segment(query, words_map);
	//get the inverted index lists
	_cachedb->get_inverted_index_iterm(words_map, index_dict);
	merge_inverted_index_iterm(words_map, index_dict, document_ids);

	return 0;
}

int milier::merge_inverted_index_iterm(_words_map_t words, _index_dict_t index_dict, std::vector<_document_id_t>& document_ids)
{
	return 0;
}

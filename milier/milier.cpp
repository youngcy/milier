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
	std::vector<std::string> words;
	_wseg->words_segment(query, words);
	//get the inverted index lists
	_cachedb->get_inverted_index_iterm(words, index_dict);
	merge_inverted_index_iterm(words, index_dict, document_ids);

	return 0;
}

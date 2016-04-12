#pragma once

#include "common.h"
#include "wseg.h"
#include "cachedb.h"

class milier
{
public:
	milier();
	~milier();

	int search(std::string query, std::vector<_document_id_t> &document_ids);
	int merge_inverted_index_iterm(std::vector<std::string> words, _index_dict_t index_dict, std::vector<_document_id_t> &document_ids);
private:
	std::shared_ptr<wseg> _wseg;
	std::shared_ptr<cachedb> _cachedb;
};


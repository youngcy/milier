#pragma once

#include "common.h"
#include "wseg.h"
#include "docsdb.h"



class indexer
{
public:
	indexer();
	~indexer();

	int total_create_index();
	int increase_create_index();

	size_t words_to_inverted_index(_document_id_t, _words_map_t&);

private:
	std::shared_ptr<docsdb> _docsdb;
	std::shared_ptr<wseg> _wseg;
	_index_dict_t _index_dict;
};


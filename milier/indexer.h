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
private:
	std::shared_ptr<docsdb> _docsdb;
	std::shared_ptr<wseg> _wseg;
	_index_dict_t _index_dict;
};


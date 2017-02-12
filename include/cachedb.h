#pragma once

#include "common.h"

class cachedb
{
public:
	cachedb();
	~cachedb();

	int get_inverted_index_iterm(_words_map_t words, _index_dict_t &indext_dic);
};


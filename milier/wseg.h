#pragma once

#include "common.h"

std::vector<std::string> _punctuations = {
	"£¬",
	"¡£"
};

class wseg
{
public:
	wseg();
	~wseg();
	wseg(int n_gram);

	size_t words_segment(_document_id_t document_id, std::string document, _index_dict_t &index_dict);
	size_t words_segment(std::string document, std::vector<std::string> &words_vec);
	size_t words_segment(std::string document, _words_map_t &words_map);
private:
	int _n_gram;
};


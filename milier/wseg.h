#pragma once

#include "common.h"

std::vector<std::string> _punctuations = {
	"£¬",
	"¡£"
};

class wseg
{
public:
	wseg(std::string fname, size_t n_gram);
	~wseg();

	bool is_punctuation(std::string::reverse_iterator iter) const;
	size_t init_the_words_dict();
	size_t words_segment(std::string document, _words_map_t &words_map);
private:
	int _n_gram;

	std::vector<std::string> _dicts_fname;
	std::unordered_set<std::string> _words_dict;
};


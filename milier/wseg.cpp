#include "wseg.h"

wseg::wseg()
{
	std::string fname("./dict");
	std::ifstream in(fname);
	if (in.is_open()) {
		std::string dict_fname;
		while (std::getline(in, dict_fname)) {
			_dicts_fname.push_back(dict_fname);
		}
		in.close();
	}
}

wseg::~wseg()
{
	_dicts_fname.clear();
	_words_dict.clear();
}

bool wseg::is_punctuation(std::string::reverse_iterator iter) const
{
	return !(std::find(_punctuations.begin(), _punctuations.end(), *iter) != _punctuations.end());
}

size_t wseg::init_the_words_dict()
{
	for (auto fname : _dicts_fname) {
		std::ifstream in(fname);
		if (in.is_open()) {
			std::string word;
			while (std::getline(in, word)) {
				_words_dict.insert(word);
			}
			in.close();
		}
	}

	return _words_dict.size();
}

size_t wseg::words_segment(std::string document, _words_map_t &words_map)
{
	std::string::reverse_iterator behinde, forward, tmp;
	behinde = forward = tmp = document.rbegin();

	//RMM algorithm
	while (forward != document.rend()) {
		while (forward != document.rend() &&
			!is_punctuation(forward)) {
			++forward;
		}
		tmp = forward;
		if (forward == behinde) {
			//all are punctuations or all words are not find in dict
			behinde = tmp = --forward;
			continue;
		}
		if (forward != document.rend()) {
			//exist punctuation
			--forward;
		}
		if (forward > behinde) {
			break;			//all words is punctuations
		}
		std::string word(forward, behinde);
		if (_words_dict.find(word) != _words_dict.end()) {
			//find the word int the dict
			_words_map_iter_t iter = words_map.find(word);
			if (iter != words_map.end()) {
				//already in words map, add postions and postion count
				iter->second.positions.push_back(
					std::distance(document.begin(), document.end()) - 
					std::distance(behinde, forward)
				);
				++(iter->second.positions_count);
			}
			else {
				postings_list postting_iterm;
				postting_iterm.positions.push_back(
					std::distance(document.begin(), document.end()) -
					std::distance(behinde, forward)
				);
				postting_iterm.positions_count = 1;
				words_map.insert(std::pair<std::string, postings_list>(word, postting_iterm));
			}
			behinde = tmp;
			forward = tmp + 1;
		}
		else {
			//the word not in the dict
			--forward;
		}
	}

	return words_map.size();
}
#include "wseg.h"

wseg::wseg()
{
	_n_gram = 2;
}


wseg::~wseg()
{
}

wseg::wseg(int n_gram = 2)
{
	_n_gram = n_gram;
}

size_t wseg::words_segment(std::string document, _words_map_t &words_map)
{
}

size_t wseg::words_segment(_document_id_t document_id, std::string document, _index_dict_t &index_dict)
{
	for (size_t i = 0; i < document.length(); i += 2) {
		std::string word(&(document[i]), _n_gram);
		_index_dict_iter_t iter = index_dict.find(word);
		if (iter != index_dict.end()) {
			//the postings_list is order by default TODO
			int index = binary_search<_index_dict_iter_t, _document_id_t>(
					index_dict.begin(), index_dict.end(), document_id
				);
			if (index >= 0) {
				//the document id has already exist
				iter->second.postings_list[index].positions.push_back(i);
				++iter->second.postings_list[index].positions_count;
			} else {
				postings_list postings_list_iterm;
				postings_list_iterm.doucument_id = document_id;
				postings_list_iterm.positions.push_back(i);
				postings_list_iterm.positions_count = 1;
				iter->second.postings_list.push_back(postings_list_iterm);
			}
		}
	}

	return 0;
}

size_t wseg::words_segment(std::string document, std::vector<std::string>& words_vec)
{
	for (size_t i = 0; i < document.length(); i += 2) {
		if (std::find(_punctuations.begin(), _punctuations.end(), document[i]) != _punctuations.end()) {
			i += 2;
		}
	}
	return words_vec.size();
}

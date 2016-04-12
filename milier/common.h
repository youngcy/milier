#pragma once

#include <memory>
#include <vector>
#include <map>
#include <algorithm>


typedef long long int _document_id_t;

typedef struct _postings_list {
	_document_id_t doucument_id;				//documents ids
	std::vector<size_t> positions;		//every word positions in documents
	size_t positions_count;				//word appearence count
} postings_list;

typedef struct _inverted_index_iterm {
	size_t token_it;					//token id
	std::vector<postings_list> postings_list;
	size_t docu_count;					//total documents count
	size_t token_count;					//total token count
}inverted_index_iterm;

typedef std::map<std::string, inverted_index_iterm> _index_dict_t;
typedef std::map<std::string, inverted_index_iterm>::iterator _index_dict_iter_t;

typedef std::map<std::string, postings_list> _words_map_t;

template <type _Iter, type _Value>
int binary_search(_Iter first, _Iter last, const _Value value)
{
	_Iter mid = (first + last) / 2;
	while (first <= last) {
		if (value < mid->document_id) {
			last = mid - 1;
		}
		else if (mid->document_id < value) {
			first = mid + 1;
		}
		else {
			return std::distance(mid, first);
		}
	}

	return -1;
}
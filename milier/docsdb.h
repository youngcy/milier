#pragma once

#include <string>
#include<vector>
#include "common.h"

class docsdb
{
public:
	docsdb();
	~docsdb();
	docsdb(std::string host, short port, std::string db_name);

	int get_increased_document_count(size_t *document_count) const;
	int get_total_document_count(size_t *document_count) const;

	_document_id_t get_total_document_id(size_t *index) const;
	_document_id_t get_increased_document_id(size_t *index) const;

	_document_id_t get_total_document_id() const;
	_document_id_t get_increased_document_id() const;

	int get_document(_document_id_t id, std::string &document);

private:
	size_t _total_document_count;
	size_t _increased_document_count;

	mutable size_t _total_document_id_index;
	std::vector<_document_id_t> _total_document_ids;
	mutable size_t _increased_document_id_index;
	std::vector<_document_id_t> _increased_document_ids;
};


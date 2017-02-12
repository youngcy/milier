#include "docsdb.h"



docsdb::docsdb()
{
	_total_document_count = 1;
	_increased_document_count = 0;
}


docsdb::~docsdb()
{
}

docsdb::docsdb(std::string host, short port, std::string db_name)
{
}

int docsdb::get_increased_document_count(size_t * document_count) const
{
	*document_count = _increased_document_count;
	return 0;
}

int docsdb::get_total_document_count(size_t * document_count) const
{
	*document_count = _total_document_count;
	return 0;
}

_document_id_t docsdb::get_total_document_id(size_t * index = nullptr) const
{
	_document_id_t document_id;
	if (index) {
		*index = _total_document_id_index;
	}

	document_id = _total_document_ids[_total_document_id_index];
	++_total_document_id_index;

	return document_id;
}

_document_id_t docsdb::get_increased_document_id(size_t * index = nullptr) const
{
	_document_id_t document_id;
	if (index) {
		*index = _increased_document_id_index;
	}

	document_id = _increased_document_ids[_increased_document_id_index];
	++_increased_document_id_index;

	return document_id;
}

_document_id_t docsdb::get_total_document_id() const
{
	_document_id_t document_id;

	document_id = _total_document_ids[_total_document_id_index];
	++_total_document_id_index;

	return document_id;
}

_document_id_t docsdb::get_increased_document_id() const
{
	_document_id_t document_id;

	document_id = _increased_document_ids[_increased_document_id_index];
	++_increased_document_id_index;

	return document_id;
}

int docsdb::get_document(_document_id_t id, std::string &document)
{
	document = "爱一个人是需要用心的，不用心怎么能够叫爱呢";

	return 0;
}

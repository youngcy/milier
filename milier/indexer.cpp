#include "indexer.h"



indexer::indexer()
{
	_docsdb = std::make_shared<docsdb>();
	_wseg = std::make_shared<wseg>();
}


indexer::~indexer()
{
	_docsdb.reset();
	_wseg.reset();
}

int indexer::total_create_index()
{
	size_t document_count = 0;;
	std::string document;

	_docsdb->get_total_document_count(&document_count);
	for (size_t i = 0; i < document_count; ++i) {
		_document_id_t document_id = _docsdb->get_total_document_id();
		_docsdb->get_document(document_id, document);
		_wseg->words_segment(document_id, document, _index_dict);
	}

	return 0;
}

int indexer::increase_create_index()
{
	size_t document_count = 0;;
	_words_map_t words_map;
	std::string document;

	_docsdb->get_increased_document_count(&document_count);
	for (size_t i = 0; i < document_count; ++i) {
		_document_id_t document_id = _docsdb->get_increased_document_id();
		_docsdb->get_document(document_id, document);
		_wseg->words_segment(document, words_map);
	}


	return 0;
}

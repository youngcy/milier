#include <iostream>
#include "common.h"
#include "milier.h"

int main()
{
	std::vector<_document_id_t> document_ids;
	std::shared_ptr<milier> _milier = std::make_shared<milier>();
	_milier->search("��������", document_ids);

	system("pause");
}
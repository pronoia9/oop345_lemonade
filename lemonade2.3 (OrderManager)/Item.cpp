#include "item.h"

Item::Item(std::vector<std::string>& row) //: itemSlots("1")
{
	if (ITEM_LOG) { std::clog << "***** [INFO] - Item.cpp - Item()  --  row size (" << row.size() << ")  row =";
	for (auto i : row)
	{
		std::clog << " " << i;
	}
	std::clog << std::endl; }

	switch (row.size())
	{
	case 5:
		itemDescription = row[4];
	case 4:
		if   (validName(row[0]))       itemName = row[0];
		else  throw std::string("Expected an item name, found '") + row[0] + "'";

		if   (validName(row[1]))  itemInstaller = row[1];
		else  throw std::string("Expected a instaler task --- found '") + row[2] + "'";

		if   (validName(row[2]))    itemRemover = row[2];
		else  throw std::string("Expected a remover task --- found '") + row[2] + "'";

		if   (validNumber(row[3])) itemSequence = row[3];
		else  throw std::string("Expected a sequence task --- found '") + row[3] + "'";
		break;
	default:
		throw std::string("Expected 4 or 5 fields, found ") + std::to_string(row.size());
	}
}

void Item::print()
{
	std::cout << "Item /Name/Installer/Remover/Sequence/Description/ = "
		      << "/" << itemName
		      << "/" << itemInstaller
		      << "/" << itemRemover
		      << "/" << itemSequence
		      << "/" << itemDescription
		      << "/\n";
}

void Item::graph(std::fstream& os)
{
	std::string q("\"");

	os << q + itemName + q + " -> " + q + itemInstaller + q + " [color=green];\n";
	os << q + itemName + q + " -> " + q + itemRemover + q + " [color=red];\n";
}

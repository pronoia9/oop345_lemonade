#pragma once
#include "utilities.h"

class Item
{
	std::string itemName, itemDescription, itemInstaller, itemRemover, itemSequence;

public:
	Item(std::vector<std::string> &row);
	void print();
	void graph(std::fstream& os);
};
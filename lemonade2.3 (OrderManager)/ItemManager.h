#pragma once
#include "item.h"

class ItemManager
{
	std::vector<Item> itemList;

public:
	ItemManager(std::vector<std::vector<std::string>> &csvData);
	void print();
	void graph(std::string& fileName);
};
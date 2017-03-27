#include "itemManager.h"

ItemManager::ItemManager(std::vector<std::vector<std::string>>& csvData)
{
	if (ITEM_LOG) std::clog << "\n\n***** [INFO] - ItemManager.cpp - ItemManager(....) START\n";
	for (auto row : csvData)
	{
		try
		{
			itemList.push_back(std::move(Item(row)));
		}
		catch (const std::string& e)
		{
			std::cerr << e << "\n";
		}
	}
	if (ITEM_LOG) std::clog << "***** [INFO] - ItemManager.cpp - ItemManager(....) END\n\n";
}

void ItemManager::print()
{
	if (ITEM_LOG) std::clog << "\n\n***** [INFO] - ItemManager.cpp - print() START\n";
	for (auto i : itemList)
	{
		i.print();
	}
	if (ITEM_LOG) std::clog << "***** [INFO] - ItemManager.cpp - print() END\n\n";
}

void ItemManager::graph(std::string & fileName)
{
	std::string f = fileName + ".gv";
	std::fstream os(f, std::ios::out | std::ios::trunc);

	os << "digraph taskGraph {\n";
	for (auto i : itemList)
	{
		i.graph(os);
	}
	os << "}\n";

	os.close();

	// linux command
	//std::string cmd = std::string("dot -Tpng ") + fileName + ".gv > " + fileName + ".gv.png";

	// windows command
	std::string cmd = "\"C:\\Program Files (x86)\\Graphviz2.38\\bin\\dot.exe\" -Tpng " + fileName + ".gv -o " + fileName + ".gv.png";

	std::cout << "\n***** running: " << cmd << "\n";
	system(cmd.c_str());
	std::cout << "\n";
}

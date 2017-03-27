#include "orderManager.h"

OrderManager::OrderManager(std::vector<std::vector<std::string>>& csvData)
{
	if (ITEM_LOG) std::clog << "\n\n***** [INFO] - OrderManager.cpp - OrderManager(....) START\n";
	for (auto row : csvData)
	{
		try
		{
			orderList.push_back(std::move(Order(row)));
		}
		catch (const std::string& e)
		{
			std::cerr << e << "\n";
		}
	}
	if (ITEM_LOG) std::clog << "***** [INFO] - OrderManager.cpp - OrderManager(....) END\n\n";
}

void OrderManager::print()
{
	if (ORDER_LOG) std::clog << "\n\n***** [INFO] - OrderManager.cpp - print() START\n";
	for (auto t : orderList)
	{
		t.print();
	}
	if (ORDER_LOG) std::clog << "***** [INFO] - OrderManager.cpp - print() END\n\n";
}

void OrderManager::graph(std::string & fileName)
{
	std::string f = fileName + ".gv";
	std::fstream os(f, std::ios::out | std::ios::trunc);

	os << "digraph taskGraph {\n";
	for (auto o : orderList)
	{
		o.graph(os);
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
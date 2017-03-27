#include "Utilities.h"
#include "TaskManager.h"
#include "ItemManager.h"
#include "OrderManager.h"

int main(int argc, char* argv[])
{
	try
	{
		if (argc != 3)
		{
			throw std::string("Usage: ") + argv[0] + " csv-data-file csv.separator-character";
		}

		std::string fileName = argv[1];
		char separator = argv[2][0];
		//std::clog << "***** [INFO] - ms2.cpp - Separator = '" << separator << "'\n";
		//std::clog << "***** [INFO] - ms2.cpp - File Name = '" << fileName << "'\n\n";

		std::vector<std::vector<std::string>> csvData;

		csvRead(fileName, separator, csvData);
		//csvPrint(csvData);

		// DEBUGGING Command Arguments = TaskList.dat "|"
		//TaskManager tm(csvData);
		//tm.print();
		//std::string gvName = "taskGraph";
		//tm.graph(gvName);

		// DEBUGGING Command Arguments = ItemList.dat "|"
		//ItemManager im(csvData);
		//im.print();
		//std::string gvName = "itemGraph";
		//im.graph(gvName);

		// DEBUGGING Command Arguments = CustomerOrders.dat "|"
		OrderManager om(csvData);
		om.print();
		std::string gvName = "orderGraph";
		om.graph(gvName);
	}
	catch (const std::string& e)
	{
		std::cerr << e << "\n";
	}
	//system("pause");
}
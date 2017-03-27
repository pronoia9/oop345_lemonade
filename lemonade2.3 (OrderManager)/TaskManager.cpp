#include "TaskManager.h"

TaskManager::TaskManager(std::vector<std::vector<std::string>> &csvData)
{
	if (TASK_LOG) std::clog << "\n\n***** [INFO] - TaskManager.cpp - TaskManager(....) START\n";
	for (auto& row : csvData)
	{
		try
		{
			taskList.push_back(std::move(Task(row)));
		}
		catch (const std::string& e)
		{
			std::cerr << e << "\n";
		}
	}
	if (TASK_LOG) std::clog << "***** [INFO] - TaskManager.cpp - TaskManager(....) END\n\n";
}

void TaskManager::print()
{
	if (TASK_LOG) std::clog << "\n\n***** [INFO] - TaskManager.cpp - print() START\n";
	for (auto t : taskList)
	{
		t.print();
	}
	if (TASK_LOG) std::clog << "***** [INFO] - TaskManager.cpp - print() END\n\n";
}

void TaskManager::graph(std::string& fileName)
{
	std::string f = fileName + ".gv";
	std::fstream os(f, std::ios::out | std::ios::trunc);

	os << "digraph taskGraph {\n";
	for (auto t : taskList)
	{
		t.graph(os);
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
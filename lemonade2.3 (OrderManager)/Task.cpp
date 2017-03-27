#include "Task.h"

Task::Task(std::vector<std::string> &row) : taskSlots("1")
{
	if (TASK_LOG) { std::clog << "***** [INFO] - Task.cpp - Task()  --  row size (" << row.size() << ")  row =";
	for (auto i : row)
	{
		std::clog << " " << i;
	}
	std::clog << std::endl; }

	switch (row.size())
	{
	case 4:
		if  (validName(row[3]))    taskFail = row[3];
		else throw std::string("Expected a failtask name --- found '") + row[3] + "'";
	case 3:
		if  (validName(row[2]))    taskPass = row[2];
		else throw std::string("Expected a failtask name --- found '") + row[2] + "'";
	case 2:
		if  (validNumber(row[1]))  taskSlots = row[1];
		else throw std::string("Expected a failtask slot --- found '") + row[1] + "'";
	case 1:
		taskName = row[0];
		break;
	default:
		throw std::string("Expected 1,2,3 or 4 fields, found ") + std::to_string(row.size());
	}
}

void Task::print()
{
	std::cout << "/Name/Slots/Pass/Fail/ = ";
	std::cout << "/" << taskName << "/" << taskSlots << "/" << taskPass << "/" << taskFail << "/\n";
}

void Task::graph(std::fstream& os)
{
	char q = '"';
	if (!taskPass.empty())  os << q << taskName << q << " -> " << q << taskPass << q << " [color=green];\n";
	if (!taskFail.empty())  os << q << taskName << q << " -> " << q << taskFail << q << " [color=red];\n";

	if (taskPass.empty() && taskFail.empty())  os << q << taskName << q << ";\n";
}
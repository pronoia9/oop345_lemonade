#pragma once
#include "Utilities.h"

class Task
{
	std::string taskName, taskSlots, taskPass, taskFail;

public:
	Task(std::vector<std::string> &row);
	void print();
	void graph(std::fstream& os);
};
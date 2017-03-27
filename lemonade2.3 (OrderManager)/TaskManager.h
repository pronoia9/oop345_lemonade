#pragma once
#include "Task.h"

class TaskManager
{
	std::vector<Task> taskList;

public:
	TaskManager(std::vector<std::vector<std::string>> &csvData);
	void print();
	void graph(std::string& fileName);
};
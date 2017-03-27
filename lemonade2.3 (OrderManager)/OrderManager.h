#pragma once
#include "order.h"

class OrderManager
{
	std::vector<Order> orderList;

public:
	OrderManager(std::vector<std::vector<std::string>> &csvData);
	void print();
	void graph(std::string& fileName);
};
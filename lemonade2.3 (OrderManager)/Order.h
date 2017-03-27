#pragma once
#include "utilities.h"

class Order
{
	std::string orderCustomer, orderProduct;
	std::vector<std::string> itemList;

public:
	Order();
	Order(std::vector<std::string> &row);
	void print();
	void graph(std::fstream& os);
};

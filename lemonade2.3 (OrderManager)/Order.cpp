#include "order.h"

Order::Order(std::vector<std::string> &row)
{
	if (ORDER_LOG) { std::clog << "***** [INFO] - Order.cpp - Order()  --  row size (" << row.size() << ")  row =";
	for (auto i : row)
	{
		std::clog << " " << i;
	}
	std::clog << std::endl; }

	if (row.size() < 3)
		throw std::string("Expected at least 3 fields - found ") + std::to_string(row.size());
	
	if (validName(row[0]))
		orderCustomer = row[0];
	else
		throw std::string("Expected a customer name, found '") + row[0] + "'";

	if (validName(row[1]))
		orderProduct = row[1];
	else
		throw std::string("Expected a product name, found '") + row[1] + "'";

	for (size_t i = 2; i < row.size(); i++)
		if (validName(row[i]))
			itemList.push_back(row[i]);
}

void Order::print()
{
	std::cout << "order /customer/product/items.../ = "
		      << "/" << orderCustomer
		      << "/" << orderProduct;

	for (auto item : itemList)
		std::cout << "/" << item;

	std::cout << "\n";
}

void Order::graph(std::fstream& os)
{
	std::string q("\"");
	
	for (auto item : itemList)
		os << q + orderCustomer + ":" + orderProduct + q + " -> " + q + item + q + " [color=blue];\n";
}
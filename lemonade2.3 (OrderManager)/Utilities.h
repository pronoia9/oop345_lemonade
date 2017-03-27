#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#define UTIL_LOG  true
#define TASK_LOG  true
#define ITEM_LOG  true
#define ORDER_LOG true

void csvRead(std::string& fileName, char separator, std::vector<std::vector<std::string>> &csvData);
void csvPrint(std::vector<std::vector<std::string>> &csvData);

void trim(std::string& s);
std::string trimm(std::string& str);
int length(std::string& str);
bool strCheck(std::string& str, char c);
bool whitespace(std::string& str);

bool validWord(std::string& s);
bool validName(std::string& s);
bool validNumber(std::string& s);
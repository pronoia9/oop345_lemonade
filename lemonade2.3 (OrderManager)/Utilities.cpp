#include "Utilities.h"

using namespace std;

void csvRead(string& fileName, char separator, vector< vector<string> > &csvData)
{
	fstream file(fileName, ios::in);
	if (!file.is_open())
		throw string("Cannot open file '") + fileName + "'\n";

	string line;
	while (getline(file, line))
	{
		if (UTIL_LOG) std::clog << "***** [INFO] - Utilities.cpp - csvRead(....) - line size = " << std::setw(2) << line.size() << "  valid=(" << strCheck(line, separator) << ")" << " -> '" << line << "'\n";
		// Checks if the line's empty AND if it obly contains whitespaces OR the separator
		if (!line.empty() && strCheck(line, ' ') && strCheck(line, separator)) //!separatorChk(line, separator)
		{
			// handle CR '\r' in data
			auto cr = line.find('\r');
			if (cr != string::npos) { line.erase(cr); }

			size_t index = 0;
			string field;
			vector<string> fields;

			while (index < line.size())
			{
				while (index < line.size() && line[index] != separator)
				{
					field += line[index];
					index++;
				}
				index++; // skip the separator
				trim(field); // skip the space

				fields.push_back(move(field));
			}
			csvData.push_back(move(fields));
		}
	}
	if (UTIL_LOG) std::clog << "\n\n";
	file.close();
}

void csvPrint(vector<vector<string>> &csvData)
{
	if (UTIL_LOG) clog << "\n\n***** [INFO] - Utilities.cpp - csvPrint(....) START\n";

	for (size_t row = 0; row < csvData.size(); row++)
	{
		cout << "***** ";
		for (size_t col = 0; col < csvData[row].size(); col++)
			cout << "[" << csvData[row][col] << "] ";

		cout << "\n";
	}

	if (UTIL_LOG) clog << "***** [INFO] - Utilities.cpp - csvPrint(....) END\n\n";
}


void trim(string& str)
{
	// trim leading spaces
	while (!str.empty() && str[0] == ' ')
		str.erase(0, 1);

	//trim trailing spaces
	while (!str.empty() && str[str.size() - 1] == ' ')
		str.erase(str.size() - 1, 1);
}

// Trims the string and returns a copy
std::string trimm(std::string & str)
{
	std::string s = str;

	while (!s.empty() && s[0] == ' ')
		s.erase(0, 1);

	while (!s.empty() && s[s.size() - 1] == ' ')
		s.erase(s.size() - 1, 1);

	return s;
}

// Trims the string and returns it's size
int length(std::string & str)
{
	std::string s = trimm(str);  
	return s.size();
}

// Checks if the string contains only c character
bool strCheck(std::string & str, char c)
{
	int cnt = 0;

	for (auto s : str)
		if (s == c || s == '\t')  cnt++;

	if (cnt == length(str)) return false;
	return true;
}

// Checks if the string is a single word, containing only alphanumeric characters and NO spaces
bool validWord(std::string & str)
{
	for (auto c : str)
		if (!isalnum(c) || c == ' ')  return false;
	return true;
}

// Checks if the string is made of alphanumeric characters and/or spaces
bool validName(std::string & str)
{
	//if (UTIL_LOG) std::clog << "***** [INFO] - Utilities.cpp - validName(" << str << ") ";
	for (auto c : str)
	{
		if (!(isalnum(c) || c == ' '))  // did NOT work with = if (!isalnum(c) || c != ' ')
		{
			//if (UTIL_LOG) std::clog << "is !isalnum(" << c << ") || is whitespace\n";
			return false;
		}
	}
	return true;
}

// Checks if the string is a digit, containing only digits and NO spaces
bool validNumber(std::string & str)
{
	for (auto n : str)
		if (!isdigit(n) || n == ' ')  return false;
	return true;
}
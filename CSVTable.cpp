#include "CSVTable.hpp"
#include <fstream>
#include <list>

using namespace std;

void CSVTable::load(const std::string &path)
{
	ifstream fp(path);
	if(!fp.is_open())
		return;
	string buffer;
	getline(fp, buffer);
	header = parse_line(buffer);

	list<Row> data;
	getline(fp, buffer);
	while(!buffer.empty())
	{
		Row next = parse_line(buffer);
		data.push_back(next);
		getline(fp, buffer);
	}
	this->data.assign(data.cbegin(), data.cend());

	fp.close();
}

CSVTable::Row CSVTable::parse_line(string data)
{
	list<string> resultList;
	string buffer;
	for(char ch : data)
	{
		if(ch == ',')
		{
			resultList.push_back(buffer);
			buffer.clear();
		}
		else
			buffer += ch;
	}
	return vector<string>(resultList.cbegin(), resultList.cend());
}

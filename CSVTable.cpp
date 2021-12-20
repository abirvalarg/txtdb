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

bool CSVTable::save(const std::string &path) const
{
	ofstream fp(path);
	if(!fp.is_open())
		return false;
	fp.close();
	return true;
}

CSVTable::Row CSVTable::parse_line(string data)
{
	list<string> resultList;
	string buffer;
	bool quoted = false;
	bool lastQuote = false;
	bool first = true;
	for(char ch : data)
	{
		if(ch == ',')
		{
			if(!quoted)
			{
				resultList.push_back(buffer);
				buffer.clear();
				first = true;
				quoted = false;
			}
			else
				buffer += ',';
		}
		else if(ch == '"')
		{
			if(!quoted && lastQuote)
				buffer += '"';
			quoted = !quoted;
		}
		else
		{
			buffer += ch;
		}

		if(ch != ',')
			first = false;
		lastQuote = ch == '"';
	}
	resultList.push_back(buffer);
	return vector<string>(resultList.cbegin(), resultList.cend());
}

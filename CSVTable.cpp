#include "CSVTable.hpp"
#include <fstream>
#include <list>
#include <sstream>

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
	fp << row_to_str(header) << '\n';
	for(const auto row : data)
		fp << row_to_str(row) << '\n';
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

string CSVTable::row_to_str(const CSVTable::Row &row)
{
	stringstream buffer;
	bool first = true;
	for(const string &col : row)
	{
		if(!first)
			buffer << ',';
		buffer << '"';
		for(char ch : col)
		{
			buffer << ch;
			if(ch == '"')
				buffer << '"';
		}
		buffer << '"';
		first = false;
	}
	return buffer.str();
}

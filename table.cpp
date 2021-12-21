#include "table.hpp"
#include <cstdlib>
#include <list>
#include <string>

using namespace std;

Table::Table(const std::string &path)
{
	stud.load(path + "/stud.csv");
	subj.load(path + "/subj.csv");
	grade.load(path + "/grade.csv");
}

vector<string> Table::subjects() const
{
	vector<string> res(subj.row_count());
	for(int i = 0; i < subj.row_count(); i++)
		res.push_back(subj.row(i)[1]);
	return res;
}

vector<int> Table::grades(int sub, int stud) const
{
	list<int> res;

	for(int i = 0; i < grade.row_count(); i++)
	{
		const CSVTable::Row &row = grade.row(i);
		if(atoi(row[1].c_str()) == sub && atoi(row[2].c_str()))
			res.push_back(atoi(row[3].c_str()));
	}

	return vector<int>(res.cbegin(), res.cend());
}
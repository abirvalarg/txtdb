#include <iostream>
#include "CSVTable.hpp"

using namespace std;

int main()
{
	CSVTable stud("data/stud.csv");
	auto head = stud.get_header();
	for(int i = 0; i < stud.row_count(); i++)
	{
		cout << "==========\n";
		CSVTable::Row row = stud.row(i);
		for(int col = 0; col < head.size(); col++)
			cout << head[col] << ": " << row[col] << '\n';
	}
	return 0;
}

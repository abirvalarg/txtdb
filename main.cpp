#include <iostream>
#include <string>
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
	size_t lastId = atoi(stud.row(stud.row_count() - 1)[0].c_str());
	stud.append({
		to_string(lastId + 1),
		"Иван",
		"Ивмнович",
		"Иванов",
		"11",
		"\"Б\""
	});
	stud.save("data/stud.csv");
	return 0;
}

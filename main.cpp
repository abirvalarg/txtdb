#include <iostream>
#include <string>
#include <vector>
#include "CSVTable.hpp"
#include "table.hpp"

using namespace std;

int main(int argc, char **argv)
{
	Table tab("data");
	const CSVTable &stud = tab.students();
	const vector<string> subj = tab.subjects();
	if(argc >= 2 && string(argv[1]) == "all" || argc == 1)
	{
		for(int _studId = 0; _studId < stud.row_count(); _studId++)
		{
			int studId = atoi(stud.row(_studId)[0].c_str());
			const CSVTable::Row &studRow = stud.row(studId);
			cout  << studRow[2] << ' ' << studRow[1] << ' ' << studRow[3] << "; " << studRow[4] << studRow[5] << '\n';
			for(int subId = 0; subId < subj.size(); subId++)
			{
				cout << '\t' << subj[subId] << '\n';
				for(int grade : tab.grades(subId, studId))
					cout << "\t\t" << grade << '\n';
			}
		}
	}
	else if(argc >= 2)
	{
		if(string(argv[1]) == "average")
		{
			for(int _studId = 0; _studId < stud.row_count(); _studId++)
			{
				int studId = atoi(stud.row(_studId)[0].c_str());
				const CSVTable::Row &studRow = stud.row(_studId);
				cout  << studRow[2] << ' ' << studRow[1] << ' ' << studRow[3] << "; " << studRow[4] << studRow[5] << '\n';
				for(int subId = 0; subId < subj.size(); subId++)
					cout << '\t' << subj[subId] << ": " << tab.average(subId, studId) << '\n';
			}
		}
		else if(string(argv[1]) == "grade")
		{
			if(argc == 3)
			{
				string grade = argv[2];
			}
		}
	}
	return 0;
}

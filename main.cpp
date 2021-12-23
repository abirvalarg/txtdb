#include <iostream>
#include <string>
#include <vector>
#include "CSVTable.hpp"
#include "table.hpp"

using namespace std;

int main(int argc, char **argv)
{
	Table tab("data");
	CSVTable &stud = tab.students();
	const vector<string> subj = tab.subjects();
	if((argc >= 2 && string(argv[1]) == "all") || argc == 1)
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
                for(int i = 0; i < stud.row_count(); i++)
                {
                    const CSVTable::Row &row = stud.row(i);
                    if(row[4] == grade)
                    {
			cout << row[0] << ": " << row[2] << ' ' << row[1] << ' ' << row[3] << "; " << row[4] << row[5] << '\n';
                    }
                }
			}
		}
        else if(string(argv[1]) == "add")
        {
            if(string(argv[2]) == "student")
            {
                string name = argv[3],
                    surname = argv[4],
                    patr = argv[5],
                    grade =  argv[6],
                    par = argv[7];
                    size_t lastId = atoi(stud.row(stud.row_count() - 1)[0].c_str());
                    stud.append({to_string(lastId + 1), name, surname, patr, grade, par});
            }
        }
	}
    tab.save("data");
	return 0;
}

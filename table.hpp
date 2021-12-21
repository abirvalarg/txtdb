#pragma once
#include "CSVTable.hpp"
#include <vector>

class Table
{
	CSVTable stud;
	CSVTable subj;
	CSVTable grade;
public:
	Table(const std::string &path);

	std::vector<std::string> subjects() const;
	std::vector<int> grades(int sub, int stud) const;
	float average(int sub, int stud) const;
};
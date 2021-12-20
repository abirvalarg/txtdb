#pragma once
#include <cstddef>
#include <string>
#include <vector>

class CSVTable
{
public:
	CSVTable() {}
	CSVTable(const std::string &path) { load(path); }

	void load(const std::string &path);
	void load_str(const std::string &data);
	const std::vector<std::string> &get_header() const;
	std::vector<std::string> &row(size_t id);
	const std::vector<std::string> &row(size_t id) const;
};

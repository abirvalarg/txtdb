#pragma once
#include <cstddef>
#include <string>
#include <vector>

class CSVTable
{
public:
	typedef std::vector<std::string> Row;

private:
	Row header;
	std::vector<Row> data;

	std::vector<std::string> parse_line(std::string data);

public:
	CSVTable() {}
	CSVTable(const std::string &path) { load(path); }

	void load(const std::string &path);
	const Row &get_header() const { return header; }
	Row &row(size_t id) { return data[id]; }
	const Row &row(size_t id) const { return data[id]; }
	size_t row_count() const { return data.size(); }
};

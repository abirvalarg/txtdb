#pragma once
#include <cstddef>
#include <string>
#include <vector>

class CSVTable
{
public:
	typedef std::vector<std::string> Row;

private:
	static std::vector<std::string> __empty;

	Row header;
	std::vector<Row> data;

	static Row parse_line(std::string data);
	static std::string row_to_str(const Row &row);

public:
	CSVTable() {}
	CSVTable(const std::string &path) { load(path); }

	void load(const std::string &path);
	const Row &get_header() const { return header; }
	Row &row(size_t id) { return data[id]; }
	const Row &by_id(size_t id) const;
	Row &by_id(size_t id);
	const Row &row(size_t id) const { return data[id]; }
	size_t row_count() const { return data.size(); }
	void append(Row row) { data.push_back(row); }
	bool save(const std::string &path) const;
};

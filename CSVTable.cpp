#include "CSVTable.hpp"
#include <fstream>

using namespace std;

void CSVTable::load_str(const std::string &data)
{
	ifstream fp(data);
	if(!fp.is_open())
		return;
}

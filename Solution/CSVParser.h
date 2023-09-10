#pragma once

#include <vector>
#include <fstream>
#include <memory>
#include <utility>

using std::vector;

namespace CSVParser
{
	std::unique_ptr<vector<vector<float>>> ParseCSV(std::ifstream& csv_file);
}
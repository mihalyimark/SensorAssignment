#include "CSVParser.h"

#include <vector>
#include <fstream>
#include <string>
#include <memory>
#include <utility>
#include <sstream>

using std::vector;

namespace CSVParser
{
	int NumberOfColumns(std::string& line)
	{
		std::istringstream iss(line);
		std::string column;
		int res = 0;
		while (std::getline(iss, column, ','))
		{
			++res;
		}

		return res;
	}

	vector<float> ParseLineAsFloats(std::string& line)
	{
		std::istringstream iss(line);
		std::string value;
		vector<float> res;
		while (std::getline(iss, value, ','))
		{
			if (!value.empty())
			{
				float parsed = std::stof(value);
				res.push_back(parsed);
			}
		}

		return res;
	}

	//The parser reads in csv files, where the values are floats.
	//The parser only stores rows, where there is no missing value.
	// The first line must be the column names in the csv file.
	//The ifstream file object must be closed by the caller.
	std::unique_ptr<vector<vector<float>>> ParseCSV(std::ifstream& csv_file)
	{
		auto data = std::make_unique<vector<vector<float>>>();
		std::string line;
		std::getline(csv_file, line);
		int n_columns = NumberOfColumns(line);
		for (int i = 0; i < n_columns; i++)
		{
			vector<float> column;
			data->push_back(column);
		}

		while (std::getline(csv_file, line))
		{
			vector<float> parsed_vec = ParseLineAsFloats(line);
			if (parsed_vec.size() == n_columns)
			{
				for (int i = 0; i < n_columns; i++)
				{
					data->at(i).push_back(parsed_vec.at(i));
				}
			}
		}

		return data;
	}
}
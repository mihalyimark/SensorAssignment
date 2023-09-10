#pragma once

#include <memory>
#include <vector>

using std::vector;
using CSVData = std::unique_ptr<std::vector<std::vector<float>>>;

namespace MyApp
{
    void RenderUI(const CSVData& imu_data, const CSVData& dbw_data);
}

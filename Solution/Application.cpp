#include "Application.h"

#include "imgui.h"
#include <vector>

namespace MyApp
{
    void RenderUI(const CSVData& imu_data, const CSVData& dbw_data)
    {
        if (!ImGui::Begin("imu.csv", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::End();
            return;
        }

        auto graph_size = ImVec2(0.0f, 100.0f);

        ImGui::PushStyleColor(ImGuiCol_PlotLines, ImColor(170, 17, 23, 255).Value);

        ImGui::PlotLines("gyro_x", imu_data->at(1).data(), imu_data->at(1).size(), 0, NULL, -0.12f, 0.18f, graph_size);
        ImGui::SameLine();
        ImGui::PlotLines("acc_x", imu_data->at(4).data(), imu_data->at(4).size(), 0, NULL, -2.8f, 3.58f, graph_size);

        ImGui::PlotLines("gyro_y", imu_data->at(2).data(), imu_data->at(2).size(), 0, NULL, -0.11f, 0.14f, graph_size);
        ImGui::SameLine();
        ImGui::PlotLines("acc_y", imu_data->at(5).data(), imu_data->at(5).size(), 0, NULL, -3.3f, 2.66f, graph_size);


        ImGui::PlotLines("gyro_z", imu_data->at(3).data(), imu_data->at(3).size(), 0, NULL, -0.14f, 0.15f, graph_size);
        ImGui::SameLine();
        ImGui::PlotLines("acc_z", imu_data->at(6).data(), imu_data->at(6).size(), 0, NULL, 5.91f, 13.14f, graph_size);

        ImGui::PlotLines("conf_g", imu_data->at(7).data(), imu_data->at(7).size(), 0, NULL, 0.0f, 1.0f, graph_size);
        ImGui::SameLine();
        ImGui::PlotLines("conf_a", imu_data->at(8).data(), imu_data->at(8).size(), 0, NULL, 0.0f, 1.0f, graph_size);

        ImGui::End();

        if (!ImGui::Begin("dbw.csv", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::End();
            return;
        }

        ImGui::PlotLines("vehicl_speed", dbw_data->at(1).data(), dbw_data->at(1).size(), 0, NULL, 8.83f, 22.93f, graph_size);
        ImGui::SameLine();
        ImGui::PlotLines("yaw_rate", dbw_data->at(2).data(), dbw_data->at(2).size(), 0, NULL, -0.016f, 0.093f, graph_size);

        ImGui::PlotLines("v_front_left", dbw_data->at(3).data(), dbw_data->at(3).size(), 0, NULL, 8.9f, 23.03f, graph_size);
        ImGui::SameLine();
        ImGui::PlotLines("v_front_right", dbw_data->at(4).data(), dbw_data->at(4).size(), 0, NULL, 8.91f, 23.23f, graph_size);

        ImGui::PlotLines("v_rear_left ", dbw_data->at(5).data(), dbw_data->at(5).size(), 0, NULL, 8.86f, 23.08f, graph_size);
        ImGui::SameLine();
        ImGui::PlotLines("v_rear_right", dbw_data->at(6).data(), dbw_data->at(6).size(), 0, NULL, 8.87f, 23.27f, graph_size);

        ImGui::End();
    }
}

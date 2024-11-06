#include "writeJSON.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

void WriteJSON::writeFile(const std::string& filePath, const std::unordered_map<std::string, std::string>& data) const {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filePath << std::endl;
        return;
    }

    nlohmann::json jsonData;
    for (const auto& pair : data) {
        jsonData[pair.first] = pair.second;
    }

    file << jsonData.dump(4); // Pretty print with 4 spaces
}
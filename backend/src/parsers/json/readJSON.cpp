#include "readJSON.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

std::unordered_map<std::string, std::string> ReadJSON::readFile(const std::string& filePath) const {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filePath << std::endl;
        return {};
    }

    nlohmann::json jsonData;
    file >> jsonData;

    std::unordered_map<std::string, std::string> result;
    for (auto it = jsonData.begin(); it != jsonData.end(); ++it) {
        result[it.key()] = it.value();
    }
    return result;
}
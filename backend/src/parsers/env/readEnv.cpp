#include "readEnv.h"
#include <fstream>
#include <iostream>

std::unordered_map<std::string, std::string> ReadEnv::readFile(const std::string& filePath) const {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filePath << std::endl;
        return {};
    }

    std::unordered_map<std::string, std::string> result;
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find("=");
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            result[key] = value;
        }
    }

    return result;
}
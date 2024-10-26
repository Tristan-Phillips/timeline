#include "config.h"
#include <fstream>
#include <sstream>
#include <iostream>

Config::Config(const std::string& filename) {
    load(filename);
}

void Config::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Remove leading and trailing whitespace
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        // Skip comments and empty lines
        if (line.empty() || line[0] == '#') continue;

        std::istringstream stream(line);
        std::string key, value;

        if (std::getline(stream, key, '=') && std::getline(stream, value)) {
            // Remove surrounding whitespace
            key.erase(0, key.find_first_not_of(" \t"));
            key.erase(key.find_last_not_of(" \t") + 1);
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);

            configMap[key] = value;
        }
    }
    file.close();
}

std::string Config::get(const std::string& key) const {
    auto it = configMap.find(key);
    if (it == configMap.end()) {
        std::cerr << "Key not found: " << key << std::endl;
        return "";
    }
    return it->second;
}
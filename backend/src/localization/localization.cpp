#include "localization.h"
#include <fstream>
#include <iostream>

Localization::Localization(const std::string& filePath) {
    loadFromFile(filePath);
}

void Localization::loadFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filePath << std::endl;
        return;
    }

    nlohmann::json jsonData;
    file >> jsonData;

    for (auto it = jsonData.begin(); it != jsonData.end(); ++it) {
        m_translations[it.key()] = it.value();
    }
}

std::string Localization::getString(const std::string& key) const {
    auto it = m_translations.find(key);
    if (it != m_translations.end()) {
        return it->second;
    }
    return ""; // return an empty string if the key is not found
}
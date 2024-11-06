#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

class Localization {
public:
    Localization(const std::string& filePath);
    std::string getString(const std::string& key) const;

private:
    std::unordered_map<std::string, std::string> m_translations;
    void loadFromFile(const std::string& filePath);
};

#endif // LOCALIZATION_H
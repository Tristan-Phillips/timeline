#pragma once

#include <string>
#include <unordered_map>

class Read {
public:
    virtual ~Read() = default;
    virtual std::unordered_map<std::string, std::string> readFile(const std::string& filePath) const = 0;
};
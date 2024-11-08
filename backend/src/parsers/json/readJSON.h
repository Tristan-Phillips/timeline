#pragma once

#include "read.h"
#include <unordered_map>
#include <string>

class ReadJSON : public Read {
public:
    std::unordered_map<std::string, std::string> readFile(const std::string& filePath) const override;
};
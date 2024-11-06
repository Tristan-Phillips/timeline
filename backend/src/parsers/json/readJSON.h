#ifndef READ_JSON_H
#define READ_JSON_H

#include "read.h"
#include <unordered_map>
#include <string>

class ReadJSON : public Read {
public:
    std::unordered_map<std::string, std::string> readFile(const std::string& filePath) const override;
};

#endif // READ_JSON_H
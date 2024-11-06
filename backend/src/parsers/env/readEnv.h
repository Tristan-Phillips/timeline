#ifndef READ_ENV_H
#define READ_ENV_H

#include "read.h"
#include <unordered_map>
#include <string>

class ReadEnv : public Read {
public:
    std::unordered_map<std::string, std::string> readFile(const std::string& filePath) const override;
};

#endif // READ_ENV_H
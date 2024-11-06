#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <map>
#include <unordered_map>
#include "smtp.h"

class Config {
    public:
        Config() = default;
        std::unordered_map<std::string, std::string> readEnv();
};

#endif // CONFIG_H
#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <unordered_map>

class Config {
public:
    Config(const std::string& filename = ".env");
    std::string get(const std::string& key) const;

private:
    std::unordered_map<std::string, std::string> configMap;
    void load(const std::string& filename);
};

#endif
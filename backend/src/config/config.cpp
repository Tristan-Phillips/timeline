#include "config.h"
#include "readEnv.h"

std::unordered_map<std::string, std::string> Config::readEnv() {
    ReadEnv reader;
    return reader.readFile(".env");
}
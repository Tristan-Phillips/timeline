#include <iostream>
#include "mockDatabase.h"
#include "config.h"
#include "smtp.h"
#include "logger.h"

int main() {
    Logger& logger = Logger::getInstance();
    logger.setOutputFile("server.log");

    Config config;
    std::unordered_map<std::string, std::string> env = config.readEnv();
    MockDatabase database(env["PGUSER"], env["PGPASSWORD"], env["PGHOST"], env["PGPORT"], env["PGDATABASE"]);

    logger.log("main_init", LogLevel::INFO);

    return 0;
}
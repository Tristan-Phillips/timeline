#include <iostream>
#include "mockDatabase.h"
#include "config.h"
#include "smtp.h"
#include "logger.h"

int main() {
    Logger& logger = Logger::getInstance();
    logger.setOutputFile("server.log");
    logger.log("main_init", LogLevel::INFO);

    Config config;
    std::unordered_map<std::string, std::string> env = config.readEnv();
    MockDatabase database(env["PGUSER"], env["PGPASSWORD"], env["PGHOST"], env["PGPORT"], env["PGDATABASE"]);
    database.connect();
    return 0;
}
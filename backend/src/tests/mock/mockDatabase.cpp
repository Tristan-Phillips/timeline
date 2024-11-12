#include "mockDatabase.h"
#include "logger.h"
#include <iostream>

MockDatabase::MockDatabase(const std::string& username, const std::string& password, const std::string& host, const std::string& port, const std::string& databaseName)
: Database(username, password, host, port, databaseName) {
    Logger::getInstance().log("mockDatabase_init", LogLevel::DEBUG);
}

bool MockDatabase::connect() {
    Logger::getInstance().log("mockDatabase_connect", LogLevel::DEBUG);
    return true;
}

void MockDatabase::disconnect() {
    Logger::getInstance().log("mockDatabase_disconnect", LogLevel::DEBUG);
}
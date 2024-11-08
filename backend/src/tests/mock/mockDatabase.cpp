#include "mockDatabase.h"
#include <iostream>

MockDatabase::MockDatabase(const std::string& username, const std::string& password, const std::string& host, const std::string& port, const std::string& databaseName)
: Database(username, password, host, port, databaseName) {
}
#include "databaseLocal.h"
#include <iostream>

DatabaseLocal::DatabaseLocal(const std::string& username, const std::string& password, const std::string& host, const std::string& port, const std::string& databaseName)
: Database(username, password, host, port, databaseName) {
}

bool DatabaseLocal::connect() {
    return true;
}

void DatabaseLocal::disconnect() {
}

bool DatabaseLocal::executeQuery(const std::string& query) {
    return true;
}
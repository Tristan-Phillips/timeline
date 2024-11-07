#include "databaseLocal.h"
#include <iostream>
#include "postgreDB.h"

DatabaseLocal::DatabaseLocal(const std::string& username, const std::string& password, const std::string& host, const std::string& port, const std::string& databaseName)
: Database(username, password, host, port, databaseName) {
}
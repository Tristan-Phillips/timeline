#ifndef MOCK_DATABASE_H
#define MOCK_DATABASE_H

#include "database.h"

class MockDatabase : public Database {
public:
    MockDatabase(const std::string& username = "username", const std::string& password = "password", const std::string& host = "localhost", const std::string& port = "465", const std::string& databaseName = "databaseName");
};

#endif // MOCK_DATABASE_H
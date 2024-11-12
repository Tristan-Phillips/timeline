#pragma once

#include <string>
#include "database.h"

class DatabaseLocal : public Database {
public:
    DatabaseLocal(const std::string& username, const std::string& password, const std::string& host, const std::string& port, const std::string& databaseName);
    bool connect() override;
    void disconnect() override;
};
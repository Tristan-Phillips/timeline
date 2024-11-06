#ifndef DATABASE_LOCAL_H
#define DATABASE_LOCAL_H

#include <string>
#include "database.h"

class DatabaseLocal : public Database {
public:
    DatabaseLocal(const std::string& username, const std::string& password, const std::string& host, const std::string& port, const std::string& databaseName);
};

#endif // DATABASE_LOCAL_H
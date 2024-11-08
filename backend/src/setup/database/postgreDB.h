#pragma once

#include <string>
#include <pqxx/pqxx>
#include <iostream>
#include "database.h"

class PostgreDB {
public:
    PostgreDB(Database* database);
private:
    Database* m_database;

    bool databaseExists();
    void updateSystem();
    void installPostgreSQL();
    void initializeDatabaseCluster();
    void startAndEnableService();
    void createSuperuserAndDatabase();
    void configureLocalAccess();
    void restartService();
    void setup();
};
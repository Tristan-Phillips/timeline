#include "mockDatabase.h"
#include <iostream>
#include "consolePrinter.h"

MockDatabase::MockDatabase(const std::string& username, const std::string& password, const std::string& host, const std::string& port, const std::string& databaseName)
: Database(username, password, host, port, databaseName) {
    ConsolePrinter printer("en.json");
    printer.cprint("mockDatabase_init");
}
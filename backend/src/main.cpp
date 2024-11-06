#include <iostream>
#include "localization.h"
#include "readJSON.h"
#include "writeJSON.h"
#include "databaseLocal.h"

int main() {
    ReadJSON reader;
    WriteJSON writer;
    Localization localization(&reader, &writer, "en.json");

    std::string greeting = localization.getString("greeting");
    std::string farewell = localization.getString("goodbye");

    std::cout << greeting << std::endl;
    std::cout << farewell << std::endl;

    localization.setString("new_key", "New Value");

    DatabaseLocal database("username", "password", "localhost", "5432", "databaseName");

    return 0;
}
#include <iostream>
#include "localization.h"
#include "readJSON.h"
#include "writeJSON.h"
#include "databaseLocal.h"
#include "config.h"

int main() {
    ReadJSON reader;
    WriteJSON writer;
    Localization localization(&reader, &writer, "en.json");

    std::string greeting = localization.getString("greeting");
    std::string farewell = localization.getString("goodbye");

    std::cout << greeting << std::endl;
    std::cout << farewell << std::endl;

    localization.setString("new_key", "New Value");


    Config config;
    std::unordered_map<std::string, std::string> env = config.readEnv();
    DatabaseLocal database(env["PGUSER"], env["PGPASSWORD"], env["PGHOST"], env["PGPORT"], env["PGDATABASE"]);

    return 0;
}
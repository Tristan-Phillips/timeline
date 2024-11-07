#include <iostream>
#include "mockDatabase.h"
#include "config.h"
#include "smtp.h"
#include "consolePrinter.h"

int main() {
    ConsolePrinter printer("en.json");
    printer.cprint("main_init");

    Config config;
    std::unordered_map<std::string, std::string> env = config.readEnv();
    MockDatabase database(env["PGUSER"], env["PGPASSWORD"], env["PGHOST"], env["PGPORT"], env["PGDATABASE"]);

    return 0;
}
#include "crow.h"
#include <pqxx/pqxx>
#include <string>
#include <iostream>

using namespace std;


int main () {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Welcome to the Timeline API";
    });

    app.port(3000).multithreaded().run();
}
#include "crow.h"
#include "config.h"
#include <pqxx/pqxx>
#include <string>
#include <iostream>

using namespace std;


int main () {
    Config config;
    std::string hostname = config.get("HOSTNAME");
    std::string port = config.get("PORT");
    std::cout << "Backend is running on: " << hostname << ":" << port << std::endl;

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Welcome to the Timeline API";
    });

    app.port(std::stoi(port)).multithreaded().run();
}
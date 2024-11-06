#include <iostream>
#include "localization.h"

int main() {
    Localization localization("en.json");

    std::string greeting = localization.getString("greeting");
    std::string farewell = localization.getString("goodbye");

    std::cout << greeting << std::endl;
    std::cout << farewell << std::endl;

    return 0;
}
#include "consolePrinter.h"
#include <iostream>
#include "localization.h"

ConsolePrinter::ConsolePrinter(const std::string localizationFile) : 
    m_reader(ReadJSON()), 
    m_writer(WriteJSON()), 
    m_localization(Localization(&m_reader, &m_writer, localizationFile)) {}

void ConsolePrinter::cprint(const std::string& message) {
    std::cout << m_localization.getString(message) << std::endl;
}
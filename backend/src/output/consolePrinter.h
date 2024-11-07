#ifndef CONSOLE_PRINTER_H
#define CONSOLE_PRINTER_H

#include "print.h"
#include <string>
#include "readJSON.h"
#include "writeJSON.h"
#include "localization.h"

class ConsolePrinter : public Print {
public:
    ConsolePrinter(const std::string localizationFile);
    void cprint(const std::string& message) override;
private:
    ReadJSON m_reader;
    WriteJSON m_writer;
    Localization m_localization;
};

#endif // CONSOLE_PRINTER_H
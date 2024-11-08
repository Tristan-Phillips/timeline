#pragma once

#include <string>
#include <fstream>
#include <mutex>
#include <memory>
#include <unordered_map>

#include "readJSON.h"
#include "writeJSON.h"
#include "localization.h"

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

class Logger {
public:
    static Logger& getInstance();

    void log(const std::string& message, LogLevel level = LogLevel::INFO);
    void setLogLevel(LogLevel level);
    void setOutputFile(const std::string& filename);
    void enableConsoleOutput(bool enable);

private:
    Logger();
    ~Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    void logToFile(const std::string& message);
    void logToConsole(const std::string& message);

    LogLevel m_logLevel;
    std::ofstream m_fileStream;
    bool m_consoleOutput;
    std::mutex m_mutex;

    ReadJSON m_reader;
    WriteJSON m_writer;
    Localization m_localization = Localization(&m_reader, &m_writer, "en.json"); // Find a better way to initialize this
};
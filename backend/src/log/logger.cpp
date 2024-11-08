#include "logger.h"
#include <iostream>
#include <ctime>
#include <sstream>

Logger::Logger() : m_logLevel(LogLevel::INFO), m_consoleOutput(true) {}

Logger::~Logger() {
    if (m_fileStream.is_open()) {
        m_fileStream.close();
    }
}

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::log(const std::string& message, LogLevel level) {
    if (level < m_logLevel) {
        return;
    }

    std::lock_guard<std::mutex> lock(m_mutex);
    std::ostringstream logEntry;
    std::time_t now = std::time(nullptr);
    logEntry << std::ctime(&now) << " [" << static_cast<int>(level) << "] " << m_localization.getString(message);

    if (m_consoleOutput) {
        logToConsole(logEntry.str());
    }
    if (m_fileStream.is_open()) {
        logToFile(logEntry.str());
    }
}

void Logger::setLogLevel(LogLevel level) {
    m_logLevel = level;
}

void Logger::setOutputFile(const std::string& filename) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_fileStream.is_open()) {
        m_fileStream.close();
    }
    m_fileStream.open(filename, std::ios::app);
}

void Logger::enableConsoleOutput(bool enable) {
    m_consoleOutput = enable;
}

void Logger::logToFile(const std::string& message) {
    if (m_fileStream.is_open()) {
        m_fileStream << message << std::endl;
    }
}

void Logger::logToConsole(const std::string& message) {
    std::cout << message << std::endl;
}
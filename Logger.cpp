#include "Logger.h"
#include <iostream>
#include <ctime>

Logger::Logger(const std::string& logFilePath) : logFilePath(logFilePath) {
    if (!logFilePath.empty()) {
        logFile.open(logFilePath, std::ios::out | std::ios::app);
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::Log(LogLevel level, const std::string& message) {
    std::stringstream logStream;
    logStream << GetCurrentTime() << " [" << ToString(level) << "] " << message;

    // Output to console
    std::cout << logStream.str() << std::endl;

    // Output to file if file path is set
    if (logFile.is_open()) {
        logFile << logStream.str() << std::endl;
    }
}

void Logger::Info(const std::string& message) {
    Log(LogLevel::INFO, message);
}

void Logger::Warning(const std::string& message) {
    Log(LogLevel::WARNING, message);
}

void Logger::Error(const std::string& message) {
    Log(LogLevel::ERROR, message);
}

std::string Logger::GetCurrentTime() {
    std::time_t t = std::time(nullptr);
    std::tm localTime;

#if defined(_MSC_VER)  // MSVC compiler (Windows)
    localtime_s(&localTime, &t);
#else  // POSIX (Linux, MacOS)
    localtime_r(&t, &localTime);
#endif

    char timeStr[100];
    std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &localTime);
    return std::string(timeStr);
}

std::string Logger::ToString(LogLevel level) {
    switch (level) {
    case LogLevel::INFO: return "INFO";
    case LogLevel::WARNING: return "WARNING";
    case LogLevel::ERROR: return "ERROR";
    default: return "UNKNOWN";
    }
}

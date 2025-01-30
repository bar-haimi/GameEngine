#pragma once
#include <string>
#include <fstream>
#include <sstream>

class Logger {
public:
    enum class LogLevel {
        INFO,
        WARNING,
        ERROR
    };

    // Constructor and Destructor
    Logger(const std::string& logFilePath = "");
    ~Logger();

    // Log methods
    void Log(LogLevel level, const std::string& message);
    void Info(const std::string& message);
    void Warning(const std::string& message);
    void Error(const std::string& message);

private:
    std::ofstream logFile;
    std::string logFilePath;

    // Helper methods
    std::string GetCurrentTime();
    std::string ToString(LogLevel level);
};

#include "Logger.h"

int main() {
    Logger logger("game_log.txt");

    // Log to console and file
    logger.Info("Engine initialized successfully.");
    logger.Warning("Low memory detected.");
    logger.Error("Failed to load texture.");

    return 0;
}

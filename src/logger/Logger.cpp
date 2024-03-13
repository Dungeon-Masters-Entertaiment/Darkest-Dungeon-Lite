//
// Created by Natalya Sklyar on 09.03.2024.
//


#include "Logger.h"

void MyLogger::LogDebug(const std::string &message) {
  LOG(INFO) << "[DEBUG] " << message;
}

void MyLogger::LogInfo(const std::string &message) {
  LOG(INFO) << message;
}

void MyLogger::LogWarning(const std::string &message) {
  LOG(WARNING) << message;
}

void MyLogger::LogError(const std::string &message) {
  LOG(ERROR) << message;
}

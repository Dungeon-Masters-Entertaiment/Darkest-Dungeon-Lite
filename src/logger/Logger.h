#include <iostream>
#include <glog/logging.h>
#include <fstream>

#ifndef MYLOGGER_HEADER
#define MYLOGGER_HEADER

class MyLogger {
 public:
  explicit MyLogger(const std::string &logFileName) {
    google::InitGoogleLogging(logFileName.c_str());
    google::SetLogDestination(1, logFileName.c_str());
    FLAGS_alsologtostderr = 1;
  }

  ~MyLogger() {
    google::ShutdownGoogleLogging();
  }

  void LogDebug(const std::string &message);

  void LogInfo(const std::string &message);

  void LogWarning(const std::string &message);

  void LogError(const std::string &message);
};

#endif

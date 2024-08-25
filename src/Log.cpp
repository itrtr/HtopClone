//
// Created by pnkjsng on 8/25/24.
//
#include "Log.h"

void log(int logLevel, std::string&& data) {
    std::cout << "[LogLevel=" << logLevel <<"] " << data << "\n";
}
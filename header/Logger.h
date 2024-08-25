//
// Created by pnkjsng on 8/25/24.
//

#ifndef HTOPCLONE_LOG_H
#define HTOPCLONE_LOG_H
#include <iostream>
#include <string>

class Logger {
public:
    static void log(const std::string& message) {
        std::cout << "[" << message << "]\n";
    }
};


#endif //HTOPCLONE_LOG_H
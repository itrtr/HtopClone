//
// Created by pnkjsng on 8/25/24.
//

#ifndef HTOPCLONE_FILEREADERRESPONSE_H
#define HTOPCLONE_FILEREADERRESPONSE_H
#include <string>
#include "Logger.h"
class FileReaderResponse {
public:
    virtual ~FileReaderResponse() = default;
    std::string getFilePath() const { return filePath_; }
    bool isSuccessfulRead() const { return successfulRead_; }

    virtual void print() const {
        std::string successfulRead = successfulRead_ ? "Yes" : "No";
        Logger::log("File Path: " + filePath_);
        Logger::log("Successful Read: " + successfulRead);
    }

protected:
    std::string filePath_;
    bool successfulRead_;
};

#endif //HTOPCLONE_FILEREADERRESPONSE_H

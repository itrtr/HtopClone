//
// Created by pnkjsng on 8/25/24.
//

#ifndef HTOPCLONE_OSFILEREADERRESPONSE_H
#define HTOPCLONE_OSFILEREADERRESPONSE_H
#include "FileReaderResponse.h"
#include <fstream>
#include <iostream>
#include <string>

class OSFileReaderResponse : public FileReaderResponse {
public:
    OSFileReaderResponse() = default;
    OSFileReaderResponse(const std::string &path,
                         bool successfulRead) {
        filePath_ = path;
        successfulRead_ = successfulRead;
    }

    OSFileReaderResponse(const std::string &path,
                         const std::string &name,
                         const std::string &id,
                         const std::string &prettyName,
                         bool successfulRead) : name_(name), id_(id), prettyName_(prettyName) {
        filePath_ = path;
        successfulRead_ = successfulRead;
    }

    std::string getOperatingSystemName() const { return name_; }
    std::string getOperatingSystemId() const { return id_; }
    std::string getOperatingSystemPrettyName() const { return prettyName_; }

    void setOperatingSystemName(const std::string &name) { this->name_ = name; }
    void setOperatingSystemId(const std::string &id) { this->id_ = id; }
    void setOperatingSystemPrettyName(const std::string &prettyName) { this->prettyName_ = prettyName; }

    virtual void print() const override {
        FileReaderResponse::print();
        Logger::log("OS Name: " + getOperatingSystemName());
        Logger::log("OS Id: " + getOperatingSystemId());
        Logger::log("OS Pretty Name: " + getOperatingSystemPrettyName());
    }

private:
    std::string name_;
    std::string id_;
    std::string prettyName_;
};

#endif // HTOPCLONE_OSFILEREADERRESPONSE_H

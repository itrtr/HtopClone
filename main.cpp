//
// Created by pnkjsng on 8/24/24.
//
#include "OSFileReader.h"
#include "Logger.h"
#include "FileReaderResponse.h"
#include "OSFileReaderResponse.h"

int main() {
    OSFileReader osFileReader;
    std::unique_ptr<FileReaderResponse> response = osFileReader.readFile("/etc/os-release");

    if (response) {
        Logger::log("File read successfully");
        // Cast to OSFileReaderResponse to access derived class methods
        auto osResponse = dynamic_cast<OSFileReaderResponse*>(response.get());
        if (osResponse) {
            osResponse->print();
        }
    } else {
        Logger::log("Failed to read file");
    }
    return 0;
}

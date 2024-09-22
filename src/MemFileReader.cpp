#include "MemFileReader.h"
#include "MemFileReaderResponse.h"
#include "Logger.h"

#include <cassert>
#include <fstream>
#include <sstream>


UniqPtr<FileReaderResponse> MemFileReader::readFile(const std::string &path) {
    std::string filePath = path;
    if (filePath.empty()) {
        //Logger::log("No input, default to base location...");
        filePath = DEFAULT_MEMORY_PATH;
    }

    std::ifstream file(filePath);
    bool successfulRead = file.is_open();

    if (successfulRead) {
        auto response = std::make_unique<MemFileReaderResponse>(filePath, successfulRead);
        std::string line;
        
        while(std::getline(file, line)) {
            std::istringstream iss(line);
            std::string key;
            std::string value;
            std::string unit;

            iss >> key >> value >> unit;
            if(key == "MemTotal:") {
                response->setTotalMemory(std::stol(value));
            } else if(key == "MemAvailable:") {
                response->setAvailMemory(std::stol(value));
            } //else if(key == "Buffers:") {
                //response->setBufferMemory(std::stol(value));
            //}

        }
        file.close();
        return response;
    }
    return nullptr;
};

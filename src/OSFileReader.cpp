//
// Created by pnkjsng on 8/25/24.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "OSFileReader.h"

UniqPtr<FileReaderResponse> OSFileReader::readFile(const std::string& path) {
    std::string filePath = path;
    // Check if the file path is empty; if so, use the default OS path
    if (filePath.empty()) {
        filePath = DEFAULT_OS_PATH;
    }

    // Attempt to open the file
    std::ifstream file(filePath);
    bool successfulRead = file.is_open();

    if (successfulRead) {
        auto response = std::make_unique<OSFileReaderResponse>(filePath, successfulRead);
        std::string content;
        std::string line;
        std::unordered_map<std::string, std::string> keyValuePairs;
        // Read the file content line by line
        while (std::getline(file, line)) {
            size_t delimiterPos = line.find('=');
            if (delimiterPos != std::string::npos) {
                std::string key = line.substr(0, delimiterPos);
                std::string value = line.substr(delimiterPos + 1);

                value.erase(std::remove(value.begin(), value.end(), '"'), value.end());

                auto trim = [](std::string &s) {
                    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
                        return !std::isspace(ch);
                    }));
                    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
                        return !std::isspace(ch);
                    }).base(), s.end());
                };
                trim(key);
                trim(value);

                keyValuePairs[key] = value;
            }
        }

        //TODO:: remove this extra looping and put the values in above loop only
        for(const auto& pp : keyValuePairs) {
            // Logger::log(pp.first + "=>" + pp.second);
            if ("NAME" == pp.first) response->setOperatingSystemName(pp.second);
            if ("ID" == pp.first) response->setOperatingSystemId(pp.second);
            if ("PRETTY_NAME" == pp.first) response->setOperatingSystemPrettyName(pp.second);
        }

        file.close();
        return response;
    }

    // Return nullptr if the read was not successful
    return nullptr;
}
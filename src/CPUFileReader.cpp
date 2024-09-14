#include "CPUFileReader.h"
#include "CPUFileReaderResponse.h"
#include "Logger.h"

#include <algorithm>
#include <cassert>
#include <fstream>
#include <sstream>
#include <vector>

/*
    /proc/stat contains a row for CPU which represents the result for all the CPU cores
    Format: cpu  149764 5756 49572 194593655 27993 0 4172 0 0 0
    1st entry - Time spent in user mode (non-nice)
    2nd entry - Time spent on nice priority processes
    3rd entry - Time spent on kernal mode
    4th entry - Idle time spent by the CPU (all cores) not executing any process
    5th entry - Idle (IOWait) but while waiting I/O bound tasks
    6th entry - Time spent on sevicing hardware interrupts
    7th entry - Time spend on servicing software interrupts
    other entries are not relevant for now since mostly related to virtual env

    for the time being we will use formular:
    % cpu utilization = 100 * (total_time - idle_time) / total_time
*/
UniqPtr<FileReaderResponse> CPUFileReader::readFile(const std::string &path) {
    std::string filePath = path;
    if (filePath.empty()) {
        // Logger::log("No input, default to base location...");
        filePath = DEFAULT_CPU_PATH;
    }

    std::ifstream file(filePath);
    bool successfulRead = file.is_open();

    if (successfulRead) {
        auto response = std::make_unique<CPUFileReaderResponse>(filePath, successfulRead);
        std::string line;
        std::vector<std::string> tokens;
        while (std::getline(file, line)) {
            // we cannot directly grep on "cpu" term since it also have data for individual CPU cores
            // like "cpu", "cpu0", "cpu1" similar, but first one represents the whole cpu
            if (line.find("cpu ") != std::string::npos) {
                std::istringstream iss(line);
                std::string token;
                while (iss >> token)
                    tokens.emplace_back(token);

                assert(tokens.size() >= 8);
                response->setUserTime(std::stod(tokens[1]));
                response->setUserNiceTime(std::stod(tokens[2]));
                response->setKernelTime(std::stod(tokens[3]));
                response->setIdleCPUTime(std::stod(tokens[4]));
                response->setIdleIOTime(std::stod(tokens[5]));
                response->setHardwareInterruptTime(std::stod(tokens[6]));
                response->setSoftwareInterruptTime(std::stod(tokens[7]));
            }
        }

        file.close();
        return response;
    }

    return nullptr;
}
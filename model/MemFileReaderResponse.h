#include "FileReaderResponse.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

class MemFileReaderResponse : public FileReaderResponse {
public:
    MemFileReaderResponse() = default;
    MemFileReaderResponse(const std::string& path,
                             bool successfulRead) {
        filePath_ = path;
        successfulRead_ = successfulRead;
    }

    void setTotalMemory(const long inputTotalMemory) { this->totalMemory_ = inputTotalMemory; }
    void setAvailMemory(const long inputAvailMemory) { this->availMemory_ = inputAvailMemory; }
    //void setBufferMemory(const long inputBufferMemory) { this->buffers_ = inputBufferMemory; }

    virtual void print() const override {
        FileReaderResponse::print();
        double totalMemory = static_cast<double>(totalMemory_) / (1024.0 * 1024.0);
        double usedMemory = static_cast<double>(totalMemory_ - availMemory_) / (1024.0 * 1024.0);
        long  usedMemoryKB = totalMemory_ - availMemory_;
        long double memoryUtilization = static_cast<long double>(usedMemoryKB) / (long double)totalMemory_;

        //Logger::log("Total Memory (kB): " + std::to_string(totalMemory_));
        //Logger::log("Available Memory (kB): " + std::to_string(availMemory_));
        // Logger::log("Buffers (kB): " + std::to_string(buffers_));

        Logger::log("Total Memory: " + castToString(totalMemory, 1) + " GB");
        Logger::log("Memory in Use:" + castToString(usedMemory, 1) + " GB " + "(" + castToString(memoryUtilization * 100, 2) + "%)");
    }
private:
    std::string castToString(const long double value, const int precisionCount) const {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(precisionCount) << value;
        return stream.str();
    }
private:
    long totalMemory_ = 0L;
    long availMemory_ = 0L;
    //long buffers_  = 0L;
    //long cached_   = 0L;
};

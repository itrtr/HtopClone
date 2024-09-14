#include "FileReaderResponse.h"
#include <iomanip>
#include <sstream>
#include <string>

class CPUFileReaderResponse : public FileReaderResponse {
public:
    CPUFileReaderResponse() = default;
    CPUFileReaderResponse(const std::string &path,
                          bool successfulRead) {
        filePath_ = path;
        successfulRead_ = successfulRead;
    }

    void setUserTime(const double inputUserTime) { this->userTime_ = inputUserTime; }
    void setUserNiceTime(const double inputUserNiceTime) { this->userNiceTime_ = inputUserNiceTime; }
    void setKernelTime(const double inputKernelTime) { this->kernerTime_ = inputKernelTime; }
    void setIdleCPUTime(const double inputIdleCPUTime) { this->idleCPUTime_ = inputIdleCPUTime; }
    void setIdleIOTime(const double inputIdleIOTime) { this->idleIOTime_ = inputIdleIOTime; }
    void setHardwareInterruptTime(const double inputHWInterruptTime) { this->hwInterrputTime_ = inputHWInterruptTime; }
    void setSoftwareInterruptTime(const double inputSWInterruptTime) { this->swInterrputTime_ = inputSWInterruptTime; }

    virtual void print() const override {
        FileReaderResponse::print();
        double totalTime = userTime_ + userNiceTime_ + kernerTime_ + idleCPUTime_ + idleIOTime_ + hwInterrputTime_ + swInterrputTime_;
        double totalWaitTime = idleCPUTime_ + idleIOTime_;
        double cpuUtilization = (totalTime - totalWaitTime) / totalWaitTime;

        // Logger::log("Total Time: " + std::to_string(totalTime));
        // Logger::log("Total Wait Time: " + std::to_string(totalWaitTime));
        // Logger::log("CPU Utilization: " + std::to_string(cpuUtilization));

        Logger::log("Overall CPU Utilization: " + castToString(cpuUtilization * 100, 4) + "%");
    }

private:
    std::string castToString(const double value, const int precisionCount) const {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(precisionCount) << value;
        return stream.str();
    }

private:
    double userTime_ = 0L;
    double userNiceTime_ = 0L;
    double kernerTime_ = 0L;
    double idleCPUTime_ = 0L;     // cpu-idle time
    double idleIOTime_ = 0L;      // io wait time
    double hwInterrputTime_ = 0L; // hw interrput time
    double swInterrputTime_ = 0L; // sw interrupt time
};
//
// Created by pnkjsng on 8/24/24.
// main.cpp - The main file which triggers the whole process
#include "CPUFileReader.h"
#include "CPUFileReaderResponse.h"
#include "FileReaderResponse.h"
#include "Logger.h"
#include "OSFileReader.h"
#include "OSFileReaderResponse.h"


void printOSInfo();
void printCPUInfo();

int main() {
    printOSInfo();
    printCPUInfo();
    return 0;
}

void printCPUInfo() {
    Logger::log("-------------------------------------");
    CPUFileReader cpuFileReader;
    std::unique_ptr<FileReaderResponse> cpuResponse = cpuFileReader.readFile("");
    if (cpuResponse) {
        cpuResponse->print();
    } else {
        Logger::log("Failed to read OS file");
    }
}

void printOSInfo() {
    Logger::log("-------------------------------------");
    OSFileReader osFileReader;
    std::unique_ptr<FileReaderResponse> osResponse = osFileReader.readFile("");

    if (osResponse) {
        osResponse->print();
    } else {
        Logger::log("Failed to read OS file");
    }
}

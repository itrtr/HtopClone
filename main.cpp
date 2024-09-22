//
// Created by pnkjsng on 8/24/24.
// main.cpp - The main file which triggers the whole process
#include "CPUFileReader.h"
#include "CPUFileReaderResponse.h"
#include "FileReaderResponse.h"
#include "Logger.h"
#include "OSFileReader.h"
#include "OSFileReaderResponse.h"
#include "MemFileReader.h"
#include "MemFileReaderResponse.h"


void printOSInfo();
void printCPUInfo();
void printMemoryInfo();

int main() {
    printOSInfo();
    printCPUInfo();
    printMemoryInfo();
    return 0;
}
void printMemoryInfo() {
    Logger::log("-------------------------------------");
    MemFileReader memFileReader;
    std::unique_ptr<FileReaderResponse> memResponse = memFileReader.readFile("");
    if(memResponse) {
        memResponse->print();
    } else {
        Logger::log("Failed to read Memory file");
    }
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

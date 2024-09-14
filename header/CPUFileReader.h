//
// Created by pnkjsng on 9/14/24.
// Concrete implementation of CPU file reader
//

#ifndef HTOPCLONE_CPUFILEREADER_H
#define HTOPCLONE_CPUFILEREADER_H

#include "FileReader.h"

#include <memory>

template <typename T>
using UniqPtr = std::unique_ptr<T>;

class CPUFileReader : public FileReader {
public:
    UniqPtr<FileReaderResponse> readFile(const std::string &filePath) override;

private:
    const std::string DEFAULT_CPU_PATH = "/proc/stat";
};

#endif // HTOPCLONE_CPUFILEREADER_H
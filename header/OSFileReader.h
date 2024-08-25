//
// Created by pnkjsng on 8/25/24.
// Concrete implementation of OS file reader
//

#ifndef HTOPCLONE_OSFILEREADER_H
#define HTOPCLONE_OSFILEREADER_H

#include "FileReader.h"
#include "FileReaderResponse.h"
#include "OSFileReaderResponse.h"
#include "Logger.h"

#include <fstream>
#include <memory>

template<typename T>
using UniqPtr = std::unique_ptr<T>;

class OSFileReader: public FileReader {
public:
    UniqPtr<FileReaderResponse> readFile(const std::string& filePath) override;
private:
    const std::string DEFAULT_OS_PATH = "/etc/os-release";
};


#endif //HTOPCLONE_OSFILEREADER_H

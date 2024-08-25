//
// Created by pnkjsng on 8/25/24.
//

#ifndef HTOPCLONE_FILEREADER_H
#define HTOPCLONE_FILEREADER_H
#include <memory>
#include "FileReaderResponse.h"

template<typename T>
using UniqPtr = std::unique_ptr<T>;

class FileReader {
public:
    virtual UniqPtr<FileReaderResponse> readFile(const std::string& filePath) = 0;
    virtual ~FileReader() = default;
};

#endif //HTOPCLONE_FILEREADER_H

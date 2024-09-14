//
// Created by pnkjsng on 8/25/24.
// FileReader.h - Abstract class for reader classes

#ifndef HTOPCLONE_FILEREADER_H
#define HTOPCLONE_FILEREADER_H
#include "FileReaderResponse.h"
#include <memory>

template <typename T>
using UniqPtr = std::unique_ptr<T>;

class FileReader {
public:
    virtual UniqPtr<FileReaderResponse> readFile(const std::string &filePath) = 0;
    virtual ~FileReader() = default;
};

#endif // HTOPCLONE_FILEREADER_H

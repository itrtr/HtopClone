#ifndef HTOPCLONE_MEMFILEREADER_H
#define HTOPCLONE_MEMFILEREADER_H

#include "FileReader.h"

#include <memory>

template <typename T>
using UniqPtr = std::unique_ptr<T>;

class MemFileReader : public FileReader {
public:
    UniqPtr<FileReaderResponse> readFile(const std::string &filePath) override;

private:
    const std::string DEFAULT_MEMORY_PATH = "/proc/meminfo";
};

#endif // HTOPCLONE_MEMFILEREADER_H
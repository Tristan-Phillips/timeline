#pragma once

#include <string>
#include <unordered_map>
#include "read.h"
#include "write.h"

class Localization {
public:
    Localization(Read* reader, Write* writer, const std::string& filePath);
    std::string getString(const std::string& key) const;
    void setString(const std::string& key, const std::string& value);

private:
    std::unordered_map<std::string, std::string> m_translations;
    Read* m_reader;
    Write* m_writer;
    std::string m_filePath;

    void load();
    void save() const;
};
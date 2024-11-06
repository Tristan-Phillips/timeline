#include "localization.h"

Localization::Localization(Read* reader, Write* writer, const std::string& filePath)
    : m_reader(reader), m_writer(writer), m_filePath(filePath) {
    load();
}

void Localization::load() {
    m_translations = m_reader->readFile(m_filePath);
}

void Localization::save() const {
    m_writer->writeFile(m_filePath, m_translations);
}

std::string Localization::getString(const std::string& key) const {
    auto it = m_translations.find(key);
    if (it != m_translations.end()) {
        return it->second;
    }
    return ""; // return an empty string if the key is not found
}

void Localization::setString(const std::string& key, const std::string& value) {
    m_translations[key] = value;
    save(); // Automatically save changes
}
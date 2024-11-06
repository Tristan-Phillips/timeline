#ifndef WRITE_JSON_H
#define WRITE_JSON_H

#include "write.h"
#include <unordered_map>
#include <string>

class WriteJSON : public Write {
public:
    void writeFile(const std::string& filePath, const std::unordered_map<std::string, std::string>& data) const override;
};

#endif // WRITE_JSON_H
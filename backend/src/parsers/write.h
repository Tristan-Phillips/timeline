#ifndef WRITE_H
#define WRITE_H

#include <string>
#include <unordered_map>

class Write {
public:
    virtual ~Write() = default;
    virtual void writeFile(const std::string& filePath, const std::unordered_map<std::string, std::string>& data) const = 0;
};

#endif // WRITE_H
#pragma once

#include <string>
#include <vector>

class UserConnections {
public:
    virtual ~UserConnections() = default;

    void addConnection(const std::string& userId) = 0;
    void removeConnection(const std::string& userId) = 0;
};
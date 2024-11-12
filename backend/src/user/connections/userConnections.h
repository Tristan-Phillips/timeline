#pragma once

#include <string>
#include <vector>

class UserConnections {
public:
    virtual ~UserConnections() = default;
    virtual void addConnection(const std::string& userId) = 0;
    virtual void removeConnection(const std::string& userId) = 0;
};
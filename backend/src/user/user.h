#pragma once

#include <string>
#include "userInfo.h"
// Metadata ?
#include "userConnections.h"
#include "logger.h"

class User {
public:
    User(std::string username); // What arguments should I pass ?

    // User information
    UserInfo& getUserInfo();

protected:
    // Member variables
    UserInfo m_userInfo;
    std::vector<UserConnections*> m_connections;
};
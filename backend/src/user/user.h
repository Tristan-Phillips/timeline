#pragma once

#include <string>
#include "userInfo.h"
// Metadata ?
#include "userConnections.h"
#include "logger.h"

enum class UserType {
    ADMIN,
    MODERATOR,
    USER
};

class User {
public:
    User(UserType userType); // What should I pass ?

    // User information
    UserInfo& getUserInfo();

protected:
    // Member variables
    UserInfo m_userInfo;
    std::vector<UserConnections*> m_connections;
    UserType m_userType;
};
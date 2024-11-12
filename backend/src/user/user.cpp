#include "user.h"

User::User(std::string username) {
    m_userInfo.setUsername(username);
}

UserInfo& User::getUserInfo() {
    return m_userInfo;
}
#include "user.h"

User::User(UserType userType) : m_userType(userType) {
}

UserInfo& User::getUserInfo() {
    return m_userInfo;
}
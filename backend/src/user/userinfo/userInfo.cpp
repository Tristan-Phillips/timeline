#include "userInfo.h"

UserInfo::UserInfo() {
}

void UserInfo::setUsername(const std::string& username) {
    m_username = username;
}

void UserInfo::setPassword(const std::string& password) {
    m_password = password;
}

void UserInfo::setEmail(const std::string& email) {
    m_email = email;
}

std::string UserInfo::getUserId() const {
    return m_userId;
}

std::string UserInfo::getUsername() const {
    return m_username;
}

std::string UserInfo::getEmail() const {
    return m_email;
}

void UserInfo::setUserId() {
    m_userId = "12345"; // Generate a unique user ID
}
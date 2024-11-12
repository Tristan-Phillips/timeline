#pragma once

#include <string>

class UserInfo {
public:
    UserInfo();
    ~UserInfo() = default;

    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void setEmail(const std::string& email);

    std::string getUserId() const;
    std::string getUsername() const;
    std::string getEmail() const;

private:
    void setUserId();

    std::string m_userId;
    std::string m_username;
    std::string m_password;
    std::string m_email;
};
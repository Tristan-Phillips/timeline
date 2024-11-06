#ifndef SMTP_H
#define SMTP_H

#include <string>
#include <iostream>
#include <unordered_map>

class SMTP {
public:
    SMTP(std::unordered_map<std::string, std::string> env) : m_env(env) {}
    void sendEmail(const std::string& recipient, const std::string& subject, const std::string& body);
private:
    std::unordered_map<std::string, std::string> m_env;
    std::string Base64Encode(const std::string &input);
};

#endif // SMTP_H
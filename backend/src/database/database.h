#pragma once

#include <string>

class Database {
public:
    virtual ~Database() = default;
    virtual bool connect() = 0;
    virtual void disconnect() = 0;
    virtual bool executeQuery(const std::string& query) = 0;

    const std::string& getUsername() const { return m_username; }
    const std::string& getPassword() const { return m_password; }
    const std::string& getHost() const { return m_host; }
    const std::string& getPort() const { return m_port; }
    const std::string& getDatabaseName() const { return m_databaseName; }
    
protected:
    Database(const std::string& username, const std::string& password, const std::string& host, const std::string& port, const std::string& databaseName)
    : m_username(username), m_password(password), m_host(host), m_port(port), m_databaseName(databaseName) {}

private:
    std::string m_username;
    std::string m_password;
    std::string m_host;
    std::string m_port;
    std::string m_databaseName;
};
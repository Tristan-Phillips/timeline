#pragma once

#include <string>
#include "user.h"
#include "timeline.h"

enum class QueryType {
    SELECT,
    INSERT,
    UPDATE,
    DELETE
};

enum class UserQueryType {
    CREATE_USER,
    DELETE_USER,
    UPDATE_USER,
    SELECT_USER
};

enum class TimelineQueryType {
    CREATE_TIMELINE,
    DELETE_TIMELINE,
    UPDATE_TIMELINE,
    SELECT_TIMELINE
};

class Database {
public:
    virtual ~Database() = default;
    virtual bool connect() = 0;
    virtual void disconnect() = 0;
    
    const std::string& getUsername() const { return m_username; }
    const std::string& getPassword() const { return m_password; }
    const std::string& getHost() const { return m_host; }
    const std::string& getPort() const { return m_port; }
    const std::string& getDatabaseName() const { return m_databaseName; }

protected:
    Database(const std::string& username, const std::string& password, const std::string& host, const std::string& port, const std::string& databaseName)
    : m_username(username), m_password(password), m_host(host), m_port(port), m_databaseName(databaseName) {}

    bool executeQuery(QueryType queryType, const std::string& query);
    bool userQuery(UserQueryType queryType, const User& user);
    bool timelineQuery(TimelineQueryType queryType, const Timeline& timeline, const User& user);

private:
    std::string m_username;
    std::string m_password;
    std::string m_host;
    std::string m_port;
    std::string m_databaseName;
};
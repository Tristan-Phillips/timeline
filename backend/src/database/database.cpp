#include "database.h"

bool Database::executeQuery(QueryType queryType, const std::string& query) {
    // Not implemented
    return true;
}


// Checking and Sanitizing should still be done as well as error handling ( and dynamic table and column names ? )

bool Database::userQuery(UserQueryType queryType, const User& user) {
    switch(queryType) {
        case UserQueryType::CREATE_USER:
            return executeQuery(QueryType::INSERT, "INSERT INTO users (user_id, username, password, email) VALUES ('" + user.getUserInfo().getUserId() + "', '" + user.getUserInfo().getUsername() + "', '" + user.getUserInfo().getPassword() + "', '" + user.getUserInfo().getEmail() + "')");
        case UserQueryType::DELETE_USER:
            return executeQuery(QueryType::DELETE, "DELETE FROM users WHERE user_id = '" + user.getUserInfo().getUserId() + "'");
        case UserQueryType::UPDATE_USER:
            return executeQuery(QueryType::UPDATE, "UPDATE users SET username = '" + user.getUserInfo().getUsername() + "', password = '" + user.getUserInfo().getPassword() + "', email = '" + user.getUserInfo().getEmail() + "' WHERE user_id = '" + user.getUserInfo().getUserId() + "'");
        case UserQueryType::SELECT_USER:
            return executeQuery(QueryType::SELECT, "SELECT * FROM users WHERE user_id = '" + user.getUserInfo().getUserId() + "'");
    }
    return false;
}

bool Database::timelineQuery(TimelineQueryType queryType, const Timeline& timeline, const User& user) {
    // switch(queryType) {
    //     case TimelineQueryType::CREATE_TIMELINE:
    //         return executeQuery(QueryType::INSERT, "INSERT INTO timelines (timeline_id, user_id, title, description) VALUES ('" + timeline.getTimelineId() + "', '" + user.getUserInfo().getUserId() + "', '" + timeline.getTitle() + "', '" + timeline.getDescription() + "')");
    //     case TimelineQueryType::DELETE_TIMELINE:
    //         return executeQuery(QueryType::DELETE, "DELETE FROM timelines WHERE timeline_id = '" + timeline.getTimelineId() + "'");
    //     case TimelineQueryType::UPDATE_TIMELINE:
    //         return executeQuery(QueryType::UPDATE, "UPDATE timelines SET title = '" + timeline.getTitle() + "', description = '" + timeline.getDescription() + "' WHERE timeline_id = '" + timeline.getTimelineId() + "'");
    //     case TimelineQueryType::SELECT_TIMELINE:
    //         return executeQuery(QueryType::SELECT, "SELECT * FROM timelines WHERE timeline_id = '" + timeline.getTimelineId() + "'");
    // }
    return false;
}
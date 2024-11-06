#ifndef USER_H
#define USER_H

#include <string>
#include "userinfo/userInfo.h"
#include "connections/friends/friends.h"
#include "connections/followers/followers.h"
#include "connections/following/following.h"
#include "connections/blocked/blocked.h"
#include "connections/teams/teams.h"
#include "connections/collaborators/collaborators.h"

class User {
public:
    virtual ~User() = default;
    // User information
    UserInfo& getUserInfo();
    // Access connections
    // Friends& getFriends();
    // Followers& getFollowers();
    // Following& getFollowing();
    // Blocked& getBlockedUsers();
    // Teams& getTeams();
    // Collaborators& getCollaborators();

protected:
    // Member variables
    UserInfo m_userInfo;
    // Friends m_friends;
    // Followers m_followers;
    // Following m_following;
    // Blocked m_blockedUsers;
    // Teams m_teams;
    // Collaborators m_collaborators;
};

#endif // USER_H
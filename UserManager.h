// UserManager.h
#pragma once
#include <string>

class User {
public:
    virtual ~User() {}

    const std::string& getUsername() const { return username; }
    const std::string& getPassword() const { return password; }

protected:
    User(const std::string& username, const std::string& password)
        : username(username), password(password) {}

private:
    std::string username;
    std::string password;
};

class Administrator : public User {
public:
    Administrator(const std::string& username, const std::string& password)
        : User(username, password) {}
};

class Operator : public User {
public:
    Operator(const std::string& username, const std::string& password)
        : User(username, password) {}
};

class UserManager {
public:
    // Metodele necesare pentru gestionarea autentificarii utilizatorilor
    bool createUser(const std::string& username, const std::string& password, const std::string& userType);
    User* authenticateUser(const std::string& username, const std::string& password);
    bool keepMeLoggedIn(const std::string& username);
};

// StockManagerApp.h
#pragma once
#include "DatabaseManager.h"
#include "SocketManager.h"
#include "UserManager.h"

class StockManagerApp {
public:
    StockManagerApp();
    ~StockManagerApp();

    void run();

private:
    DatabaseManager dbManager;
    SocketManager socketManager;
    UserManager userManager;

    User* currentUser;

    void showLoginScreen();
    void showCreateUserScreen();
    void showMainScreen();
};

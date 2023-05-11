// StockManagerApp.cpp
#include "StockManagerApp.h"
#include <iostream>

StockManagerApp::StockManagerApp()
    : dbManager(), socketManager(), userManager(), currentUser(nullptr) {
}

StockManagerApp::~StockManagerApp() {
    if (currentUser != nullptr) {
        delete currentUser;
    }
}

void StockManagerApp::run() {
    // Aici puteti adauga logica pentru initializarea conexiunii la baza de date
    // si a conexiunii server-socket, daca este necesar.

    // Afiseaza ecranul de login
    showLoginScreen();
}

void StockManagerApp::showLoginScreen() {
    std::string username, password;

    std::cout << "Login Screen\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    currentUser = userManager.authenticateUser(username, password);
    if (currentUser != nullptr) {
        showMainScreen();
    }
    else {
        std::cout << "Authentication failed. Try again.\n";
        showLoginScreen();
    }
}

void StockManagerApp::showCreateUserScreen() {
    std::string username, password, userType;

    std::cout << "Create User Screen\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    std::cout << "User Type (Administrator/Operator): ";
    std::cin >> userType;

    if (userManager.createUser(username, password, userType)) {
        std::cout << "User created successfully.\n";
    }
    else {
        std::cout << "User creation failed.\n";
    }
}

void StockManagerApp::showMainScreen() {
    std::cout << "Main Screen\n";
    // Aici puteti afisa meniul principal si implementa logica pentru diferitele
    // functionalitati ale aplicatiei, in functie de rolul utilizatorului curent.
}

#include "declarations.h"

void printWelcomeText() {
    cout 
        << "\tStore your passwords safely with"
        << makeAnsii(CYAN_FG, NOSTYLE) << " (LEV)\n" << RESET
        << "\tRun" << makeAnsii(CYAN_FG, NOSTYLE) << " \"lev init\"" << RESET << " to set up you profile\n"
    ;
}

void printStartText() {
    cout 
        << "\tStore your passwords safely with"
        << makeAnsii(CYAN_FG, NOSTYLE) << " (LEV)\n" << RESET
        << "\tRun" << makeAnsii(CYAN_FG, NOSTYLE) << " \"lev help\"" << RESET << " to get started\n"
    ;
}

string makeAnsii(int fg, int style) {
    return "\033[" +  to_string(style) + ";" + to_string(fg) + "m";
}

bool isLevCommand(string command, array<string, 10> arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (command == arr.at(i)) 
            return true;
    }

    return false;
}

void printInvalidCommand() {
    cout 
        << makeAnsii(RED_FG, BOLD) 
        << "\tInvalid " << RESET
        << "lev command"
        << "\n\tRun" << makeAnsii(CYAN_FG, NOSTYLE) << " \"lev help\"" << RESET << " to get help\n"
    ;
}

void printMustInit() {
    cout 
        << "\tThis is your first time using " << makeAnsii(CYAN_FG, NOSTYLE) << "(LEV)\n" << RESET
        << "\tRun" << makeAnsii(CYAN_FG, NOSTYLE) << " \"lev init\"" << RESET << " to get started\n"
    ;
}

int initUser(string* master_password, int* session_duration) {
    cout << makeAnsii(CYAN_FG, NOSTYLE) << "\tMaster Password: " << RESET << "\033[" << 32 << "G";
    getline(cin, *master_password);

    cout << makeAnsii(CYAN_FG, NOSTYLE) << "\tSession duration (in minutes):" << RESET << "\033[" << 32 << "G";
    cin >> *session_duration;

    if (cin.fail())
        return 1;

    return 0;
}

void printInvalidInput() {
    cout 
        << makeAnsii(RED_FG, BOLD) 
        << "\tInvalid " << RESET
        << "Input"
        << "\n\tRun" << makeAnsii(CYAN_FG, NOSTYLE) << " \"lev help\"" << RESET << " to get help\n"
    ;
}

void printConfigIsFull() {
    cout 
        << "\tUser is already set up"
        << "\n\tRun" << makeAnsii(CYAN_FG, NOSTYLE) << " \"lev master\"" << RESET << " to change the master password"
        << "\n\tRun" << makeAnsii(CYAN_FG, NOSTYLE) << " \"lev time\"" << RESET << " to change the session time\n"
    ;
}
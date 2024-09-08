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

void printHelp() {
    cout << "\tUsage: lev " << makeAnsii(CYAN_FG, NOSTYLE) << "<command> " << RESET << "\n\n";
    cout << "\t" << makeAnsii(CYAN_FG, NOSTYLE) << "<commands>\n" << RESET;
    cout << "\t    help: Get help for ""commands\n";
    cout << "\t        Usage: lev help  \n\n";
    cout << "\t    init: Initialize your lev Account\n";
    cout << "\t        Usage: lev init\n";
    cout << "\t        Prompts: \n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<master password> " << RESET << "- Your master password\n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<session duration> " << RESET << "- The duration in minutes of a session\n\n";
    cout << "\t    master: Change the master password\n";
    cout << "\t        Usage: lev set \n";
    cout << "\t        Prompts: \n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<old master password> " << RESET << "- The current master password\n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<new master password> " << RESET << "- The new master password\n\n";
    cout << "\t    time: Change the session duration\n";
    cout << "\t        Usage: lev time \n";
    cout << "\t        Prompts: \n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<duration in mins> " << RESET << "- New session duration in minutes\n\n";
    cout << "\t    list: List all entries\n";
    cout << "\t        Usage: lev list\n";
    cout << "\t        Description: Displays all stored password entries\n\n";
    cout << "\t    add: Add a new entry\n";
    cout << "\t        Usage: lev add \n";
    cout << "\t        Prompts: \n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<name> " << RESET << "- The name of the entry \n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<url> " << RESET << "- The URL associated with the entry \n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<password> " << RESET << "- The password for the entry\n\n";
    cout << "\t    remove: Remove an existing entry\n";
    cout << "\t        Usage: lev remove \n";
    cout << "\t        Prompts: \n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<name> " << RESET << "- The name of the entry to remove\n\n";
    cout << "\t    search: Search entries containing a query using fuzzy search\n";
    cout << "\t        Usage: lev search \n";
    cout << "\t        Prompts: \n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<query> " << RESET << "- The search query to find entries\n\n";
    cout << "\t    edit: Edit an existing entry\n";
    cout << "\t        Usage: lev edit \n";
    cout << "\t        Prompts: \n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<name> " << RESET << "- The current name of the entry\n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<newname> " << RESET << "- The new name for the entry\n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<newurl> " << RESET << "- The new URL for the entry\n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<newpassword> " << RESET << "- The new password for the entry\n\n";
    cout << "\t    copy: Copy the password of an entry to clipboard\n";
    cout << "\t        Usage: lev copy \n";
    cout << "\t        Prompts: \n";
    cout << "\t             " << makeAnsii(CYAN_FG, NOSTYLE) << "<name> " << RESET << "- The name of the entry whose password will be copied\n\n";
    cout << "\t    gen: Generate a secure password and copy it to the clipboard\n";
    cout << "\t        Usage: lev gen\n";
}
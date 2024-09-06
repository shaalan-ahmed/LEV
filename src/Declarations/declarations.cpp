#include "declarations.h"

void printWelcomeText() {
    cout 
        << "\tStore your passwords safely with"
        << makeAnsii(CYAN_FG, NOSTYLE) << " (LEV)\n" << RESET
        << "\tRun" << makeAnsii(CYAN_FG, NOSTYLE) << " \"lev init\"" << RESET << " to get started\n"
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
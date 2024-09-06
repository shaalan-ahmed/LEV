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
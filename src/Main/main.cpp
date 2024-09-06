#include "../Declarations/declarations.h"

string arguments[] = {
    "init", 
    "help",
    "add",
    "remove",
    "list",
    "copy",
    "gen",
    "search",
    "edit",
    "send"
};

int main (int argc, char *argv[]) {
    if (argc == 1) {
        printWelcomeText();
    }   
    
    return 0;
}

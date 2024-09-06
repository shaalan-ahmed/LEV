#include "../Declarations/declarations.h"

array<string, LEN> lev_commands = {
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

        return 0;
    }   

    string cmd = argv[1];

    if (! isLevCommand(cmd, lev_commands)) {
        printInvalidCommand();

        return 1;
    }
    
    return 0;
}

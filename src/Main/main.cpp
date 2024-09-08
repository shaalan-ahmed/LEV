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

filesystem::path home_dir = filesystem::path(getenv("HOME"));
filesystem::path hidden_dir = home_dir / ".lev";
filesystem::path config_file = hidden_dir / ".config.lev";

bool must_init = false;

string master_password = "";
int session_duration = 0;

ofstream file;

int main (int argc, char *argv[]) {
    if (! filesystem::exists(hidden_dir)) {
        filesystem::create_directory(hidden_dir);

        must_init = true;
    }

    file.open(config_file, ios::app);

    if (filesystem::is_empty(config_file))
        must_init = true;

    if (argc == 1) {
        if (must_init)
            printWelcomeText();
        else
            printStartText();

        return 0;
    }   

    string cmd = argv[1];

    if (! isLevCommand(cmd, lev_commands)) {
        printInvalidCommand();

        return 1;
    }

    if (cmd == "init") {
        if (! filesystem::is_empty(config_file)) {
            printConfigIsFull();

            return 1;
        }

        if (initUser(&master_password, &session_duration) == 1) {
            printInvalidInput();

            master_password = "";
            session_duration = 0;

            return 1;
        }

        file << master_password << endl;
        file << session_duration << endl;

        file.close();

        return 0;
    }

    if (cmd == "help") {
        printHelp();

        return 0;
    }

    if (must_init) {
        printMustInit();

        return 0;
    }
    
    return 0;
}
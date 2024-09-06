#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <array>

using namespace std;

#define RESET "\033[0m"
#define RED_FG 31
#define GREEN_FG 32
#define YELLOW_FG 33
#define BLUE_FG 34
#define MAGENTA_FG 35
#define CYAN_FG 36
#define WHITE_FG 37
#define BOLD 1
#define UNDERLINE 4
#define NOSTYLE 0

#define LEN 10

void printWelcomeText();
void printInvalidCommand();

string makeAnsii(int fg, int style);

bool isLevCommand(string command, array<string, 10> arr);
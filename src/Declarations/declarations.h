#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <filesystem>
#include <fstream>

using namespace std;

#define RESET "\033[0m"
#define RED_FG 31
#define GREEN_FG 32
#define YELLOW_FG 33
#define BLUE_FG 34
#define MAGENTA_FG 35
#define CYAN_FG 36
#define WHITE_FG 37
#define BOLD 1/home/ahmed/Desktop/C++/High_Level_Utilities/src/Declarations/declarations.cpp /home/ahmed/Desktop/C++/High_Level_Utilities/src/Declarations/declarations.h
#define UNDERLINE 4
#define NOSTYLE 0

#define LEN 10

void printWelcomeText();
void printStartText();
void printInvalidCommand();
void printMustInit();
void printInvalidInput();
void printConfigIsFull();
void printHelp();

int initUser(string* master_password, int* session_duration);

string makeAnsii(int fg, int style);

bool isLevCommand(string command, array<string, 10> arr);
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

#define ARENA_SIZE 8

using namespace std;

struct defoltTurn {
    size_t iStart;
    size_t iEnd;
    size_t jStart;
    size_t jEnd;
    char figureType = ' ';
    char turnType = ' ';
};

struct turn {
    defoltTurn wTurn;
    defoltTurn bTurn;
};

const char figureType[] = {'K', 'k', 'Q', 'q', 'R', 'N', 'n', 'B', 'b', '\0'};

void print_arena(char (*arena)[ARENA_SIZE]);
turn parser(string str);
char* parseWhiteTurn(char* cursor, turn& turn);
char* parseBlackTurn(char* cursor, turn& turn);
char* parseStart(char* cursor, defoltTurn& turn);
char* parseEnd(char* cursor, defoltTurn& turn);
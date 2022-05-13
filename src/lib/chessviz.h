#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <gtest.h>

#define ARENA_SIZE 8

using namespace std;

struct partturn {
    int i;
    int j;
};

struct defaultTurn {
    partturn start;
    partturn end;
    partturn startKingPos;
    char figureType = ' ';
    char turnType = ' ';
    char turnOutcome = ' ';
};

struct turn {
    defaultTurn wTurn;
    defaultTurn bTurn;

    turn()
    {
        wTurn.startKingPos.i = 0;
        wTurn.startKingPos.j = 4;

        bTurn.startKingPos.i = 7;
        bTurn.startKingPos.j = 4;
    }
};

const char figureType[] = {'K', 'Q', 'R', 'N', 'B', 'P', '\0'};

//parser functions

int parser(string stroke, turn& turn);
char* parseFullTurn(char* cursor, defaultTurn& turn);
char* parsePartTurn(char* cursor, partturn& turn);
bool checkCoordinateX(char* cursor, int& j);
bool checkCoordinateY(char* cursor, int& _i);
char* parseFigureType(char* cursor, defaultTurn& turn);
char* parseTurnType(char* cursor, defaultTurn& turn);
char* parseTurnOutcome(char* cursor, defaultTurn& turn);
char* parseCastling(char* cursor, defaultTurn& turn);
bool checkCoordinatesCastling(defaultTurn& turn, const int range);
char* skipSpace(char* cursor);

//chessviz functions

void print_arena(char arena[ARENA_SIZE][ARENA_SIZE]);
int do_turn(defaultTurn turn, char (*arena)[ARENA_SIZE]);
bool check_corr_figureType(defaultTurn turn, char arena[ARENA_SIZE][ARENA_SIZE]);
bool check_corr_turnType(defaultTurn turn, char arena[ARENA_SIZE][ARENA_SIZE]);
bool check_corr_turnLength(defaultTurn turn);
bool check_corr(defaultTurn turn, char arena[ARENA_SIZE][ARENA_SIZE]);
bool check_corr_border(defaultTurn turn);
int make_a_turn(turn turn, char (*arena)[ARENA_SIZE], int num__line);
bool check_winner(defaultTurn turn);
bool check_obstruction_castl(const defaultTurn turn, const char arena[ARENA_SIZE][ARENA_SIZE]);
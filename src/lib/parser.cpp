#include "chessviz.h"

turn parser(string stroke)
{
    turn turn;
    char* str = new char[stroke.length() + 1];
    char* cursor = str;
    str = strcpy(str, stroke.c_str());

    while (*cursor == ' ') {
        cursor++;
    }

    cursor += 2;

    while (*cursor == ' ') {
        cursor++;
    }

    cursor = parseWhiteTurn(cursor, turn);
    cursor = parseBlackTurn(cursor, turn);

    return turn;
}

char* parseWhiteTurn(char* cursor, turn& turn)
{
    defoltTurn defoltTurn;

    if (strchr(figureType, *cursor)) {
        defoltTurn.figureType = *cursor;
        cursor++;
    } else {
        defoltTurn.figureType = 'p';
    }

    cursor = parseStart(cursor, defoltTurn);

    if (*cursor == '-') {
        defoltTurn.turnType = '-';
    } else if (*cursor == 'x') {
        defoltTurn.turnType = 'x';
    } else {
        cout << "unknown character in parseWhiteTurn" << endl;
        return NULL;
    }
    cursor++;

    cursor = parseEnd(cursor, defoltTurn);
   
    while (*cursor == ' ') {
        cursor++;
    }

    turn.wTurn = defoltTurn;
    return cursor;
}

char* parseBlackTurn(char* cursor, turn& turn) 
{
    defoltTurn defoltTurn;

    if (strchr(figureType, *cursor)) {
        defoltTurn.figureType = *cursor;
        cursor++;
    }

    cursor = parseStart(cursor, defoltTurn);

    if (*cursor == '-') {
        defoltTurn.turnType = '-';
    } else if (*cursor == 'x') {
        defoltTurn.turnType = 'x';
    } else {
        cout << "unknown character in parseBlackTurn" << endl;
        return NULL;
    }
    cursor++;

    cursor = parseEnd(cursor, defoltTurn);

    turn.bTurn = defoltTurn;
    return cursor;
}

char* parseStart(char* cursor, defoltTurn& turn)
{
    switch (*cursor) {
    case 'a':
        turn.jStart = 0;
        break;
    case 'b':
        turn.jStart = 1;
        break;
    case 'c':
        turn.jStart = 2;
        break;
    case 'd':
        turn.jStart = 3;
        break;
    case 'e':
        turn.jStart = 4;
        break;
    case 'f':
        turn.jStart = 5;
        break;
    case 'g':
        turn.jStart = 6;
        break;
    case 'h':
        turn.jStart = 7;
        break;
    default:
        cout << "error in parseStart" << endl;
        return NULL;
    }

    cursor++;

    int i;
    try {
        i = stoi(cursor);
    } catch (const exception&) {
        cout << "not a number";
        return NULL;
    }
    
    if (i > 8 || i < 0) {
        cout << "going out of bounds" << endl;
        return NULL;
    }

    turn.iStart = i;
    cursor++;

    return cursor;
}

char* parseEnd(char* cursor, defoltTurn& turn)
{
    switch (*cursor) {
    case 'a':
        turn.jEnd = 0;
        break;
    case 'b':
        turn.jEnd = 1;
        break;
    case 'c':
        turn.jEnd = 2;
        break;
    case 'd':
        turn.jEnd = 3;
        break;
    case 'e':
        turn.jEnd = 4;
        break;
    case 'f':
        turn.jEnd = 5;
        break;
    case 'g':
        turn.jEnd = 6;
        break;
    case 'h':
        turn.jEnd = 7;
        break;
    default:
        cout << "error in parseEnd" << endl;
        return NULL;
    }

    cursor++;

    int i;
    try {
        i = stoi(cursor);
    } catch (const exception&) {
        cout << "not a number";
        return NULL;
    }

    if (i > ARENA_SIZE || i < 0) {
        cout << "going out of bounds" << endl;
        return NULL;
    }

    turn.iEnd = i;
    cursor++;

    return cursor;
}
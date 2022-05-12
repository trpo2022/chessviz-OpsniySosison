#include "chessviz.h"

int parser(string stroke, turn& turn)
{
    char* str = new char[stroke.length() + 1];
    char* cursor = str;
    str = strcpy(str, stroke.c_str());

    cursor = skipSpace(cursor);

    cursor += 2;

    cursor = skipSpace(cursor);

    cursor = parseFullTurn(cursor, turn.wTurn);

    if (cursor == NULL) {
        cout << str << endl;
        return 1;
    }

    cursor = parseTurnOutcome(cursor, turn.wTurn);

    if (cursor == NULL) {
        cout << str << endl;
        return 1;
    }

    if (turn.wTurn.turnOutcome == '#') {
        return 0;
    }

    cursor = parseFullTurn(cursor, turn.bTurn);

    if (cursor == NULL) {
        cout << str << endl;
        return 1;
    }

    parseTurnOutcome(cursor, turn.bTurn);

    if (cursor == NULL) {
        cout << str << endl;
        return 1;
    }

    delete[] str;
    return 0;
}

char* parseFullTurn(char* cursor, defaultTurn& turn)
{

    if (*cursor == '0') {
        cursor = parseCastling(cursor, turn);

        if (cursor == NULL) {
            return NULL;
        }

        return cursor;
    }

    cursor = parseFigureType(cursor, turn);

    cursor = parsePartTurn(cursor, turn.start);

    if (cursor == NULL) {
        return NULL;
    }

    cursor = parseTurnType(cursor, turn);

    if (cursor == NULL) {
        return NULL;
    }

    cursor = parsePartTurn(cursor, turn.end);

    if (cursor == NULL) {
        return NULL;
    }

    return cursor;
}

char* parsePartTurn(char* cursor, partturn& turn)
{
    if (!checkCoordinateX(cursor, turn.j)) {
        return NULL;
    }

    cursor++;

    if (!checkCoordinateY(cursor, turn.i)) {
        return NULL;
    }

    cursor++;

    return cursor;
}

bool checkCoordinateX(char* cursor, int& j)
{
    int temp = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        if (i == *cursor) {
            j = temp;
            return true;
        }
        temp++;
    }
    cout << "expected letter, but given '" << *cursor << "' " << endl;
    return false;
}

bool checkCoordinateY(char* cursor, int& _i)
{
    int i;
    try {
        i = stoi(cursor);
    } catch (const exception&) {
        cout << "expected number, but given '" << *cursor << "' " << endl;
        return false;
    }

    _i = i - 1;

    return true;
}

char* parseFigureType(char* cursor, defaultTurn& turn)
{
    if (strchr(figureType, toupper(*cursor))) {
        turn.figureType = *cursor;
        cursor++;
    } else {
        turn.figureType = 'P';
    }

    return cursor;
}

char* parseTurnType(char* cursor, defaultTurn& turn)
{
    if (*cursor == '-') {
        turn.turnType = '-';
    } else if (*cursor == 'x') {
        turn.turnType = 'x';
    } else {
        cout << "expected move type (x or -), but given '" << *cursor << "' "
             << endl;
        return NULL;
    }

     cursor++;

    return cursor;
}

char* parseTurnOutcome(char* cursor, defaultTurn& turn)
{
    if (*cursor == ' ') {
        cursor++;
    } else if (*cursor == '\n' || *cursor == '\0' || *cursor == '\r') {
        return cursor;
    } else if (*cursor == '#') {
        cursor++;
        turn.turnOutcome = '#';
    } else if (*cursor == '+') {
        cursor++;
        turn.turnOutcome = '+';
    } else {
        cout << "unknow turn outcome '" << *cursor << "' " << endl;
        return NULL;
    }

    return cursor;
}

char* parseCastling(char* cursor, defaultTurn& turn)
{
    int range = 0;

    turn.turnType = 'C';
    while (*cursor == '0') {
        range++;
        cursor += 2;
    }
    cursor--;

    if (!checkCoordinatesCastling(turn, range)) {
        return NULL;
    }

    return cursor;
}

bool checkCoordinatesCastling(defaultTurn& turn, const int range)
{
    turn.start.i = turn.startKingPos.i;
    turn.start.j = turn.startKingPos.j;

    if (range == 2) {
        turn.end.i = turn.startKingPos.i;
        turn.end.j = turn.start.j + (range + 1);
    } else if (range == 3) {
        turn.end.i = turn.startKingPos.i;
        turn.end.j = turn.start.j - (range + 1);
    } else {
        cout << "unknow castling " << endl;
        return false;
    }
    
    return true;
}

char* skipSpace(char* cursor)
{
    while (*cursor == ' ') {
        cursor++;
    }

    return cursor;
}

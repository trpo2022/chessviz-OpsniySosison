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

    if (turn.wTurn.turnOutcome == '#') {
        return 0;
    }

    cursor = parseFullTurn(cursor, turn.bTurn);

    if (cursor == NULL) {
        cout << str << endl;
        return 1;
    }

    parseTurnOutcome(cursor, turn.bTurn);

    return 0;
}

char* parseFullTurn(char* cursor, defaultTurn& turn)
{

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
 
char* skipSpace(char* cursor)
{
    while (*cursor == ' ') {
        cursor++;
    }

    return cursor;
}

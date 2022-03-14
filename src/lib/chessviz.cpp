#include "chessviz.h"

void print_arena(char arena[ARENA_SIZE][ARENA_SIZE])
{
    for (int i = 0; i < ARENA_SIZE; i++) {
        for (int j = 0; j < ARENA_SIZE; j++) {
            cout << arena[i][j];
        }
        cout << endl;
    }
    cout << "--------" << endl;
}

int make_a_turn(turn turn, char (*arena)[ARENA_SIZE], int num__line)
{
    if (do_turn(turn.wTurn, &arena[0]) != 0) {
        cout << "whites correct move error in " << num__line << " line" << endl;
        return 1;
    }
    if (!check_winner(turn.wTurn)) {
        cout << "White winner" << endl;
        return 2;
    }
    if (do_turn(turn.bTurn, &arena[0]) != 0) {
        cout << "blacks correct move error in " << num__line << " line"
                << endl;
        return 1;
    }
    if (!check_winner(turn.bTurn)) {
        cout << "Black winner" << endl;
        return 3;
    }

    return 0;
}

int do_turn(defaultTurn turn, char (*arena)[ARENA_SIZE])
{
    if (!check_corr(turn, arena)) {
        return 1;
    }

    if (turn.turnType == '-') {
        swap(arena[turn.start.i][turn.start.j], arena[turn.end.i][turn.end.j]);
    } else if (turn.turnType == 'x') {
        arena[turn.end.i][turn.end.j] = arena[turn.start.i][turn.start.j];
        arena[turn.start.i][turn.start.j] = ' ';
    }
    print_arena(arena);

    return 0;
}

bool check_corr(defaultTurn turn, char arena[ARENA_SIZE][ARENA_SIZE])
{
    if (!check_corr_border(turn)) {
        return false;
    }
    if (!check_corr_figureType(turn, arena)) {
        return false;
    }
    if (!check_corr_turnType(turn, arena)) {
        return false;
    }
    if (!check_corr_turnLength(turn)) {
        return false;
    }

    return true;
}

bool check_corr_figureType(defaultTurn turn, char arena[ARENA_SIZE][ARENA_SIZE])
{
    if (toupper(turn.figureType)
        != toupper(arena[turn.start.i][turn.start.j])) {
        cout << "figures do not match" << endl;
        return false;
    }

    return true;
}

bool check_corr_turnType(defaultTurn turn, char arena[ARENA_SIZE][ARENA_SIZE])
{
    if (turn.turnType == '-'
        && strchr(figureType, toupper(arena[turn.end.i][turn.end.j]))) {
        cout << "You are trying to make a normal move into a square with a "
                "piece: ["
             << turn.end.i + 1 << "][" << turn.end.j + 1 << "]" << endl;
        return false;
    } else if (turn.turnType == 'x' && arena[turn.end.i][turn.end.j] == ' ') {
        cout << "You are trying to cut down an empty cell ["
             << turn.end.i + 1 << "][" << turn.end.j + 1 << "]" << endl;
        return false;
    }

    return true;
}

bool check_corr_turnLength(defaultTurn turn)
{
    int turn_length;
    
    switch (turn.figureType) {
    case 'P':
        turn_length = abs(turn.start.i - turn.end.i);
        if (turn_length != 2 && turn_length != 1) {
            cout << "pawn move too long" << endl;
            return false;
        }
        break;
    /*default:
        cout << "unknown figure" << endl;
        return false;
        break;*/
    }

    return true;
}

bool check_corr_border(defaultTurn turn)
{
    if (turn.end.i > ARENA_SIZE || turn.end.j > ARENA_SIZE
        || turn.start.i > ARENA_SIZE || turn.start.j > ARENA_SIZE) {
        cout << "attempt to go out of bounds" << endl;
        return false;
    }

    return true;
}

bool check_winner(defaultTurn turn)
{
    return turn.turnOutcome != '#';

    //if (turn.turnOutcome == '#') {
    //    return false;
    //}
}

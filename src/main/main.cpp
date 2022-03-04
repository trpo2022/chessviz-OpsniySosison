#include "lib/chessviz.h"

int main()
{
    char arena[ARENA_SIZE][ARENA_SIZE] // game arena
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    ifstream data("./inputdata");
    string line;
    turn turn;
    int num__line = 1;

    print_arena(arena);
    if (data.is_open()) {
        while (getline(data, line)) {
            int code_return_parser;
            code_return_parser = parser(line, turn);
            if (code_return_parser != 0 && code_return_parser != 3
                && code_return_parser != 4) {
                cout << "input data error in " << num__line << " line" << endl;
                return 1;
            }
            if (do_turn(turn.wTurn, &arena[0]) != 0) {
                cout << "whites correct move error in " << num__line << " line"
                     << endl;
                return 2;
            }
            if (code_return_parser != 3) {
                if (do_turn(turn.bTurn, &arena[0]) != 0) {
                    cout << "blacks correct move error in " << num__line
                         << " line" << endl;
                    return 2;
                }
            } else if (code_return_parser == 4) {
                cout << "Black winner!" << endl;
            } else {
                cout << "White winner!" << endl;
            }
            num__line++;
        }
    } else {
        cout << "error, file is not open" << endl;
        return 3;
    }

    data.close();

    return 0;
}
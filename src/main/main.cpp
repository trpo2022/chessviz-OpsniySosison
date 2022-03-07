#include "lib/chessviz.h"

/*
«адачи на завтра:
6. доделать остальное из методички
7. подумать как будет правильнее объ€вл€ть победу.
*/

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
            if (code_return_parser != 0 && code_return_parser != 2
                && code_return_parser != 3) {
                cout << "input data error in " << num__line << " line" << endl;
                return 1;
            }
            make_a_turn(turn, code_return_parser, num__line);
            num__line++;
        }
    } else {cout << "error, file is not open" << endl; return 3;}

    data.close();

    return 0;
}
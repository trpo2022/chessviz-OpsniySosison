#include "lib/chessviz.h"

int main() {
    //char arena[ARENA_SIZE][ARENA_SIZE] // game arena
    //        = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    //           {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    //           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    //           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    //           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    //           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    //           {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    //           {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    ifstream data("./inputdata");
    string line;
    turn turn;

    if (data.is_open()) {
        while (getline(data, line)) {
            turn = parser(line);        }
    } else {
        cout << "error, file is not open" << endl;
        return 1;
    }

    data.close();

    //print_arena(&arena[0]);
    return 0;
}
#include <iostream>

#define ARENA_SIZE 8

using namespace std;

void print_arena(char arena[ARENA_SIZE][ARENA_SIZE]) {
	cout << "ARENA" << endl;
    for (int i = 0; i < ARENA_SIZE; i++) {
        for (int j = 0; j < ARENA_SIZE; j++) {
            cout << arena[i][j];
		}
		cout << endl;
	}
}

int main() {
    char arena[ARENA_SIZE][ARENA_SIZE]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    print_arena(arena);
    return 0;
}
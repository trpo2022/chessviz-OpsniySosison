#include "chessviz.h"

void print_arena(char (*arena)[ARENA_SIZE]) 
{
    //system("clear");
    cout << "ARENA:" << endl;
    for (int i = 0; i < ARENA_SIZE; i++) {
        for (int j = 0; j < ARENA_SIZE; j++) {
            cout << arena[i][j];
        }
        cout << endl;
    }
}

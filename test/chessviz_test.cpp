#include "src/lib/chessviz.h"
#include "thirdparty/ctest.h"

CTEST(chessviz_suite, check_border)
{
    defaultTurn enter;
    enter.end.i = 8;
    enter.end.j = 6;

    enter.start.i = 5;
    enter.start.j = 3;

    const bool res = check_corr_border(enter);

    ASSERT_FALSE(res);
}

CTEST(chessviz_suite, check_corr_)
{
     char arena[ARENA_SIZE][ARENA_SIZE] 
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    defaultTurn enter;

    enter.figureType = 'P';
    enter.turnType = '-';
    enter.start.i = 1;
    enter.start.j = 2;
    enter.end.i = 4;
    enter.end.j = 2;

    const bool res = check_corr(enter, arena);
    
    ASSERT_FALSE(res);
}

CTEST(chessviz_suite, check_corr_tt)
{
    char arena[ARENA_SIZE][ARENA_SIZE]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    defaultTurn enter;

    enter.figureType = 'P';
    enter.turnType = '-';
    enter.start.i = 5;
    enter.start.j = 2;
    enter.end.i = 6;
    enter.end.j = 2;

    const bool res = check_corr_turnType(enter, arena);

    ASSERT_FALSE(res);
}

CTEST(chessviz_suite, check_corr_tl) 
{
    defaultTurn enter;

    enter.figureType = 'N';
    enter.start.i = 5;
    enter.start.j = 2;
    enter.end.i = 6;
    enter.end.j = 2;

    const bool res = check_corr_turnLength(enter);

    ASSERT_FALSE(res);
}

CTEST(chessviz_suite, )
{
    char arena[ARENA_SIZE][ARENA_SIZE]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    defaultTurn enter;

    enter.start.i = 0;
    enter.start.j = 0;
    enter.figureType = 'P';

    const bool res = check_corr_figureType(enter, arena);

    ASSERT_FALSE(res);
}

CTEST(chessviz_suite, check_obs_c)
{
    char arena[ARENA_SIZE][ARENA_SIZE]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', ' ', ' ', ' ', 'K', 'B', 'N', 'R'}};

    defaultTurn enter;

    enter.end.i = 7;
    enter.end.j = 0;

    enter.startKingPos.i = 7;
    enter.startKingPos.j = 4;

    const bool res = check_obstruction_castl(enter, arena);

    ASSERT_TRUE(res);
}


CTEST(chessviz_suite, make_a_t) 
{
    char arena[ARENA_SIZE][ARENA_SIZE]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    turn enter;

    enter.wTurn.figureType = 'P';
    enter.wTurn.turnType = '-';
    enter.wTurn.turnOutcome = '#';
    enter.wTurn.start.i = 1;
    enter.wTurn.start.j = 3;
    enter.wTurn.end.i = 3;
    enter.wTurn.end.j = 3;

    enter.bTurn.figureType = 'P';
    enter.bTurn.turnType = '-';
    enter.bTurn.start.i = 6;
    enter.bTurn.start.j = 3;
    enter.bTurn.end.i = 4;
    enter.bTurn.end.j = 3;

    const int exp = 2;
    const int res = make_a_turn(enter, arena, 1);

    ASSERT_EQUAL(exp, res);
}

CTEST(chessviz_suite, do_turn_)
{
    char arena[ARENA_SIZE][ARENA_SIZE]
            = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
               {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    defaultTurn enter;

    enter.figureType = 'P';
    enter.turnType = '-';
    enter.start.i = 1;
    enter.start.j = 3;
    enter.end.i = 3;
    enter.end.j = 3;

    const int exp = 0;
    const int res = do_turn(enter, arena);

    ASSERT_EQUAL(exp, res);
}

CTEST(chessviz_suite, c_win)
{
    defaultTurn enter;
    
    const bool res = check_winner(enter);

    ASSERT_FALSE(res);
}

CTEST(chessviz_suite, print_ar)
{
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
}
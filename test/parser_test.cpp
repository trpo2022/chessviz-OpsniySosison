#include "src/lib/chessviz.h"
#include "thirdparty/ctest.h"

CTEST(parser_suite, full_parser)
{
    turn turn;
    string enter = "1. e2-e4 e7-e5\r";

    const int exp = 0;
    const int res = parser(enter, turn);

    ASSERT_EQUAL(exp, res);
}

CTEST(parser_suite, parse_ft)
{
    defaultTurn turn;
    char str[] = "e2-e4 \r";
    char* cursor = str;

    ASSERT_NOT_NULL(parseFullTurn(cursor, turn));
}

CTEST(parser_suite, parse_pt)
{
    partturn turn;
    char str[] = "e2";
    char* cursor = str;

    ASSERT_NOT_NULL(parsePartTurn(cursor, turn));
}

CTEST(parser_suite, check_cx)
{
    char str[] = "b";
    char* cursor = str;

    int j;

    ASSERT_TRUE(checkCoordinateX(cursor, j));
}

CTEST(parser_suite, check_cy)
{
    char str[] = "2";
    char* cursor = str;

    int i;

    ASSERT_TRUE(checkCoordinateY(cursor, i));
}

CTEST(parser_suite, parse_fig_t)
{
    char str[] = "Q";
    char* cursor = str;

    defaultTurn turn;
    parseFigureType(cursor, turn);

    ASSERT_EQUAL('Q', turn.figureType);
}

CTEST(parser_suite, parse_tt)
{
    char str[] = "-";
    char* cursor = str;

    defaultTurn turn;

    ASSERT_NOT_NULL(parseTurnType(cursor, turn));
}

CTEST(parser_suite, parse_to)
{
    char str[] = "#";
    char* cursor = str;

    defaultTurn turn;

    ASSERT_NOT_NULL(parseTurnOutcome(cursor, turn));
}

CTEST(parser_suite, parse_c)
{
    char str[] = "0-0-0";
    char* cursor = str;

    defaultTurn turn;

    ASSERT_NOT_NULL(parseCastling(cursor, turn));
}

CTEST(parser_suite, check_cc)
{
    defaultTurn enter;
    int range = 2;

    enter.startKingPos.j = 4;

    int exp = 7;
    checkCoordinatesCastling(enter, range);

    ASSERT_EQUAL(exp, enter.end.j);
}

CTEST(parser_suite, skip_s)
{
    char str[] = "   1   ";
    char* cursor = str;

    cursor = skipSpace(cursor);

    char exp[] = "1   ";

    ASSERT_STR(exp, cursor);
}

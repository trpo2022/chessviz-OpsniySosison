#include "src/lib/chessviz.h"
#include "thirdparty/ctest.h"

CTEST(chessviz_suite, check_border)
{
    defaultTurn enter;
    enter.end.i = 8;
    enter.end.j = 6;

    enter.start.i = 5;
    enter.start.j = 3;

    const bool exp = false;
    const bool res = check_corr_border(enter);

    ASSERT_EQUAL(exp, res);
}
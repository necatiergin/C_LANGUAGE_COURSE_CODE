#include <stdio.h>
#include <assert.h>

#define assert_msg(MSG,EXPR)   assert( (MSG, (EXPR)) )

int main(void)
{
    int x = 0;
    //
    assert_msg("invariant not hold: ", x > 5);
}

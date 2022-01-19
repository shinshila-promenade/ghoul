#include "tokio.h"

int main()
{
    Counter* counter = counter_create(GHOUL_START_VALUE);
    counter_loop(counter);
    free(counter);
    return 0;
}
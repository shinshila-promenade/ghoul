#ifndef TOKIO_H
#define TOKIO_H

#include <stdio.h>
#include <malloc.h>


/* <SLEEP FUNCTION> */
#if defined(_WIN32)
#include <Windows.h>
#define SLEEP(MS) Sleep(MS);

#elif defined(__linux__)
#include <unistd.h>
#define SLEEP(MS) usleep(MS * 1000);
#endif
/* <SLEEP FUNCTION> */


#define GHOUL_START_VALUE 1000
#define GHOUL_VALUE 7


typedef struct {
    int value;
} Counter;

Counter* counter_create(const int i) {
    Counter* counter = malloc(sizeof(Counter));
    counter->value = i;

    return counter;
}

void counter_decrease(Counter* counter) {
    counter->value -= GHOUL_VALUE;
}

const char* counter_format(Counter* counter) {
    if (counter->value - GHOUL_VALUE > -1)
        return "%d - %d = %d\n";
    return "\\033[0;31mI'm a ghoul...\\033[0m\\n"; // Print the end.
}

void counter_print(Counter* counter) {
    printf(counter_format(counter),
           counter->value, GHOUL_VALUE,
           counter->value - GHOUL_VALUE);
}

void counter_loop(Counter* counter) {
    while (counter->value > 0) {
        counter_print(counter);
        counter_decrease(counter);
        SLEEP(25);
    }
}


#endif //GHOUL_TOKIO_TOKIO_H
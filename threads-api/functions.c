#include <stdio.h>
#include <pthread.h>
#include "common_threads.h"

void* func(void* arg) {
    int arg_int = (int) arg;
    int x = arg_int * 2;
    return (void*) x;
}

int main(int argc, char *argv[]) {
    int foo;
    foo = (int) func((void*) 100);
    printf("foo = %d\n", foo);

    pthread_t p;
    Pthread_create(&p, NULL, func, (void*) 100);
    int y;
    Pthread_join(p, (void**) &y);
    printf("%d\n", y);
    return 0;
}
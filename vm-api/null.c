#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int *i = (int *)malloc(sizeof(int));
    i = NULL;
    *i = 1; // modify the pointer but the pointer doesn't point to anything
    free(i); // doesn't free anything because i is NULL
}

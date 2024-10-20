#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int *i = (int *)malloc(sizeof(int));
    *i = 10;
}
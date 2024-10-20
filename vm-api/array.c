#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int size = 100;
    
    int *data = (int *)malloc(size * sizeof(int));
    data[99] = 0;// warum geht das immer noch mit data[100]?
    //free(data);
}
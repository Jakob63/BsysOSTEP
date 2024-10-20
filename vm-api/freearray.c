#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int size = 100;
    
    int *data = (int *)malloc(size * sizeof(int));
    data[99] = 23; // warum geht das auch mit data[100]?
    // free(data);
    // printf("data[99] = %d\n", data[99]);
    free(data + 50 * sizeof(int)); // free the memory starting from the 50th element
    //printf("data[99] = %d\n", data[99]);
    //free(data); // free the memory starting from the 0th element
}
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }
    printf("PID: %d\n", getpid());
    int mebibytes = atoi(argv[1]); 
    size_t bytes = mebibytes * 1024 * 1024;
    int *array = (int*) malloc(bytes);
    if(array == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    //_Bool a = 1;
    while(1)
    {
        for (int i = 0; i < bytes/4; i++)
        {
            array[i] = 1;
            //printf("%d", array[i]);
        }
    }
    free(array);
    return 0;
}
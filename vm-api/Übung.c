#include <stdio.h>
#include <stdlib.h>

int main()
{
    double size;
    printf("Gib eine gewünschte Arraygröße ein: ");
    scanf("%d", &size);
    int *arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Speicher konnte nicht allokiert werden\n");
        return 1;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}
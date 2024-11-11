#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

void initVector(Vector *vec) // initialize the vector
{
    vec->size = 0;
    vec->capacity = 4;
    vec->data = (int *) malloc(vec->capacity * sizeof(int));
}

int getElement(Vector *vec, int index) // get an element from the vector
{
    if (index < 0 || index >= vec->size)
    {
        printf("Index out of bounds\n");
        return -1;
    }
    return vec->data[index];
}

void addElement(Vector *vec, int element) // add an element to the vector
{
    vec->size++;
    if (vec->size > vec->capacity)
    {
        vec->capacity = vec->capacity * 2;
        vec->data = (int *) realloc(vec->data, vec->capacity * sizeof(int));
    }
    vec->data[vec->size - 1] = element;
}

void removeElement(Vector *vec, int index) // remove an element from the vector
{
    if (index < 0 || index >= vec->size)
    {
        printf("Index out of bounds\n");
        return;
    }
    for (int i = index; i < vec->size - 1; i++)
    {
        vec->data[i] = vec->data[i + 1];
    }
    vec->size--;
}

void freeVector(Vector *vec) // free the vector
{
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

void printVector(Vector *vec) // print the vector
{
    printf("Data: ");
    for (int i = 0; i < vec->size; i++) {
        printf("%d ", vec->data[i]);
    }
    printf(", Anzahl-Elemente: %zu, Größe: %zu\n", vec->size, vec->capacity);
}

int main() {
    Vector vec;
    initVector(&vec);
    addElement(&vec, 1);
    addElement(&vec, 2);
    addElement(&vec, 3);
    removeElement(&vec, 2);
    addElement(&vec, 4);
    addElement(&vec, 5);


    printVector(&vec);
    printf("Element an Index 3: %d\n", getElement(&vec, 3));
    freeVector(&vec);

    return 0;
}
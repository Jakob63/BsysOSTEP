#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

void vector_initialisieren(Vector *vec)
{
    vec->size = 0;
    vec->capacity = 4;
    vec->data = (int *) malloc(vec->capacity * sizeof(int));
}

void add_element(Vector *vec, int element)
{
    vec->size++;
    if (vec->size > vec->capacity)
    {
        vec->capacity = vec->capacity * 2;
        vec->data = (int *)realloc(vec->data, vec->capacity * sizeof(int));
    }
    vec->data[vec->size - 1] = element;
}

void vector_freigeben(Vector *vec)
{
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

void print_vector(Vector *vec)
{
    printf("Data: ");
    for (size_t i = 0; i < vec->size; i++)
    {
        printf("%d ", vec->data[i]);
    }
    printf(", Anzahl-Elemente: %zu, Größe: %zu\n", vec->size, vec->capacity);
}

int main(int argc, char* argv[])
{
    Vector v;
    vector_initialisieren(&v);
    add_element(&v, 24);
    add_element(&v, 34);
    add_element(&v, 44);
    print_vector(&v);
    vector_freigeben(&v);
}


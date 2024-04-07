#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    size_t size;
    size_t capacity;
} Vector;

void vector_init(Vector *vector, size_t initial_capacity) {
    vector->array = (int *)malloc(initial_capacity * sizeof(int));
    if (vector->array == NULL) {
        // Handle memory allocation failure
        exit(1);
    }
    vector->size = 0;
    vector->capacity = initial_capacity;
}

int vector_is_full(Vector *vector) {
    return vector->size == vector->capacity;
}

void vector_resize(Vector *vector, size_t new_capacity) {
    int *temp = (int *)realloc(vector->array, new_capacity * sizeof(int));
    if (temp == NULL) {
        // Handle memory allocation failure
        exit(1);
    }
    vector->array = temp;
    vector->capacity = new_capacity;
}

void vector_add(Vector *vector, int element) {
    if (vector_is_full(vector)) {
        vector_resize(vector, vector->capacity * 2);
    }
    vector->array[vector->size++] = element;
}

int vector_get(Vector *vector, size_t index) {
    if (index < vector->size) {
        return vector->array[index];
    }
    // Handle error for out-of-bounds index
    return -1; // Example error handling
}

void vector_remove(Vector *vector, size_t index) {
    if (index < vector->size) {
        for (size_t i = index; i < vector->size - 1; i++) {
            vector->array[i] = vector->array[i + 1];
        }
        vector->size--;
    }
}

int vector_is_empty(Vector *vector) {
    return vector->size == 0;
}

size_t vector_size(Vector *vector) {
    return vector->size;
}

void vector_clear(Vector *vector) {
    vector->size = 0;
}

void vector_free(Vector *vector) {
    free(vector->array);
    vector->array = NULL;
    vector->size = 0;
    vector->capacity = 0;
}

size_t vector_capacity(Vector *vector) {
    return vector->capacity;
}

int vector_contains(Vector *vector, int element) {
    for (size_t i = 0; i < vector->size; i++) {
        if (vector->array[i] == element) {
            return 1;
        }
    }
    return 0;
}

void vector_insert(Vector *vector, size_t index, int element) {
    if (vector->size == vector->capacity) {
        vector_resize(vector, vector->capacity * 2);
    }
    if (index <= vector->size) {
        for (size_t i = vector->size; i > index; i--) {
            vector->array[i] = vector->array[i - 1];
        }
        vector->array[index] = element;
        vector->size++;
    }
}

int main() {
    Vector myVector;
    vector_init(&myVector, 5); // Initialize vector with capacity of 5

    // Add some elements
    vector_add(&myVector, 10);
    vector_add(&myVector, 20);
    vector_add(&myVector, 30);

    printf("Vector size: %zu\n", vector_size(&myVector));
    printf("Vector capacity: %zu\n", vector_capacity(&myVector));

    // Insert an element
    vector_insert(&myVector, 1, 15);
    printf("After insertion, element at index 1: %d\n", vector_get(&myVector, 1));

    // Remove an element
    vector_remove(&myVector, 2);
    printf("After removal, element at index 2: %d\n", vector_get(&myVector, 2));

    vector_free(&myVector); // Free the vector
    return 0;
}

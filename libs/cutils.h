#ifndef CUTILS_H
#define CUTILS_H

#include <stddef.h> // To use "size_t".

// A simple dynamic array of integers.
typedef struct {
    int     *items;     // Pointer to the actual integers in memory.
    size_t  count;      // How many elements are currently stored.
    size_t  capacity;   // How many elements fit before the array must grow
} IntList;

// Initialize the list so it's safe to use (empty, no memory allocated yet).
void inlist_init(IntList *list);

// Free any memory used by the list and reset it.
void inlist_free(IntList *list);

#endif 
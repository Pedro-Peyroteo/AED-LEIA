#include "cutils.h"
#include <stdlib.h> // For malloc(), free(), realloc().

#define ITEM_TYPE int
#define INITIAL_CAPACITY 4

// Set the list to a safe empty state.
// No allocated memory.
void intlist_init(IntList *list) {
    list->items = NULL;
    list->count = 0;
    list->capacity = 0;
} 

// Free any memory used by the list (if any) and reset it.
void intlist_free(IntList *list){
    free(list->items);          // Free the allocated memory.
    list->items = NULL;         // Reset pointer.
    list->count = 0;            // Reset element count.
    list->capacity = 0;         // Reset capacity.
}

/*  
    Ensures the list has enough capacity to hold at least min_capacity elements.
    If not enough, it will grow the internal array.
    Returns false if any memory allocation fails.
*/
static bool ensure_capacity(IntList *list, size_t value_needed){
    // Checks if list has enough capacity for the new value.
    if (list->capacity >= value_needed) return true;

    // Decide new capacity.
    if (list->capacity > SIZE_MAX / 2) {
        return false; // Prevent overflow in new_capacity.
    }
    size_t new_capacity = (list->capacity == 0) ? INITIAL_CAPACITY : (list->capacity * 2);
    
    if (new_capacity < value_needed) new_capacity = value_needed;

    // Calculate size in bytes safely.
    size_t new_size = new_capacity * sizeof(int);

    // Check for overflow.
    if (new_size / sizeof(int) != new_capacity) {
        return false; // Multiplication overflowed;
    }

    // Reallocate memory.
    // Note: If realloc fails, the original memory block is not freed, and list->items remains valid.
    int *new_items = realloc(list->items, new_size);
    if (!new_items) return false;

    list->items = new_items;
    list->capacity = new_capacity;
    return true;
}

// Append value to list.
bool intlist_append(IntList *list, int value){
    // Checks if list has enough capacity to hold new value.
    if(!ensure_capacity(list, list->count + 1)) return false;
    list->items[list->count++] = value;
    return true;
}
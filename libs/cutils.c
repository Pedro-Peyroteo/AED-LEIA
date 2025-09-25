#include "cutils.h"
#include <stdlib.h> // For malloc(), free(), realloc().

// Set the list to a safe empty state.
// No allocated memory.
void inlist_init(IntList *list) {
    list->items = NULL;
    list->count = 0;
    list->capacity = 0;
} 

// Free any memory used by the list (if any) and reset it.
void inlist_free(IntList *list){
    free(list->items);          // Free the allocated memory.
    list->items = NULL;         // Reset pointer.
    list->count = 0;            // Reset element count.
    list->capacity = 0;         // Reset capacity.
}
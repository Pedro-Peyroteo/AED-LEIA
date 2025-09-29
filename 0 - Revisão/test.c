#include "cutils.h"
#include <stdio.h>

int main(void) {
    IntList nums;           // Create a list variable.
    intlist_init(&nums);    // Initialize the list.

    printf("Count: %zu\nCapacity: %zu\n", nums.count, nums.capacity);

    intlist_append(&nums, 1);
    intlist_append(&nums, 2);
    intlist_append(&nums, 3);
    intlist_append(&nums, 4);
    intlist_append(&nums, 5);

    printf("Count: %zu\nCapacity: %zu\n", nums.count, nums.capacity);

    intlist_free(&nums); // Free any memory used by the list.

    printf("Count: %zu\nCapacity: %zu\nItems: %zu", nums.count, nums.capacity, nums.items);

    return 0;
}
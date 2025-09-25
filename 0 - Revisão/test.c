#include "cutils.h"
#include <stdio.h>

int main(void) {
    IntList nums;           // Create a list variable.
    IntList_init(&nums);    // Initialize the list.

    printf("Count: %zu\nCapacity: %zu\n", nums.count, nums.capacity);

    intlist_free(&nums); // Free any memory used by the list.

    return 0;
}
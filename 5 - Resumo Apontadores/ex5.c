#include <stdio.h>

char *my_strchr(char *s, int ch) {
    // Create a pointer to store the result (initially NULL).
    char *result = NULL;

    // Loop through the string until '\0'
    while (*s != '\0') {
        // If current character == ch, update result to this position.
        if (*s == ch) {
            result = s;
        }
        // Move to next character.
        s++;
    }

    // If ch == '\0', return pointer to terminator.
    if (ch == '\0') {
        return s;
    }

    // Return result (NULL if not found, or last match).
    return result;
}

char *my_strstr(char *str1, char *str2) {
    // If str2 is empty, return str1 immediately.
    if (*str2 == '\0') {
        return str1;
    }

    // Loop through str1
    for (; *str1 != '\0'; str1++) {
        // Create pointers for comparison.
        char *p1 = str1;
        char *p2 = str2;

        // Compare characters of str2 with this part of str1.
        while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
            // Move both pointers forward.
            p1++;
            p2++;
        }

        // If full match (end of str2 reached), return pointer to match.
        if (*p2 == '\0') {
            return str1;
        }
    }

    // End of str1 reached without match, return NULL.
    return NULL;
}

int main() {
    char name[100];

    // Ask user for full name.
    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);

    // Call my_strchr with space ' ' to find last space.
    // char *last_space = my_strchr(name, ' ');
    char *last_space = my_strchr(name, 't');

    // If found, print the part after it (last surname).
    if (last_space != NULL) {
        // Print the raw address (cast to void* for %p)
        printf("Address of last space: %p\n", (void*) last_space);

        // Print the character found
        printf("Character at that address: '%c'\n", *last_space);

        // Print the last surname (skip the space itself)
        printf("Last surname: %s\n", last_space + 1);
    } else {
        printf("No surname found. Full name: %s\n", name);
    }

    // Test my_strstr with two sample strings.
    char text[] = "banana";
    char pattern[] = "na";
    char *found = my_strstr(text, pattern);

    // Print the result or message if not found.
    if (found != NULL) {
        printf("Substring found: %s\n", found);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}

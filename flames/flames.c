#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> // For toupper/tolower if needed, but isalpha/tolower are from ctype.h

#define MAX_NAME_LEN 100 // Increased size for longer names
#define FLAMES_LEN 6

// Function to clean a name (lowercase, remove spaces and non-letters)
void clean_name(char *name) {
    int i, j = 0;
    for (i = 0; name[i] != '\0'; i++) {
        // Only keep alphabetic characters
        if (isalpha((unsigned char)name[i])) {
            name[j++] = tolower((unsigned char)name[i]);
        }
    }
    name[j] = '\0'; // Null-terminate the cleaned string
}

// Function to find the total number of non-common letters
int get_uncommon_count(char *name1, char *name2) {
    // We use copies to modify them without changing the original input strings
    char copy1[MAX_NAME_LEN], copy2[MAX_NAME_LEN];
    strcpy(copy1, name1);
    strcpy(copy2, name2);

    int len1 = strlen(copy1);
    int len2 = strlen(copy2);
    int common_count = 0;

    // Loop through name1, then name2 to find and mark common characters
    for (int i = 0; i < len1; i++) {
        if (copy1[i] == '*') continue; // Skip already marked letters

        for (int j = 0; j < len2; j++) {
            if (copy2[j] == '*') continue; // Skip already marked letters

            if (copy1[i] == copy2[j]) {
                // Mark both characters as matched/cancelled (using a placeholder '*')
                copy1[i] = '*';
                copy2[j] = '*';
                common_count += 2; // Count two letters: one from each name
                break; // Move to the next unique letter in name1
            }
        }
    }

    // The result is the total length minus the count of common letters
    return (len1 + len2) - common_count;
}

// Function to get the final FLAMES result using the count
char* calculate_flames(int count) {
    // The FLAMES word is a simple character array that will be modified
    static char flames[FLAMES_LEN + 1] = "FLAMES";
    int current_len = FLAMES_LEN;
    int index = 0;

    // Handle the special case where all letters cancel out
    if (count == 0) {
        return "FRIENDS (100% match, means perfect friendship/compatibility!)";
    }
    
    // Core elimination logic: runs until only one letter is left (current_len > 1)
    while (current_len > 1) {
        // 1. Calculate the index to eliminate (circular count)
        // (count - 1) is used because if count is 1, the index should be (0+1-1) % len = 0.
        // The index variable holds the starting point for the count in the current loop.
        index = (index + count - 1) % current_len;

        // 2. Eliminate the character at the calculated index
        for (int i = index; i < current_len - 1; i++) {
            flames[i] = flames[i + 1];
        }
        
        // 3. Update the array length
        flames[--current_len] = '\0'; // Decrease length and re-null-terminate
    }

    // 4. Return the result based on the final remaining letter
    switch (flames[0]) {
        case 'F': return "FRIENDS";
        case 'L': return "LOVE";
        case 'A': return "AFFECTION";
        case 'M': return "MARRIAGE";
        case 'E': return "ENEMY";
        case 'S': return "SIBLINGS";
        default: return "UNKNOWN"; // Should not happen
    }
}

int main() {
    char name1[MAX_NAME_LEN], name2[MAX_NAME_LEN];

    printf("✨ Welcome to the Basic FLAMES Love Calculator ✨\n");
    printf("----------------------------------------------\n");
    
    // Using fgets to read the whole line, including spaces (for full names)
    printf("Enter the First Person's Name (e.g., Rohan Kumar): ");
    if (fgets(name1, MAX_NAME_LEN, stdin) == NULL) return 1;

    printf("Enter the Second Person's Name (e.g., Priya Sharma): ");
    if (fgets(name2, MAX_NAME_LEN, stdin) == NULL) return 1;

    // Remove the newline character that fgets leaves at the end
    name1[strcspn(name1, "\n")] = 0;
    name2[strcspn(name2, "\n")] = 0;

    // 1. Clean the names
    clean_name(name1);
    clean_name(name2);

    // 2. Calculate the uncommon count
    int uncommon_count = get_uncommon_count(name1, name2);

    printf("\n--- Result ---\n");
    printf("Letters remaining after cancellation: %d\n", uncommon_count);
    
    // 3. Determine and display the result
    char *result = calculate_flames(uncommon_count);
    
    printf("Your relationship status is: **%s**\n", result);
    printf("----------------------------\n");

    return 0;
}
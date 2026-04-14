//Problem Statement 73.
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string.
If all characters repeat, return '$'.

#include <stdio.h>
#include <string.h>

char firstNonRepeating(char *s) {
    int freq[26] = {0};

    // Count frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Find first non-repeating character
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$'; // If all characters repeat
}

int main() {
    char str[1000];

    printf("Enter a string: ");
    scanf("%s", str);

    char result = firstNonRepeating(str);

    printf("First non-repeating character: %c\n", result);

    return 0;
}  

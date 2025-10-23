#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int isPalindrome(char str[], int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

void findLongestPalindrome(char str[]) {
    int len = strlen(str);
    int maxLength = 1;
    int startIndex = 0;
    
    // Check all possible substrings
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            // Check if substring from i to j is a palindrome
            if (isPalindrome(str, i, j)) {
                int currentLength = j - i + 1;
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                    startIndex = i;
                }
            }
        }
    }
    
    //print longest palindrome substring
    for (int i = startIndex; i < startIndex + maxLength; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char str[MAX_LEN];
    scanf("%s", str);
    findLongestPalindrome(str);
    
    return 0;
}
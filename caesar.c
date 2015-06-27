#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    if (!argv[1] || argc > 2) {
        printf("You did not enter a single non-negative integer.\n");
        return 1;
    }
    else {
        int k = (atoi(argv[1]) % 26);
        string message = GetString();
        
        for (int i = 0, n = strlen(message); i < n; i++)
        {
            if (isdigit(message[i])) {
                printf("%c", message[i]);
            }
            else if (ispunct(message[i])) {
                printf("%c", message[i]);
            }
            else if (isspace(message[i])) {
                printf(" ");
            }
            else {
                int asciiValue = message[i];
                
                if (isupper(asciiValue)) {
                   int asciiValPlusKey = (asciiValue + k);
                    if (asciiValPlusKey > 90) {
                        char encryptedChar = ((asciiValPlusKey - 90) + 64);
                        printf("%c", encryptedChar);
                    }
                    else {
                        char encryptedChar = asciiValPlusKey;
                        printf("%c", encryptedChar);
                    }
                }
                else {
                    int asciiValPlusKey = (asciiValue + k);
                    if (asciiValPlusKey > 122) {
                        char encryptedChar = ((asciiValPlusKey - 122) + 96);
                        printf("%c", encryptedChar);
                    }
                    else {
                        char encryptedChar = asciiValPlusKey;
                        printf("%c", encryptedChar);
                    }
                }
            }
        }
        printf("\n");
        return 0;
    }
}

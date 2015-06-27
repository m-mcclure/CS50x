#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]) {
    string keyword = argv[1];
    bool keywordIsOK = true;
    
    if (argc != 2) {
        printf("You did not enter a single keyword with only letters for encryption. Run the program again.\n");
        return 1;
    }
    
    for (int i = 0, n = strlen(keyword); i < n; i++) {
            if (isdigit(keyword[i])) {
                keywordIsOK = false;
            }
            else if (ispunct(keyword[i])) {
                keywordIsOK = false;
            }
        }
    
    if (keywordIsOK == false) {
        printf("You did not enter a single keyword with only letters for encryption. Run the program again.\n");
        return 1;
    }
    else {
        string message = GetString();
        string keyword = argv[1];
        int keyOfKeywordCurrentChar;
        int lengthOfKeyword = strlen(keyword);
        int keywordIntArray[lengthOfKeyword];
        int keywordPositionCounter = 0;
        char currentChar = 0;
        int asciiIntForCurrentChar;
        
        for (int i = 0; i < lengthOfKeyword; i++) {
            if (isupper(keyword[i])) {
                        char currentKeywordChar = keyword[i];
                        int asciiIntForCurrentKeywordChar = (int) currentKeywordChar;
                        keyOfKeywordCurrentChar = asciiIntForCurrentKeywordChar - 65;
                        keywordIntArray[i] = keyOfKeywordCurrentChar;            
                    } else if (islower(keyword[i])) {
                        char currentKeywordChar = keyword[i];
                        int asciiIntForCurrentKeywordChar = (int) currentKeywordChar;
                        keyOfKeywordCurrentChar = asciiIntForCurrentKeywordChar - 97;
                        keywordIntArray[i] = keyOfKeywordCurrentChar;
                    }
        }

        for (int i = 0, n = strlen(message); i < n; i++) {
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
                    if (isupper(message[i])) {
                        currentChar = message[i];
                        asciiIntForCurrentChar = (int) currentChar;
                        
                        asciiIntForCurrentChar = asciiIntForCurrentChar + keywordIntArray[keywordPositionCounter];
                        
                        if (asciiIntForCurrentChar > 90) {
                            asciiIntForCurrentChar = asciiIntForCurrentChar - 26;
                        }
                        char newChar = asciiIntForCurrentChar;
                        printf("%c", newChar);
                        if (keywordPositionCounter < lengthOfKeyword - 1) {
                            keywordPositionCounter++;
                        } else {
                            keywordPositionCounter = 0;
                        }                     
                    } else if (islower(message[i])) {
                        currentChar = message[i];
                        asciiIntForCurrentChar = (int) currentChar;
                        asciiIntForCurrentChar = asciiIntForCurrentChar + keywordIntArray[keywordPositionCounter];
                        
                        if (asciiIntForCurrentChar > 122) {
                            asciiIntForCurrentChar = asciiIntForCurrentChar - 26;
                        }
                        char newChar = asciiIntForCurrentChar;
                        printf("%c", newChar);
                        if (keywordPositionCounter < lengthOfKeyword - 1) {
                            keywordPositionCounter++;
                        } else {
                            keywordPositionCounter = 0;
                        }         
                    }
            }
        }
        printf("\n");
        return 0;
        }
}

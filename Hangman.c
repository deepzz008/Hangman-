#include <stdio.h>
#include <string.h>

int main() {
    char word[] = "apple";   // word to guess
    int len = strlen(word);
    char show[len + 1];
    int tries = 6;           // wrong guesses allowed
    char ch;
    int ok, i;

    // fill with underscores
    for (i = 0; i < len; i++) {
        show[i] = '_';
    }
    show[len] = '\0';

    printf("Hangman Game!\n");

    while (tries > 0 && strcmp(word, show) != 0) {
        printf("\nWord: %s\n", show);
        printf("Tries left: %d\n", tries);
        printf("Enter letter: ");
        scanf(" %c", &ch);

        ok = 0;
        for (i = 0; i < len; i++) {
            if (word[i] == ch && show[i] == '_') {
                show[i] = ch;
                ok = 1;
            }
        }

        if (!ok) {
            tries--;
            printf("Wrong!\n");
        } else {
            printf("Correct!\n");
        }
    }

    if (strcmp(word, show) == 0) {
        printf("\nYou win! Word: %s\n", word);
    } else {
        printf("\nYou lose! Word was: %s\n", word);
    }

    return 0;
}
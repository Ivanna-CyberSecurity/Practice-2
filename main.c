#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); 
    int bet;
    int length;
    int win = 0;

    printf("Введіть вашу ставку: ");
    scanf("%d", &bet);

    printf("Введіть довжину послідовності цифр: ");
    scanf("%d", &length);

    int sequence[length];
    int i;

    for (i = 0; i < length; i++) {
        sequence[i] = rand() % 10;
        printf("%d ", sequence[i]);
    }
    printf("\n");

    int seven_count = 0;
    int same_count = 0;

    for (i = 0; i < length; i++) {
        if (sequence[i] == 7) {
            seven_count++;
        }

        int j;
        for (j = i + 1; j < length; j++) {
            if (sequence[i] == sequence[j]) {
                same_count++;
            }
        }
    }

    if (seven_count > 0) {
        win += bet;
    }

    if (same_count > 0) {
        win += bet;
    }

    if (same_count >= length / 3) {
        win += bet;
    }

    printf("Ваш виграш: %d\n", win);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int diceRoll = 0;
    srand((unsigned int)time(NULL));
    printf("Rolling a die...\n");
    diceRoll = (rand() % 6) + 1;
    printf("You rolled a %d!\n", diceRoll);
    return 0;
}
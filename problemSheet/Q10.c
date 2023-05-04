//number guess between 1 and 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int n = rand() % 100 + 1, guess;
    do 
    {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &guess);
        if (guess > n) printf("Too high!\n");
        else if (guess < n) printf("Too low!\n");
        else printf("Correct!\n");
    } 
    while (guess != n);

}
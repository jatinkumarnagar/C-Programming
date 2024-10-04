#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    // Initialize random number generator
    srand(time(0));

    // Generate random number between 1 and 100
    int randomNumber = (rand() % 10) + 1;
    int no_of_guesses = 0;
    int guessed;

    // Print the random number
    // printf("Random Number %d\n", randomNumber);

    do
    {

        printf("Guess the number: ");
        scanf("%d", &guessed);
        if (guessed>randomNumber)
        {
            printf("Lower Number Please!\n");
        }
        else if(guessed<randomNumber){
            printf("Higher Number Please!\n");
        }
        else{
            printf("Congrats!! You Won!\n");
        }
        
        no_of_guesses++;

    } while (guessed != randomNumber);

    printf("You guessed the number in %d guesses", no_of_guesses);

    return 0;
}
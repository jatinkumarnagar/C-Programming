#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    int player, computer;
    char playAgain;

    do {
        computer = rand() % 3;

        /*
           0 --> Snake
           1 --> Water
           2 --> Gun
        */

        printf("Choose 0 for Snake, 1 for Water, and 2 for Gun: ");
        scanf("%d", &player);

        // Check if the input is valid
        if (player < 0 || player > 2) {
            printf("Invalid choice! Please choose 0, 1, or 2.\n");
            continue; // Skip to the next iteration of the loop
        }

        printf("Computer chose: %d\n", computer);

        // Determine the outcome of the game
        if (player == computer) {
            printf("It's a Draw!\n");
        } else if ((player == 0 && computer == 1) || 
                   (player == 1 && computer == 2) || 
                   (player == 2 && computer == 0)) {
            printf("You Won!!!\n");
        } else {
            printf("You Lost!!!\n");
        }

        // Ask if the player wants to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");

    return 0;
}

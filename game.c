#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int players, turns;
    int i, j;
    
    // Seed random number generator
    srand(time(0));
    
    printf("Enter the number of players: ");
    scanf("%d", &players);
    
    printf("Enter the number of turns per player: ");
    scanf("%d", &turns);
    
    int score[players];
    
    // Initialize all scores to 0
    for (i = 0; i < players; i++) {
        score[i] = 0;
    }

    // Simulate the game
    for (i = 0; i < players; i++) {
        printf("\nPlayer %d:\n", i + 1);
        for (j = 0; j < turns; j++) {
            int die = (rand() % 6) + 1; // Generate random number 1–6
            printf(" Turn %d: Rolled %d\n", j + 1, die);
            score[i] += die;
        }
        printf(" Total score for Player %d: %d\n", i + 1, score[i]);
    }

    // Find the winner
    int winner = 0;
    for (i = 1; i < players; i++) {
        if (score[i] > score[winner]) {
            winner = i;
        }
    }

    printf("\nFinal Scores:\n");
    for (i = 0; i < players; i++) {
        printf(" Player %d: %d\n", i + 1, score[i]);
    }

    printf("\n🏆 Winner: Player %d with %d points! 🏆\n", winner + 1, score[winner]);

    return 0;
}
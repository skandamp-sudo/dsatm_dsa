#include <stdio.h>
#include <string.h>

// Define structure for Movie
struct Movie {
    char title[100], genre[50], actor[50], actress[50];
    float rating;
};

// Helper function to prompt user and read a line of text
void get_string(const char* prompt, char* buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
}

int main() {
    int n, i;
    printf("Enter the number of movies to store: ");
    scanf("%d", &n);
    getchar(); // Consume newline left by scanf

    struct Movie movies[n]; // Array of structures

    // Input movie details using the helper function
    for (i = 0; i < n; i++) {
        printf("\n--- Enter details of Movie %d ---\n", i + 1);
        get_string("Enter Title: ", movies[i].title, 100);
        get_string("Enter Genre: ", movies[i].genre, 50);
        get_string("Enter Actor: ", movies[i].actor, 50);
        get_string("Enter Actress: ", movies[i].actress, 50);
        printf("Enter Rating (out of 10): ");
        scanf("%f", &movies[i].rating);
        getchar(); // Consume newline
    }

    // Display all movie details
    printf("\n=========== Movie Database ===========\n");
    for (i = 0; i < n; i++) {
        // Consolidate all output into a single printf statement
        printf("\nMovie %d:\n Title  : %s\n Genre  : %s\n Actor  : %s\n Actress: %s\n Rating : %.1f/10\n",
               i + 1, movies[i].title, movies[i].genre, movies[i].actor, movies[i].actress, movies[i].rating);
    }
    return 0;
}
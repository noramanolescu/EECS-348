#include <stdio.h>

int main()
{
    char* plays[] = {"TD", "FG", "Safety", "TD + 2pt", "TD + FG"}; // array for types of plays 
    int points[] = {6, 3, 2, 8, 7}; // array for number of points (indices corresponding to array for plays)
    
    // user input for the score
    int score; 
    printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
    scanf("%d", &score);
    
    // function to print combination of plays 
    void print_score(int a, int b, int c, int d, int e, char* plays[]) {
        printf("%d %s, %d %s, %d %s, %d %s, %d %s\n", 
        a, plays[0], b, plays[1], c, plays[2], 
        d, plays[3], e, plays[4]);
    }
    
    // function returning the amount of points based on given number of plays 
    int find_score(int a, int b, int c, int d, int e, int points[]) {
        return (a*points[0]) + (b*points[1]) + (c*points[2]) + (d*points[3]) + (e*points[4]);
    }
    
    // while loop for prompting the user for a score until 0 or 1 is entered 
    while (score > 1) {
    int i, j, k, l, m;
    for (i=0; i<score; i++) {
        for (j=0; j<score; j++) {
            for (k=0; k<score; k++) {
                for (l=0; l<score; l++) {
                    for (m=0; m<score; m++) {
                        if (find_score(i, j, k, l, m, points) == score) {
                            print_score(i, j, k, l, m, plays);
                        } else {
                            continue;
                        }
    }
    }
    }
    }
    }
    // prompt user for a score again
    printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
    scanf("%d", &score);
    }

    return 0;
}
#include <stdio.h>

void find_combinations(int score, int td_2pt, int td_fg, int td, int fg, int safety) {
    // prints the current possible score combination
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2pt, td_fg, td, fg, safety);
}

void generate_combinations(int score) {
    // nested loop to iterate through all possible combinations of the scoring plays
    for (int td_2pt = 0; td_2pt <= score / 8; ++td_2pt) {
        for (int td_fg = 0; td_fg <= (score - td_2pt * 8) / 7; ++td_fg) {
            for (int td = 0; td <= (score - td_2pt * 8 - td_fg * 7) / 6; ++td) {
                for (int fg = 0; fg <= (score - td_2pt * 8 - td_fg * 7 - td * 6) / 3; ++fg) {
                    for (int safety = 0; safety <= (score - td_2pt * 8 - td_fg * 7 - td * 6 - fg * 3) / 2; ++safety) {
                        // Check if the current combination adds up to the score
                        if (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                            find_combinations(score, td_2pt, td_fg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        
        // checks for int
        if (scanf("%d", &score) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n');  // clear input buffer; code kept running and crashed
            continue;
        }

        // stops the loop
        if (score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n\n", score);
        generate_combinations(score);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIECES 100
#define MAX_LINE 100
#define MAX_ROD_LENGTH 10000

typedef struct {
    int length;
    int value;
} rod_piece;


void read_input(rod_piece pieces[], int *num_pieces);
int rod_cutting(int rod_length, rod_piece pieces[], int num_pieces, int cuts[]);
void print_output(int rod_length, rod_piece pieces[], int num_pieces, int cuts[], int max_value);


int main(int argc,char *argv[] ) {
    // Check for the correct number of arguments
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <rod_length>\n", argv[0]);
        printf("Add the rod length as an argument\n");
        exit(1);
    }

    // Check for the correct rod length
    int rod_length = atoi(argv[1]);
    if (rod_length <= 0 || rod_length > MAX_ROD_LENGTH) {
        fprintf(stderr, "Rod length must be between 1 and %d\n", MAX_ROD_LENGTH);
        exit(1);
    }

    rod_piece pieces[MAX_PIECES];
    int num_pieces = 0;

    read_input(pieces, &num_pieces);

    int cuts[MAX_PIECES] = {0};
    int max_value = rod_cutting(rod_length, pieces, num_pieces, cuts);

    print_output(rod_length, pieces, num_pieces, cuts, max_value);

    return 0;
}

//Read the list of piece prices from standard input. Each line has the format "<length>, <value>" where both are integers. 
void read_input(rod_piece pieces[], int *num_pieces) {
    *num_pieces = 0;
    char line[MAX_LINE];
    int length;
    int value;

    while(fgets(line, sizeof(line), stdin) != NULL) {
        if(sscanf_s(line, "%d, %d", &length, &value) == 2) {
            pieces[*num_pieces].length = length;
            pieces[*num_pieces].value = value;
            (*num_pieces)++;
        }
    }
}

int rod_cutting(int rod_length, rod_piece pieces[], int num_pieces, int cuts[]){
    int dp[MAX_ROD_LENGTH + 1] = {0};
    int choice[MAX_ROD_LENGTH + 1] = {0};

    // calculate the maximum value for each length
    for (int i = 1; i <= rod_length; i++) {
        for (int j = 0; j < num_pieces; j++) {
            if (pieces[j].length <= i) {
                int new_value = dp[i - pieces[j].length] + pieces[j].value;
                if (new_value > dp[i]) {
                    dp[i] = new_value;
                    choice[i] = j;
                }
            }
        }
    }

    // calculate the cuts
    int remaining_length = rod_length;
    while (remaining_length > 0 && choice[remaining_length] != 0) {
        int index = choice[remaining_length];
        cuts[index]++;
        remaining_length -= pieces[index].length;
    }
    return dp[rod_length];
}

// Output: Write the cutting lists and remainder to standard out. The format for each line is "<n> @ <size> = <total value>" 
void print_output(int rod_length, rod_piece pieces[], int num_pieces, int cuts[], int max_value) {
    for(int i = 0; i < num_pieces; i++) {
        printf("%d @ %d = %d\n", cuts[i], pieces[i].length, pieces[i].value);
    }

    int total_cut_length = 0;
    for(int i = 0; i < num_pieces; i++) {
        total_cut_length += cuts[i] * pieces[i].length;
    }

    int remainder = rod_length - total_cut_length;
    printf("Remainder: %d\n", remainder);
    printf("Value: %d\n", max_value);
}

/*
* Student ID: 201275442
* Student Name: Jabraan Altaf
* Email: sgjaltaf@student.liverpool.ac.uk
*
* User: sgjaltaf
*
* Problem ID: 1081
* RunID: 34151
* Result: Accepted
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* Function prototypes */
bool gameRules(int num, bool alive);
bool ** initial(int row, int col);
int numNeighbors(bool ** prev, int rl, int cl, int row, int cols);
bool ** nextConfig(bool ** prev, int row, int col);
void output(int rows, int cols, bool ** config);

/* Main Function */
int main() {
  int rows;
  int cols;
  int sims;
  bool ** config;
  // Getting the input for the number of rows, columns and simulations
  scanf("%d %d %d", &rows, &cols, &sims);
  // Constructing an initial function board and iterating simulations on this board to get a final configuration according to Game Of Life rules
  config = initial(rows, cols);
  for (int i = 0; i < sims; i++) {
    config = nextConfig(config, rows, cols);
  }
// Calling output function
  output(rows, cols, config);

  return 0;
}

/* Function which takes in an initial configuration, via the user, as a 2D character array and converts it into a 2D boolean array */
bool ** initial(int row, int col) {
  char ** userConfig;
  bool ** config;
// Dynamically allocating memory to hold the 2D array from the user
  userConfig = malloc(row * sizeof(char * ));
  for (int i = 0; i < row; i++) {
    userConfig[i] = malloc(col * sizeof(char));
  }
// Taking in the character input from the user and placing it in the character array
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      scanf(" %c", & userConfig[i][j]);
    }
  }
// Dynamically allocating memory for a 2D boolean array
  config = malloc(row * sizeof(bool * ));
  for (int i = 0; i < row; i++) {
    config[i] = malloc(col * sizeof(bool));
  }
// Converting character array to boolean array where if there is 'X' value (alive), the boolean array places true in that corresponding position
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (userConfig[i][j] == 'X') {
        config[i][j] = true;
      } else {
        config[i][j] = false;
      }
    }
    free(userConfig[i]);//deallocating memory from the user's char array
  }
  free(userConfig);

  return config;
}

/* Function which returns the next configuration of the Game Of Life */
bool ** nextConfig(bool ** prev, int row, int col) {
  bool ** config;
  int num;
// Dynamically allocating a 2D boolean array which holds the configuration of the game board
  config = malloc(row * sizeof(bool * ));
  for (int i = 0; i < row; i++) {
    config[i] = malloc(col * sizeof(bool));
  }
// Initializing configuration to have all false values
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      config[i][j] = false;
    }
  }
// Iterating through the previous configuration to count number of neighbors, and place a true value at a spot on the board if the game rules returns true
  for (int r = 0; r < row; r++) {
    for (int c = 0; c < col; c++) {
      num = numNeighbors(prev, row, col, r, c);
      if (gameRules(num, prev[r][c])) {
        config[r][c] = true;
      }
    }
  }
// Deallocating memory from the previous configuration
  for (int i = 0; i < row; i++) {
    free(prev[i]);
  }
  free(prev);

  return config;

}

/* Function which returns whether a cell is alive or not in accordance to current state and number of neighbors */
bool gameRules(int num, bool alive) {
  if (alive && (num == 2 || num == 3)){
    return true;
  }
  else if (!alive && num == 3){
    return true;
  }
  else{
    return false;
  }
}

/* Function which returns the number of alive neighbors a specific cell has */
int numNeighbors(bool ** prev, int rl, int cl, int row, int cols) {
// Number of neighbors starts at -1 if cell is already alive and 0 if it's dead
  int num = prev[row][cols] ? -1 : 0;
// Iterating through nearby cells to count if there are any alive neighbors
  for (int r = row - 1; r <= row + 1; r++) {
    for (int c = cols - 1; c <= cols + 1; c++) {
      if (r >= 0 && r < rl && c >= 0 && c < cl && prev[r][c]) {
        num++;
      }
    }
  }

  return num;

}

/* Function which iterates through the configuration array and prints 'X' when cell is alive (true) and dot when cell is dead (false) */
void output(int rows, int cols, bool ** config) {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (config[r][c]) {
        printf("X");
      } else {
        printf(".");
      }
    }
    puts(""); // Ensures correct format of output, i.e. row after row
  }
// Deallocating the configuration to save memory
  for (int i = 0; i < rows; i++) {
    free(config[i]);
  }
  free(config);
}

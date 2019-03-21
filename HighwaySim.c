/*
* Student ID: 201275442
* Student Name: Jabraan Altaf
* Email: sgjaltaf@student.liverpool.ac.uk
*
* User: sgjaltaf
*
* Problem ID: 1084
* RunID: 34144
* Result: Accepted
*/
#include <stdio.h>
#include <stdlib.h>
/* Function prototypes */
void simulation(int timeSteps, int pairs, int numRows, int numCols, int position[pairs], char ** lanes, int arrival[timeSteps], int rowIndex[timeSteps]);
char **makeLanes (int numRows, int numCols);
void output(int numRows, int numCols, char ** lanes);

/* Main Function */
int main() {
//Initializing variables
  char ** lanes;
  int numRows;
  int numCols;
  int timeSteps;
  int pairs = 0;
  int pos = 0;
// Getting user input for rows columns and time steps
  scanf("%d%d%d\n", & numRows, & numCols, & timeSteps);
// Initializing array for arrival times and row indexes
  int arrival[timeSteps];
  int rowIndex[timeSteps];
// Taking in user input for arrival times and row index until there is an EOF input
  while (scanf("%d %d", & arrival[pos], & rowIndex[pos]) == 2) {
    pos++; // Incrementing position of both arrays
    pairs++; // Incrementing counter which counts number of time step and row index pairs by user
  }
// Initializing an array,which holds position of where there is a match in time steps of user input and current time steps, with -1 values
  int position[pairs];
  for (int i = 0; i < pairs; i++) {
    position[i] = -1;
  }
  lanes = makeLanes(numRows, numCols);
  simulation(timeSteps, pairs, numRows, numCols, position, lanes, arrival, rowIndex);
  output(numRows, numCols, lanes);

  return 0;
}

/* Function which returns a 2D character array which will represent the lanes for the highway */
char **makeLanes (int numRows, int numCols) {
  char **lanes;
// Dynamically allocating the 2D lanes array
  lanes = malloc(numRows * sizeof(char * ));
  for (int i = 0; i < numRows; i++) {
    lanes[i] = malloc(numCols * sizeof(char));
  }
// Initializing the lanes array with dot(represents empty space on the lane)
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      lanes[i][j] = '.';
    }
  }
  return lanes;
}

/* Function which simulates the movement and arrival of vehicles on highway lanes */
void simulation(int timeSteps, int pairs, int numRows, int numCols, int position[pairs], char ** lanes, int arrival[timeSteps], int rowIndex[timeSteps]) {
  int matches = 0;
  int count = 0;
  int r, c;
  for (int t = 0; t < timeSteps; t++) {
    matches = 0;
// Checking if the current time step matches a time step in the position array
    for (int i = 0; i < pairs; i++) {
      if (count == arrival[i]) {
        matches++;
        position[i] = i; // At which positions did we find these matches
      }
    }
// Movement Step - shift elements to the right
    for (int rowI = 0; rowI < numRows; rowI++) {
      for (int index = numCols - 2; index >= 0; index--) {
        lanes[rowI][index + 1] = lanes[rowI][index];
      }
    }
// Making sure that each lane's first element is free so that a vehicle can arrive in the future
    for (int i = 0; i < numRows; i++) {
      lanes[i][0] = '.';
    }
// Arrival step - finding corresponding row value and placing an X (vehicle) in that row
    for (int i = 0; i < pairs; i++) {
      if (position[i] != -1 && matches > 0) {
        r = position[i];
        c = rowIndex[r];
        lanes[c][0] = '1';
      }
    }
    count++;
// Re-initializes position array so there is no conflicts in positions at a different time step
    for (int i = 0; i < pairs; i++) {
      position[i] = -1;
    }
  }
}

/* Function which prints out the final configuration of the car lanes after the number of time steps entered by the user. */
void output(int numRows, int numCols, char ** lanes) {
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      printf("%c", lanes[i][j]);
    }
    puts(""); // Used to format the output to match the car rows
  }
// Deallocating memory from the lanes array
  for (int i = 0; i < numRows; i++) {
    free(lanes[i]);
  }
  free(lanes);
}

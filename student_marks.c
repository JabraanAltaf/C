#include <stdio.h>

int main()
{
	// Declaring variables
    int greater = 0; // For marks >= 85
    int middle = 0;	// For marks >= 60 and <= 84
    int smaller = 0; // For marks < 60
    int i;

    //Calling functions to get the marks and the results
    getMarks(i, &smaller, &middle, &greater);
    getResults(smaller, middle, greater);

    return 0;
}

// Function which loops to gets the user's marks (ends if value is 0) and increments the counter for a grade interval
void getMarks(int i, int *smaller, int *middle, int *greater){
     while(1){
        scanf("%d", &i);
        if (i < 60 && i > 0){
            (*smaller)++; // Incrementing value at the pointer
        }
        else if (i >= 60 && i<= 84){
            (*middle)++;
        }

        else if (i >= 85){
            (*greater)++;
        }
    // Ending input if value is 0
        if (i == 0){
            break;
        }
    }
}

// Function which prints out details about the marks
void getResults(int smaller, int middle, int greater) {
        printf(">=85:%d\n60-84:%d\n<60:%d", greater,middle,smaller);
}

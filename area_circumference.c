#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14
int main(){
    // Declaring variables
    int r1, r2;
    float sumArea = 0.0;
    float sumCircumference = 0.0;

    // Getting input of two radius and ensuring that the first input is less than the second
    scanf("%d %d", &r1, &r2);
    if (r1 > r2) {
        exit(0); // Quits the program
    }

    // Calling function to get the sum of the Areas and Circumferences and printing out their values;
    calculations(r1,r2,&sumArea,&sumCircumference);
    printf("%.3f\n%.3f", sumArea, sumCircumference);

    return 0;
}

// Function which calculates the sum of the area and circumference for two radius values
void calculations(int r1, int r2, float *sumArea, float *sumCircumference) {
    float area = 0.0;
    float circumference = 0.0;

    // Iterating from the smaller to larger radius and keeping a sum of the area and circumference of the circles
    for (r1; r1 <= r2; r1++){
        area = (pow(r1, 2) * PI) + area;
        circumference = (2 * PI * r1) + circumference;
    }

    // Pointing the sumArea to the value of area and sumCircumference to the value of circumference
    *sumArea = area;
    *sumCircumference = circumference;
}

#include <stdio.h>
#include <math.h>

// Function prototype
int calc_decimalVal(int a, int b, int n);

int main() {
    int a, b, n, decimalVal;

    // Getting input for the 3 numbers; calling the function and printing out the n-th digit.
    scanf("%d %d %d", &a, &b, &n);
    decimalVal = calc_decimalVal(a,b,n);
    printf("%d", decimalVal);

    return 0;
}

// Function which calculates the nth digit after the decimal point of operation a/b.
int calc_decimalVal(int a, int b, int n) {
    int decimalVal;
    float division, fullDecimal;

    division = (float)a/b; // Casting the division of a/b in to a float value
    fullDecimal = division * pow(10, n); // Multiplying by 10^n so that the n-th digit is before the decimal point
    decimalVal = (int)fullDecimal % 10; // Casting operation to integer and using the modulus of 10 to find the remainder value

    return decimalVal;
}

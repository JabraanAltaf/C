// Program which works out the lowest common multiple of two numbers by first working out the highest common factor
#include <stdio.h>

int main()
{
    int i = 1; // Start with zero because can't
    int num1, num2, hcf, lcm;

    scanf("%d %d", &num1, &num2);

	// Finding the highest common factor
    while(i<=num1 || i<=num2)
      {
            if(num1%i==0 && num2%i==0) {
                  hcf=i;
            }
            i++;
      }

    /* LCM = (Product of numbers/HCF)*/

    lcm = num1 * num2/hcf;
    printf("HCF: %d", hcf);
    printf("LCM: %d", lcm);

    //

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num;
    // Using a while loop to keep printing out integers as characters, until there is an EOF input.
    while(scanf("%d",&num) == 1){
        printf("%c",num);
    }
    return 0;
}


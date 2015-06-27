#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    int inCents, coinCount, a, b, c, i, j, k;
    
    float changeOwed;
    
    

    do
    {
    printf("How much change do I owe you? ");
    changeOwed = GetFloat();
    
    }
    while (changeOwed < 0);
    {
        inCents = round(((changeOwed)*100.0));
       
    }
    
    a = (inCents % 25);
    i = ((inCents - a)/25);
    b = (a % 10);
    j = (a - b)/10;
    c = (b % 5);
    k = (b - c)/5;
    coinCount = i + j + k + c;
    
    printf("%d\n", coinCount);
    
    return 0;

}

// Greedy Algorithm
// Prompts the min denomination of coins for the change

#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    float bal = 0;
    // a = 25 cents
    // b = 10 cents
    // c = 5 cents
    // d = 1 cents
    int a = 0, b = 0, c = 0, d = 0;   
    
    // Get the change owed to the customer
    // Repeat until a valid positive number is entered    
    do
    {
        bal = get_float("Change owed: ");               
    } 
    while (bal < 0);
   
    // Convert dollars into cents
    // For example: if change = 9.75 then cents = 975.00
    
    bal = round(bal * 100);    
    //printf("Balance: %f\n", bal);
   
    // Calculate the number of 25c, 10c, 5c and 1c coins to be given
    
    if (bal > 0)
    {       
        while ( bal >= 25)
        {
            bal = bal - 25;
            a++;
        }
          
        while (bal >= 10)
        {
            bal = bal - 10;
            b++;
        }
           
        while (bal >= 5)
        {
            bal = bal - 5;
            c++;
        }
           
        while (bal >= 1)
        {
            bal = bal - 1;
            d++;
        }
    }
    
    int total = a + b + c + d;
    printf("%i\n", total);                            
}


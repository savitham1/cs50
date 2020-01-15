// This program checks if the entered card is a VISA, AMEX, MasterCard or INVALID.

#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{    
    unsigned long long int num = 0, b = 0, c = 0, temp_val = 0;
    
    // Number of digits entered
    int count = 0;     
    unsigned long long int d = 0; 
    long int sum = 0;
    int fsum = 0;
    int fdig = 0;
    int v_fdig = 0;
    
    num = get_long("Number: ");
    
    // Temp variable 'val' is storing the value of n
    temp_val = num;
    //printf("\nval: %llu\n", temp_val);
    
    // Count the number of digits entered
    while (num != 0)
    {
        count++;
        num = num / 10;              
    }    
    
    // Reassign the card number to the variable num
    num = temp_val;
    
    // Seperate the digits based on their positions
    for (int i = 0; i < count; i++)
    {  
        b = num % 10;
        num = num / 10;
        
        //printf("i = %i ; b = %llu ; n: %llu\n", i, b, num);
        // Stores first two digits of the card in 'fdig' to verify AMEX and MASTER card
        // Stores the first digit in v_fdig for VISA card verification
        if (i == count - 3)
        {
            fdig = num;
            v_fdig = fdig / 10;
        }       
        
        // Sum of the digits that aren't multiplied by 2
        if (i % 2 == 0)
        {
            sum = sum + b;
        }       
        else 
        {
            // Multiplying every other digit of the card number by 2           
            c = b * 2;
            
            // Add the products' digits
            while (c != 0)
            {
                d = d + c % 10;   
                c = c / 10;
            }
        } 
        // printf("sum = %li ; d = %llu ; c: %llu\n", sum, d, c);        
    } 
    
    // printf("Sum: %li and d: %llu\n", sum, d);
    fsum = sum + d;
    
    // printf("Final Sum: %i\n First two digits: %i", fsum, fdig );
    fsum = fsum % 10;
    if (fsum == 0 && count >= 13)
    {
        if (fdig == 34 || fdig == 37)
        {
            printf("AMEX\n");           
        }
        
        else if (fdig >= 51 && fdig <= 55)
        {
            printf("MASTERCARD\n");
        }
            
        else if (v_fdig == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        
        else       
        {            
            printf("INVALID\n");        
        }                 
    }        
    else       
    {        
        printf("INVALID\n");        
    }  
}


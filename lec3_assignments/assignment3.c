/*Write a c program that draw a pyramid of
stars with height entered by the user*/


#include <stdio.h>
void main()
{
	int row;
	printf(" plz enter number of raws : ");
	scanf("%d",&row);
	
	for (int i =1; i <= row; i++)  
    {  
        for (int j = 1; j <= row - i; j++)  
        {  
            printf ("  ");   
        }  
		 for (int k = 1; k <= ( 2 * i - 1); k++)  
        {  
            printf ("* "); // print the Star  
        }  
        printf ("\n");  
    }  
}
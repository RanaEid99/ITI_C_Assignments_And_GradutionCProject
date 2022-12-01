#include <stdio.h>
//Write a code that can draw this pyramid
void main()
{
	int row, col;
	printf(" plz enter number of raws : ");
	scanf("%d",&row);
	printf(" plz enter number of coloums : ");
	scanf("%d",&col);
	
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
/*Write a C program that ask the user to
enter two numbers and print their
summation, this program should never
ends until the user close the window*/

#include <stdio.h>
void main()
{
	
int num1,num2,sum=0;
	for(int i=0;;i++)
	{
		printf(" plz enter first number : ");
		scanf("%d",&num1);
		printf(" plz enter second number : ");
		scanf("%d",&num2);
		sum = num1+num2;
		printf(" the sum of two numbers = %d\n",sum);
		
	}
}
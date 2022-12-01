#include <stdio.h>
/*Write a code that takes 2 numbers and print their
summation, subtraction, anding, oring, and Xoring*/

void main()
{
	int num1, num2;
	printf(" plz enter number 1 : ");
	scanf("%d",&num1);
	printf(" plz enter number 2 : ");
	scanf("%d",&num2);
	
	printf(" num1 + num2 = %d\n" , num1+num2);
	printf(" num1 - num2 = %d\n" , num1-num2);
	printf(" num1 & num2 = %d\n" , num1&num2);
	printf(" num1 | num2 = %d\n" , num1|num2);
	printf(" num1 ^ num2 = %d\n" , num1^num2);
	
	
}
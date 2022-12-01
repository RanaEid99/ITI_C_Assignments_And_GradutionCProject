/*Write a code that will ask the user to enter 3
numbers, the program will print the maximum
number of them.*/
#include <stdio.h>
void main()
{
	int num1,num2,num3;
	printf(" plz enter three numbers : ");
	scanf("%d %d %d",&num1,&num2,&num3);
    /*((num1>num2) && (num1>num3))?printf("num1 is max %d",num1): \
	((num2>num1) && (num2>num3))?printf("num 2 is max %d",num2): \
	((num3>num1) && (num3>num2))?printf("num 3 is max %d",num3):printf("three numbers are the same"));*/
	
	if ((num1>num2) && (num1>num3))
		printf("num1 is max %d",num1);
	else if ((num2>num1) && (num2>num3))
		printf("num 2 is max %d",num2);
	else if ((num3>num1) && (num3>num2))
		printf("num 3 is max %d",num3);
	else
		printf("three numbers are the same");
}
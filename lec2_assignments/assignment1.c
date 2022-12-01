
/*Write a C code that ask the user to enter 10
numbers, then ask him to enter another number
to search on it in the 10 numbers and print its
location in case it is found.
In case the number is not found, it will print
number no exist*/
#include <stdio.h>
void main()
{
	int search,num1, num2,num3,num4,num5,num6,num7,num8,num9,num10;
	printf(" plz enter number 1 : ");
	scanf("%d",&num1);
	printf(" plz enter number 2 : ");
	scanf("%d",&num2);
	printf(" plz enter number 3 : ");
	scanf("%d",&num3);
	printf(" plz enter number 4 : ");
	scanf("%d",&num4);
	printf(" plz enter number 5 : ");
	scanf("%d",&num5);
	printf(" plz enter number 6 : ");
	scanf("%d",&num6);
	printf(" plz enter number 7 : ");
	scanf("%d",&num7);
	printf(" plz enter number 8 : ");
	scanf("%d",&num8);
	printf(" plz enter number 9 : ");
	scanf("%d",&num9);
	printf(" plz enter number 10 : ");
	scanf("%d",&num10);
	
	printf("Enter the value to search : ");
	scanf("%d",&search);
	
	if(search==num1)
	{
		printf("value is exist at element number 1\n");
	}
	else if(search==num2)
	{
		printf("value is exist at element number 2\n");
	}
	else if(search==num3)
	{
		printf("value is exist at element number 3\n");
	}
	else if(search==num4)
	{
		printf("value is exist at element number 4\n");
	}
	else if(search==num5)
	{
		printf("value is exist at element number 5\n");
	}
	else if(search==num6)
	{
		printf("value is exist at element number 6\n");
	}
	else if(search==num7)
	{
		printf("value is exist at element number 7\n");
	}
	else if(search==num8)
	{
		printf("value is exist at element number 8\n");
	}
	else if(search==num9)
	{
		printf("value is exist at element number 9\n");
	}else if(search==num10)
	{
		printf("value is exist at element number 10\n");
	}
	else 
	{
		printf(" number not exist\n");
	}
	
	
}






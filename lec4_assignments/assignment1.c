/*
C program the implement 2 function:

1- Function to get the maximum of 4 values
2- Function to get the minimum of 4 values

The program will ask the user first to enter the 4 values, then print the maximum
number and minimum number of them.
*/
#include <stdio.h>
void get_min (int n1,int n2,int n3,int n4);
void get_max (int n1,int n2,int n3,int n4);
void main()
{
	int num1,num2,num3,num4,max_num,min_num;
	printf(" plz enter number 1 : ");
	scanf("%d",&num1);
	printf(" plz enter number 2 : ");
	scanf("%d",&num2);
	printf(" plz enter number 3 : ");
	scanf("%d",&num3);
	printf(" plz enter number 4 : ");
	scanf("%d",&num4);
	get_max(num1,num2,num3,num4);
	printf("\n");
	get_min (num1,num2,num3,num4);
}

void get_max (int n1,int n2,int n3,int n4)
{
	if ((n1>n2) && (n1>n3) && (n1>n4))
		printf("number 1 is max %d",n1);
	else if ((n2>n1) && (n2>n3) && (n2>n4))
		printf("number 2 is max %d",n2);
	else if ((n3>n1) && (n3>n2) && (n3>n4))
		printf("number 3 is max %d",n3);
	else if ((n4>n1) && (n4>n2) && (n4>n3))
		printf("number 3 is max %d",n4);
	else
		printf("four numbers are the same");
}

void get_min (int n1,int n2,int n3,int n4)
{
	if ((n1<n2) && (n1<n3) && (n1<n4))
		printf("number 1 is min %d",n1);
	else if ((n2<n1) && (n2<n3) && (n2<n4))
		printf("number 2 is min %d",n2);
	else if ((n3<n1) && (n3<n2) && (n3<n4))
		printf("number 3 is min %d",n3);
	else if ((n4<n1) && (n4<n2) && (n4<n3))
		printf("number 3 is min %d",n4);
	else
		printf("four numbers are the same");
}
/*Write a C code that ask the user to enter 10 values and save them in an array
using a for loop. Then print the minimum and the maximum of the values.*/
#include <stdio.h>

void main()
{
	int arr[10],max,min;
	for(int i=0;i<10;i++)
	{
		printf(" plz enter number%d : ",i);
		scanf("%d",&arr[i]);
	}
	max=arr[0];
		min=arr[0];
	for(int i=0;i<10;i++)
	{
		
		if(arr[i] > max)
		{
			max=arr[i];
		}
		else if(arr[i] < min)
		{
			min=arr[i];
		}
	}
	printf(" maximum number  = %d  ,  minimum number  = %d ",max , min);
	
}
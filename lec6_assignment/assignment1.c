/*Write a C code that defines a function which takes an array as input argument and
apply the bubble sorting algorithm on it, then print the result*/
#include <stdio.h>
void bubble_sort(int *ptr);
int main()
{
    int arr[5]={4,7,1,0,3};

    bubble_sort(arr);
    for(int i=0;i<5;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}

void bubble_sort(int *ptr)
{
    int temp;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5-i-1;j++)
        {
            if(ptr[j]>ptr[j+1])
            {
                temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] =temp;
            }
        }
    }
}
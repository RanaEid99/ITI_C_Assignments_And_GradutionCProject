/*Write C code that manage a small school. The school has 3 classes each class
contains 10 students. Define three arrays for the three classes each one with a
length of 10. Save a random numbers in all array elements to indicate the
students grade. The program will calculate and display the following statistics:
1- Number of passed students
2- Number of Failed students
3- Highest grade
4- Lowest grade
5- Average grade
Knowing that the total grade is from 100 and the minimum passing grade is 50.*/

#include <stdio.h>

void main()
{
	int class1[10] = {60,55,80,40,50,70,66,49,75,65};
	int class2[10] = {83,30,20,44,98,75,55,63,72,54};
	int class3[10] = {90,58,44,42,62,51,86,33,59,64};
	int count_pass , count_fail;
	int max1=class1[0] ,max2=class2[0],max3=class3[0] , min1=class1[0] ,min2=class2[0] , min3=class3[0] ;
	int Highest_grade ,Lowest_grade,sum=0;
	float Average_grade ;
	for(int i=0;i<10;i++)
	{
		if(class1[i] >=50 )
			count_pass++;
		if(class2[i] >=50 )
			count_pass++;
		if(class3[i] >=50)
			count_pass++;
		
		if(class1[i] <=50 )
			count_fail++;
		if(class2[i] <=50 )
			count_fail++;
		if(class2[i] <=50 )
			count_fail++;
		
		if(class1[i] > max1)
		{
			max1=class1[i];
		}
		else if(class1[i] < min1)
		{
			min1=class1[i];
		}
		if(class2[i] > max2)
		{
			max2=class2[i];
		}
		else if(class2[i] < min2)
		{
			min2=class2[i];
		}
		if(class3[i] > max3)
		{
			max3=class3[i];
		}
		else if(class3[i] < min3)
		{
			min3=class3[i];
		}
		sum += class1[i]+class2[i]+class3[i];
	}
	Average_grade= sum/30;
	if( (max1>max2) && (max1>max3))
	{
		Highest_grade = max1;
	}else if((max2>max1) && (max2>max3)){
		Highest_grade = max2;
	}else
		Highest_grade = max3;
	
	if((min1<min2) && (min1<min3))
		Lowest_grade = min1;
	else if((min2<min1) && (min2<min3))
		Lowest_grade = min2;
	else 
		Lowest_grade = min3;
	
	printf(" Number of passed students : %d\n",count_pass);
	printf(" Number of Failed students : %d\n",count_fail);
	printf(" Highest grade student : %d\n",Highest_grade);
	printf(" Lowest grade student : %d\n",Lowest_grade);
	printf(" Average grade : %f" , Average_grade);
	
}
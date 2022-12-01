/*Write a login program in C that ask the
user to enter his ID and his password, if
the ID is correct the system will ask the
user to enter his password up to 3 times,
if he enters the password right the
systems welcomes him, if the three times
are incorrect, the system print No more
tries. If the user ID is incorrect the
system print You are not registered*/


#include <stdio.h>
void main()
{
	int id,i=2,password;
	printf(" plz enter your ID : ");
	scanf("%d",&id);
	if ((id != 1234)&&(id != 5678)&&(id != 9870))
	{
		printf(" You are not registered\n");
	}
	else if (id == 1234)
	{
		printf(" plz enter your password : ");
	    scanf("%d",&password);
		if (password==7788)
			printf(" Welcome Ahmed");
		else{
		while((password!=7788)&&(i!=0))
		{
			printf(" try again  ");
	        scanf("%d",&password);
			if (password==7788)
			{printf(" Welcome Ahmed"); break;}
			i--;
		}
			if (i==0) printf(" Incorrect password for 3 times. No more tries ");
		}
	}
}
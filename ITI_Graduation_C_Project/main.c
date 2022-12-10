#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>  ////this to include file,color and cls functions to make the application easy to use
#include <time.h>
#include "STD_Types.h"  
#include "admin.h"
#include "client.h"

void main()
{
	while(1)
	{
		// program runs continously until user exit it or enter wrong choice.
		
		system("color 6");  // change color in cmd       
		u8 choice, select;  // declare variables
		printf("\n\t\t-------------------->>Bank Management System<<------------------------\n");
		printf("\t*-------------------------------------------------------------------------------------*\n");
		printf("\t\t[1].Admin Window.\n \
               [2].Client Window\n. \
		[3].Exit_system.\n"); // print differente modes to select one at least
		printf("    Enter your choice : ");
		scanf("%d",&choice);   // get selection from user
		
		// Admin window opens when user enter 1 in cmd
		if (choice == 1)
    {
		printf("--------------------------------------------------------------------\n");
        printf("                    **** Admin Window ****\n");
		printf("--------------------------------------------------------------------\n");
        printf("\t\t[1]- Create_New_Account.\n \
               [2]- Open_Existing_Account.\n \
               [3]- Exit_system.\n");  //print differente modes that available to admin and he selects one at least

	    printf("  Enter your choice : ");
	    scanf("%d",&select); // get selection from user.

	    if(select==1)       {  Create_New_Account(); }
		else if(select==2)  {  Open_Existing_Account();}
		else if (select==3) {  printf("\n\t\t\t============ Thank You ===========\n");  exit(0);}
		else {printf("   Wrong Choice!!........");  break;}
		// when user enter wrong selection the program print wrong choice then terminate.
	}
	
	// Client Window opens when user enter 2 in cmd
	else if(choice == 2)
	{
		printf("--------------------------------------------------------------------\n");
		printf("                   **** Client Window ****\n");
		printf("---------------------------------------------------------------------\n");
        printf("\t\t[1]- Client_Make_Transaction.\n \
               [2]- Client_Change_Account_Password.\n \
               [3]- Client_Get_Cash.\n \
               [4]- Client_Deposit_in_Account.\n");
		//print differente modes that available to client and he selects one at least

		printf("  Enter your choice : ");
		scanf("%d",&select); // get selection from user.

		if(select ==1)        {  Client_Make_Transaction(); }
		else if (select==2)   {  Client_Change_Account_Password();}
		else if(select==3)    {  Client_Get_Cash();}
		else if(select==4)    {  Client_Deposit_in_Account();}
		else {printf(" Wrong Choice......"); break;}
		// when user enter wrong selection the program print wrong choice then terminate.
	}
	else if (choice==3) {  printf("\n\t\t\t============ Thank You ===========\n");  exit(0);}
	// program exit when user enter 3 in cmd.
	
	else{ printf("   Wrong Choice!!........");  break;}
	}

}
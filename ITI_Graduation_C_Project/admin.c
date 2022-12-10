#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "STD_Types.h"
#include "admin.h"


// function to return to main menu of Admin Window to make another function(selection).
void Admin_Window()
{
	u8 select;
    printf("  **** Admin Window ****\n");
	printf("--------------------------------------------------------------------\n");
    printf("\t\t[1]- Create_New_Account.\n \
           [2]- Open_Existing_Account.\n \
           [3]- Exit_system.\n");
	printf("  Enter your choice : ");
	scanf("%d",&select);

	if(select==1)       {  Create_New_Account(); }
	else if(select==2)  {  Open_Existing_Account();}
	else if (select==3) {printf("\n\t\t\t========= Thank You ===========\n");  exit(0);} // program exit.
	else {printf(" Wrong Choice!!......");}
}
//================================================================================================
// function for creating new account
void Create_New_Account()
{
	
    FILE *fileOne = fopen("accountInfo.txt", "a+"); //create a file to store and appened data of accounts in it 

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n"); // if file doesn't exist return error.
    }

    Account accountInformation;	// create obj from struct
    system("cls");

    printf("\t\t\t====== Create New Account ======\n");

    printf("\n\t\t\tEnter Account's Name : ");
    getchar();
    gets(accountInformation.name);  // entering name when creating a new account.
    printf("\t\t\tEnter Your Adress : ");
    scanf("%s",&accountInformation.address); // entering address when creating a new account.
	u8 check_ADD = strspn(accountInformation.address , "abcdefghijklmnoZ"); //checking address that if it equal only numbers not accepted.
	if(check_ADD == 0)
	{
		printf("\n\t\t\tAddress mustn't equal numbbers only must have a string."); exit(0); // program exit if user enter only numbers for address.
	}
    printf("\t\t\tEnter Your Age : ");
    scanf("%d",&accountInformation.age); // entering age when creating a new account.
	if(accountInformation.age < 21)      // check if age is less than 21 then must have Guardian ID. 
	{
		printf("\n\t\t\tEnter Guardian ID : ");
		scanf("%s",&accountInformation.Guardian_National_ID); // entering Guardian_National_ID when creating a new account.
		if(strlen(accountInformation.Guardian_National_ID) != 14)  // function returns the length of string passed.
		{
			printf("\n\t\t\tNational ID must be 14 numbers.");
			exit(0);
		}

	}
    printf("\n\t\t\tEnter National ID : ");
    scanf("%s",&accountInformation.National_id);  // entering National_ID when creating a new account.
	if(strlen(accountInformation.National_id)==14)   // function returns the length of string passed.
    {printf("\n\t\t\tEnter Current Account Balance : ");
    scanf("%f", &accountInformation.Balance);  // entering Balance when creating a new account.
	printf("\n\t\t\t"); Generate_Password();   // generate password random.
	printf("\n\t\t\t Enter Account ID : ");
	_flushall();
	gets(accountInformation.Account_id);
	printf("%s",accountInformation.Account_id); // entering Account ID when creating a new account.
	accountInformation.state = Active;
    fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);

    printf("\n\n\t\t\tAccount has been created sucessfully\n");
	}
	else
	{   printf("\n\t\t\tNational ID must be 14 numbers.");  exit(0);}
    fclose(fileOne); // closing file
}

//============================================================
// function for generating password automatically
void Generate_Password()
{
	u8 password[] = "1234567890qwertyuiopasdfghjklzxcvbnm!@#$^&*()_- +=QWERTYUIOPASDFGHJKLZXCVBNM':\"<>,.?";

	srand(time(NULL));
	for(u8 i = 0; i < 9; i++)
	{
		printf("%c", password[rand() % (sizeof password - 1)]); //function for generate random password
	}
}

//======================================================================
// user use this function when he has an Account.
void Open_Existing_Account()
{
	FILE *fileOne = fopen("accountInfo.txt", "r+"); // open file for reading mode and writing mode.

    Account accountInformation;
    u8 flag = 0, select;
    u8 searchAccountID[5];

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");
	printf("\t\t\t\t====== Open_Existing_Account ======\n");

    printf("\n\n\t\t\tEnter Bank Account ID : ");
    scanf("%s",&searchAccountID); // asked to enter Bank Account ID
    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.Account_id, searchAccountID) == 0) // function for comparing account ids.
        {
            flag++; // flag indicate existing accounts.
            printf("\n\t\t\tAccount Name : %s", accountInformation.name);
			printf("\n\t\t\tAccount Number : %s",accountInformation.Account_id);
			printf("\n\t\t\tAge : %d",accountInformation.age);
			printf("\n\t\t\tAddress : %s",accountInformation.address);
			printf("\n\t\t\tCurrent Account's Balance : %.2f\n", accountInformation.Balance);
			printf("------------------------------------------------------------------------------\n");
			printf("\t\t What do you want to do?\n");
			printf("\t\t[1]- Make_Transaction.\n \
	        [2]- Change_Account_Status.\n \
                [3]- Get_Cash.\n \
                [4]- Deposit_in_Account.\n \
                [5]- Return_to_main_Menu.\n");

			printf("  Enter your choice : ");
			scanf("%d",&select);
			
			if(select==1){ Make_Transaction();}
			else if (select==2){ Change_Account_Status();}
			else if(select==3) {Get_Cash();}
			else if(select==4) {Deposit_in_Account();}
			else if (select==5) {Admin_Window();}
			else {printf(" Wrong Choice......");}
        }
    }
    if (flag == 0)
    {
        printf("\n\t\t\tAccount ID is not found"); // if flag =0 Account ID is not found
    }
	 fclose(fileOne);
}
//===========================================================================
// use this function if you want to Change_Account_Status.
void Change_Account_Status()
{
	FILE *fileOne = fopen("accountInfo.txt", "r+");
    Account accountInformation;
	u8 AccountID_1[5];
	u8 new_status[11];
	u8 Status , val1 , val2 , val3, flag=0;
    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }
    system("cls");
    printf("\t\t\t\t====== Change Account Status ======\n");
	printf("\n\t\t\tEnter Account ID : ");
    scanf("%s",&AccountID_1);
	printf("\n\t\t\tEnter Account Status from Active , Restricted or Closed. ");
	printf("\n\t\t\tAccount Status : ");
	_flushall();
	gets(new_status);
	val1 = strcmp(new_status , "Active"); // compare new status with Active state.
	val2 = strcmp(new_status , "Restricted"); // compare new status with Restricted state
	val3 = strcmp(new_status , "Closed"); // compare new status with Closed state
	if(val1 == 0){     Status = 0 ;  }
	if(val2 == 0){     Status = 1 ;  }
	if(val3 == 0){	   Status = 2 ;  }

    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.Account_id, AccountID_1) == 0)
        {
			flag++;
			accountInformation.state = Status;
			printf("\t\t\t Account Status Changed. ");
            fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne); // use this function to write in file.        
        }
	}
    if (flag == 0)
    {
        printf("\n\t\t\tAccount is not found");
    }
    fclose(fileOne);
}
//===========================================================================
//function to transfer amount from existing account to another existing account
void Make_Transaction()
{
    FILE *fileOne = fopen("accountInfo.txt", "r");
    FILE *transfer = fopen("transfer.txt", "w");

    Account accountInformation, transferInformation;
	u8 AccountID_send[5];
	u8 AccountID_rec[5];
	f32 amount;
    u8 flag = 0;

    if (fileOne == NULL || transfer == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Account Transaction ======\n");
	
	printf("\n\t\t\tEnter Account ID you want to transfer money from.: ");
    scanf("%s",&AccountID_send);
	
    printf("\n\t\t\tEnter Account ID you want to transfer money to.: ");
    scanf("%s",&AccountID_rec);

    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.Account_id,AccountID_send ) == 0)
        {
            flag++;
				printf("\n\t\t\tCurrent Balance:$ %.2f", accountInformation.Balance);
                printf("\n\t\t\tEnter the amount you want to transfer: ");
                scanf("%f", &amount);
                if ((accountInformation.Balance > amount) &&(accountInformation.state == 0))
                {
					if (strcmp(accountInformation.Account_id,AccountID_rec ) == 0)
					{	
						
						accountInformation.Balance = accountInformation.Balance - amount;
						transferInformation.Balance = transferInformation.Balance + amount;
						printf("\n\t\t\tCurrent Balance after transfer: %.2f", accountInformation.Balance);

						fwrite(&accountInformation, sizeof(accountInformation), 1, transfer);
						printf("\n\n\t\t\tTransfer successfully!\n\n");
					}
                    
                }
                else
                {
					printf("\n\n\t\t\tUnsufficient Balance!\n\n");
                    fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);
					
                }

        }
		 else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);
        }
	}

    if (flag == 0)
    {
        printf("\n\t\t\tAccount is not found");
    }

    fclose(fileOne);
    fclose(transfer);

    remove("accountInfo.txt");
    rename("transfer.txt", "accountInfo.txt");
}
//===============================================================================================
// function to withdraw from account
void Get_Cash()
{
    FILE *fileOne = fopen("accountInfo.txt", "r+");
    Account accountInformation;
	u8 AccountID_w[5];
	f32 amount;
    u8 flag = 0;

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }
    system("cls");

    printf("\t\t\t\t====== Get Cash ======\n");
	printf("\n\t\t\tEnter Account ID : ");
    scanf("%s",&AccountID_w);

    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.Account_id, AccountID_w) == 0)
        {
			if((accountInformation.state == 0))
            {flag++;
				printf("\n\t\t\tCurrent Balance: %.2f", accountInformation.Balance);
                printf("\n\t\t\tEnter the amount you want to withdraw: ");
                scanf("%f", &amount);
                if (accountInformation.Balance < amount)
                {
                    printf("\n\n\t\t\tUnsufficient Balance!\n\n");
                    fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);
                }
                else
                {
                    accountInformation.Balance = accountInformation.Balance - amount;
                    printf("\n\t\t\tCurrent Balance after withdraw: %.2f", accountInformation.Balance);
					
                    fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);
                    printf("\n\n\t\t\tWithdraw successfully!\n\n");
                }
			}
        }
		 else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);
        }
	}
    if (flag == 0)
    {
        printf("\n\t\t\tAccount is not found");
    }

    fclose(fileOne);
}
//=======================================================================================
//Deposit_in_Account function

void Deposit_in_Account()
{
	FILE *fileOne = fopen("accountInfo.txt", "r");
    Account accountInformation;
	u8 AccountID_d[5];
	f32 amount;
	
	 if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");
    printf("\t\t\t\t====== Deposit in Account ======\n");

    printf("\n\t\t\tEnter Account ID : ");
    scanf("%s",&AccountID_d);

    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.Account_id,AccountID_d) == 0)
        {
			if((accountInformation.state == 0))
            {printf("\n\t\t\tCurrent Balance:$ %.2f", accountInformation.Balance);
            printf("\n\t\t\tEnter the amount you want to deposit:$ ");
            scanf("%f", &amount);
            accountInformation.Balance = accountInformation.Balance + amount;
            printf("\n\t\t\tCurrent Balance after Deposit:$ %.2f", accountInformation.Balance);

            fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);
            printf("\n\n\t\t\tDeposited successfully!\n\n");
			}
        }
		else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);
        }
 
    }
    fclose(fileOne);
}
//================================================================================

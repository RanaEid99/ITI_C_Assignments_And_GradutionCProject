#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

typedef struct Account
{
    char name[40];
    char National_id[14];
	char Guardian_National_ID[14];
    char age;
    char address[50];
    float Balance;
	char password[8];
	char Account_id[5];
	char state[6];
} Account;


// function to return to main menu
void menu()
{
	char choice, select;
	printf("\t\t[1].Admin Window.\n \
               [2].Client Window\n. ");
    printf("  Enter your choice : ");
    scanf("%d",&choice);
    if (choice == 1)
    {
        printf("  **** Admin Window ****\n");
        printf("\t\t[1]- Create_New_Account.\n \
               [2]- Open_Existing_Account.\n \
               [3]- Exit_system.\n");

	    printf("  Enter your choice : ");
	    scanf(" %d",&select);

	    if(select==1){  Create_New_Account(); }
		else if(select==2) {Open_Existing_Account();}
		else if (select==3) {/*Exit_System();*/ printf("\n\t\t\t========= Thank You ===========\n");
            exit(0);}
		else {printf(" Wrong Choice......");}
	}
    else if(choice == 2)
	{
        printf("  **** Client Window ****\n");
        printf("\t\t[1]- Make_Transaction.\n \
                [2]- Change_Account_Password.\n \
                [3]- Get_Cash.\n \
                [4]- Deposit_in_Account.\n \
                [5]- Return_to_main_Menu.\n");

		printf("  Enter your choice : ");
		scanf(" %d",&select);

		if(select =1){  Make_Transaction(); }
		else if (select==2){ Change_Account_Password();}
		else if(select==3) { Get_Cash();}
		else if(select==4) {Deposit_in_Account();}
		else if (select==5) {menu();}
		else {printf(" Wrong Choice......");}
	}
    else
	{ printf(" Wrong Choice......");}

}
//============================================================
// function for creating new account

void Create_New_Account()
{
    FILE *fileOne = fopen("accountInfo.bin", "ab+");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Account accountInformation;  // create obj from struct

    system("cls");

    printf("\t\t\t====== Create New Account ======\n");

    printf("\n\t\t\tEnter Account's Name : ");
    getchar();
    gets(accountInformation.name);
    printf("\t\t\tEnter Your Adress : ");
    gets(accountInformation.address);
    printf("\t\t\tEnter Your Age : ");
    scanf("%d",&accountInformation.age);
	if(accountInformation.age < 21)
	{
		printf("\n\t\t\tEnter Guardian ID : ");
		scanf("%d",&accountInformation.Guardian_National_ID);

	}
    printf("\n\t\t\tEnter National ID : ");
    scanf("%d",&accountInformation.National_id);
    printf("\n\t\t\tEnter Current Account Balance : ");
    scanf("%f", &accountInformation.Balance);
	Generate_Password();
	printf("\n");
	Generate_AccountID();
	accountInformation.state[6] = "active";
    fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);

    printf("\n\n\t\t\tAccount has been opened sucessfully\n");

    fclose(fileOne);
}

//============================================================
// function for generating password automatically
void Generate_Password()
{
	char password[] = "1234567890qwertyuiopasdfghjklzxcvbnm!@#$^&*()_- +=QWERTYUIOPASDFGHJKLZXCVBNM':\"<>,.?";

	srand(time(NULL));
	for(int i = 0; i < 9; i++)
	{
		printf("%c", password[rand() % (sizeof password - 1)]);
	}
}

//======================================================================

// function for generating  Bank account ID automatically
void Generate_AccountID()
{
	char ID[] = "1234567890";

	srand(time(NULL));
	for(int i = 0; i < 5; i++)
	{
		printf("%c", ID[rand() % (sizeof ID - 1)]);
	}
}
//=====================================================================
// function for opening Exist Account if you have account

void Open_Existing_Account()
{
	// asked to enter Client Bank Account ID
	FILE *fileOne = fopen("accountInfo.bin", "rb");

    Account accountInformation;

    int flag = 0, select;
    char searchAccountID[5];

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");
	printf("\t\t\t\t====== Open_Existing_Account ======\n");

    printf("\n\n\t\t\tEnter Bank Account ID : ");
    scanf("%d",&searchAccountID);
    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.Account_id, searchAccountID) == 0)
        {
            flag++;
            printf("\n\t\t\tAccount Name : %s", accountInformation.name);
			printf("\n\t\t\tAccount Number : %s",accountInformation.Account_id);
			printf("\n\t\t\tAge : %s",accountInformation.age);
			printf("\n\t\t\tAddress : %s",accountInformation.address);
			printf("\n\t\t\tCurrent Account's Balance : %.2f\n", accountInformation.Balance);
			
			printf("\t\t[1]- Make_Transaction.\n \
                [2]- Change_Account_Status.\n \
                [3]- Get_Cash.\n \
                [4]- Deposit_in_Account.\n \
                [5]- Return_to_main_Menu.\n");

			printf("  Enter your choice : ");
			scanf(" %d",&select);
			
			if(select =1){ Make_Transaction();}
			else if (select==2){/* Change_Account_Status();*/}
			else if(select==3) {Get_Cash();}
			else if(select==4) {Deposit_in_Account();}
			else if (select==5) {menu();}
			else {printf(" Wrong Choice......");}
        }
    }
    if (flag == 0)
    {
        printf("\n\t\t\tAccount ID is not found");
    }
	 fclose(fileOne);
}

//=========================================================================
//function to transfer amount from existing account to another existing account
void Make_Transaction()
{
    FILE *fileOne = fopen("accountInfo.bin", "rb");
    FILE *transfer = fopen("transfer.bin", "wb");

    Account accountInformation, transferInformation;

    int flag = 0;

    if (fileOne == NULL || transfer == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Account Transaction ======\n");

    printf("\n\t\t\tEnter Account ID you want to transfer money to.: ");
    scanf("%d",&transferInformation.Account_id);

    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.Account_id, transferInformation.Account_id) == 0)
        {
            flag++;
				printf("\n\t\t\tCurrent Balance:$ %.2f", accountInformation.Balance);
                printf("\n\t\t\tEnter the amount you want to transfer: ");
                scanf("%f", &transferInformation.Balance);
                if (accountInformation.Balance < transferInformation.Balance)
                {
                    printf("\n\n\t\t\tUnsufficient Balance!\n\n");
                    fwrite(&accountInformation, sizeof(accountInformation), 1, transfer);
                }
                else
                {
                    accountInformation.Balance -= transferInformation.Balance;
                    printf("\n\t\t\tCurrent Balance after transfer: %.2f", accountInformation.Balance);

                    fwrite(&accountInformation, sizeof(accountInformation), 1, transfer);
                    printf("\n\n\t\t\tTransfer successfully!\n\n");
                }

        }
		 else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, transfer);
        }
	}

    if (flag == 0)
    {
        printf("\n\t\t\tAccount is not found");
    }

    fclose(fileOne);
    fclose(transfer);

    remove("accountInfo.bin");
    rename("transfer.bin", "accountInfo.bin");
}
//===============================================================
// function --> exit from system
/*void Exit_System()
{
	printf("Exiting the program....\n");
    //exit(0);
}*/
//================================================================

// user window
// function to change password

void Change_Account_Password(){

	FILE *fileOne = fopen("accountInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Account accountInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Change Account Password ======\n");

    printf("\n\t\t\tEnter Account ID : ");
    getchar();
    gets(tempInformation.Account_id);

    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.Account_id, tempInformation.Account_id) == 0)
        {
            flag++;

            printf("\n\t\t\tEnter Password to Update: ");
			getchar();
            gets(tempInformation.password);
            strcpy(accountInformation.password, tempInformation.password);

            fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
            printf("\n\n\t\t\tUpdated successfully!\n\n");

        }
        else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("accountInfo.bin");
    rename("temp.bin", "accountInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tAccount is not found");
    }
}

//=====================================================================================
//Deposit_in_Account function

void Deposit_in_Account()
{
	
	FILE *fileOne = fopen("accountInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Account accountInformation, tempInformation;
	
	 if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Deposit in Account ======\n");

    printf("\n\t\t\tEnter Account ID : ");
    getchar();
    gets(tempInformation.Account_id);

    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.Account_id, tempInformation.Account_id) == 0)
        {
            printf("\n\t\t\tCurrent Balance:$ %.2f", accountInformation.Balance);
            printf("\n\t\t\tEnter the amount you want to deposit:$ ");
            scanf("%f", &tempInformation.Balance);
            accountInformation.Balance += tempInformation.Balance;
            printf("\n\t\t\tCurrent Balance after Deposit:$ %.2f", accountInformation.Balance);

            fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
            printf("\n\n\t\t\tDeposited successfully!\n\n");
        }
		else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, temp);
        }
 
    }
    fclose(fileOne);
    fclose(temp);

    remove("accountInfo.bin");
    rename("temp.bin", "accountInfo.bin");
}
//===========================================================================================
// function to withdraw from account
void Get_Cash()
{
    FILE *fileOne = fopen("accountInfo.bin", "rb");
    FILE *cash = fopen("cash.bin", "wb");

    Account accountInformation, cashInformation;

    int flag = 0;

    if (fileOne == NULL || cash == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Get Cash ======\n");
	printf("\n\t\t\tEnter Account ID : ");
    scanf("%d",&cashInformation.Account_id);

    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.Account_id, cashInformation.Account_id) == 0)
        {
            flag++;
				printf("\n\t\t\tCurrent Balance:$ %.2f", accountInformation.Balance);
                printf("\n\t\t\tEnter the amount you want to withdraw: ");
                scanf("%f", &cashInformation.Balance);
                if (accountInformation.Balance < cashInformation.Balance)
                {
                    printf("\n\n\t\t\tUnsufficient Balance!\n\n");
                    fwrite(&accountInformation, sizeof(accountInformation), 1, cash);
                }
                else
                {
                    accountInformation.Balance -= cashInformation.Balance;
                    printf("\n\t\t\tCurrent Balance after withdraw: %.2f", accountInformation.Balance);

                    fwrite(&accountInformation, sizeof(accountInformation), 1, cash);
                    printf("\n\n\t\t\tWithdraw successfully!\n\n");
                }

        }
		 else
        {
            fwrite(&accountInformation, sizeof(accountInformation), 1, cash);
        }
	}

    if (flag == 0)
    {
        printf("\n\t\t\tAccount is not found");
    }

    fclose(fileOne);
    fclose(cash);

    remove("accountInfo.bin");
    rename("cash.bin", "accountInfo.bin");
}
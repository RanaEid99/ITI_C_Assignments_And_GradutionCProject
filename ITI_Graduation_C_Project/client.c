#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "STD_Types.h"
#include "admin.h"
#include "client.h"


//function to transfer amount from existing account to another existing account
void Client_Make_Transaction()
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

    //remove("accountInfo.txt");
    //rename("transfer.txt", "accountInfo.txt");
}
//===============================================================================================

// function to change password

void Client_Change_Account_Password(){

	FILE *fileOne = fopen("accountInfo.txt", "r");
    Account accountInformation;
	u8 AccountID_2[5] , new_password[8];
    u8 flag = 0;

    if (fileOne == NULL){	printf("\n\t\t\tError !\n");	}

    system("cls");
    printf("\t\t\t\t====== Change Account Password ======\n");

    printf("\n\t\t\tEnter Account ID : ");
    scanf("%s",&AccountID_2);
    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.Account_id,AccountID_2) == 0)
        {
            flag++;
            printf("\n\t\t\tEnter Password to Update: ");
			_flushall();
            gets(new_password);
            strcpy(accountInformation.password,new_password);

            fwrite(&accountInformation, sizeof(accountInformation), 1, fileOne);
            printf("\n\n\t\t\tUpdated Password Successfully!\n\n");

        }
    }
    if (flag == 0)
    {
        printf("\n\t\t\tAccount is not found");
    }
	fclose(fileOne);
}
//===============================================================================================
// function to withdraw from account
void Client_Get_Cash()
{
    FILE *fileOne = fopen("accountInfo.txt", "r");
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

void Client_Deposit_in_Account()
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
    getchar();
    gets(AccountID_d);

    while (fread(&accountInformation, sizeof(accountInformation), 1, fileOne) == 1)
    {
        if (strcmp(accountInformation.Account_id,AccountID_d) == 0)
        {
			if(accountInformation.state == 0)
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

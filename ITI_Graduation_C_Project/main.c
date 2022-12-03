/*
 * main.c
 *      Author: rana
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

/*typedef struct Account
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
} Account;*/

// prototype of functions
void menu();
void Create_New_Account();
void Generate_Password();
void Generate_AccountID();
void Open_Existing_Account();
void Change_Account_Password();
void Exit_System();
void Make_Transaction();
void Deposit_in_Account();
void Get_Cash();

void main()
{

    printf("----------------->>Bank Management System<<---------------------\n");
	menu();

}

//============================================================


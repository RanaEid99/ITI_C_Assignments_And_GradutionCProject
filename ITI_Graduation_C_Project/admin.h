#ifndef ADMIN_H_
#define ADMIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "STD_Types.h"

typedef enum { Active, Restricted,Closed } Status;
typedef struct Account
{
    u8 name[40];
    u8 National_id[14];
	u8 Guardian_National_ID[14];
    u8 age;
    u8 address[50];
    f32 Balance;
	u8 password[8];
	u8 Account_id[5];
Status state;
} Account;

void Admin_Window();
void Create_New_Account();
void Generate_Password();
void Open_Existing_Account();
void Make_Transaction();
void Get_Cash();
void Deposit_in_Account();
void Change_Account_Status();


#endif /* ADMIN_H_ */

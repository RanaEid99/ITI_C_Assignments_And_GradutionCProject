#ifndef CLIENT_H_
#define CLIENT_H_

/*typedef enum { Active, Restricted,Closed } Status;
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
	Status state;
} Account;*/


void Client_Make_Transaction();
void Client_Get_Cash();
void Client_Deposit_in_Account();
void Client_Change_Account_Password();
#endif /* CLIENT_H_ */
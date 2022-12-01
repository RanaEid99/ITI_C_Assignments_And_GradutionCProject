
#include <stdio.h>
int calc(int num1,int num2,char oper);

int fact (int num);
void main()
{
	
	int x,y,res;
	char oper;
	printf(" plz enter two numbers : ");
	scanf("%d %d",&x,&y);
	printf(" plz enter operation : ");
	scanf(" %c",&oper);
	res = calc(x,y,oper);
	printf(" result = %d",res);
}
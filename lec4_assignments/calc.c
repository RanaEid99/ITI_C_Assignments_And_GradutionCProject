#include <stdio.h>
int sum(int x, int y)
      {
	    return x+y;
      }
	  
int sub(int x, int y)
      {
	    return x-y;
      }

    int mul(int x, int y)
      {
	   return x*y;
      }

    int div(int x, int y)
      {
	    return x/y;
      }

    int rem(int x, int y)
      {
	    return x%y;
      }
int calc(int num1,int num2,char oper)
{
	
	switch(oper)
	{
		case '+':
	sum(num1,num2);   break;
	   case '-':
	sub(num1,num2);   break;
       case '*':
	mul(num1,num2);   break;
	   case '/':
	div(num1,num2);   break;
       case '%':
	   rem(num1,num2);  break;
	   default :
	   printf(" wrong operation! ");
	}

}



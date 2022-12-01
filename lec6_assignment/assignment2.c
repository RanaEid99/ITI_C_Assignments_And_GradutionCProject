/*Write a C code that define 3 int variables x, y and z and 3 pointers to int p, q
and r. Set x, y, z to three distinct values. Set p, q, r to the addresses of x, y, z
respectively.
a- Print with labels the values of x, y, z, p, q, r, *p, *q, *r.
b- Print the message: Swapping pointers.
c- Execute the swap code: r = p; p = q; q = r;
d- Print with labels the values of x, y, z, p, q, r, *p, *q, *r.*/

#include <stdio.h>
void main(){
	
	int x=5 , y=8 , z=10 ;
	int *p, *q ,*r;
	p = &x;
	q = &y;
	r = &z;
	printf(" x = %d , y = %d , z = %d \n\n",x,y,z);
	printf(" p = %d , q = %d , r = %d \n\n",p,q,r);
	printf(" *p = %d , *q = %d , *r = %d \n\n",*p,*q,*r);
	
	printf("------------------Swapping pointers--------------------\n ");
	r = p;  p = q;  q = r;
	printf(" x = %d , y = %d , z = %d \n\n",x,y,z);
	printf(" p = %d , q = %d , r = %d \n\n",p,q,r);
	printf(" *p = %d , *q = %d , *r = %d \n\n",*p,*q,*r);
	
}
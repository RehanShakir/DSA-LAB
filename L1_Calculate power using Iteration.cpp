#include<stdio.h>
int power(int base, int exp);

int main()
{
	int base, exp;
	printf("Enter Base =");
	scanf("%d",&base);
	printf("Enter Exponent =");
	scanf("%d",&exp);
	
	printf("%d^%d = %d  Answer.",base,exp,power(base,exp));
	
}
int power(int base, int exp)
{
	int res=1,i;
	for(i=1; i<=exp; i++)
	{
		res = res * base;
	}
	return res;
}

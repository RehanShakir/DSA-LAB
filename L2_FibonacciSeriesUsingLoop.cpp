#include<stdio.h>
void fib(int n);

int main()
{
	fib(8);
}
void fib(int n)
{
	int n1=0,n2=1,res=0;
	printf("%d\n%d",n1,n2);
	for(int i=0; i<=n-2; i++)
	{
		res = n1 + n2;
		printf("\n%d",res);
		 n1 = n2;
		n2 = res;
	}
}

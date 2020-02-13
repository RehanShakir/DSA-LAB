#include<stdio.h>
int fab(int n);

int main()
{
	int num;
	printf("Enter No of Terms=");
	scanf("%d",&num);
	for(int i=0; i<num; i++)
	{
		printf("\n%d",fab(i));
	}
	
}

fab(int n)
{
	
	
	if(n==0)
	{
		return 0;
	}
	else if(n==1)
	{
	 	return 1;
	}
	else
	{
	 	return (fab(n-1)+fab(n-2));
	}
}

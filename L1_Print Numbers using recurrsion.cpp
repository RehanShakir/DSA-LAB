#include<stdio.h>
int number(int num, int base);
int main()
{
    int num;
    printf("Enter the base case=");
    scanf("%d",&num);
    
    printf("\n%d",number(1,num));
		
}
int number(int num,int base)
{    
	if(num==base)
	    return base;
	else 
	{
		printf("\n%d",num);
		return number(num=num+1,base);
	}
	    
}

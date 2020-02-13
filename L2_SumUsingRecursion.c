#include<stdio.h>
int sum(int num);
void main()
{   int num;
    printf("Enter A Number=");
    scanf("%d",&num);

    printf("Sum of Natural Numbers = %d",sum(num));
}
int sum(int num)
{
    if(num==0)
        return 0;
    else
        return (num+sum(num-1));
}


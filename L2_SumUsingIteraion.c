#include<stdio.h>
int sum(int num);

void main()
{
    int num;
    printf("Enter a Number=");
    scanf("%d",&num);
    printf("Sum = %d",sum(num));

}
int sum(int num)
{  int res=0;

    for(int i=1; i<=num; i++)
    {
        res = res + i;
    }
    return res;
}

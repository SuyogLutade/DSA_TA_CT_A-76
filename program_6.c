#include<stdio.h>
#include<conio.h>

void main()
{
    int binary[16]={0},decimalNo,top=-1,t;
    printf("\n Enter the decimal number : ");
    scanf("%d",&decimalNo);
    while(decimalNo>0)
    {
        top++;
        binary[top]=decimalNo%2;
        decimalNo/=2;
    }
    t=top;
    printf("\n decimal number in the binary is : ");
    while(t>=0)
    printf("%d",binary[t--]);
}
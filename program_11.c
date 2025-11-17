#include<stdio.h>
#include<conio.h>
#include<math.h>
int isopd(char c)
{
    if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')
    return 1;
    else
    return 0;
}
int num(char c)
{
    if(c=='0')
    return 0;
    else if(c=='1')
    return 1;
    else if(c=='2')
    return 2;
   else if(c=='3')
    return 3;
   else if(c=='4')
    return 4;
   else if(c=='5')
    return 5;
   else if(c=='6')
    return 6;
   else if(c=='7')
    return 7;
   else if(c=='8')
    return 8;
   else if(c=='9')
    return 9;
}
int isopr(char c)
{
    if(c=='/'||c=='*'||c=='-'||c=='+'||c=='^'||c=='%')
    return 1;
    else
    return 0;
}
int priority(char c)
{
    if(c=='^')
    return 3;
    else if(c=='/'||c=='*')
    return 2;
    else if (c=='-'||c=='+')
    return 1;
    else
    return 0;
}
int ans(char c,int x,int y)
{
    if(c=='+')
    return x+y;
    else if(c=='-')
    return x-y;
    else if(c=='*')
    return x*y;
    else if(c=='/')
    return x/y;
    else if(c=='%')
    return x%y;
    else if(c=='^')
    return (int)pow(x,y);
}
int main()
{
    char exp[20],stk[20];
    int ch=0,top=-1,i=0,j=0,sol[20]={0},a;
    printf("\n Enter the infix expresion(eg. (a+b*c+d/e)): ");
    scanf("%s",exp);
    while(exp[i]!='\0')
    {
        ch=0;
        if(exp[i]=='(')
        {
            stk[++top]=exp[i];
        }
        else if(isopd(exp[i]))
        {
            a=0;
            while(isopd(exp[i]))
            {
                a=a*10+num(exp[i]);
                i++;
            }
            sol[j]=a;
             j++;
            ch=1;
        }
        else if(isopr(exp[i]))
        {
            if(stk[top]=='('||priority(stk[top])<priority(exp[i]))
            stk[++top]=exp[i];
            else 
            {
                while(top!=-1&&priority(stk[top])>=priority(exp[i]))
                {
                    j--;
                sol[j-1]=ans(stk[top],sol[j-1],sol[j]);
                top--;
                }
               stk[++top]=exp[i];
            }
        }
        else if(exp[i]==')')
        {
            while(stk[top]!='(')
            {
               j--; 
               sol[j-1]=ans(stk[top],sol[j-1],sol[j]);
                top--;
            }
            top--;
        }
        if(ch==0)
        i++;
    }
   if(top==-1)
     printf("\nanswer= %d",sol[j-1]);
    return 0;
}
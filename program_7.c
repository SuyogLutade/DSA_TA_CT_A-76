#include<stdio.h>
#include<conio.h>
int isopd(char c)
{
    if(c>='a'&&c<='z')
    return 1;
    else
    return 0;
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
}
int main()
{
    char ch,infix[20],postfix[20],stk[20];
    int top=-1,i=0,j=0;
    printf("\n Enter the infix expresion: ");
    scanf("%s",infix);
    printf("%s",infix);
    while(infix[i]!='\0')
    {
        ch=infix[i];
        if(ch=='(')
        {
            top++;
            stk[top]=ch;
        }
        else if(isopd(ch))
        {
            postfix[j]=ch;
            j++;
        }
        else if(isopr(ch))
        {
            if(stk[top]=='(')
            {
                top++;
				stk[top]=ch;
            }
            else if(isopr(stk[top]))
            {
                
                if(priority(stk[top])<priority(ch))
                {
                	top++;
                    stk[top]=ch;
                }
                else if(priority(stk[top])>=priority(ch))
                {
                    postfix[j]=stk[top];
                    j++;
                    stk[top]=ch;
                }
            }
          
        }
        else if(ch==')')
        {
            while(stk[top]!='(')
            {
            postfix[j++]=stk[top];
            top--;
            }
            top--;
        }
        i++;
    }
   
    postfix[j]='\0';
    printf("postfix= %s",postfix);
    return 0;
}

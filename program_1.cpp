#include<iostream>
#define max 30
using namespace std;
int top = -1,stk[max];

int main()
{
    int ch;
    do
    {
        cout<<"\n Enter your choice : \n\t1.push \n\t2.pop\n\t3.traverce \n\t:";
        cin>>ch;
        switch(ch)
        {
            case 1://push
            if(top<max-1)
            {
                cout<<"\nEnter the number you want to enter : ";
                cin>>stk[++top];
                cout<<stk[top]<<" is pushed.";
            }
            else
                cout<<"\nThe stack is full.";

                break;
            case 2://pop
                if(top>-1)
                {
                   cout<<stk[top--]<<" is poped."; 
                }
                else
                cout<<"stack is empty.";

                break;
            case 3://traverce
                int temp=top;
                while(temp>-1)
                {
                    cout<<temp<<"->"<<stk[temp]<<endl;
                    temp--;
                }
                break;
            
        }
    }while(ch>0 and ch<4);
}
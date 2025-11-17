#include<iostream>
#define max 30
using namespace std;

typedef struct Stack
{
    int num;
    struct Stack *pre;

}*S;

S getNode()
{
    S new1= (S)malloc(sizeof(struct Stack));
    new1->pre=NULL;
    return new1;
}

int main()
{
    S head=NULL,temp=NULL,top=NULL,newNode;
    int ch;
    do{
    cout<<"\n Enter your choice : \n\t1.push \n\t2.pop\n\t3.traverce \n\t:";
    cin>>ch;
    switch(ch)
    {
        case 1:
            newNode=getNode();
            cout<<"\n Enter the number : ";
            cin>>newNode->num;
        if(head == NULL)
        {
            head = newNode;
            top=newNode;
        }
        else
        {
            newNode->pre=top;
            top=newNode;
        }
        break;

        case 2:
            if (head==NULL)
            {
                cout<<"\n the stack is empty";
            }
            else if(top==head)
            {
                free(top);
                top=NULL;
                head=NULL;
            }
            else
            {
                temp = top;
                top = top->pre;
                free(temp);
                cout << "\nTop element popped.\n";
            }

        break;

        case 3:
        if (head==NULL)
            {
                cout<<"\n the stack is empty";
            }
            else
            {
                temp=top;
                while(temp!=NULL)
                {
                    cout<<temp->num<<endl;
                    temp=temp->pre;
                }
            }

        break;
    }
}while(ch>0 and ch<4);
return 0;
}
#include<iostream>
#define max 30
using namespace std;

typedef struct Stack
{
    int num;
    struct Stack *next;

}*S;

S getNode()
{
    S new1= (S)malloc(sizeof(struct Stack));
    new1->next=NULL;
    return new1;
}

int main()
{
    S front=NULL,temp=NULL,rear=NULL,newNode;
    int ch;
    do{
    cout<<"\n Enter your choice : \n\t1.inserrt  \n\t2.delete\n\t3.display \n\t:";
    cin>>ch;
    switch(ch)
    {
        case 1:
            newNode=getNode();
            cout<<"\n Enter the number : ";
            cin>>newNode->num;
        if(front == NULL)
        {
            front = newNode;
            rear=newNode;
        }
        else
        {
            rear->next=newNode;
            rear=newNode;
        }
        break;

        case 2:
            if (front==NULL)
            {
                cout<<"\n the stack is empty";
            }
            else if(front==rear)
            {
                free(rear);
                rear=NULL;
                front=NULL;
            }
            else
            {
                temp = front;
                front= front->next;
                free(temp);
                cout << "\nTop element deleted.\n";
            }

        break;

        case 3:
        if (front==NULL)
            {
                cout<<"\n the stack is empty";
            }
            else
            {
                temp=front;
                while(temp->next!=NULL)
                {
                    cout<<temp->num<<"->";
                    temp=temp->next;
                }
                    cout<<temp->num;

            }

        break;
    }
}while(ch>0 and ch<4);
return 0;
}
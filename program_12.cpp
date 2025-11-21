//12. Program on linked list : creation, insertion, deletion, reversing, merging, finding middle ,sorting, detecting loop in linked list, sum of data, printing odd-even data form SLL
#include<iostream>
#include<cstdlib>
#define max 30
using namespace std;

typedef struct list
{
    int num;
    struct list * next;
}*L;

L getNode()
{
    L new1;
    new1=(L)malloc(sizeof(struct list));
    new1->next=NULL;
    return new1;
}
void displayList(L temp)
{
    cout<<endl;
    while(temp!=NULL)
    {
        cout<<temp->num<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
L deleteNode(L head, int val)
{
    L temp = head,t;

    // deleting head node
    if(head != NULL && head->num == val)
    {
        head = head->next;
        free(temp);
        return head;
    }

    while(temp != NULL && temp->next != NULL && temp->next->num != val)
    {
        t=temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "\nnode not found.";
        return head;
    }

    t->next=temp->next;

    free(temp);
    return head;
}

L reverse(L head)
{
    L next = NULL,pre=NULL;

    while(head != NULL)
    {
       next=head->next;
       head->next=pre;
       pre=head;
       head=next;
    }
    return pre;
}
void middle(L head)
{
    L t1,t2;
    t1=head;
    t2=head;
    while(t1 != NULL && t1->next != NULL)
    {
        t1 = t1->next;
        t1 = t1->next;
        if(t1 != NULL)
            t2 = t2->next;
    }
    if(t1!=NULL)
    {
        cout<<"\n The middle nodes contain : "<<t2->num<<" and "<<t2->next->num;
        return;
    }
    else
    {
        cout<<"\n The middle node contain : "<<t2->num;
        return;
    }
}
void detectLoop(L head)
{
    L t1=head,t2=head;
    while(t2!=NULL && t2->next!=NULL)
    {
        t1=t1->next;
        t2=t2->next->next;
        if(t1==t2)
        {
            printf("\n loop is present ");
            return;
        }
    }
    printf("\n loop is not present ");
}
int sum(L temp )
{
    int sum=0;
    while(temp!=NULL)
    {
        sum+=temp->num;
        temp=temp->next;
    }
    return sum;
}
void sort (L head)
{
    L i,j;
    int t;
    for(i=head;i!=NULL;i=i->next)
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->num>j->num)
            {
                t=i->num;
                i->num=j->num;
                j->num=t;
            }
        }
}
void displayEven(L temp)
{
    while(temp!=NULL)
    {
        if(temp->num%2==0)
        cout<<temp->num<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
L insert(L head,int pos)
{
    L new1 = getNode();
    cout<<"\n Enter the number to insert : ";
    cin>>new1->num;

    // insert at head or empty list
    if(pos <= 1 || head == NULL)
    {
        new1->next = head;
        return new1;
    }

    L temp = head;
    for(int i = 1; temp != NULL && i < pos - 1; ++i)
        temp = temp->next;

    if(temp == NULL)   // position out of range
    {
        cout<<"\nthere is not that many nodes to place the node between 2 nodes .";
        free(new1);
        return head;
    }

    new1->next = temp->next;
    temp->next = new1;
    cout<<"\n the node is inserted.";
    return head;
}
void displayOdd(L temp)
{
    while(temp!=NULL)
    {
        if(temp->num%2!=0)
        cout<<temp->num<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
void addLoop(L head, int n,L last)
{
    while(head!=NULL && head->num!=n)
    {
        head=head->next;
    }
    if(head==NULL)
    {
        cout<<"\n node not found.";
        return;
    }
    last->next=head;
}
int main()
{
    L head=NULL,temp,newNode,head1=NULL,temp1;
    int ch,n,val;
    do{
        system("cls");
    cout<<"\nEnter the choise:";
    cout<<"\n\t1.create first list.";
    cout<<"\n\t2.create second list.";
    cout<<"\n\t3.insert in middle of 1st list.";
    cout<<"\n\t4.insert in middle of 2nd list.";
    cout<<"\n\t5.delete the node with value in 1st list,\n\t(first node containing the value in list will be deleted).";
    cout<<"\n\t6.reverse the 1st list.";
    cout<<"\n\t7.merging (list 1 + list 2).";
    cout<<"\n\t8.finding middle of 1st list.";
    cout<<"\n\t9.sorting 1st list.";
    cout<<"\n\t10.detecting loop in 1st list.";
    cout<<"\n\t11.sum of the data of 1st list.";
    cout<<"\n\t12.print even and odd data of 1st list.";
    cout<<"\n\t13.display the 1st list.";
    cout<<"\n\t14.display the 2nd list.";
    cout<<"\n\t15.add loop in 1st list with last node.";
    cout<<"\n\t16.exit.\n:";
    cin>>ch;
    switch(ch)
    {
        case 1:
            cout<<"\n Enter the number of node : ";
            cin>>n;
        while(n>0)
        {
        
                if(head==NULL)
                {
                    head=getNode();
                    cout<<"\nEnter the number:";
                    cin>>head->num;
                    temp=head;
                }
                else
                {
                    newNode=getNode();
                    cout<<"\nEnter the number:";
                    cin>>newNode->num;
                    temp->next=newNode;
                    temp=newNode;
                }
                n--;
        }
        cout<<endl;
        system("pause");
        break;
        case 2:
            cout<<"\n Enter the number of node : ";
            cin>>n;
         while(n>0)
        {
                if(head1==NULL)
                {
                    head1=getNode();
                    cout<<"\nEnter the number:";
                    cin>>head1->num;
                    temp1=head1;
                }
                else
                {
                    newNode=getNode();
                    cout<<"\nEnter the number:";
                    cin>>newNode->num;
                    temp1->next=newNode;
                    temp1=newNode;
                }
             n--;
        }
        cout<<endl;
        system("pause");
        break;
        case 3:
                
                    cout<<"\nEnter the number of node : ";
                    cin>>n;
                    head=insert(head,n);
                    
        cout<<endl;
        system("pause");
        break;
        case 4:
                cout<<"\nEnter the number of node : ";
                    cin>>n;
                    head1=insert(head1,n);
                   
        cout<<endl;
        system("pause");
        break;
        case 5:

                if(head!=NULL)
                {
                    cout<<"\nEnter the value to be deleted:";
                    cin>>val;
                    head=deleteNode(head,val);
                }
                else
                cout<<"\nThe list is empty";
        cout<<endl;
        system("pause");
        break;
        case 6:
                if(head!=NULL)
                head=reverse(head);
                else
                cout<<"\nThe list is empty";
        cout<<endl;
        system("pause");
        break;
        case 7:
               if(head == NULL)
                {
                    head = head1;
                }
                else
                {
                    temp->next = head1;
                    temp=temp1;
                }
                head1 = NULL;
        cout<<endl;
        system("pause");
        break;
        case 8:
                if(head!=NULL)
                middle(head);
                else
                cout<<"\nThe list is empty";
        cout<<endl;
        system("pause");
        break;
        case 9:
                if(head!=NULL)
                sort(head);
                else
                cout<<"\nThe list is empty";
        cout<<endl;
        system("pause");
        break;
        case 10:
                detectLoop(head);
        cout<<endl;
        system("pause");
        break;
        case 11://sum
                printf("\n the sum of all data in 1st list : %d",sum(head));
        cout<<endl;
        system("pause");
        break;
        case 12:
                cout<<"\n the even data in the list : ";
                displayEven(head);
                cout<<"\n the odd data in the list : ";
                displayOdd(head);
        cout<<endl;
        system("pause");
        break;
         case 13:
                displayList(head);
        cout<<endl;
        system("pause");
        break;
        case 14:
                displayList(head1);
        cout<<endl;
        system("pause");
        break;
        case 15:
        
                displayList(head1);
                cout<<"\n enter the number from you want to start the loop :";
                cin>>n;
                addLoop(head,n,temp);
        cout<<endl;
        system("pause");
        break;
    }
}while(ch<16 && ch>0);
}
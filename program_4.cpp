#include<iostream>
#define max 30
using namespace std;

int main()
{
    int r1=-1,r2=max+1,f1=0,f2=max,que[max];
     int ch;
    do
    {
        cout<<"\n Enter your choice : \n\t1.insert in Q1\n\t2.insert in Q2 \n\t3.delete in Q1\n\t4.delete in Q2\n\t5.display \n\t6.display \n\t:";
        cin>>ch;
        switch(ch)
        {
            case 1://insert in Q1
            if(r1<r2)
            {
                cout<<"\nEnter the number you want to insert : ";
                cin>>que[++r1];
                cout<<que[r1]<<" is inserted.";
            }
            else
                cout<<"\nThe Queue is full.";

                break;
            case 2://insert in Q2
            if(r1<r2)
            {
                cout<<"\nEnter the number you want to insert : ";
                cin>>que[--r2];
                cout<<que[r1]<<" is inserted.";
            }
            else
                cout<<"\nThe Queue is full.";

                break;
            case 3://delete in Q1
                if(r1>=f1)
                {
                   cout<<que[f1]<<" is deleted."; 
                   f1++;
                }
                else
                cout<<"empty is empty.";
            case 4://delete in Q1
                if(r2>=f2)
                {
                   cout<<que[f2]<<" is deleted."; 
                   f2--;
                }
                else
                cout<<"empty is empty.";

                break;
            case 5://display Q1
            if(r1>=f1)
            {
                int temp=f1;
                while(temp<r1)
                {
                    cout<<que[temp]<<"->";
                    temp++;
                }
                cout<<que[temp];
            
            }
            else
            cout<<"queue is empty.";
                break;
            case 6://display Q2
            if(r2<=f2)
            {
                int temp=f2;
                while(temp>r2)
                {
                    cout<<que[temp]<<"->";
                    temp--;
                }
                cout<<que[temp];
                
            }
            else
            cout<<"queue is empty.";
                break;
            
        }
    }while(ch>0 and ch<7);
    
}
#include<iostream>
#define max 30
using namespace std;
int r = -1,f = 0,que[max];

int main()
{
    int ch;
    do
    {
        cout<<"\n Enter your choice : \n\t1.insert \n\t2.delete\n\t3.display \n\t:";
        cin>>ch;
        switch(ch)
        {
            case 1://insert
            if(r<max-1)
            {
                cout<<"\nEnter the number you want to insert : ";
                cin>>que[++r];
                cout<<que[r]<<" is inserted.";
            }
            else
                cout<<"\nThe Queue is full.";

                break;
            case 2://delete
                if(r>=f)
                {
                   cout<<que[f]<<" is deleted."; 
                   f++;
                }
                else
                cout<<"empty is empty.";

                break;
            case 3://display
            if(r>=f){
                int temp=f;
                while(temp<r)
                {
                    cout<<que[temp]<<"->";
                    temp++;
                }
                cout<<que[temp];
            }
            else
            cout<<"empty is empty.";
                break;
            
        }
    }while(ch>0 and ch<4);
}
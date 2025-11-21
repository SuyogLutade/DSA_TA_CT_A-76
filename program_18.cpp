#include<iostream>
#include<stdlib.h>
using namespace std;
#define max 26
typedef struct terminal
{
   struct terminal* alfabate[max];
   int ref;
}T;
T *getNode()
{
    T* new1 = (T*)malloc(sizeof( struct terminal));
    new1->ref=0;
    for(int i=0;i<max;i++)
    new1->alfabate[i]=NULL;
    return new1;
}
int getIndex(char c)
{
    if(c<97)
    return c-'A';
    else
    return c-'a';
}

int main()
{
    T* root ,*temp,*new1;
    int ch,i,idx,n;
    char str[max],resp;
    root=getNode();
do{
    
    
    printf("\n enter your choise");
    printf("\n1.insert directly \n2.search \n\t:");
    scanf("%d",&ch);
    switch (ch)
    {
        
    case 1:
    temp=root;
        printf("\n enter the string : ");
        scanf("%s",str);
        i=0;
        while(str[i]!='\0')
        {
            idx=getIndex(str[i]);
            if (temp->alfabate [idx]!=NULL)
            {
                temp=temp->alfabate[idx];
            }
            else
            {
                new1=getNode();
                temp->alfabate[idx]=new1;
                temp=new1;
            }
            i++;
        }
        if(temp->ref==1)
        {
            printf("\nword is already pressent in the trie.");
        }
        else
        {
            printf("\nword is inserted in the trie.");
            temp->ref=1;
        }
        
        break;
        case 2: 
            printf("\n enter the string : ");
            scanf("%s",str);
            temp=root;
            i=0;
            while(str[i]!='\0')
        {
            idx=getIndex(str[i]);
            if (temp->alfabate [idx]!=NULL)
            {
                temp=temp->alfabate[idx];
            }
            else
            {
                new1=getNode();
                temp->alfabate[idx]=new1;
            }
            i++;
        }
        if(temp->ref==1 && str[i]=='\0')
        {
            printf("\nword is pressent in the trie.");
        }
        else
        {
            printf("\nword is not pressent in the trie.");
        }

        break;
    }
    }while(ch<=3&&ch>0);
    return 0;
}

#include<iostream>
#include<stdlib.h>
#define max 30
using namespace std;

int graph[max][max],n,ch;
void visit(int node,bool visited[max],int removed)
{
    visited[node]=true;
    for(int i=0;i<n;i++)
    {
        if(graph[node][i]==1 && !visited[i] && i!=removed)
            visit(i,visited,removed);
    }
}

bool isFailure(int removed)
{
    bool visited[max]={false};
    int start=-1;
    for(int i=0;i<n;i++)
    {
        if(i!=removed)
        {
            start=i;
            break;
        }
    }
    if(start==-1)
    return false;

    visit(start,visited,removed);

    for(int i=0;i<n;i++)
    {
        if(i!=removed && !visited[i])
            return true;
    }
    return false;

}

int main ()
{
    do{
    cout<<"enter your choise:\n\t1.enter the graph\n\t2.search whether the graph id bi-connected or not\n\t:";
    cin>>ch;
    switch (ch)
    {
        case 1:
        
        cout<<"\n enter the number of nodes : ";
        cin>>n;
    for(int i=0;i<n;i++)
    {
        graph[i][i]=0;
        for(int j=i+1;j<n;j++)
        {
            cout<<"graph["<<i<<"]["<<j<<"]= ";
            cin>>graph[i][j];
            graph[j][i]=graph[i][j];
        }
    }
        break;
    case 2:
    int i;
    for( i=0;i<n;i++)
    {
        if(isFailure(i))
        {
            printf("\nThe graph is non biconnected.");
            break;
        }

    }
    if(i<n)
    printf("\nThe graph is biconnected.");
    

        break;
    }
}while(ch<3 and ch>0);

}
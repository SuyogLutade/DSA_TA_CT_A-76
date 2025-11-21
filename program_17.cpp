#include<iostream>
#include<stdlib.h>
#define max 30
using namespace std;

int graph[max][max],n,ch,visited[max]={0};
void DFS(int u, int n) {
    visited[u] = 1;
    printf("%d,", u);

    for (int v = 0; v < n; v++) {
        if (graph[u][v] == 1 && !visited[v])
            DFS(v, n);
    }
}
void BFS(int start, int n) {
    int que[max], f = 0, r = -1;

    visited[start] = 1;
    que[++r] = start;

    while (f <= r) {
        int u = que[f++];
        printf("%d,", u);

        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1 && !visited[v]) {
                visited[v] = 1;
                que[++r] = v;
            }
        }
    }
}

int main ()
{
    
    do{
    cout<<"enter your choise:\n\t1.enter the non-directional graph\n\t2.enter the directional graph\n\t3.DFS \n\t4.BFS \n\t:";
    cin>>ch;
    switch (ch)
    {
        case 1://non directional
        
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
        case 2://directional
            cout<<"\n enter the number of nodes : ";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<"graph["<<i<<"]["<<j<<"]= ";
                    cin>>graph[i][j];
                }
            }

        break;
        case 3://DFS
        int start;
            printf("\n Enter the start node : ");
            scanf("%d",&start);
            printf("\n DFS : ");
            DFS(start,n);
        case 4://BFS
        int start;
            printf("\n Enter the start node : ");
            scanf("%d",&start);
            printf("\n BFS : ");
            BFS(start,n);
        break;
    }
}while(ch<=3 and ch>0);

}
#include<stdio.h>

int main()
{
    int n,e;
    int u[50],v[50],w[50];
    int d[20];

    printf("Enter vertices and edges: ");
    scanf("%d%d",&n,&e);

    printf("Enter edges (source destination weight):\n");
    for(int i=0;i<e;i++)
        scanf("%d%d%d",&u[i],&v[i],&w[i]);

    for(int i=0;i<n;i++)
        d[i]=9999;

    d[0]=0;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<e;j++)
        {
            if(d[u[j]]!=9999 && d[u[j]]+w[j]<d[v[j]])
                d[v[j]]=d[u[j]]+w[j];
        }
    }

    for(int j=0;j<e;j++)
    {
        if(d[u[j]]!=9999 && d[u[j]]+w[j]<d[v[j]])
        {
            printf("Negative cycle exists\n");
            return 0;
        }
    }

    printf("Shortest distances from vertex 0:\n");
    for(int i=0;i<n;i++)
        printf("%d -> %d\n",i,d[i]);

    return 0;
}

#include<stdio.h>

int n,cost[10][10],visited[10];
int ans=9999;

void tsp(int city,int count,int sum)
{
    if(count==n)
    {
        if(cost[city][0]!=0 && sum+cost[city][0]<ans)
            ans=sum+cost[city][0];
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i] && cost[city][i]!=0)
        {
            visited[i]=1;
            tsp(i,count+1,sum+cost[city][i]);
            visited[i]=0;
        }
    }
}

int main()
{
    printf("Enter number of cities (max 10): ");
    scanf("%d",&n);

    printf("Enter cost matrix (0 means no edge):\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    visited[0]=1;
    tsp(0,1,0);

    if(ans==9999)
        printf("No complete tour exists\n");
    else
        printf("Minimum cost = %d\n",ans);

    return 0;
}

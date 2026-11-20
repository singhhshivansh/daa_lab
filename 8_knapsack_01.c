#include<stdio.h>

int main()
{
    int n,W;
    int wt[20],val[20],dp[20][20];

    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter weights:\n");
    for(int i=1;i<=n;i++)
        scanf("%d",&wt[i]);

    printf("Enter profits:\n");
    for(int i=1;i<=n;i++)
        scanf("%d",&val[i]);

    printf("Enter capacity: ");
    scanf("%d",&W);

    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i==0 || w==0)
                dp[i][w]=0;
            else if(wt[i]<=w)
            {
                int a=val[i]+dp[i-1][w-wt[i]];
                int b=dp[i-1][w];
                dp[i][w]=(a>b)?a:b;
            }
            else
                dp[i][w]=dp[i-1][w];
        }
    }

    printf("Maximum profit = %d\n",dp[n][W]);
    return 0;
}

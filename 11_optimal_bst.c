#include<stdio.h>
#include<limits.h>

int main()
{
    int n,f[20],dp[20][20];

    printf("Enter number of keys: ");
    scanf("%d",&n);

    printf("Enter frequencies: ");
    for(int i=1;i<=n;i++)
        scanf("%d",&f[i]);

    for(int i=1;i<=n;i++)
        dp[i][i]=f[i];

    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            int sum=0;
            dp[i][j]=INT_MAX;

            for(int k=i;k<=j;k++)
                sum=sum+f[k];

            for(int k=i;k<=j;k++)
            {
                int cost=sum;

                if(k>i)
                    cost=cost+dp[i][k-1];

                if(k<j)
                    cost=cost+dp[k+1][j];

                if(cost<dp[i][j])
                    dp[i][j]=cost;
            }
        }
    }

    printf("Minimum cost = %d\n",dp[1][n]);
    return 0;
}

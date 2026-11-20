#include<stdio.h>

int main()
{
    int n,a[10][10];

    printf("Enter number of vertices (max 10): ");
    scanf("%d",&n);

    printf("Enter adjacency matrix (use 9999 for infinity):\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][k]!=9999 && a[k][j]!=9999 &&
                   a[i][k]+a[k][j]<a[i][j])
                    a[i][j]=a[i][k]+a[k][j];
            }
        }
    }

    printf("Shortest distance matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    return 0;
}

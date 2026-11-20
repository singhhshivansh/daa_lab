
#include<stdio.h>
int a[20],n,target,x[20],found=0;

void subset(int i,int sum)
{
    if(sum==target)
    {
        printf("Subset: ");
        found=1;
        for(int j=0;j<i;j++)
            if(x[j])
                printf("%d ",a[j]);
        printf("\n");
        return;
    }
    if(i==n || sum>target)
        return;

    x[i]=1;
    subset(i+1,sum+a[i]);

    x[i]=0;
    subset(i+1,sum);
}

int main()
{
    int i;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter target: ");
    scanf("%d",&target);

    subset(0,0);

    if(!found)
        printf("No subset found");
    return 0;
}

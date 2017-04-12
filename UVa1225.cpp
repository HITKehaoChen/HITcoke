#include <stdio.h>
int main()
{
    int T,b,c,i,n,j,e,t;
    scanf("%d",&T);
    while(T--)
    {
        int k[10]={0};
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            t=i;
            j=0;
            int a[5]={0};
            while(t)
            {
                a[j++]=t%10;
                t/=10;
            }
            for(e=0;e<j;e++)
                k[a[e]]++;
        }
        int first=1;
        for(i=0;i<10;i++)
        {
            if(first)
                first=0;
            else printf(" ");
            printf("%d",k[i]);
        }
        printf("\n");
    }
}


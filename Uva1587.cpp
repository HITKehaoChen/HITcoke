#include <stdio.h>
#include <stdlib.h>

struct pallet
{
    int w,h;
};

int is_samestruct(struct pallet a,struct pallet b)
{
    if (a.w==b.w&&a.h==b.h)
        return 1;
    else
        return 0;
}

int main()
{
    struct pallet p[6],temp;
    int i,j,t;
    while(scanf("%d%d",&p[0].w,&p[0].h)!=EOF)
    {
        if (p[0].w<p[0].h)
        {
            t=p[0].w;
            p[0].w=p[0].h;
            p[0].h=t;
        }
        for (i=1;i<6;i++)
        {
            scanf("%d%d",&p[i].w,&p[i].h);
            if (p[i].w<p[i].h)
            {
                t=p[i].w;
                p[i].w=p[i].h;
                p[i].h=t;
            }
        }
        for (i=1;i<=6-1;i++)
            for (j=0;j<6-i;j++)
                if (p[j].w<p[j+1].w)
                {
                    temp=p[j];
                    p[j]=p[j+1];
                    p[j+1]=temp;
                }
        for (i=1;i<=6-1;i++)
            for (j=0;j<6-i;j++)
                if (p[j].h<p[j+1].h&&p[j].w==p[j+1].w)
                {
                    temp=p[j];
                    p[j]=p[j+1];
                    p[j+1]=temp;
                }

        for (i=0;i<6;i+=2)
            if (!is_samestruct(p[i],p[i+1]))
                break;
        if (i==6)
        {
            if (p[0].w==p[2].w)
            {
                if ((p[4].w==p[0].h&&p[4].h==p[2].h)||(p[4].w==p[2].h&&p[4].h==p[0].h))
                    printf("POSSIBLE\n");
                else
                    printf("IMPOSSIBLE\n");
            }
            else
                printf("IMPOSSIBLE\n");
        }
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}

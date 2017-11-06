#include <stdio.h>  
#define MAX 0x3f3f3f3f  
#define RANGE 105  
  
int d[RANGE][RANGE];  
int n;  
  
int Min( int a,int b )  
{  
    return a<b?a:b;  
}  
void warshall_floyd( void )  
{  
    int i,j,k;  
    for( k=1;k<=n;++k )  
        for( i=1;i<=n;++i )  
            for( j=1;j<=n;++j )  
                d[i][j]=Min( d[i][j],d[i][k]+d[k][j] );  
}  
  
int main()  
{  
    int m,A,B,C,i,j;  
  
    while( scanf("%d%d",&n,&m) )  
    {  
        if( !n && !m )  break;  
  
        // 初始化  
        for( i=1;i<=n;++i )  
            for( j=1;j<=i;++j )  
            {  
                if( i==j ) d[i][j]=0;  
                else    d[i][j]=d[j][i]=MAX;  
            }  
  
        // 输入  
        for( i=0;i<m;++i )  
        {  
            scanf("%d%d%d",&A,&B,&C);  
            d[A][B]=d[B][A]=C;  
        }  
  
        // floyd算法求最短路  
        warshall_floyd();  
        printf("%d\n",d[1][n]);  
    }  
    return 0;  
}  

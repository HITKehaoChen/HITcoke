#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    int m,n,t=0;
    while(cin>>m&&m)
    {
        cin>>n;
        if(t)cout<<endl;
        char a[m][n];
        int b[m][n];
        memset(b,0,sizeof(b));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++)//在另一个整形二维数组中编号
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='*')
                {
                    b[i][j]=-1;
                }
                if(b[i][j]>=0)
                {
                    if(!i||!j)
                    {
                        cnt++;
                        b[i][j]=cnt;
                    }
                    else
                    {
                        if(a[i][j-1]=='*'||a[i-1][j]=='*')
                        {
                            cnt++;
                            b[i][j]=cnt;
                        }
                    }
                }
            }
        }
        cout<<"puzzle #"<<++t<<":"<<endl;
        cout<<"Across"<<endl;
        for(int i=0;i<m;i++)//横向的
        {
            for(int j=0;j<n;j++)
            {
                if((j==0||b[i][j-1]==-1)&&b[i][j]>=0)
                {
                    printf("%3d.",b[i][j]);
                    for(int k=j;k<n;k++)
                    {
                        cout<<a[i][k];
                        if(b[i][k+1]==-1||k+1==n)
                        {
                            cout<<endl;
                            break;
                        }
                    }
                }
            }
        }
        cout<<"Down"<<endl;
        for(int i=0;i<m;i++)//纵向的
        {
            for(int j=0;j<n;j++)
            {
                if((i==0||b[i-1][j]==-1)&&b[i][j]>=0)
                {
                    printf("%3d.",b[i][j]);
                    for(int k=i;k<m;k++)
                    {
                        cout<<a[k][j];
                        if(b[k+1][j]==-1||k+1==m)
                        {
                            cout<<endl;
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

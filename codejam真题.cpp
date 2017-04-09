#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    char n[25];
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        scanf("%s",n);
        int l=strlen(n);
        for(int j=0;j<l;j++){
            for(int k=1;k<l;k++){
                if(n[k]>=n[k-1])continue;
                else{
                    n[k-1]=(char)((int)n[k-1]-1);
                    while(k<l){
                        n[k++]='9';
                    }
                }
            }
        }
        cout<<"Case #"<<i<<": ";
        int zero=0;
        for(int j=0;j<l;j++){
            if(zero==0&&n[j]=='0')continue;
            if(zero==0&&n[j]!='0'){
                zero=1;
                cout<<n[j];
                continue;
            }
            cout<<n[j];
        }
        cout<<endl;
    }
    return 0;
}

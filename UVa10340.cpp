#include<stdio.h>
#include <string.h>
#define N 100000
char s[N],sub[N];
int book[N];
int main(){
	int sublen,slen;
	int i,j;
	int flag;
	int min;
	while(scanf("%s%s",sub,s)!= EOF){
        sublen = strlen(sub);
        slen = strlen(s);
        memset(book,-1,sizeof(book));

        min = 0;
        for (int i = 0; i < sublen; i++)
        {
        	for (int j = min; j < slen; j++)
        	{
        		if (sub[i]==s[j])
        		{
        			book[i] = j;
        			min = j+1;
        			break;
        		}
        	}
        }
        flag = 1;
        for (int i = 0; i < sublen; i++)
        {
        	if (book[i]=-1)
        	{
        		flag = 0;
        		break;
        	}
        }
        if (flag)
        {
        	printf("Yes\n");/* code */
        }
        else 
        	printf("No\n");

	}
	return 0 ;
}

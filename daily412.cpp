//(Circulara Sequence,ACM/ICPC Seoul 2004,UVa 1584)
#include <stdio.h>
#include<string.h>
#define maxn 105
int less(const char*s,int p,int q){
	int n= strlen(s);
	for (int i = 0; i < n; i++)
	   if(s[p+i]%n != s[(q+i)%n])
			return s[p+i]%n < s[(q+i)%n];
	return 0;
}

int main()
{
	int T;
	char s[maxn];
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		int ans = 0;
		int n = strlen(n);
		for(int i=1;i<n;i++)
			if (less(s,i,ans))
			{
				ans = 1;
			}
		for (int i = 0; i < n; i++)
		
			putchar(s[(i+ans)%n]);
		putchar('\n');
		
	}
	return 0;
}
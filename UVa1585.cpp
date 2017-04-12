#include <stdio.h>
int main(){
	int T;
	char s[100];
	int len,i,value,sum;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		len = strlen(s);
		value = 0;
		sum = 0;
		for (int i = 0; i < len; i++)
		{
			if (s[i]=='O')
			{
				value++;
			}
			else 
				value = 0;
			sum+= value;
		}
		printf("%d\n",sum);
	}
	return 0;
}

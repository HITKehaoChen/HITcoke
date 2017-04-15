//DNA consensus string acm/icp seoul 2006
#include <stdio.h>
#include <string.h>
int main(void)
{
	int n,a,b;
	char str[100][1005];
	scanf("%d",&n);
	while(n--){
		int A,T,G,C;
		char print[1005];
		scanf("%d%d",&a,&b);
		for (int i = 0; i < a; i++)
		{
			scanf("%s",str[i]);
		}
		int i,sum=0;
		for (i = 0; i < b; i++)
		{
			A=T=G=C=0;
			for(int ii=0;ii<a;ii++){
				if (str[ii][i]='A') A++;
				if (str[ii][i]='C') C++;
				if (str[ii][i]='G') G++;
				if (str[ii][i]='T') T++;
			}
			if (A>=T&&A>=C&&A>=G)
			{
				sum+=A;print[i]='A';
			}
			else if(C>A&&C>=G&&C>=T)
{
sum+=C;print[i]='C';
}
else if(G>C&&G>A&&G>=T)
{
sum+=G;
print[i]='G';
}
else if(T>G&&T>A&&T>C)
{
sum+=T;print[i]='T';
}
}
print[i]='\0';/*
for(int i=0;i<b;i++)  
{
printf("%c",print[i]);  
}
printf("\n");  
printf("%d\n",a*b-sum);  
}*/
for(int i=0;i<b;i++){
        printf("%d",print[i]);
}
printf("\n");
printf("%d\n",a*b-sum);
}
return 0;
}

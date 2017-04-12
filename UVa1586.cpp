#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100
char s[max];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		double sum = 0;
		scanf("%s", s);
		double arr[] = { 12.01, 1.008, 16.00, 14.01 };
		int a[4];
		memset(a, 0, sizeof(a));
		int len = strlen(s);
		for (int i = 0; i < len; i++)
		{
			if (s[i] == 'C')
			if (isdigit(s[i + 1]) && isdigit(s[i + 2]))
				a[0] += 10 * (s[i + 1] - '0') + (s[i + 2] - '0');
			else
				a[0] += isdigit(s[i + 1]) ? s[i + 1] - '0' : 1;
			if (s[i] == 'H')
			if (isdigit(s[i + 1]) && isdigit(s[i + 2]))
				a[1] += 10 * (s[i + 1] - '0') + (s[i + 2] - '0');
			else
				a[1] += isdigit(s[i + 1]) ? s[i + 1] - '0' : 1;
			if (s[i] == 'O')
			if (isdigit(s[i + 1]) && isdigit(s[i + 2]))
				a[2] += 10 * (s[i + 1] - '0') + (s[i + 2] - '0');
			else
				a[2] += isdigit(s[i + 1]) ? s[i + 1] - '0' : 1;
			if (s[i] == 'N')
			if (isdigit(s[i + 1]) && isdigit(s[i + 2]))
				a[3] += 10 * (s[i + 1] - '0') + (s[i + 2] - '0');
			else
				a[3] += isdigit(s[i + 1]) ? s[i + 1] - '0' : 1;
		}
		for (int i = 0; i < 4; i++)
			sum += arr[i] * a[i];
		printf("%.03f\n", sum);
	}
	return 0;
}

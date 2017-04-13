//Puzzle 1993Final UVa227
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=4&page=show_problem&problem=163
/*题目分析：题目需要做的事情

①输入55的字符，每个格子有一个字母，有一个格子是空格

②找出输入字符空格的具体位置，保存下来

③之后分别检测指令A,B,L,R,这里还需要注意边界的地方，

④最后根据指令进行移动，最后从新输出每个格子的每个字符

学习笔记：

①这道题跟以前那道填数字的题目，有区别，因为题目中需要两个输入，格子形状输入用gets(a[i])表示第几行。输出的时候可以采用循环printf("%c %c %c %c %c\n", a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]); 注意这里输入不能用scanf因为有一个是空格。这样就输出我们需要的结果了。

②对于检测指令，第一步是如果是非法指令，但是我们不好描述条件时，输出，这个时候为了和和发指令区分开来，所以我们设置了一个flag，如果非法时，我们设为0这样最后输出的时候，我们就有条件

③检测指令的时候，还需要注意边界问题，记住a[x][y] x代表的是竖直方向，y代表的是水平方向。一定要注意边界问题

④检测到指令的时候，我们首先需要将空格移动到目标位置的值放在空格区域，之后把空格放入目标区域这个与以前填数多一步，因为以前那个目标区域全是0

*/
#include <stdio.h>
#include <string.h>
#define maxn 20
#define command 10000
char a[maxn][maxn];
char s[command];
int main(){
	int blank_x=0,blank_y=0;
	int flag = 1;
	gets(a[0]);
	gets(a[1]);
	gets(a[2]);
	gets(a[3]);
	gets(a[4]);
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			if (a[x][y]==' ')
			{
				blank_x = x;
				blank_y = y;
			}
		}
	}
	gets(s);
	int len = strlen(s);
	for (int i = 0; i < len; i++ )
	{
		if (s[len-1]=='0'||s[i]=='A'||s[i]=='R'||s[i]=='L'||s[i]=='B')
		{
			if (s[i] == 'A' && blank_x != 0)
			{
				a[blank_x][blank_y] = a[blank_x-1]a[blank_y];
				a[--blank_x][blank_y] = ' ';
			}
			if (s[i] == 'R' && blank_y != 4)
			{
				a[blank_x][blank_y] = a[blank_x][blank_y+1];
                a[blank_x][++blank_y] = ' ';
			}
			if (s[i]=='B'&& blank_x != 4)
			{
				 a[blank_x][blank_y] = a[blank_x+1][ blank_y];
                a[++blank_x][ blank_y] = ' ';			}
                if (s[i] == 'L' && blank_y != 0)
                {
                	a[blank_x][blank_y] = a[blank_x][ blank_y-1];
                a[blank_x][--blank_y] = ' ';
                }
		}
		else flag = 0;
	}
	if (flag)
	{
		for (int i = 0; i < 5; i++)
		{
			printf("%c %c %c %c %c\n",a[i][0], a[i][1], a[i][2], a[i][3], a[i][4] );
		}
	}
		else 
			printf("This puzzle has no final configuration.");
	return 0;
}

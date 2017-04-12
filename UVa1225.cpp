/*Trung is bored with his mathematics homeworks. He takes a piece of chalk and starts writing a sequence of consecutive integers starting with 1 to N (1 < N < 10000) . After that, he counts the number of times each digit (0 to 9) appears in the sequence. For example, with N = 13 , the sequence is:
12345678910111213
In this sequence, 0 appears once, 1 appears 6 times, 2 appears 2 times, 3 appears 3 times, and each digit from 4 to 9 appears once. After playing for a while, Trung gets bored again. He now wants to write a program to do this for him. Your task is to help him with writing this program.
Input 
The input file consists of several data sets. The first line of the input file contains the number of data sets which is a positive integer and is not bigger than 20. The following lines describe the data sets.
For each test case, there is one single line containing the number N .
Output 
For each test case, write sequentially in one line the number of digit 0, 1,...9 separated by a space.
Sample Input 
2 
3 
13
Sample Output 
0 1 1 1 0 0 0 0 0 0 
1 6 2 2 1 1 1 1 1 1*/
#include <stdio.h>
int main()
{
    int T,b,c,i,n,j,e,t;
    scanf("%d",&T);
    while(T--)
    {
        int k[10]={0};
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            t=i;
            j=0;
            int a[5]={0};
            while(t)
            {
                a[j++]=t%10;
                t/=10;
            }
            for(e=0;e<j;e++)
                k[a[e]]++;
        }
        int first=1;
        for(i=0;i<10;i++)
        {
            if(first)
                first=0;
            else printf(" ");
            printf("%d",k[i]);
        }
        printf("\n");
    }
}


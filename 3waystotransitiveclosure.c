#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<time.h>
#define N 350
#define TRUE 0
int Arr[N][N] = {{0}};
int b[N][N] = {{0}};
int generate_random_matrix()
{
        int i = 0;
        int j = 0;
        srand(time(NULL));
        for (i = 0; i < N; ++i)
        {
                for (j = 0; j < N; ++j)
                {
                        Arr[i][j] = rand() % 2;
                }
        }
        /*for(i=0;i<N;++i){
                        for(j=0;j<N;++j){
                                printf("%d\t",Arr[i][j]);
                        }
                }
                printf("产生完毕\n");
                return 0;*/
}
int output_matrix(int a[N][N])
{
        int i = 0, j = 0;
        for (i = 0; i < N; i++)
        {
                for (j = 0; j < N; j++)
                {
                        printf("%d\t", a[i][j]);
                }
                putchar('\n');
        }
        return TRUE;
}
int warshall(int a[N][N])
{
        int col = 0;
        int line = 0;
        int temp = 0;
        for (col = 0; col < N; col++)
        {
                for (line = 0; line < N; line++)
                {
                        if (a[line][col] != 0)
                        {
                                for (temp = 0; temp < N; temp++)
                                {
                                        a[line][temp] = a[line][temp] | a[col][temp];
                                }
                        }
                }
        }
        return TRUE;
}
int warshallb(int a[N][N])
{
        int i = 0;
        int j = 0;
        int k = 0;
        for ( k = 0; k < N; k++)
        {
                for (i = 0; i < N; i++)
                {
                        for ( j = 0; j < N; j++)
                        {
                                a[i][j] = a[i][j] | a[k][j];
                        }
                }
        }
}
int intitialWay(int a[N][N])
{
        int i, j, k, flag, n;
        for (i = 0; i < N; i++)
        {
                for (j = 0; j < N; j++)
                {
                        b[i][j] = a[i][j];
                }
        }//赋值操作
        //布尔积部分
        for (n = 2; n <= N; n++)
        {
                for (k = 0; k < N; k++)
                {
                        for (i = 0; i < N; i++)
                        {
                                for (j = 0; j < N; j++)
                                {
                                        a[i][j] |= (b[i][k] & b[k][j]);  /*flag = 0;

                                        if ((b[i][k] == 1 ) && (b[k][j] == 1))
                                        {
                                                flag = 1;
                                        }
                                        a[i][j] = a[i][j]|flag;*/


                                }
                        }

                }
        }

        /*for ( i = 0; i < N; ++i)
        {
                for ( j = 0;j<N;++j)
                {
                        a[i][j]=(a[i][j])|(c[i][j]);
                }
        }*/
}
int main(void)
{
        int i;
        for (i = 0; i <= 10; i++)
        {
                clock_t start, finish;
                double duration;
                FILE *stream;
                stream = fopen("d://test1.txt", "a+" );
                generate_random_matrix();
                start = clock();
                intitialWay(Arr);
                output_matrix(Arr);
                finish = clock();
                duration = (double)(finish - start) / CLOCKS_PER_SEC;
                fprintf(stream, "%f seconds\n", duration );
                fclose(stream);
        }
        return 0;
}

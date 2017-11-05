#include <stdio.h>

#define MAXSIZE 50
int i;

typedef struct//定义顺序存储结构体
{
    char data[MAXSIZE];
    int length;
}List;

void InitList(List *P)//初始化空表
{
    int n;
    for(i=0;i<P->length;i++)//初始化所有内容为\0
        P->data[i] = '\0';
    P->length = 0;
    printf("请输入存入字符的个数：");
    scanf("%d",&n);
    getchar();//接收一个字符防止回车对内容的影响
    printf("请输入内容：");
    for(i=0;i<n;i++)
    {
        scanf("%c",&P->data[i]);
        P->length++;
    }
    printf("存入完毕！\n\n");
}

int ListEmpty(List L)//空表返回0,非空表返回1
{
    if(L.length == 0)//空表
        return 0;
    else
        return 1;
}

void ClearList(List *P)//清空线性表
{
    for(i=0;i<P->length;i++)
        P->data[i] = '\0';
    P->length=0;
    printf("线性表已清空！\n\n");
}

char GetElem(List L,int x,char e)//得到第x个位置的元素并赋值给e返回
{
    if(x<1 || x>L.length)//查找的位置超出范围
    {
        printf("位置异常！\n\n");
        return 0;
    }
    else
    {
        e = L.data[x-1];
        return e;
    }
}

int LocateElem(List L,char e)
{
    for(i=0;i<L.length;i++)//查找e的位置
        if(L.data[i] == e)
            return i+1;
    return 0;
}

int ListInsert(List *P,int x,char e)//删除位置x上的数据，成功返回1，失败返回0
{
    printf("在第%d个位置插入%c\n",x,e);
    if(P->length == MAXSIZE)//表满了
    {
        printf("线性表已满，插入失败！\n");
        return 0;
    }
    if(x<1 || x>P->length+1)//超出范围，超出最后一位异常才是异常
    {
        printf("插入位置异常，插入失败！\n");
        return 0;
    }
    if(x <= P->length)//插入位置不再尾部
    {
        for(i=P->length-1;i>=x-1;i--)
            P->data[i+1] = P->data[i];
        P->data[x-1] = e;
        P->length++;
        printf("插入成功！\n");
        return 1;
    }
    if(x == P->length+1)//插入位置在尾部
    {
        P->data[x] = e;
        P->length++;
        printf("插入成功！\n\n");
        return 1;
    }
}

char ListDelete(List *P,int x,char e)//删除位置x上的数据，成功返回e,失败返回0
{
    printf("删除第%d位置上的数据\n",x);
    if(P->length == 0)//空表
    {
        printf("线性表为空表，删除失败！\n");
        return 0;
    }
    if(x<1 || x>P->length)//范围异常
    {
        printf("删除位置异常，删除失败！\n");
        return 0;
    }
    if(x < P->length)//删除位置不是尾部
    {
        e = P->data[x-1];
        for(i=x;i<P->length;i++)
            P->data[i-1] = P->data[i];
        P->data[P->length-1] = '\0';
        P->length--;
        printf("删除成功！\n");
        return e;
    }
    if(x == P->length)//删除位置在尾部
    {
        e = P->data[x-1];
        P->data[x-1] = '\0';
        P->length--;
        printf("删除成功！\n\n");
        return e;
    }
}

void OutputList(List L)//输出线性表中内容
{
    if(L.length == 0)
        printf("线性表中没有内容，为空表！");
    else
    {
         printf("线性表内容如下：\n");
        for(i=0;i<L.length;i++)
            printf("%c",L.data[i]);
        printf("\n\n");
    }
}

int main()
{
    List L;

    InitList(&L);//测试初始化

    if(ListEmpty(L))
        printf("线性表非空！\n\n");
    else printf("线性表为空！\n\n");

    OutputList(L);

    char E;
    printf("请输入查找的位置：");//测试按位置查找
    scanf("%d",&i);
    E = GetElem(L,i,E);
    if(E != 0)
        printf("第%d个位置上是：%c\n\n",i,E);

    printf("请输入要查找的元素：");//测试按元素查找
    getchar();
    scanf("%c",&E);
    i = LocateElem(L,E);
    if(i)
        printf("%c在线性表中的位置是：%d\n\n",E,i);
    else printf("没有在线性表中找到%c\n\n",E);

    printf("请输入插入字符：");//测试插入
    getchar();
    scanf("%c",&E);
    printf("请输入插入的位置：");
    scanf("%d",&i);
    ListInsert(&L,i,E);
    OutputList(L);

    int j;
    printf("请输入删除的元素位置：");//测试删除
    scanf("%d",&j);
    E = ListDelete(&L,j,E);
    if(E != 0)
        printf("线性表第%d个位置的%c已删除！\n\n",j,E);
    OutputList(L);

    ClearList(&L);//测试清空
    if(ListEmpty(L))
        printf("线性表非空！\n\n");
    else printf("线性表为空！\n\n");
    OutputList(L);
    return 0;
}

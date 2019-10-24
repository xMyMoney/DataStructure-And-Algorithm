#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100
typedef int datatype;
typedef struct
{
	datatype data[MAXSIZE];
	int length;
}SeqList;
/*
初始化顺序表*/
SeqList *Init_SeqList()
{
	SeqList* L;
	L = new SeqList;
	L->length = 0;
	return L;
}
/*
插入运算
在第i位置进行插入
步骤: 1.将n到i顺序向后移动一位，以空出第i个元素的位置
      2.将x置入空出的位置
	  3.修改顺序表的长度，+1*/
int Insert_SeqList(SeqList* L, int i, datatype x)
{
	int j;
	if (L->length == MAXSIZE - 1)              //顺序表已满，不能插入
	{
		printf("顺序表已满！\n");
		return 0;
	}
	if (i < 1 || i>L->length + 1)               //检查插入位置是否合法 1<=i<=length+1
	{
		printf("插入位置不合法！\n");
			return 0;
	}
	for (j = L->length; j >= i; j--)
	{
		L->data[j + 1] = L->data[j];         //节点往后移动一位
	}
	L->data[i] = x;                         //将插入的值赋给i位置·
	L->length++;                            //表长加1，length仍指向表的最后一个元素
	return 1;
}
/*
删除运算
将第i个位置的元素进行删除
步骤:  1.将i+1到n顺序向前移动一位，即覆盖
       2.修改表长，-1*/
int Delete_SeqList(SeqList* L, datatype i)
{
	int j;
	if (i<1 || i>L->length)                //检查删除位置的合法性  1<=i<=n
	{
		return 0;
	}
	else {
		for (j = i; j <= L->length; j++)
		{
			L->data[j] = L->data[j + 1];  //向前移动一个位置进行覆盖
		}
		L->length--;
		return 1;
	}
}
/*
按值查找
查找顺序表中是否与x相等的值
步骤:  1.从第一个元素开始进行比较*/
int Search_SeqList(SeqList* L, datatype x)
{
	int i = 0;
	while (i <= L->length && L->data[i] != x)
	{
		i++;
	}
	if (i > L->length) {
		return 0;
	}
	else {
		return i;                           //返回x所在位置
	}
}
/*
取表中元素
按所给i位置得到元素*/
int Get_SeqList(SeqList* L, int i)
{
	if (i<1 || i>L->length + 1) {
		return 0;
	}
	else {
		return L->data[i];
	}
}
/*
打印顺序表*/
void Print(SeqList* L)
{
	int i = 1;
	while (i <= L->length) {
		printf("%d->",L->data[i]);
		i++;
	}
	printf("\n");
}
void main()
{
	SeqList* L=NULL;
	int i, j, k;
	datatype x;
	do
	{
		printf("\n\n\n\n");
		printf("\t\t\t 顺序表系统\n");
		printf("\t\t*******************************\n");
		printf("\t\t*        1----初始化表　  　　*\n");
		printf("\t\t*        2----插    入　　　　*\n");
		printf("\t\t*        3----删　　除　　　　*\n");
		printf("\t\t*        4----查　　找　　　　*\n");
		printf("\t\t*        5----显　　示　　　　*\n");
		printf("\t\t*        0----返　　回　　　　*\n");
		printf("\t\t*******************************\n");
		printf("\t\t 请选择菜单项(0－5)：");
		scanf_s("%d", &k); 
		getchar();
		switch (k)
		{
		case 1:
			L = Init_SeqList();    //初始化线性表
			break;
		case 2: 
			if (L == NULL) {
				printf("顺序表未初始化！");
				break;
			}
			else {
				printf("\n   请输入插入的位置i和数据X(输入格式：i,X):");     //在线性表第i位置处插入值为X的元素
				scanf_s("%d,%d", &i, &x);
				j = Insert_SeqList(L, i, x);
				break;
			}
			
		case 3:          //删除线性表中值为X的元素 
			printf("\n   请输入要删除元素的位置i:");
			scanf_s("%d", &i);
			j = Delete_SeqList(L, i);
			if (j == 1) {
				printf("删除成功!!");
			}
			else {
				printf("删除失败!!");
			}
			break;
		case 4:       //查找线性表中元素值为x的位置
			printf("\n   请输入要查找的数值X:");
			scanf_s("%d", &x);
			j = Search_SeqList(L, x);
			if (j != -1)
			{
				Print(L); printf("中值为X所在的位置是 %d ", j);
			}
			else
				printf("线性表中无此元素!!\n");
			break;
		case 5:        //输出线性表
			printf("\n线性表的顺序存储为：");
			Print(L);
			}
		} while (k != 0);
	}
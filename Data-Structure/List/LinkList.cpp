#include <stdio.h>
#include <malloc.h>
#define datatype int
typedef struct node
{
	datatype data;        //链表的数据域
	struct node* next;    //链表的指针域
} LNode, * LinkList;

/*
头插法
步骤:  1.将数据放入到新节点数据域
       2.将新节点指针域指向头节点指针域
       3.将头节点指针域指向新节点*/
LinkList  HeadCreat_LinkList()
{
	LinkList head;                          //头节点为空
	LNode* s;
	head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	char flag = 'y';
	printf("开始用头插法创建单链表:\n");
	while (flag == 'y' || flag == 'Y')
	{
		s = (LinkList)malloc(sizeof(LNode));
		printf("请输入新结点数据:");
		scanf_s("%d", &s->data);
		s->next = head->next;
		head->next = s;
		getchar();
		printf("是否继续输入?(Y/N):");
		scanf_s("%c", &flag);
	}
	return head;
}

/*
尾插法
步骤:  2.新节点链接在尾节点之后
       3.尾指针指向新节点，即始终指向尾部节点*/
LinkList RearCreat_LinkList()
{
	LinkList head;               
	LNode* s,*rear;
	head = (LNode *)malloc(sizeof(LNode));
	rear = head;                              //尾指针指向链表当前表尾
	char flag = 'y';
	printf("开始用尾插法创建单链表:\n");
	while (flag == 'y' || flag == 'Y')
	{
		s = (LNode *)malloc(sizeof(LNode));
		printf("请输入新结点数据:");
		scanf_s("%d", &s->data);
		rear->next = s;
		rear = s;                             //rear始终指向尾部节点                       
		getchar();
		printf("是否继续输入?(Y/N):");
		scanf_s("%c", &flag);
	}
	rear->next = NULL;                       //建表结束后尾节点指针域置为空
	return head;
}

/*插入操作
在单链表L的第i个位置上插入值为x的元素*/
int  Insert_LinkList(LinkList  L, int i, datatype  x)
{
	int j = 1;
	LinkList p = L;
	while (j < i && p) {
		p = p->next;
		j++;
	}
	if (j > i || !p) {
		printf("插入位置不正确！\n");
	}
	else {
		LinkList s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->next = p->next;
		p->next = s;
		return 1;
	}
	return 0;
}

/*
按序号查找
查找第i个元素结点，找到返回其指针，否则返回空*/
LNode* Get_LinkList(LinkList L, int i)
{
	int j;
	LNode* p;
	p = L;
	j = 0;
	while (p->next != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (i == j)
		return p;
	else
		return NULL;
}

/*
按值查找
查找单链表数据域中是否与x相等的元素，找到返回其指针，否则返回空*/
LNode* Locate_LinkList(LinkList L, datatype x)
{
	LNode* p = L->next;
	while (p != NULL && p->data != x)
	{
		p = p->next;
	}
	return p;
}

/*
删除操作----无返回删除节点的值
步骤:  1.寻找第i-1个节点,这个节点指针域指向第i个节点，即被删除节点
       2.第(i-1)个节点的指针域指向第(i+1)个节点
	   3.释放第i个节点空间
*/
int Del_LinkList_N(LinkList L, int i)
{
	LinkList p, s;
	p = Get_LinkList(L, i - 1);
	if(p==NULL)
	{
		printf("第%d个节点不存在！", i - 1);
		return 0;
	}
	else {
		if (p->next == NULL)
		{
			printf("第%d个节点不存在",i);
			return 0;
		}
		else {
			s = p->next;
			p->next = s->next;
			free(s);
			return 1;
		}
	}
}

/*
删除操作----有返回删除节点的值
步骤:  1.定义一个指针q,将其指向被删除的节点
	   2.将被删除节点的值赋给x所指向的变量
	   3.修改相应指针值删除节点，释放被删除节点空间
*/
int Del_LinkList_H(LinkList L, int i)
{
	/*  尾部删除
	LNode* q;
	int d = 0;
	if (p->next != NULL)
	{
		q = p->next;
		i = q->data;
		p->next = q->next;
		free(q);
		return d;
		
	}
	return 0;
	*/

	LinkList p, s;
	datatype del=0;
	p = Get_LinkList(L, i - 1);
	if (p == NULL)
	{
		printf("第%d个节点不存在！", i - 1);
		return 0;
	}
	else {
		if (p->next == NULL)
		{
			printf("第%d个节点不存在", i);
			return 0;
		}
		else {
			s = p->next;
			del = s->data;
			p->next = s->next;
			free(s);
			return del;
		}
	}
}

/*
求表长----带头节点*/
int Length_LinkList_H(LinkList L)
{
	LNode* p = L;
	int count = 0;
	while (p->next)
	{
		p = p->next;
		count++;
	}
	return count;
}

/*
求表长----不带头节点*/
int Length_LinkList_N(LinkList L)
{
	LNode* p = L;
	int count = 0;
	if (p == NULL)
	{
		return 0;
	}
	count = 1;
	while (p->next)
	{
		p = p->next;
		count++;
	}
	return count;
}

/*
输出单链表*/
void print(LinkList L)          
{
	LNode* p = L->next;
	while (p->next != NULL)
	{
		printf("%d->", p->data);    //输出表中非最后一个元素
		p = p->next;
	}
	printf("%d\n", p->data);      //输出表中最后一个元素    
}

void main()
{
	LinkList  H=NULL
		;
	int i, j, k;
	datatype x;
	do
	{
		printf("\n\n\n\n");
		printf("\t\t\t 链表子系统\n");
		printf("\t\t*******************************\n");
		printf("\t\t*        1----建    表　  　　*\n");
		printf("\t\t*        2----插    入　　　　*\n");
		printf("\t\t*        3----删　　除　　　　*\n");
		printf("\t\t*        4----查　　找　　　　*\n");
		printf("\t\t*        5----显　　示　　　　*\n");
		printf("\t\t*        0----返　　回　　　　*\n");
		printf("\t\t*******************************\n");
		printf("\t\t 请选择菜单项(0－5)：");
		scanf_s("%d", &k); getchar();
		switch (k)
		{
		case 1:
			H = HeadCreat_LinkList();      //用头插入法建立单链表
			break;
		case 2:
			print(H);
			printf("请输入插入的位置i和数据X(输入格式：i,X):");
			scanf_s("%d,%d", &i, &x);
			j = Insert_LinkList(H, i, x);
			if (j == 1)
			{
				printf("插入成功！");
				print(H);
			}
			else {
				printf("插入失败！");
			}
			break;
		case 3:
			print(H);
			printf("请输入要删除元素的位置i:");
			scanf_s("%d", &i);
			j = Del_LinkList_H(H, i);
			if (j != 0) {
				printf("删除成功!被删除数据为%d\n", j);
				print(H);
			}
			else {
				printf("删除失败!");
			}
			break;
		case 4:
			printf("\n   请输入要查找的序号i:");
			scanf_s("%d", &i);
			LNode* p;
			p = Get_LinkList(H, i);
			if (p != NULL)
			{
				print(H); printf("中序号为i的地址是 %d ", p);
			}
			else {
				printf("链表中无此序号!!\n");
			}
			break;
		case 5:
			printf("\n表的存储顺序为：");
			print(H);
			break;
		default:
			printf("无此选项！");
			break;
		}
	} while (k != 0);
}
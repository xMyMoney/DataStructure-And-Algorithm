#include <stdio.h>
#include <malloc.h>
#define datatype int
typedef struct node
{
	datatype data;        //�����������
	struct node* next;    //�����ָ����
} LNode, * LinkList;

/*
ͷ�巨
����:  1.�����ݷ��뵽�½ڵ�������
       2.���½ڵ�ָ����ָ��ͷ�ڵ�ָ����
       3.��ͷ�ڵ�ָ����ָ���½ڵ�*/
LinkList  HeadCreat_LinkList()
{
	LinkList head;                          //ͷ�ڵ�Ϊ��
	LNode* s;
	head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	char flag = 'y';
	printf("��ʼ��ͷ�巨����������:\n");
	while (flag == 'y' || flag == 'Y')
	{
		s = (LinkList)malloc(sizeof(LNode));
		printf("�������½������:");
		scanf_s("%d", &s->data);
		s->next = head->next;
		head->next = s;
		getchar();
		printf("�Ƿ��������?(Y/N):");
		scanf_s("%c", &flag);
	}
	return head;
}

/*
β�巨
����:  2.�½ڵ�������β�ڵ�֮��
       3.βָ��ָ���½ڵ㣬��ʼ��ָ��β���ڵ�*/
LinkList RearCreat_LinkList()
{
	LinkList head;               
	LNode* s,*rear;
	head = (LNode *)malloc(sizeof(LNode));
	rear = head;                              //βָ��ָ������ǰ��β
	char flag = 'y';
	printf("��ʼ��β�巨����������:\n");
	while (flag == 'y' || flag == 'Y')
	{
		s = (LNode *)malloc(sizeof(LNode));
		printf("�������½������:");
		scanf_s("%d", &s->data);
		rear->next = s;
		rear = s;                             //rearʼ��ָ��β���ڵ�                       
		getchar();
		printf("�Ƿ��������?(Y/N):");
		scanf_s("%c", &flag);
	}
	rear->next = NULL;                       //���������β�ڵ�ָ������Ϊ��
	return head;
}

/*�������
�ڵ�����L�ĵ�i��λ���ϲ���ֵΪx��Ԫ��*/
int  Insert_LinkList(LinkList  L, int i, datatype  x)
{
	int j = 1;
	LinkList p = L;
	while (j < i && p) {
		p = p->next;
		j++;
	}
	if (j > i || !p) {
		printf("����λ�ò���ȷ��\n");
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
����Ų���
���ҵ�i��Ԫ�ؽ�㣬�ҵ�������ָ�룬���򷵻ؿ�*/
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
��ֵ����
���ҵ��������������Ƿ���x��ȵ�Ԫ�أ��ҵ�������ָ�룬���򷵻ؿ�*/
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
ɾ������----�޷���ɾ���ڵ��ֵ
����:  1.Ѱ�ҵ�i-1���ڵ�,����ڵ�ָ����ָ���i���ڵ㣬����ɾ���ڵ�
       2.��(i-1)���ڵ��ָ����ָ���(i+1)���ڵ�
	   3.�ͷŵ�i���ڵ�ռ�
*/
int Del_LinkList_N(LinkList L, int i)
{
	LinkList p, s;
	p = Get_LinkList(L, i - 1);
	if(p==NULL)
	{
		printf("��%d���ڵ㲻���ڣ�", i - 1);
		return 0;
	}
	else {
		if (p->next == NULL)
		{
			printf("��%d���ڵ㲻����",i);
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
ɾ������----�з���ɾ���ڵ��ֵ
����:  1.����һ��ָ��q,����ָ��ɾ���Ľڵ�
	   2.����ɾ���ڵ��ֵ����x��ָ��ı���
	   3.�޸���Ӧָ��ֵɾ���ڵ㣬�ͷű�ɾ���ڵ�ռ�
*/
int Del_LinkList_H(LinkList L, int i)
{
	/*  β��ɾ��
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
		printf("��%d���ڵ㲻���ڣ�", i - 1);
		return 0;
	}
	else {
		if (p->next == NULL)
		{
			printf("��%d���ڵ㲻����", i);
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
���----��ͷ�ڵ�*/
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
���----����ͷ�ڵ�*/
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
���������*/
void print(LinkList L)          
{
	LNode* p = L->next;
	while (p->next != NULL)
	{
		printf("%d->", p->data);    //������з����һ��Ԫ��
		p = p->next;
	}
	printf("%d\n", p->data);      //����������һ��Ԫ��    
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
		printf("\t\t\t ������ϵͳ\n");
		printf("\t\t*******************************\n");
		printf("\t\t*        1----��    ��  ����*\n");
		printf("\t\t*        2----��    �롡������*\n");
		printf("\t\t*        3----ɾ��������������*\n");
		printf("\t\t*        4----�顡���ҡ�������*\n");
		printf("\t\t*        5----�ԡ���ʾ��������*\n");
		printf("\t\t*        0----�������ء�������*\n");
		printf("\t\t*******************************\n");
		printf("\t\t ��ѡ��˵���(0��5)��");
		scanf_s("%d", &k); getchar();
		switch (k)
		{
		case 1:
			H = HeadCreat_LinkList();      //��ͷ���뷨����������
			break;
		case 2:
			print(H);
			printf("����������λ��i������X(�����ʽ��i,X):");
			scanf_s("%d,%d", &i, &x);
			j = Insert_LinkList(H, i, x);
			if (j == 1)
			{
				printf("����ɹ���");
				print(H);
			}
			else {
				printf("����ʧ�ܣ�");
			}
			break;
		case 3:
			print(H);
			printf("������Ҫɾ��Ԫ�ص�λ��i:");
			scanf_s("%d", &i);
			j = Del_LinkList_H(H, i);
			if (j != 0) {
				printf("ɾ���ɹ�!��ɾ������Ϊ%d\n", j);
				print(H);
			}
			else {
				printf("ɾ��ʧ��!");
			}
			break;
		case 4:
			printf("\n   ������Ҫ���ҵ����i:");
			scanf_s("%d", &i);
			LNode* p;
			p = Get_LinkList(H, i);
			if (p != NULL)
			{
				print(H); printf("�����Ϊi�ĵ�ַ�� %d ", p);
			}
			else {
				printf("�������޴����!!\n");
			}
			break;
		case 5:
			printf("\n��Ĵ洢˳��Ϊ��");
			print(H);
			break;
		default:
			printf("�޴�ѡ�");
			break;
		}
	} while (k != 0);
}
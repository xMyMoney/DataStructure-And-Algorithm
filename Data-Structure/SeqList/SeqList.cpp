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
��ʼ��˳���*/
SeqList *Init_SeqList()
{
	SeqList* L;
	L = new SeqList;
	L->length = 0;
	return L;
}
/*
��������
�ڵ�iλ�ý��в���
����: 1.��n��i˳������ƶ�һλ���Կճ���i��Ԫ�ص�λ��
      2.��x����ճ���λ��
	  3.�޸�˳���ĳ��ȣ�+1*/
int Insert_SeqList(SeqList* L, int i, datatype x)
{
	int j;
	if (L->length == MAXSIZE - 1)              //˳������������ܲ���
	{
		printf("˳���������\n");
		return 0;
	}
	if (i < 1 || i>L->length + 1)               //������λ���Ƿ�Ϸ� 1<=i<=length+1
	{
		printf("����λ�ò��Ϸ���\n");
			return 0;
	}
	for (j = L->length; j >= i; j--)
	{
		L->data[j + 1] = L->data[j];         //�ڵ������ƶ�һλ
	}
	L->data[i] = x;                         //�������ֵ����iλ�á�
	L->length++;                            //����1��length��ָ�������һ��Ԫ��
	return 1;
}
/*
ɾ������
����i��λ�õ�Ԫ�ؽ���ɾ��
����:  1.��i+1��n˳����ǰ�ƶ�һλ��������
       2.�޸ı���-1*/
int Delete_SeqList(SeqList* L, datatype i)
{
	int j;
	if (i<1 || i>L->length)                //���ɾ��λ�õĺϷ���  1<=i<=n
	{
		return 0;
	}
	else {
		for (j = i; j <= L->length; j++)
		{
			L->data[j] = L->data[j + 1];  //��ǰ�ƶ�һ��λ�ý��и���
		}
		L->length--;
		return 1;
	}
}
/*
��ֵ����
����˳������Ƿ���x��ȵ�ֵ
����:  1.�ӵ�һ��Ԫ�ؿ�ʼ���бȽ�*/
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
		return i;                           //����x����λ��
	}
}
/*
ȡ����Ԫ��
������iλ�õõ�Ԫ��*/
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
��ӡ˳���*/
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
		printf("\t\t\t ˳���ϵͳ\n");
		printf("\t\t*******************************\n");
		printf("\t\t*        1----��ʼ����  ����*\n");
		printf("\t\t*        2----��    �롡������*\n");
		printf("\t\t*        3----ɾ��������������*\n");
		printf("\t\t*        4----�顡���ҡ�������*\n");
		printf("\t\t*        5----�ԡ���ʾ��������*\n");
		printf("\t\t*        0----�������ء�������*\n");
		printf("\t\t*******************************\n");
		printf("\t\t ��ѡ��˵���(0��5)��");
		scanf_s("%d", &k); 
		getchar();
		switch (k)
		{
		case 1:
			L = Init_SeqList();    //��ʼ�����Ա�
			break;
		case 2: 
			if (L == NULL) {
				printf("˳���δ��ʼ����");
				break;
			}
			else {
				printf("\n   ����������λ��i������X(�����ʽ��i,X):");     //�����Ա��iλ�ô�����ֵΪX��Ԫ��
				scanf_s("%d,%d", &i, &x);
				j = Insert_SeqList(L, i, x);
				break;
			}
			
		case 3:          //ɾ�����Ա���ֵΪX��Ԫ�� 
			printf("\n   ������Ҫɾ��Ԫ�ص�λ��i:");
			scanf_s("%d", &i);
			j = Delete_SeqList(L, i);
			if (j == 1) {
				printf("ɾ���ɹ�!!");
			}
			else {
				printf("ɾ��ʧ��!!");
			}
			break;
		case 4:       //�������Ա���Ԫ��ֵΪx��λ��
			printf("\n   ������Ҫ���ҵ���ֵX:");
			scanf_s("%d", &x);
			j = Search_SeqList(L, x);
			if (j != -1)
			{
				Print(L); printf("��ֵΪX���ڵ�λ���� %d ", j);
			}
			else
				printf("���Ա����޴�Ԫ��!!\n");
			break;
		case 5:        //������Ա�
			printf("\n���Ա��˳��洢Ϊ��");
			Print(L);
			}
		} while (k != 0);
	}
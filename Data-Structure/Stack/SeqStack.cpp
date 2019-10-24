#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100
typedef int datatype;
typedef struct
{
	datatype data[MAXSIZE];
	int top;
}SeqStack;

/*
������ջ
��ջ��־ top=-1*/
SeqStack* Init_Stack()
{
	SeqStack * s;
	s = new SeqStack;
	s->top = -1;
	return s;
}

/*�жϿ�ջ*/
int Empty_Stack(SeqStack *s)
{
	if (s->top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

/*��ջ*/
int Push_Stack(SeqStack* s, datatype e)
{
	if (s->top == MAXSIZE - 1) {        //ջ��
		return 0;
	}
	else {
		s->top++;                       //ջ��+1
		s->data[s->top] = e;            //����������ջ��Ԫ��
		return 1;
	}
}

/*��ջ*/
int Pop_Stack(SeqStack* s, datatype* e)
{
	if (Empty_Stack(s)) {              //ջ�ղ��ܳ�ջ
		return 0;
	}
	else {
		*e = s->data[s->top];          //ջ��Ԫ�ش���e
		s->top--;                      //ջ��-1
		return *e;
	}
}

/*ȡջ��Ԫ��*/
datatype GetTop_Stack(SeqStack* s)
{
	if (Empty_Stack(s)) {
		return 0;
	}else{
		return s->data[s->top];
	}
}

/*���ջ*/
void Destroy_Stack(SeqStack *s)
{
	s->top = -1;
}

/*/��ջ����*/
int Length_Stack(SeqStack* s) {
	return s->top + 1;           //�����±��0��ʼ,+1
}

/*��ӡջ*/
void print(SeqStack* s)
{
	int i = 0;
	while (i<=s->top)
	{
		printf("%d->", s->data[i]);
		i++;
	}
	printf("\n");
}

void main()
{
	SeqStack* s = NULL;
	int i, j, k;
	datatype x;
	do
	{
		printf("\n\n\n\n");
		printf("\t\t\t ˳��ջϵͳ\n");
		printf("\t\t*******************************\n");
		printf("\t\t*        1----��ʼ��ջ��  ����*\n");
		printf("\t\t*        2----��    ջ��������*\n");
		printf("\t\t*        3----������ջ��������*\n");
		printf("\t\t*        4----ջ��Ԫ�ء�������*\n");
		printf("\t\t*        5----ջ��������������*\n");
		printf("\t\t*        6----��ӡ  ջ��������*\n");
		printf("\t\t*        0----�������ء�������*\n");
		printf("\t\t*******************************\n");
		printf("\t\t ��ѡ��˵���(0��5)��");
		scanf_s("%d", &k);
		getchar();
		switch (k)
		{
		case 1:
			s = Init_Stack();    
			break;
		case 2:
			printf("\n   ��������ջ����X(�����ʽ:X):");     
			scanf_s("%d", &x);
			j = Push_Stack(s, x);
			break;
		case 3:
			print(s);
			j = Pop_Stack(s, &x);
			if (j != 0) {
				printf("��ջ�ɹ�!��ջԪ��Ϊ%d\n",j);
				print(s);
			}
			else {
				printf("��ջʧ��!!");
			}
			break;
		case 4:       
			x = GetTop_Stack(s);
			printf("ջ��Ԫ��:%d\n",x);
			print(s);
			break;
		case 5:        
			j = Length_Stack(s);
			printf("ջ��=%d\n",j);
			break;
		case 6:
			print(s);
			break;
		}
	} while (k != 0);
}
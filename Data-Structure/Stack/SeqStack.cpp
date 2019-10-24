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
建立空栈
空栈标志 top=-1*/
SeqStack* Init_Stack()
{
	SeqStack * s;
	s = new SeqStack;
	s->top = -1;
	return s;
}

/*判断空栈*/
int Empty_Stack(SeqStack *s)
{
	if (s->top == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

/*入栈*/
int Push_Stack(SeqStack* s, datatype e)
{
	if (s->top == MAXSIZE - 1) {        //栈满
		return 0;
	}
	else {
		s->top++;                       //栈顶+1
		s->data[s->top] = e;            //将数据置入栈顶元素
		return 1;
	}
}

/*出栈*/
int Pop_Stack(SeqStack* s, datatype* e)
{
	if (Empty_Stack(s)) {              //栈空不能出栈
		return 0;
	}
	else {
		*e = s->data[s->top];          //栈顶元素存入e
		s->top--;                      //栈顶-1
		return *e;
	}
}

/*取栈顶元素*/
datatype GetTop_Stack(SeqStack* s)
{
	if (Empty_Stack(s)) {
		return 0;
	}else{
		return s->data[s->top];
	}
}

/*清空栈*/
void Destroy_Stack(SeqStack *s)
{
	s->top = -1;
}

/*/求栈长度*/
int Length_Stack(SeqStack* s) {
	return s->top + 1;           //数组下标从0开始,+1
}

/*打印栈*/
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
		printf("\t\t\t 顺序栈系统\n");
		printf("\t\t*******************************\n");
		printf("\t\t*        1----初始化栈　  　　*\n");
		printf("\t\t*        2----入    栈　　　　*\n");
		printf("\t\t*        3----出　　栈　　　　*\n");
		printf("\t\t*        4----栈顶元素　　　　*\n");
		printf("\t\t*        5----栈　　长　　　　*\n");
		printf("\t\t*        6----打印  栈　　　　*\n");
		printf("\t\t*        0----返　　回　　　　*\n");
		printf("\t\t*******************************\n");
		printf("\t\t 请选择菜单项(0－5)：");
		scanf_s("%d", &k);
		getchar();
		switch (k)
		{
		case 1:
			s = Init_Stack();    
			break;
		case 2:
			printf("\n   请输入入栈数据X(输入格式:X):");     
			scanf_s("%d", &x);
			j = Push_Stack(s, x);
			break;
		case 3:
			print(s);
			j = Pop_Stack(s, &x);
			if (j != 0) {
				printf("出栈成功!出栈元素为%d\n",j);
				print(s);
			}
			else {
				printf("出栈失败!!");
			}
			break;
		case 4:       
			x = GetTop_Stack(s);
			printf("栈顶元素:%d\n",x);
			print(s);
			break;
		case 5:        
			j = Length_Stack(s);
			printf("栈长=%d\n",j);
			break;
		case 6:
			print(s);
			break;
		}
	} while (k != 0);
}
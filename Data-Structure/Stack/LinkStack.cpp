#include <stdio.h>
#include <malloc.h>
#define datatype int
typedef struct node
{
	datatype data;        //链表的数据域
	struct node* next;    //链表的指针域
} StackNode, * LinkStack;

/*置空栈*/
LinkStack Init_LinkStack()
{
	return NULL;
}

/*判断空栈*/
int Empty_LinkStack(LinkStack top)
{
	if (top == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

/*入栈*/
LinkStack Push_LinkStack(LinkStack top, datatype e)
{
	StackNode* s;
	s = new StackNode;
	s->data = e;
	s->next = top;
	top = s;
	return top;
}

/*出栈*/
LinkStack Pop_LinkStack(LinkStack top, datatype* e)
{
	StackNode* p;
	if (Empty_LinkStack(top)) {
		return 0;
	}
	else {
		*e = top->data;
		p = top;
		top = top->next;
		free(p);
		return top;
	}
}

/*取栈顶元素*/
datatype GetTop_LinkStack(LinkStack top)
{
	if (Empty_LinkStack(top)) {
		return 0;
	}
	else {
		return top->data;
	}
}

/*打印栈*/
void print(LinkStack  top)
{
	StackNode* p = top;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
}


void main()
{
	LinkStack  S = NULL
		;
	int i, j, k;
	datatype x;
	do
	{
		printf("\n\n\n\n");
		printf("\t\t\t 链栈系统\n");
		printf("\t\t*******************************\n");
		printf("\t\t*        1----建    栈　  　　*\n");
		printf("\t\t*        2----入    栈　　　　*\n");
		printf("\t\t*        3----出　　栈　　　　*\n");
		printf("\t\t*        4----栈顶元素　　　　*\n");
		printf("\t\t*        5----显　　示　　　　*\n");
		printf("\t\t*        0----返　　回　　　　*\n");
		printf("\t\t*******************************\n");
		printf("\t\t 请选择菜单项(0－5)：");
		scanf_s("%d", &k); getchar();
		switch (k)
		{
		case 1:
			S = Init_LinkStack();      
			break;
		case 2:
			printf("请输入入栈的数据X:");
			scanf_s("%d",&x);
			S = Push_LinkStack(S,x);
			if (S != 0) {
				printf("入栈成功！\n");
				print(S);
			}
			else {
				printf("入栈失败！");
			}
			break;
		case 3:
			print(S);
			S = Pop_LinkStack(S, &x);
			if (x != 0) {
				printf("出栈成功！\n出栈元素是:%d",x);
			}
			else {
				printf("出栈失败!");
			}
			break;
		case 4:
			x = GetTop_LinkStack(S);
			if (x != 0) {
				printf("栈顶元素:%d",x);
			}
			else {
				printf("栈空");
			}			
			break;
		case 5:
			printf("\n栈的链式储存为：");
			print(S);
			break;
		case 0:
			break;
		default:
			printf("无此选项！");
			break;
		}
	} while (k != 0);
}

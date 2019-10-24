#include <stdio.h>
#include <malloc.h>
#define datatype int
typedef struct node
{
	datatype data;        //�����������
	struct node* next;    //�����ָ����
} StackNode, * LinkStack;

/*�ÿ�ջ*/
LinkStack Init_LinkStack()
{
	return NULL;
}

/*�жϿ�ջ*/
int Empty_LinkStack(LinkStack top)
{
	if (top == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

/*��ջ*/
LinkStack Push_LinkStack(LinkStack top, datatype e)
{
	StackNode* s;
	s = new StackNode;
	s->data = e;
	s->next = top;
	top = s;
	return top;
}

/*��ջ*/
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

/*ȡջ��Ԫ��*/
datatype GetTop_LinkStack(LinkStack top)
{
	if (Empty_LinkStack(top)) {
		return 0;
	}
	else {
		return top->data;
	}
}

/*��ӡջ*/
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
		printf("\t\t\t ��ջϵͳ\n");
		printf("\t\t*******************************\n");
		printf("\t\t*        1----��    ջ��  ����*\n");
		printf("\t\t*        2----��    ջ��������*\n");
		printf("\t\t*        3----������ջ��������*\n");
		printf("\t\t*        4----ջ��Ԫ�ء�������*\n");
		printf("\t\t*        5----�ԡ���ʾ��������*\n");
		printf("\t\t*        0----�������ء�������*\n");
		printf("\t\t*******************************\n");
		printf("\t\t ��ѡ��˵���(0��5)��");
		scanf_s("%d", &k); getchar();
		switch (k)
		{
		case 1:
			S = Init_LinkStack();      
			break;
		case 2:
			printf("��������ջ������X:");
			scanf_s("%d",&x);
			S = Push_LinkStack(S,x);
			if (S != 0) {
				printf("��ջ�ɹ���\n");
				print(S);
			}
			else {
				printf("��ջʧ�ܣ�");
			}
			break;
		case 3:
			print(S);
			S = Pop_LinkStack(S, &x);
			if (x != 0) {
				printf("��ջ�ɹ���\n��ջԪ����:%d",x);
			}
			else {
				printf("��ջʧ��!");
			}
			break;
		case 4:
			x = GetTop_LinkStack(S);
			if (x != 0) {
				printf("ջ��Ԫ��:%d",x);
			}
			else {
				printf("ջ��");
			}			
			break;
		case 5:
			printf("\nջ����ʽ����Ϊ��");
			print(S);
			break;
		case 0:
			break;
		default:
			printf("�޴�ѡ�");
			break;
		}
	} while (k != 0);
}

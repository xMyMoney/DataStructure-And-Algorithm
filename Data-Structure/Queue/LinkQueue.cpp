#include<stdio.h>
#include<malloc.h>
typedef int datatype;
typedef struct QNode {
	datatype data;
	struct QNode* next;
}QNode;
typedef struct {
	QNode* front;
	QNode* rear;
	int length;
}LinkQueue;

/*���ӳ�ʼ��*/
LinkQueue *Init_LinkQueue()
{
	LinkQueue* q;
	QNode* p;
	q = new LinkQueue;
	p = new QNode;
	p->next = NULL;
	q->front = q->rear = p;
	return q;
}

/*�ж϶ӿ�*/
int EmptyQueue(LinkQueue* q)
{
	if (q->front == q->rear) {
		return 1;
	}
	return 0;
}

/*���*/
int EnLinkQueue(LinkQueue *q,datatype e)
{
	QNode* p;
	p = new QNode;
	if (!p) {
		return 0;
	}
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
	q->length++;
	return 1;
}

/*����*/
int DeLinkQueue(LinkQueue* q, datatype* e)
{
	QNode* p;
	if (EmptyQueue(q)) {
		return 0;
	}
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (p == q->rear) {
		q->front = q->rear;
	}
	free(p);
	q->length--;
	return 1;
}

/*��ʾ����*/
void print(LinkQueue* q)
{
	QNode* p = q->front->next;
	while (p->next != NULL) {
		printf("%d<-",p->data);
		p = p->next;
	}
	printf("%d\n", p->data);
}

void main()
{
	LinkQueue *Q=NULL;
		;
	int i, j, k;
	datatype x;
	do
	{
		printf("\n\n\n\n");
		printf("\t\t\t ����ϵͳ\n");
		printf("\t\t*******************************\n");
		printf("\t\t*        1----��ʼ���С�  ����*\n");
		printf("\t\t*        2----��    ��  ������*\n");
		printf("\t\t*        3----�������ӡ�������*\n");
		printf("\t\t*        4----�ԡ���ʾ��������*\n");
		printf("\t\t*        0----�������ء�������*\n");
		printf("\t\t*******************************\n");
		printf("\t\t ��ѡ��˵���(0��4)��");
		scanf_s("%d", &k); getchar();
		switch (k)
		{
		case 1:
			Q = Init_LinkQueue();      
			break;
		case 2:
			printf("��������ӵ�����X:");
			scanf_s("%d", &x);
			j = EnLinkQueue(Q,x);
			if (j == 1)
			{
				printf("��ӳɹ���\n");
				print(Q);
			}
			else {
				printf("���ʧ�ܣ�");
			}
			break;
		case 3:
			print(Q);
			j =DeLinkQueue(Q,&x);
			if (j != 0) {
				printf("���ӳɹ�!����Ԫ��:%d\n", x);
				print(Q);
			}
			else {
				printf("����ʧ��!");
			}
			break;
		case 4:
			printf("���е���ʽ�洢˳��Ϊ��\n");
			print(Q);
			break;
		case 0:
			break;
		}
	} while (k != 0);
}
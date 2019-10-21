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

/*链队初始化*/
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

/*判断队空*/
int EmptyQueue(LinkQueue* q)
{
	if (q->front == q->rear) {
		return 1;
	}
	return 0;
}

/*入队*/
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

/*出队*/
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

/*显示队列*/
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
		printf("\t\t\t 链队系统\n");
		printf("\t\t*******************************\n");
		printf("\t\t*        1----初始队列　  　　*\n");
		printf("\t\t*        2----入    队  　　　*\n");
		printf("\t\t*        3----出　　队　　　　*\n");
		printf("\t\t*        4----显　　示　　　　*\n");
		printf("\t\t*        0----返　　回　　　　*\n");
		printf("\t\t*******************************\n");
		printf("\t\t 请选择菜单项(0－4)：");
		scanf_s("%d", &k); getchar();
		switch (k)
		{
		case 1:
			Q = Init_LinkQueue();      
			break;
		case 2:
			printf("请输入入队的数据X:");
			scanf_s("%d", &x);
			j = EnLinkQueue(Q,x);
			if (j == 1)
			{
				printf("入队成功！\n");
				print(Q);
			}
			else {
				printf("入队失败！");
			}
			break;
		case 3:
			print(Q);
			j =DeLinkQueue(Q,&x);
			if (j != 0) {
				printf("出队成功!出队元素:%d\n", x);
				print(Q);
			}
			else {
				printf("出队失败!");
			}
			break;
		case 4:
			printf("队列的链式存储顺序为：\n");
			print(Q);
			break;
		case 0:
			break;
		}
	} while (k != 0);
}
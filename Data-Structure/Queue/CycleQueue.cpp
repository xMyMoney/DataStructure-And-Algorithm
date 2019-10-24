#include<stdio.h>
#include<malloc.h>
#define MAXQSIZE 100
typedef int datatype;
typedef struct {
	datatype data[MAXQSIZE];
	int front, rear;
}CycleQueue;

/*�ÿն�*/
CycleQueue *Init_Queue()
{
	CycleQueue* q;
	q = new CycleQueue;
	q->front = q->rear = -1;
	return q;
}

/*�ж϶ӿ�*/
int Empty_Queue(CycleQueue* q)
{
	if (q->front == q->rear) {
		return 1;
	}
	return 0;
}

/*���*/
int EnQueue(CycleQueue* q, datatype e)
{
	if ((q->rear + 1) % MAXQSIZE == q->front) {
		printf("������");
		return 0;
	}
	else {
		q->rear = (q->rear + 1) % MAXQSIZE;
		q->data[q->rear] = e;
		return 1;
	}
}

/*����*/
int DelQueue(CycleQueue* q, datatype* e)
{
	if (Empty_Queue(q)) {
		printf("�ӿգ�");
		return 0;
	}
	else {
		q->front = (q->front + 1) % MAXQSIZE;
		*e = q->data[q->front];
		return 1;
	}
}

/*��ӡ����*/
void print(CycleQueue* q)
{
	int i = q->front;
	while (i!=q->rear) {
		printf("%d<-",q->data[i+1]);
		i = (i + 1) % MAXQSIZE;
	}
	printf("\n");
}

void main()
{
	CycleQueue* Q = NULL;
	int i, j, k;
	datatype x;
	do
	{
		printf("\n\n\n\n");
		printf("\t\t\t ѭ������ϵͳ\n");
		printf("\t\t*******************************\n");
		printf("\t\t*        1----�ÿն��С�  ����*\n");
		printf("\t\t*        2----��    �ӡ�������*\n");
		printf("\t\t*        3----�������ӡ�������*\n");
		printf("\t\t*        4----�ԡ���ʾ��������*\n");
		printf("\t\t*        0----�������ء�������*\n");
		printf("\t\t*******************************\n");
		printf("\t\t ��ѡ��˵���(0��4)��");
		scanf_s("%d", &k);
		getchar();
		switch (k)
		{
		case 1:
			Q = Init_Queue();   
			break;
		case 2:
			if (Q == NULL) {
				printf("˳���δ��ʼ����");
				break;
			}
			else {
				printf("\n��������ӵ�����X:");     
				scanf_s("%d",&x);
				j = EnQueue(Q, x);
				if (j == 1) {
					printf("��ӳɹ���\n");
				}
				else {
					printf("���ʧ�ܣ�\n");
				}
				break;
			}

		case 3:          
			j = DelQueue(Q, &x);
			if (j == 1) {
				printf("���ӳɹ�!����Ԫ��:%d",x);
			}
			else {
				printf("ɾ��ʧ��!!");
			}
			break;
		case 4:
			printf("ѭ������:\n");
			print(Q);
			break;
		}
	} while (k != 0);
}
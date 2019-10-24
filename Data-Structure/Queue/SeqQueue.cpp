#include<stdio.h>
#include<malloc.h>
#define QUEUESIZE 100
typedef int datatype;
typedef struct
{
	datatype data[QUEUESIZE];
	int front, rear;
}SeqQueue;

/*���г�ʼ��*/
SeqQueue *Init_SeqQueue()
{
	SeqQueue* q;
	q = new SeqQueue;
	q->front = q->rear=-1;             //��ͷ��β=1ʱ ����Ϊ��
	return q;
}

/*���*/
int EnSeqQueue(SeqQueue* q, datatype e)
{
	q->rear++;                         //��β+1
	q->data[q->rear] = e;              //���ݴ浽��β
	return 1;	
}

/*����*/
int DeSeqQueue(SeqQueue* q, datatype* e)
{

	if (q == NULL) {
		return 0;
	}
	else {
		q->front++;                    //��ͷ+1
		*e = q->data[q->front];        //ԭ��ͷԪ�ط���e��   
		return 1;
	}
}

/*��ӳ�*/
int LenSeqQueue(SeqQueue* q)
{
	if (q == NULL) {
		return 0;
	}
	else {
		return q->rear - q->front;
	}
}

/*���ͷ*/
datatype FontSeqQueue(SeqQueue* q)
{
	if (q == NULL) {
		return 0;
	}
	else {
		return q->data[q->front];
	}	
}

/*��ӡ����*/
void print(SeqQueue* q)
{
	int i = 0;
	while (i <= q->rear) {
		printf("%d<-",q->data[i]);
		i++;
	}
	printf("\n");
}

void main()
{
	SeqQueue* Q = NULL;
	int i, j, k;
	datatype x;
	do
	{
		printf("\n\n\n\n");
		printf("\t\t\t ˳�����ϵͳ\n");
		printf("\t\t*******************************\n");
		printf("\t\t*        1----��ʼ���С�  ����*\n");
		printf("\t\t*        2----��    �ӡ�������*\n");
		printf("\t\t*        3----�������ӡ�������*\n");
		printf("\t\t*        4----�ӡ�������������*\n");
		printf("\t\t*        5----�ӡ���ͷ��������*\n");
		printf("\t\t*        0----�������ء�������*\n");
		printf("\t\t*******************************\n");
		printf("\t\t ��ѡ��˵���(0��5)��");
		scanf_s("%d", &k);
		getchar();
		switch (k)
		{
		case 1:
			Q = Init_SeqQueue();    
			break;
		case 2:
			if (Q == NULL) {
				printf("����δ��ʼ����");
				break;
			}
			else {
				printf("\n��������ӵ�����X:");     
				scanf_s("%d",&x);
				j = EnSeqQueue(Q,x);
				print(Q);
				break;
			}			
		case 3:          
			j = DeSeqQueue(Q, &x);
			if (j == 1) {
				printf("���ӳɹ�!����Ԫ��:%d\n",x);
				print(Q);
			}
			else {
				printf("����ʧ��!\n");
				print(Q);
			}
			break;
		case 4:      
			print(Q);
			j = LenSeqQueue(Q);
			printf("\n ���жӳ�:%d",j);		
			break;
		case 5:  
			print(Q);
			x = FontSeqQueue(Q);
			printf("��ͷΪ:%d",x);
			break;
		}
	} while (k != 0);
}
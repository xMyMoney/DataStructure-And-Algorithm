#include<stdio.h>
#include<malloc.h>
#define QUEUESIZE 100
typedef int datatype;
typedef struct
{
	datatype data[QUEUESIZE];
	int front, rear;
}SeqQueue;

/*队列初始化*/
SeqQueue *Init_SeqQueue()
{
	SeqQueue* q;
	q = new SeqQueue;
	q->front = q->rear=-1;             //队头队尾=1时 队列为空
	return q;
}

/*入队*/
int EnSeqQueue(SeqQueue* q, datatype e)
{
	q->rear++;                         //队尾+1
	q->data[q->rear] = e;              //数据存到队尾
	return 1;	
}

/*出队*/
int DeSeqQueue(SeqQueue* q, datatype* e)
{

	if (q == NULL) {
		return 0;
	}
	else {
		q->front++;                    //队头+1
		*e = q->data[q->front];        //原队头元素放入e中   
		return 1;
	}
}

/*求队长*/
int LenSeqQueue(SeqQueue* q)
{
	if (q == NULL) {
		return 0;
	}
	else {
		return q->rear - q->front;
	}
}

/*求队头*/
datatype FontSeqQueue(SeqQueue* q)
{
	if (q == NULL) {
		return 0;
	}
	else {
		return q->data[q->front];
	}	
}

/*打印队列*/
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
		printf("\t\t\t 顺序队列系统\n");
		printf("\t\t*******************************\n");
		printf("\t\t*        1----初始队列　  　　*\n");
		printf("\t\t*        2----入    队　　　　*\n");
		printf("\t\t*        3----出　　队　　　　*\n");
		printf("\t\t*        4----队　　长　　　　*\n");
		printf("\t\t*        5----队　　头　　　　*\n");
		printf("\t\t*        0----返　　回　　　　*\n");
		printf("\t\t*******************************\n");
		printf("\t\t 请选择菜单项(0－5)：");
		scanf_s("%d", &k);
		getchar();
		switch (k)
		{
		case 1:
			Q = Init_SeqQueue();    
			break;
		case 2:
			if (Q == NULL) {
				printf("队列未初始化！");
				break;
			}
			else {
				printf("\n请输入入队的数据X:");     
				scanf_s("%d",&x);
				j = EnSeqQueue(Q,x);
				print(Q);
				break;
			}			
		case 3:          
			j = DeSeqQueue(Q, &x);
			if (j == 1) {
				printf("出队成功!出队元素:%d\n",x);
				print(Q);
			}
			else {
				printf("出队失败!\n");
				print(Q);
			}
			break;
		case 4:      
			print(Q);
			j = LenSeqQueue(Q);
			printf("\n 队列队长:%d",j);		
			break;
		case 5:  
			print(Q);
			x = FontSeqQueue(Q);
			printf("队头为:%d",x);
			break;
		}
	} while (k != 0);
}
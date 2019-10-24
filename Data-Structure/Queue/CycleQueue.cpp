#include<stdio.h>
#include<malloc.h>
#define MAXQSIZE 100
typedef int datatype;
typedef struct {
	datatype data[MAXQSIZE];
	int front, rear;
}CycleQueue;

/*置空队*/
CycleQueue *Init_Queue()
{
	CycleQueue* q;
	q = new CycleQueue;
	q->front = q->rear = -1;
	return q;
}

/*判断队空*/
int Empty_Queue(CycleQueue* q)
{
	if (q->front == q->rear) {
		return 1;
	}
	return 0;
}

/*入队*/
int EnQueue(CycleQueue* q, datatype e)
{
	if ((q->rear + 1) % MAXQSIZE == q->front) {
		printf("队满！");
		return 0;
	}
	else {
		q->rear = (q->rear + 1) % MAXQSIZE;
		q->data[q->rear] = e;
		return 1;
	}
}

/*出队*/
int DelQueue(CycleQueue* q, datatype* e)
{
	if (Empty_Queue(q)) {
		printf("队空！");
		return 0;
	}
	else {
		q->front = (q->front + 1) % MAXQSIZE;
		*e = q->data[q->front];
		return 1;
	}
}

/*打印队列*/
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
		printf("\t\t\t 循环队列系统\n");
		printf("\t\t*******************************\n");
		printf("\t\t*        1----置空队列　  　　*\n");
		printf("\t\t*        2----入    队　　　　*\n");
		printf("\t\t*        3----出　　队　　　　*\n");
		printf("\t\t*        4----显　　示　　　　*\n");
		printf("\t\t*        0----返　　回　　　　*\n");
		printf("\t\t*******************************\n");
		printf("\t\t 请选择菜单项(0－4)：");
		scanf_s("%d", &k);
		getchar();
		switch (k)
		{
		case 1:
			Q = Init_Queue();   
			break;
		case 2:
			if (Q == NULL) {
				printf("顺序表未初始化！");
				break;
			}
			else {
				printf("\n请输入入队的数据X:");     
				scanf_s("%d",&x);
				j = EnQueue(Q, x);
				if (j == 1) {
					printf("入队成功！\n");
				}
				else {
					printf("入队失败！\n");
				}
				break;
			}

		case 3:          
			j = DelQueue(Q, &x);
			if (j == 1) {
				printf("出队成功!出队元素:%d",x);
			}
			else {
				printf("删除失败!!");
			}
			break;
		case 4:
			printf("循环队列:\n");
			print(Q);
			break;
		}
	} while (k != 0);
}
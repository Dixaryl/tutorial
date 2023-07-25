#define MaxSize 10
#include <stdbool.h> 
#include <stdio.h>

// 循环队列（模运算将存储空间在逻辑上变成了“环状 ”） 
typedef struct {
	int data[MaxSize];
	int front, rear;
}SeQueue;

void InitQueue(SeQueue *Q){
	// front指向队头元素，rear指向队尾元素的后一个位置，也就是接下来数据要插入的位置 
	Q->front, Q->rear = Q->data[0]; 
} 

bool QueueEmpty(SeQueue *Q){
	if(Q->front == Q->rear){
		return true;
	}else{
		return false;
	}
}

// 入队
bool EnQueue(SeQueue *Q, int x){
	// 由于队列存在出队操作，当Q->rear == MaxSize时可能在队头附近又存在可以存放的空间 
	// 人为规定当队尾指针的再下一个位置是队头，则队列已满 
	if((Q->rear+1) % MaxSize == Q->front){
		return false;
	}
	Q->data[Q->rear] = x;
	// 模运算将无限的整数域映射到有限的整数集合上 
	Q->rear = (Q->rear+1) % MaxSize; 
	return true;
} 

// 出队，将出队的值返回 
bool DeQueue(SeQueue *Q, int *x){
	if(Q->front == Q->rear){
		return false;
	} 
	*x = Q->data[Q->front];
	Q->front = (Q->front+1) % MaxSize;
	return true;
} 

bool GetHead(SeQueue *Q, int *x){
	if(Q->front == Q->rear){
		return false;
	}
	*x = Q->data[Q->front];
	return true;
}

void main(){
	SeQueue Q;
	InitQueue(&Q);
	EnQueue(&Q, 1);
	int x;
	DeQueue(&Q, &x);
	printf("%d", x);
}
 // 循环队列数据元素个数：(rear+MaxSize-front) % MaxSize
 // 不想浪费循环队列的最后一块存储空间的话，需要在队列结构（struct）定义变量size，记录存放了几个数据元素
 // 替换方案：也可以在队列结构（struct）定义变量tag，记录最后一次的操作是删除还是添加，如果front == rear的最后一次操作是删除，那就只能添加不能删除，tag为0代表删除，tag为1代表添加 

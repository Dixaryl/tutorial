#include <stdbool.h>
#include <stdlib.h >
#include <stdio.h>

// 队列，链式存储
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode;

typedef struct {
	// 这两个变量是指向LinkNode数据结构，如果放在LinkNode中定义，每个结点都会有队头和队尾指针，显然有问题 
	LinkNode *front, *rear;
}LinkQueue;

bool InitQueue(LinkQueue *Q){
	// front，rear同时指向头结点 
	// 问题：为什么"(*Q).front, (*Q).rear  = (LinkNode *)malloc(sizeof(LinkNode));"能通过编译，但是结果不对，感觉和malloc有关 
	(*Q).front = (*Q).rear  = (LinkNode *)malloc(sizeof(LinkNode));
	(*Q).front->next = NULL;
	return true; 
}

bool IsEmpty(LinkQueue *Q){
	if((*Q).front == (*Q).rear){
		return true;
	}else{
		return false;
	}
} 

void EnQueue(LinkQueue *Q, int x){
	// 写的可读性有点差了，队尾结点的next本来指向NULL，现在分配一个新结点
	// 然后将表尾指针下移到下一个结点，分别赋值和修改next指针 
	(*Q).rear->next = (LinkNode *)malloc(sizeof(LinkNode));
	(*Q).rear = (*Q).rear->next;
	(*Q).rear->data = x;
	(*Q).rear->next = NULL;
} 

// 为什么有的函数返回bool有的却是void？这主要和学习的示例代码有关，示例代码本身的风格就不太统一，所以都用用看 
bool DeQueue(LinkQueue *Q, int *x){
	if((*Q).front == (*Q).rear){
		return false;
	}
	LinkNode *p = (*Q).front->next;
	*x = p->data;
	(*Q).front->next = p->next;
	// 如果删除的是队尾结点，需要特殊处理，直接销毁结点会导致rear下次使用时空指针 
	if((*Q).rear == p){
		(*Q).rear = (*Q).front; 
	}
	free(p);
	return true;
} 

bool GetHead(LinkQueue *Q, int *x){
	if((*Q).front == (*Q).rear){
		return false;
	}
	*x = (*Q).front->next->data;
	return true;
}

void main(){
	LinkQueue Q;
	InitQueue(&Q);
	// 简单测试
	EnQueue(&Q, 1);
	int x;
	GetHead(&Q, &x);
	printf("入队1后，队头的值是%d\n", x);
	EnQueue(&Q, 2);
	printf("入队2后，队头的值是%d\n", x);
	DeQueue(&Q, &x);
	GetHead(&Q, &x);
	printf("出队后，队头的值是%d\n", x);
	DeQueue(&Q, &x);
	printf("再次出队后，出队的值是%d\n", x);
} 

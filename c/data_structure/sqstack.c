// 栈（Stack）从逻辑结构来看是一种特殊的线性表，只允许在一端进行插入或删除 
// 栈顶：允许插入或删除的一端
// 特点：后进（入栈的数据元素）先出

#include <stdbool.h>
#include <stdio.h>
#define MaxSize 10

typedef struct{
	int data[MaxSize];
	int top;
}SqStack; 

// 初始化顺序栈
bool InitStack(SqStack *S){
	// 因为data[0]此时还没存放数据元素 
	(*S).top = -1;	
	return true; 
}

bool EmptyStack(SqStack *S){
	if((*S).top == -1){
		return true;
	}else{
		return false;
	}
} 

// 进栈（对于栈这种数据结构的插入操作）
bool Push(SqStack *S, int x){
	if((*S).top == MaxSize-1){
		return false;
	}
	// 先增加top，再给data赋值，++在前就先加 
	(*S).data[++(*S).top] = x;
	return true; 
} 

// 出栈
int Pop(SqStack *S){
	if((*S).top == -1){
		return false;
	}
	// 先赋值再-- 
	int x = (*S).data[(*S).top--];
	return x;
} 

int GetTop(SqStack *S){
	if((*S).top == -1){
		return false;
	}
	return (*S).data[(*S).top];
}

void main(){
	SqStack S;
	InitStack(&S);
	EmptyStack(&S);
}

#include <stdbool.h>
#include <stdio.h> 
#define MaxSize 10

typedef struct{
	int data[MaxSize];
	int top0;
	int top1;
}ShStack;

// 初始化共享栈 
bool InitStack(ShStack *S){
	(*S).top0 = -1;
	(*S).top1 = MaxSize;
}

bool PushStack0(ShStack *S, int x){
	// 判断是否栈满 
	if((*S).top0+1 == (*S).top1){
		return false; 
	}
	(*S).data[++(*S).top0] = x;
	return true;
}

bool PushStack1(ShStack *S, int x){
	if((*S).top0+1 == (*S).top1){
		return false; 
	}
	(*S).data[--(*S).top1] = x;
	return true;
}

int PopStack0(ShStack *S){
	if((*S).top0 == -1){
		return false;
	}
	return (*S).data[(*S).top0--];
}

int PopStack1(ShStack *S){
	if((*S).top1 == MaxSize){
		return false;
	}
	return (*S).data[(*S).top1++];
}

void main(){
	ShStack S;
	InitStack(&S);
}

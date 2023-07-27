#include <stdbool.h>
#include <stdlib.h> 
#include <stdio.h>

// 链栈
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}*LiStack;

// 不带头结点 
bool InitLiStack(LiStack *S){
	*S = NULL;
	return true;
}

bool push(LiStack *S, int e){
	struct LinkNode *p = (struct LinkNode *)malloc(sizeof(struct LinkNode));
	p->data = e;
	p->next = *S; 
	*S = p;
	return true;
}

bool pop(LiStack *S){
	if((*S) == NULL){
		return false;
	}
	struct LinkNode *p = (*S);
	(*S) = (*S)->next;
	free(p);
	return true;
}

int GetTop(LiStack *S){
	if((*S) == NULL){
		return false;
	}
	return (*S)->data;	
}

void main(){
	LiStack S;
	InitLiStack(&S);
	push(&S, 1);
	push(&S, 2);
	pop(&S);
	printf("%d\n", GetTop(&S));
}

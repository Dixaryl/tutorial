#include <stdbool.h>
#include <stdlib.h>

typedef struct DNode{
	int data;
	struct DNode *prior, *next;
}DNode, *DLinkList;

bool InitDLinkList(DLinkList *L){
	(*L) = (DNode *)malloc(sizeof(DNode));
	if((*L) == NULL){
		return false;
	} 
	(*L)->prior, (*L)->next = NULL;
	return true;
}

bool Empty(DLinkList *L){
	if((*L)->next == NULL){
		return true;
	}else{
		return false;
	}
}

// 在p结点后插入s结点 
bool InsertNextDNode(DNode **p, DNode **s){
	(*s)->next = (*p)->next;
	(*s)->prior = (*p);
	if((*p)->next != NULL){
		(*p)->next->prior = (*s);
	}
	(*p)->next = (*s); 
	return true;
} 

// 删除p结点的后继结点 
bool DeleteNextDNode(DNode **p){
	DNode *q = (*p)->next; 
	if(q == NULL){
		return false;
	} 
	(*p)->next = q->next;
	if(q->next != NULL){
		q->next->prior = (*p);
	}
	free(q);
	return true;
}

// 销毁双链表
void DestoryList(DLinkList *L){
	while((*L)->next != NULL){
		DeleteNextDNode(L);
	}
	free(*L);
	*L = NULL; 
} 

void main(){
	DLinkList L;
}

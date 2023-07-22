#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
// 将struct LNode变量的指针重命名为单链表（LinkList） 
// LNode *L等价于LinkList L 
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList; 

bool InitList(LinkList *L){
	//不带头结点时，头指针指向的下一个节点用来存放数据 
	*L = NULL;
	return true; 
}

bool Empty(LinkList *L){
	// 判断不带头结点的单链表是否为空 
	return (*L==NULL);
}

// 按位序插入 
bool ListInsert(LinkList *L, int i, int e){
	// 位序从1开始，小于1不合法 
	if(i<1){
		return false;
	}
	// 由于没有头结点，所以p没法指在i-1==0的结点上，所以要特殊处理
	if(i==1){
		// 申请一片新的结点空间
		LNode *s = (LNode *)malloc(sizeof(LNode));
		// 把参数e存到新结点里面
		s->data = e;
		s->next = *L;
		*L = s;
	} 
	// 指针p指向了和L相同的位置，因为L是二级指针，所以要解引用 
	LNode *p; 
	p = *L; 
	// 当前p指向了哪个结点(位序)
	int j = 1;
	// 在位序i插入值的前提是p得指向位序i-1，也就是j等于i-1，也就是退出循环的条件是j<i-1
	// p = p->next一直循环的话，p会指向NULL，当p指向NULL的时候，就不符合 p得指向位序i-1
	while(p!=NULL&&j<i-1){
		p = p->next;
		j++;
	} 
	// p向NULL的时候，说明输入的位序i不合法，应该终止
	if(p==NULL){
		return false; 
	} 
	// 申请一片新的结点空间
	LNode *s = (LNode *)malloc(sizeof(LNode));
	// 把参数e存到新结点里面
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true; 
} 


void main(){
	LinkList L;
	// L是一个指针变量，变量在传递后如何想依然操作这个变量，而非复制品，就得取地址传入 
	// 取地址后就是一个指针，就得用这个变量的指针变量去接收，接收到的其实是这个变量的内存中存放地址
	// 由于是指针变量的指针，解引用后才能使用 
	InitList(&L);
	// 如果在InitList传入的是L，初始化操作的是L的复制品，那L本身没有被赋值为Null，此时Empty会return 0 
	Empty(&L);
	ListInsert(&L, 1, 5); 
} 

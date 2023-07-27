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
	// 带头结点时，头指针指向的下一个节点称为头结点，头结点不存放实际数据，头结点指向的下一个节点用于存放实际数据 
	*L = (LNode *)malloc(sizeof(LNode));
	if((*L) == NULL){
		return false;
	} 
	// 括号是不能省的，不然编译报错，运算符优先级有高低 
	(*L)->next = NULL; 
	return true;
}

bool Empty(LinkList *L){
	// 判断带头结点的单链表是否为空，需要判断头节点的next指针是否为空
	return ((*L)->next==NULL); 
}

// 后插操作：在p结点之后插入元素e 
bool InsertNextNode(LNode **p, int e){ 
	// 既在单独使用中增加健壮性，又能和按位序插入结合 
	if(*p==NULL){
		return false; 
	} 
	LNode *s = (LNode *)malloc(sizeof(LNode));
	// 没见过内存分配失败的 
	if(s==NULL){
		return false;
	}
	s->data = e;
	s->next = (*p)->next;
	(*p)->next = s;
	return true; 
}

// 前插操作：在结点p的前一个位置插入e
// 不传入单链表L下的实现 
bool InsertPriorNode(LNode **p, int e){
	// 算法的实现的前提就是p指向一个结点 
	if(*p==NULL){
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s==NULL){
		return false;
	} 
	s->next = (*p)->next;
	(*p)->next = s;
	// 让结点里的数据跑路
	s->data = (*p)->data;
	(*p)->data = e;
	return true;
	 
} 

// 按位序插入 
bool ListInsert(LinkList *L, int i, int e){
	// 位序从1开始，小于1不合法 
	if(i<1){
		return false;
	}
	// 指针p指向了和L相同的位置，因为L是二级指针，所以要解引用 
	LNode *p; 
	p = *L; 
	// 当前p指向了哪个结点，把头结点看成第0个结点 
	int j = 0;
	// 在位序i插入值的前提是p得指向位序i-1，也就是j等于i-1，也就是退出循环的条件是j<i-1
	// p = p->next一直循环的话，p会指向NULL，当p指向NULL的时候，就不符合 p得指向位序i-1
	while(p!=NULL&&j<i-1){
		p = p->next;
		j++;
	} 
	// 如果有两个地方同时用了这段代码，万一写错了就需要改两个地方，但封装成基本操作后，就只要改一个地方，易维护且代码更简洁 
	return InsertNextNode(&p, e);
} 

// 按位序删除，删除第i个位置的元素并用e返回删除的值
int ListDelete(LinkList *L, int i, int *e){
	if(i<1){
		return false;
	}
	LNode *p = *L;
	int j = 0;
	// 需要让p指向第i-1个结点，也就是j==i-1，也就是循环条件是j<i-1
	while(p!=NULL && j<i-1){
		p = p->next;
		j++;
	}
	if(p==NULL){
		return false;
	}
	// 如果p指向的是最后一个结点，那删除这个结点的下一个结点就不合法 
	if(p->next == NULL){
		return false; 
	}
	LNode *q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	return true;
} 

// 删除指定结点
// 将后继结点q存放的数据放到结点p，调整指针后，删掉数据p 
// 空指针错误，就是一个指向NULL的指针，而你想要用箭头运算符去访问成员变量 
bool DeleteNode(LinkList *L, LNode **p){
	// p既不应该是空的，也不应指向第0个结点 ，因为我认为删除头节点是不合法的 
	if(*p==NULL || *p == *L){
		return false;
	}
	LNode *q = (*p)->next;
	// 如果p是最后一个结点，需要特殊处理
	// q首先指向第一个结点，如果q的下一个结点不是p，就下移一个节点，最后调整指针，删除p 
	if(q==NULL){
		// q不能指向第一个结点，这在只有一个结点时会产生边界问题 
		q = *L;
		while(q->next != *p){
			q = q->next;
		}
		q->next = (*p)->next;
		free(p);
	} 
	// 如果p是最后一个结点，q就指向NULL，q->data就空指针 
	(*p)->data = q->data;
	(*p)->next = q->next;
	free(q);
	return true;
} 

// 按位查找  
LNode *GetElem(LinkList *L, int i){
	if(i<1){
		return false;
	}
	LNode *p = *L;
	int j = 0;
	// p要指向第i个结点，j就要等于i，退出循环的条件是j<i
	// 如果i过大的话，p最终会指向NULL 
	// 无论位序值过大或者过小，都会返回NULL 
	while(p!=NULL && j<i){
		p = p->next;
		j++;
	} 
	// 返回p指向的地址 
	return p;
} 

// 按值查找
LNode *LocateElem(LinkList *L, int e){
	LNode *p = (*L)->next;
	// 找到data==e的结点后跳出循环 
	while((p->data != e) && p!=NULL){
		p = p->next;
	}
	return p;
} 

// 求表长 
int Length(LinkList *L){
	int len = 0;
	LNode *p = *L;
	while(p->next != NULL){
		p = p->next;
		len++;
	}
	return len;
} 

// 尾插法建立单链表（正向建立单链表）
// 建立完毕后返回头指针
LinkList List_TailInsert(LinkList *L){
	int x;
	*L = (LNode *)malloc(sizeof(LNode));
	LNode *s, *r = (*L);
	scanf("%d", &x);
	while(x != 9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", x); 
	}
	r->next = NULL;
	return (*L);
} 

LinkList List_HeadInsert(LinkList *L){
	int x;
	LNode *s;
	InitList(L);
	scanf("%d", &x);
	while(x != 9999){
		InsertNextNode(L, x);
		scanf("%d", &x);
	}
	return (*L);
}

void main(){
	LinkList L;
	// L是一个指针变量，变量在传递后如何想依然操作这个变量，而非复制品，就得取地址传入 
	// 取地址后就是一个指针，就得用这个变量的指针变量去接收，接收到的其实是这个变量的内存中存放地址
	// 由于是指针变量的指针，解引用后才能使用 
	InitList(&L);
	// 如果在InitList传入的是L，初始化操作的是L的复制品，那L本身没有被赋值为Null，此时Empty会return 0 
	Empty(&L);
	ListInsert(&L, 1, 2);
} 

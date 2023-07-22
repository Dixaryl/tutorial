// 顺序表就是以顺序存储方式（无论是动态还是静态）实现的线性表
// 所谓顺序就是逻辑上相邻的元素物理上也相邻 
#include <stdio.h>
#include <stdlib.h>
#define InitSize 10
typedef struct {
	// 指针指向了顺序表当中的第一个数据元素 
	int *data;
	int MaxSize;
	// 记录顺序表的当前长度 
	int length; 
} SeqList;

void InitList(SeqList *L){
	// malloc返回的是一篇连续存储空间的地址，而地址直接赋值给指针就行了 
	L->data=(int *)malloc(InitSize*sizeof(int));
	L->length=0;
	L->MaxSize=InitSize;
} 

void IncreaseSize(SeqList *L, int len){
	// 把顺序表data指针的值赋给指针p，p和data指向相同地址 
	int *p=L->data;
	// len是需要增加的额外长度而非总长度 
	L->data=(int *)malloc((L->MaxSize+len)*sizeof(int));
	// for循环先赋值，然后判断条件，通过了才运行
	for(int i=0; i<L->length; i++){
		// L是指针变量，使用箭头运算符访问成员变量data（指针） 
		// data指向malloc动态分配一块连续的存储空间（数组）后，就能按数组形式进行访问 
		L->data[i]=p[i]; 
	}
	L->MaxSize=L->MaxSize+len;
	// free函数会将p指针指向的一整片存储空间释放
	// p是局部变量，当函数运行结束时，存储p变量的存储空间会被自动回收 
	free(p);
}

int main(){
	SeqList L;
	InitList(&L);
	// .和->是用于访问结构体（struct）和指针（pointer）中的成员的运算符
	L.data[0]=1;
	L.length++;
	IncreaseSize(&L, 5);
	return 0;
}

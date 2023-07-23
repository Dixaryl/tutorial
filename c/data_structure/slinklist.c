#include <stdio.h>
#include <stdbool.h>
#define MaxSize 10

// 这种结构体定义，省略了struct Node中的Node，就无法以struct Node的形式去声明变量了 
// typedef 一个具体的结构体 为 一个固定大小的数组，那么以后用SLinkList去声明变量a，a就是一个含有MaxSize个具体的结构体的数组 
typedef struct{
	int data;
	int next; 
}SLinkList[MaxSize];

bool InitSLinkList(SLinkList L){
	L[0].next = -1;
	for(int i=1; i<MaxSize; i++){
		// 用-2标记哪些结点是空闲结点，便于增加结点时区分 
		L[i].next = -2;
	}
	return true;
}

void main(){
	SLinkList L;
	// 数组名是一个指向数组中第一个元素的常量指针，在编写函数时，可以使用常量指针来传递参数，确保函数不会修改参数的值
	InitSLinkList(L); 
}

#include <stdio.h>
#include <stdbool.h>
#define MaxSize 10
typedef struct{
	// 顺序表静态存储表长刚开始确定后就无法更改 
	int data[MaxSize];
	// lenth用于指示已经存放的数量 
	int length;
}SqList;

// 在C语言中，函数参数的传递方式有三种：传值、传引用
// 传值：将实参的值复制一份传递给函数，函数内部对参数值的修改不会影响到实参
// 传引用：将实参的地址传递给函数，函数内部通过对地址的操作来修改实参的值 
// 内存中会有遗留的脏数据，所以C语言初始化时的赋值很重要，默认赋值为0是编译器做的，但编译器可能有bug 
void InitList(SqList *L){
	// 使用箭头运算符（->）来访问传递进来的结构体指针的成员变量 
	L->length=0;
} 

// 在顺序表L的第i个位置插入指定元素e 
//第i个位置指的是位序，是从1开始的
bool ListInsert(SqList *L, int i, int e){
	if(i<1||i>L->length+1 ){
		printf("未按顺序插入，请重新指定位序！\n");
		return false;
	}
	if(L->length>=MaxSize){
		printf("顺序表已满，插入失败!\n");
		return false;
	}
	for(int j=L->length; j>=i; j--){
		L->data[j]=L->data[j-1];
	}
	L->data[i-1]=e;
	L->length++; 
	printf("在第%d位置插入元素%d成功\n", i, e);
	return true; 
} 

bool ListDelete(SqList *L, int i, int *e){
	// 删除的位序不规范 
	if(i<1||i>L->length){
		printf("位序i不规范，请重新输入！\n");
		return false;
	}
	// 只要L是指针变量，通过L进行访问的内容都得用箭头运算符 
	*e = L->data[i-1];
	for(int j=i;j<L->length;j++){
		L->data[i-1]=L->data[i];
	}
	L->length--;
	return true; 
}

//按位查找，返回位序所对应的值 
int GetElem(SqList *L, int i){
	if(i<1||i>L->length){
		printf("位序i不规范，请重新输入！\n");
		return false;
	}
	return L->data[i-1];
} 

// 按值查找，返回的值所对应的位序
int LocateElem(SqList *L, int e){
	for(int i=0;i<L->length;i++){
		if(L->data[i]==e){
			return i+1;
		}
	}
	printf("按值查找失败！\n"); 
	return false;
} 

int main(){
	// 声明一个顺序表 
	SqList L;
	// 取地址运算符 
	InitList(&L);
	L.data[0]=1;
	L.length++;
	L.data[1]=2;
	L.length++;
	L.data[2]=3;
	L.length++;
	L.data[3]=4;
	L.length++;
	L.data[4]=5;
	L.length++;
	L.data[5]=6;
	L.length++;
	printf("值为5的位序是%d\n", LocateElem(&L, 5));
} 

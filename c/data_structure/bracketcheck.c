// 括号匹配 

#include <stdbool.h>
#include <stdio.h>
#define MaxSize 10

typedef struct{
	char data[MaxSize];
	// top指向栈顶元素，空栈时指向-1 
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
bool Push(SqStack *S, char x){
	if((*S).top == MaxSize-1){
		return false;
	}
	// 先增加top，再给data赋值，++在前就先加 
	(*S).data[++(*S).top] = x;
	return true; 
} 

// 出栈
// 如果栈空，弹出失败，如果返回值是int的话，就不知道是由于弹出元素的值是0还是弹出失败，所以还是得返回bool 
bool Pop(SqStack *S, char *x){
	if((*S).top == -1){
		return false;
	}
	// 先赋值再-- 
	*x = (*S).data[(*S).top--];
	return true;
} 

int GetTop(SqStack *S){
	if((*S).top == -1){
		return false;
	}
	return (*S).data[(*S).top];
}

// 匹配失败情况：左括号有剩余，右括号有剩余，左右括号不匹配 
bool BracketCheck(char str[], int length){
	SqStack S;
	InitStack(&S);
	for(int i; i<length; i++){
		// 如果是左括号就压入栈中 
		if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
			Push(&S, str[i]);
		}else{
			// 如果是右括号就先看栈是否为空，如果为空就说明又括号多了，然后弹出栈顶元素，如果不匹配就false 
			if(EmptyStack(&S)){
				// 如果栈空，返回true，if条件满足，无法弹出栈 
				return false; 
			}
			char topElem;
			Pop(&S, &topElem);
			if(str[i] == ')' && topElem != '('){
				return false;
			}
			if(str[i] == ']' && topElem != '['){
				return false;
			}
			if(str[i] == '}' && topElem != '{'){
				return false;
			}
		} 
	}
	// 最后看栈是否为空，即左括号是否有剩余
	return EmptyStack(&S); 
} 

int main(){
	int size = 10; 
	char bracket; 
	char str[size];
	int length;
	printf("请输入括号序列并以#号结束，最大输入括号数为%d\n", size);
	for(length=0; length<size; length++){
		scanf("%c", &bracket);
		if(bracket == '#'){
			break;
		}
		if(bracket == '\n'){
			printf("未以#号结束"); 
			return 0; 
		} 
		if(bracket != ('(' || ')' || '[' || ']' || '{' || '}')){
			printf("输入中含有非括号字符"); 
			return 0; 
		}
		str[length] = bracket;
	}
	printf("输入的括号序列为："); 
	for(int j=0; j<length; j++){
		printf("%c", str[j]);
	}
	if(BracketCheck(str, length)){
		printf("\n通过检测！"); 
	}else{
		printf("\n未通过检测！"); 
	}
} 

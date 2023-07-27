// 逆波兰表达式（后缀表达式）运算符在两个操作数的后面，左优先原则 
// 波兰表达式（前缀表达式） 运算符在两个操作数的前面 ，右优先原则
// 下面这套代码是将中缀表达式转后缀表达式，与后缀表达式求值相结合的中缀表达式求值 

#include <stdbool.h>
#include <stdio.h>
#define MaxSize 100

typedef struct{
	char data[MaxSize];
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
bool Pop(SqStack *S, char *x){
	if((*S).top == -1){
		return false;
	}
	// 先赋值再-- 
	*x = (*S).data[(*S).top--];
	return true;
} 

bool GetTop(SqStack *S, char *x){
	if((*S).top == -1){
		return false;
	}
	*x = (*S).data[(*S).top];
	return true;
}

// 形参：左操作数，运算符operator，右操作数 
int Eval(char left, char op, char right){
	int res;  
	switch(op){
		case '+':
			// 查ASCII表，0是48，1是49，49-48=1，就转成数字了 
			res = (left-'0') + (right-'0');
			break;
		case '-':
			res = (left-'0') - (right-'0');
			break;
		case '*':
			res = (left-'0') * (right-'0');
			break;
		case '/':
			res = (left-'0') / (right-'0');
			break;
	}
	return res;
} 

// 判断是否是运算符
bool IsOperator(char c){
	if(c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/'){
		return true;
	}else{
		return false;
	}
	if(c == '+'){
		return true;
	}else{
		return false;
	}
} 

// 判断运算符栈的栈顶元素是否具有更高优先级
bool IsHigher(SqStack *S, char op){
	char topElem; 
	if(GetTop(S, &topElem)){
		if(topElem == '('){
			return false;
		}
		if(topElem == '*' || topElem == '/') {
			return true;
		}
		if((topElem == '+' || topElem == '-') && (op == '+' || op == '-')){
			return true;
		}
	}else{
		// 栈空 
		return false;
	}
} 

// 弹出两个操作数求值后，压入操作数栈 
bool Postfix(SqStack *S, char op){
	char left;
	char right;
	// 右操作数先出栈，左操作数再出栈，计算后重新压入栈 
	Pop(S, &right);
	Pop(S, &left);
	// C语言int实参可以直接传给char形参 
	Push(S, Eval(left, op, right) + '0');
	return true;
} 

// 表达式求值 
int ExpressionEvaluation(char str[], int length){
	// 接收弹出的运算符 
	char topElem; 
	char left;
	char right;
	// 定义操作数栈和运算符栈，并初始化 
	SqStack s, f;
	InitStack(&s);
	InitStack(&f);
	// 读取表达式及表达式的长度 
	for(int i=0; i<length; i++){
		// 如果读到的是操作数，就加入到操作数栈
		if(!IsOperator(str[i])) {
			Push(&s, str[i]);
		}else{
			// 否则读到的就是运算符或界限符，遇到的是左括号直接入栈
			if(str[i] == '('){
				Push(&f, str[i]);
				continue;
			} 
			// 如果遇到的是右括号，就把栈顶元素到左括号的运算符都弹出
			if(str[i] == ')'){
				while(true){
					Pop(&f, &topElem);
					if(topElem == '('){
						break;
					}
					Postfix(&s, topElem);
				}
				continue;
			}
			// 如果遇到的是运算符，依次弹出栈中优先级高于或等于自己的运算符，若栈空或栈顶元素是左括号则不弹出
			while(IsHigher(&f, str[i])){
				Pop(&f, &topElem);
				Postfix(&s, topElem);
			}
			// 之后再把当前的运算符入栈
			Push(&f, str[i]); 
		}		
	}
	// 将运算符栈中剩余运算符依次弹出
	while(!EmptyStack(&f)){
		Pop(&f, &topElem);
		Postfix(&s, topElem);
	} 
	// 此时操作数栈只有一个元素，将其弹出，就是最后的结果
	Pop(&s, &topElem); 
	return topElem-'0'; 
} 

void main(){
	// 没法用15，因为char是对应ASCII 
	char exp[] = {'(', '(', '8', '/', '(', '6', '-', '(', '1', '+', '1', ')', ')', ')', '*', '3', '-', '(', '2', '+', '(', '1', '+', '1', ')', ')'};
	int length = 26;
	int res = ExpressionEvaluation(exp, length);
	printf("预期结果：2\n实际结果：%d", res);	
}
// 缺点是压入操作数栈的元素是char类型，只能支持0-9，因为输入是一个char数组

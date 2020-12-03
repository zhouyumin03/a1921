#include "stack.h"
int main(){
	LinkStack *s=InitStack();
	Push(s,80);
	Push(s,90);
	Pop(s);
	Push(s,70);
	printf("栈顶元素为：%d\n ",GetTop(s));
	Operation();
	printf("\n");
	return 0;
}


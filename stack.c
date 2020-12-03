#include"stack.h"
#include"string.h"                                                                                                  

LinkStack* InitStack(){                                                                                                       
	LinkStack *t=(LinkStack*)malloc(sizeof(LinkStack));
	t->next=NULL;
	return t;
}
int Empty(LinkStack *s){
	return s->next==NULL;

}
int priority(char x){
	switch (x){
		case '+':
		case '-':
		case '=': return 1;
		case '*':
		case '/': return 2;
		case '(': return 3;
	}
}
double compute(double x,double y,char op){
	switch(op){
		case '+':return x+y;
		case '-':return x-y;
		case '*':return x*y;
		case '/':return x/y;
	}
}
void Push(LinkStack *s,dataType x){                                                                                                                                                                                                      node *t=(node*)malloc(sizeof(node));
	t->data=x;
	t->next=s->next;
	s->next=t;
}
void Pop(LinkStack *s){
	if (Empty(s)) exit(1);
	node *p=s->next;
	s->next=p->next;
	free(p);
}
dataType GetTop(LinkStack *s){
	return s->next->data;
}
void Operation(){
	char s2[500], t[1001], op;
	double s1[500];
	int top1=-1, top2=-1;
	double x,y;
	scanf("%s",t);
	for (int i=0;i<strlen(t);i++){
		if (t[i]>='0' && t[i]<='9'){
			double value =0;
			while (t[i]>='0'&&t[i]<='9'){
				value=10*value + t[i]-'0';
				i++;
			}
			if(t[i]=='.'){
				double r=10.0;i++;
				while (t[i]>='0' && t[i]<='9'){
					value += (t[i]-'0')/r;
					r*=10;
					i++;
				}
			}
			s1[++top1]=value;
		}
		if(t[i]==')'){
			while (s2[top2] !='('){
				y=s1[top1--];
				x=s1[top1--];
				op=s2[top2--];
				s1[++top1]=compute(x,y,op);
			}
			top2--;
		}else{
			while (top2!=-1 && s2[top2]!='(' && priority(t[i])<=priority(s2[top2])){
				y=s1[top1--];
				x=s1[top1--];
				op=s2[top2--];
				s1[++top1]=compute(x,y,op);
			}
			s2[++top2]=t[i];
		}
	}
	printf("%.2f\n ",s1[top1]);
}




#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"shiyan1.h"

int main() {
	LinkList *list = CreateList();
	Insert(list,1,10);
	Insert(list,1,20);
	Delete(list,2);
	Insert(list,1,30);
	Insert(list,1,40);
	printf("链表元素的个数：%d\n",Size(list));
	Print(list);
	printf("链表的第二个元素为：%d\n",GetData(list,2));
	system("pause");



#define n 11
#define m 3


	int k = 0;
	LinkList *p, *q, *r;
	p = q = (LinkList*)malloc(sizeof(LinkList));//创建第一个结点
	p->data = 1;
	for(int i=2; i<=n; i++){
		r = (LinkList*)malloc(sizeof(LinkList));
		r->data = i;
		q->next = r;
		q = r;
	}
	q->next = p;

	q = p;
	while(q->next !=q){
	   for(int i=1; i<m; i++){
		p = q;
	        q = q->next;
	}
	p->next = q->next;
	free(q);
	q = p->next;
	}
	printf("最后一个获胜者的编号是：%d\n", q->data);
}

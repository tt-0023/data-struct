#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct Node{
	ElementType data;
	struct Node *next;
}Node;
typedef Node *List;
//初始化链表
List InitList(){
	List head=(List)malloc(sizeof(Node));
	head->next=NULL;
	return head;
}
//判断链表是否为空
int IsEmpty(List L){
	return L->next==NULL;
}
//求链表长度
int GetLength(List L){
	int count=0;
	Node *p=L->next;
	while(p!=NULL){
		count++;
		p=p->next;
	}
	return count;
}
//插入
int Insert(List L, int position , ElementType x){
	Node *p=L;
	int count=0;
	while(p!=NULL&&count<position-1){
		p=p->next;
		count++;
	}
	if(p==NULL||count>position-1){
		printf("插入位置不合法\n");
		return 0;
	}
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->next=p->next;
	p->next=newNode;
	return 1;
}
//删除
int Delete(List L,int position){
	Node *p=L;
	int count=0;
	while(p!=NULL&&count<position-1){
		p=p->next;
		count++;
	}
	if(p->next==NULL||count>position-1){
		printf("删除位置不合法\n");
		return 0;
	}
	Node *temp=p->next;
	p->next=temp->next;
	free(temp);
	return 1;	
}
//查找
int Find(List L,ElementType x){
	Node *p=L->next;
	int position=1;
	while(p!=NULL){
		if(p->data==x){
			return position;
		}
		p=p->next;
		position++;
	}
	return -1;
}

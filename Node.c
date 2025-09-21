#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct Node{
	ElementType data;
	struct Node *next;
}Node;
typedef Node *List;
//��ʼ������
List InitList(){
	List head=(List)malloc(sizeof(Node));
	head->next=NULL;
	return head;
}
//�ж������Ƿ�Ϊ��
int IsEmpty(List L){
	return L->next==NULL;
}
//��������
int GetLength(List L){
	int count=0;
	Node *p=L->next;
	while(p!=NULL){
		count++;
		p=p->next;
	}
	return count;
}
//����
int Insert(List L, int position , ElementType x){
	Node *p=L;
	int count=0;
	while(p!=NULL&&count<position-1){
		p=p->next;
		count++;
	}
	if(p==NULL||count>position-1){
		printf("����λ�ò��Ϸ�\n");
		return 0;
	}
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->next=p->next;
	p->next=newNode;
	return 1;
}
//ɾ��
int Delete(List L,int position){
	Node *p=L;
	int count=0;
	while(p!=NULL&&count<position-1){
		p=p->next;
		count++;
	}
	if(p->next==NULL||count>position-1){
		printf("ɾ��λ�ò��Ϸ�\n");
		return 0;
	}
	Node *temp=p->next;
	p->next=temp->next;
	free(temp);
	return 1;	
}
//����
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

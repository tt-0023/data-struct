#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct{
	int data[MAXSIZE];
	int length
}seqlist;
//��ʼ��˳���
void InitList(seqlist *L){
	L->length=0;
}
//�ж��Ƿ�Ϊ��
int ISempty(seqlist L){
	return L.length==0;
}
//��ó���
int Getlength(seqlist L){
	return L.length;
}
void Insert(seqlist *L,int position,int value){
	if(L->length>=MAXSIZE){
		printf("˳�������!\n");
		return;
	}
	if(position<1||position>L->length+1){
		printf("λ�ò��Ϸ�!\n");
		return ;
	}
	for(int i=L->length;i>=position;i--){
		L->data[i]=L->data[i-1];
	}
	L->data[position-1]=value;
	L->length++;
	printf("����ɹ���\n");
}
int Delete(seqlist *L,int position){
	if(position<1||position>L->length){
		printf("λ�ò��Ϸ���\n");
		return 0;
	}
	for(int i=position;i<L->length;i++){
		L->data[i-1]=L->data[i];
	}
	L->length--;
	return 1;
	}
int Find(seqlist L,int value){
	for(int i=0;i<L.length;i++){
		if(L.data[i]==value){
			return i+1;
		}
	}
	return -1;
}
void PrintList(seqlist L){
	printf("˳������ݳ���%d",L.length);
	for(int i=0;i<L.length;i++){
		printf("%d",L.data[i]);
	}
	printf("\n");
}

int main(){
	seqlist myList;
	InitList(&myList);
	Insert(&myList,1,10);
	Insert(&myList,2,20);
	Insert(&myList,3,30);
	Insert(&myList,4,635);
	Insert(&myList,5,34);
	Delete(&myList,4);
	Find(myList,20);
	printf("��ǰ����Ϊ��%d\n",Getlength(myList));
	printf("�Ƿ�Ϊ�գ�%s\n",ISempty(myList)?"��":"��");
	PrintList(myList);
	return 0;
}


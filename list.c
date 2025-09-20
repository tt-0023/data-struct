#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct{
	int data[MAXSIZE];
	int length
}seqlist;
//初始化顺序表
void InitList(seqlist *L){
	L->length=0;
}
//判断是否为空
int ISempty(seqlist L){
	return L.length==0;
}
//获得长度
int Getlength(seqlist L){
	return L.length;
}
void Insert(seqlist *L,int position,int value){
	if(L->length>=MAXSIZE){
		printf("顺序表已满!\n");
		return;
	}
	if(position<1||position>L->length+1){
		printf("位置不合法!\n");
		return ;
	}
	for(int i=L->length;i>=position;i--){
		L->data[i]=L->data[i-1];
	}
	L->data[position-1]=value;
	L->length++;
	printf("插入成功！\n");
}
int Delete(seqlist *L,int position){
	if(position<1||position>L->length){
		printf("位置不合法！\n");
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
	printf("顺序表内容长度%d",L.length);
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
	printf("当前长度为：%d\n",Getlength(myList));
	printf("是否为空：%s\n",ISempty(myList)?"是":"否");
	PrintList(myList);
	return 0;
}


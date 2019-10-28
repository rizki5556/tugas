#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct node{
	int lkey;
	char name[10];
	struct node* next;
} TNODE;

TNODE *first, *last;

int loadnode(TNODE *p);
void freenode(TNODE *p);
void printnode(TNODE *p);

void createlist()
{
	TNODE *p;
	int n=sizeof(TNODE);
	
	first=last=0;
	for(;;)
	{
		if((p=(TNODE*)malloc(n))==0)
		{
			printf("\nmemori tidak cukup");
			break;
		}
		if(loadnode(p)!=1)
		{
			freenode(p);
			break;
		}
		p->next=0;
		if (first==0) first=last=p;
		else{
			last->next=p;
			last=p;
		}
	}
}

int loadnode(TNODE *p)
{
	char opt;
	printf(\nmasukan node baru?);
	opt=getche();
	opt=touper(opt);
	if(opt!='N'){
		puts("\nmasukan data untuk node: ");
		printf("\nlkey:\t");
		if(scanf("%d",&(p->lkey))!=1)return 0;
		printf("\nname:\t");
		if(scanf("%s",p->name)!=1) return 0;
		return 1;
	}
	else
	return-1;
}

void freenode(TNODE *p){
	free(p);
}

void viewalllist()
{
	TNODE *p;
	p=first;
	while(p){
		printnode(p);
		p=p->next;
	}
}

TNODE* findnode(int key)
{
	TNODE *p;
	p=first;
	while(p){
		if(p->lkey==key)return p;
		p=p->next;
	}
	return 0;
}

void printnode(TNODE *p)
{
	if(p) printf("\n%d\t%s",p->lkey,p->name);
}

TNODE* insertbeforefirst()
{
	TNODE *p;
	int n=sizeof(TNODE);
	if(((p=(TNODE*)malloc(n))!=0) && (loadnode(p)==1))
	{
		if(first==0){
			p->next=0;
			first=last=p;
		}
		else{
			p->next=first;
			first=p;
		}
		return p;
	}
	if(p==0)
		printf("\nmemori tidak cukup");
	else
		freenode(p);
	return 0;
}

TNODE* insertbeforekey(int key)
{
	TNODE *p, *q, *q1;
	int n=sizeof(TNODE);
	
	q1=0;
	q=first;
	while(q){
		if(q->lkey==key)break;
		q1=q;
		q=q->next
	}
	if(q==0){
		printf("\ntidak ada node yang mempunyai kunci atau senarai kosong");
		return 0;
	}
	if(((p=(TNODE*)malloc(n))!=0)&&(loadnode(p)==1)){
		if(q==first){
			p->next=first;
			first=p;
		}
		else{
			p->next=q;
			q1->next=p;
		}
		return p;
	}
	if(p==0)
		printf("\nmemori tidak cukup");
	else
		freenode(p);
	return 0;
}
TNODE* insertafterkey(int key)
{
	TNODE *p, *q;
	int n=sizeof(TNODE);
	
	q=first;
	while(q){
		if(q->lkey==key) break;
		q=q->next;
	}
	if(q==0){
		printf("\ntidak ada node yang mempunyai kunci atau senarai kosong");
		return 0;
	}
	if (((p=(TNODE*)malloc(n))!=0)&&(loadnode(p)==1))
	{
		if(q==last){
			p->next=0;
			last->next=p;
			last=p;
		}
		else{
			p->next=q->next;
			q->next=p;
		}
		return p;
	}
	if(p==0)
		printf("\nmemori tidak cukup");
	else
		freenode(p);
	return 0;
}

TNODE* insertafterlast()
{
	TNODE *p;
	int n=sizeof(TNODE);
	if (((p=(TNODE*)malloc(n))!=0)&&(loadnode(p)==1))
	{
		p->next=0;
		if(first==0)
			first=last=p;
		else{
			last->next=p;
			last=p;
		}
		return p;
	}
	if(p==0)
		printf("\nmemori tidak cukup");
	else
		freenode(p);
	return 0;
}

void removefirst()
{
	TNODE *p;
	
	if(first==0)
		return;
	if(first==last){
		freenode(first);
		first=last=0;
		return;
	}
	p=first;
	first=first->next;
	freenode(p);
}

void removelast()
{
	TNODE *P, *q;
	
	if(first==0)
		return;
	if(first==last){
		freenode(first);
		first=last=0;
		return;
	}
	q=0;
	p=first;
	while(p!=last){
		q=p;
		p=p->next;
	}
	p=last;
	freenode(p);
	q->next=0;
	last=q;
}

void removebykey(int key)
{
	TNODE *p, *q;
	if(first==0)
		return;
	q=0;
	p=first;
	while(p){
		if(p->lkey==key) break;
		q=p;
		p=p->next;
	}
	if(!p){
		printf("\ntidak ada node yang mempunyai kunci");
		return;
	}
	if(first==last){
		freenode(first);
		first=last=0;
		return;
	}
	if(p==first){
		first=first->next;
		freenode(p);
		return;
	}
	if(p==last){
		q->next=0;
		last=q;
		freenode(p);
		return;
	}
	q->next=p->next;
	freenode(p);
}

void deletelist()
{
	TNODE *p;
	p=first;
	while(p){
		first=first->next;
		freenode(p);
		p=first;
	}
	last=0;
}

void main()
{
	createlist();
	viewalllist();
	insertafterlast();
	viewalllist();
	removefirst();
	viewalllist();
	insertafterkey(1);
	viewalllist();
	removebykey(1);
	viewalllist();
	deletelist();
	viewalllist();
}

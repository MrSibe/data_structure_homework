#include "../include/students.h"

#ifndef LIST_H
#define LIST_H

typedef struct LNode
{
	Student data;
	struct LNode *next;		//指向后继结点
}LinkNode;

void InitList(LinkNode *&L);
void DispList(LinkNode *L);
int ListLength(LinkNode *&L);
bool ListInsert(LinkNode *&L,int i,Student e);
void DestroyList(LinkNode *&L);
bool ListEmpty(LinkNode *&L);
bool ListDelete(LinkNode *&L, int i, Student &e);

#endif
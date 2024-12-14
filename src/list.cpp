#include "../include/list.h"
#include "../include/students.h"

/*****单链表的基本操作*****/

void DestroyList(LinkNode *&L) //销毁单链表
{
	LinkNode *pre = L, *p = L->next;
	while(p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

bool ListEmpty(LinkNode *&L) //判空
{
	return(L->next == NULL);
}

int ListLength(LinkNode *&L) //求链表的长度
{
	int n = 0;
	LinkNode *p = L;
	while(p->next != NULL)
	{ 
		n++;
		p = p->next;
	}
	return n;
}

bool ListDelete(LinkNode *&L, int i, Student &e)
{
	// 在带头结点的单链线性表L的第i个元素之前删除元素e  
	/********** Begin **********/ 
	int j = 0;
	LinkNode *p = L, *q;
	if(i <= 0)  return false;
	while(j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if(p == NULL) return false;
	else
	{
		q = p->next;
		if(q == NULL)
		{
			return false;
		}
		e = q->data;
		p -> next = q -> next;
		free(q);
		return true;
	}
	/********** End **********/
}

void InitList(LinkNode *&L)
{ 
	// 操作结果：构造一个空的单链表L
	/********** Begin **********/ 
	L = (LinkNode *)malloc(sizeof(LinkNode));
	L->next = NULL;
	/********** End **********/
}

bool ListInsert(LinkNode *&L, int i, Student e)
{
	// 在带头结点的单链线性表L的第i个元素之前插入元素e  
	/********** Begin **********/ 
	int j = 0;
	LinkNode *p = L, *s;
	if(i <= 0) return false;
	while(j < i - 1 && p != NULL)
	{
		j++;
		p = p -> next;
	}
	if(p == NULL) return false;
	else
	{
		s = (LinkNode *)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
	/********** End **********/
}

void DispList(LinkNode *L)
{
	/********** Begin **********/ 
	LinkNode *p = L->next;
	if (p == NULL) {
        printf("\n暂无学生信息！\n");
        return;
    }
	printf("学号\t\t姓名\t\t性别\t专业\t\t\t年级\t班级\n");
	while(p != NULL)
	{
		printf("%s\t%10s\t%s\t%s\t%s\t%s\n", p->data.ID, p->data.Name, p->data.Gender, p->data.Major, p->data.Grade, p->data.Class);
		p = p->next;
	}
	/********** End **********/
}
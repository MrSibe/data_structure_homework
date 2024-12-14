#include <string.h>
#include <iostream>
using namespace std;

#ifndef AVL_H
#define AVL_H

const int Maxsize = 256;

typedef int KeyType;                    //定义关键字类型
typedef struct node                     //记录类型
{
    KeyType key;                        //教室编号(关键字项)
    int bf;                             //平衡因子
    char sec[Maxsize]; // 校区
    char name[Maxsize]; // 教室
    char lei[Maxsize]; // 类别
    char mutimedia[2]; // 是否有多媒体设备
    int size; // 容量
    char pos[Maxsize]; // 所在教学楼
    struct node *lchild, *rchild;        //左右孩子指针
}BSTNode;

void LeftProcess(BSTNode *&p,int &taller);
void RightProcess(BSTNode *&p,int &taller);
int InsertAVL(BSTNode *&b, KeyType e, char sec[Maxsize], char name[Maxsize], char lei[Maxsize], char mutimedia[2], int size, char pos[Maxsize], int &taller);
void DispBSTree(BSTNode *b);
void LeftProcess1(BSTNode *&p,int &taller);
void RightProcess1(BSTNode *&p,int &taller);
void Delete2(BSTNode *q, BSTNode *&r, int &taller);
int DeleteAVL(BSTNode *&p, KeyType x, int &taller);

#endif
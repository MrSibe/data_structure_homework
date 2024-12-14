#include <iostream>
#include "list.h"
using namespace std;

#ifndef STU_OPER_H
#define STU_OPER_H

void add_stu(LinkNode *&L);
void auto_add_student(LinkNode *&L, Student new_student);
void delete_stu(LinkNode *&L);
void modify_stu(LinkNode *&L);
void query_stu(LinkNode *&L);
void show_all_stu(LinkNode *L);
void batch_modify_stu(LinkNode *&L);

#endif
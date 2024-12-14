#include <iostream>
#include "../include/list.h"
#include "../include/show_menu.h"
#include "../include/stu_oper.h"
#include "../include/room_oper.h"
#include "../include/read_write_csv.h"
#include "../include/init.h"
using namespace std;

#ifndef SWITCH_CHOICE_H
#define SWITCH_CHOICE_H

void main_switch(LinkNode *&L, BSTNode *&b, const char* filename1, const char* filename2);
void student_switch(LinkNode *&L);
void classroom_switch(BSTNode *&b);
void show_room(BSTNode *&b);
void end_switch(LinkNode *&L, BSTNode *&b,const char* filename1, const char* filename2);
void batch_modify_stu(LinkNode *&L);

#endif
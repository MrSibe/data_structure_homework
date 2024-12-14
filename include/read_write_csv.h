#include <iostream>
#include <fstream>
#include "../include/list.h"
#include "../include/AVL.h"
using namespace std;


#ifndef READ_WRITE_CSV_H
#define READ_WRITE_CSV_H

Student parseStudent(const char* line);
void createCSV(const char* filename);
int read_stu_CSV(const char* filename, LinkNode*& L);
void write_stu_CSV(const char* filename, LinkNode*& L);
int read_room_CSV(const char* filename, BSTNode*& b);
void write_room_CSV(const char* filename, BSTNode*& b);
void write_sigle_room(BSTNode*b, FILE* file);

#endif
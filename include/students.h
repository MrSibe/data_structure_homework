#include <iostream>
#include <malloc.h>
#include <string.h>
using namespace std;

#define MAX_SIZE 256

#ifndef STUDENTS_H
#define STUDENTS_H

// 学生结构体: 学号、姓名、性别、年级、专业、班级
typedef struct student
{
    char ID[MAX_SIZE];
    char Name[MAX_SIZE];
    char Gender[MAX_SIZE];
    char Grade[MAX_SIZE];
    char Major[MAX_SIZE];
    char Class[MAX_SIZE];
}Student;

#endif
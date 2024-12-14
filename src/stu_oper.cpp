#include "../include/stu_oper.h"
#include "../include/students.h"
#include "../include/list.h"
#include "../include/clear_screen.h"

void add_stu(LinkNode *&L)
{
    Student new_student;
    printf("=== 添加学生 ===\n");
    printf("请输入学号: ");
    scanf("%s", new_student.ID);
    printf("请输入姓名: ");
    scanf("%s", new_student.Name);
    printf("请输入性别(M/F): ");
    scanf("%s", new_student.Gender);
    printf("请输入专业: ");
    scanf("%s", new_student.Major);
    printf("请输入年级: ");
    scanf("%s", new_student.Grade);
    printf("请输入班级: ");
    scanf("%s", new_student.Class);
    auto_add_student(L, new_student);
}

void auto_add_student(LinkNode *&L, Student new_student)
{
    ListInsert(L, ListLength(L) + 1, new_student);
}

void delete_stu(LinkNode *&L)
{   
    char id[20];
    printf("=== 删除学生信息 ===\n");
    printf("请输入要删除的学生学号: ");
    scanf("%s", id);
    Student temp;
    // 遍历查找要删除的学生
    int pos = 1;
    LinkNode *p = L->next;
    while (p != NULL) {
        if (strcmp(p->data.ID, id) == 0) {
            if (ListDelete(L, pos, temp)) {
                printf("\n学生信息删除成功！\n");
                return;
            }
        }
        pos++;
        p = p->next;
    }
    printf("\n未找到该学号的学生！\n");
}

void modify_stu(LinkNode *&L)   
{
    char id[20];
    printf("=== 修改学生信息 ===\n");
    printf("请输入要修改的学生学号: ");
    scanf("%s", id);
    system(CLEAR_SCREEN);
    LinkNode *p = L->next;
    while (p != NULL) {
        if (strcmp(p->data.ID, id) == 0) {
            printf("找到学生，请输入新的信息：\n");
            printf("请输入姓名: ");
            scanf("%s", p->data.Name);
            printf("请输入性别(M/F): ");
            scanf("%s", p->data.Gender);
            printf("请输入专业: ");
            scanf("%s", p->data.Major);
            printf("请输入年级: ");
            scanf("%s", p->data.Grade);
            printf("请输入班级: ");
            scanf("%s", p->data.Class);
            printf("\n修改成功！\n");
            return;
        }
        p = p->next;
    }
    printf("未找到该学号的学生！\n");
}


void query_stu(LinkNode *&L)
{
    char id[20];
    printf("=== 查询学生信息 ===\n");
    printf("请输入要查询的学生学号: ");
    scanf("%s", id);
    system(CLEAR_SCREEN);
    LinkNode *p = L->next;
    while (p != NULL) {
        if (strcmp(p->data.ID, id) == 0) {
            printf("学生信息如下：\n");
            printf("学号：%s\n", p->data.ID);
            printf("姓名：%s\n", p->data.Name);
            printf("性别：%s\n", p->data.Gender);
            printf("专业：%s\n", p->data.Major);
            printf("年级：%s\n", p->data.Grade);
            printf("班级：%s\n", p->data.Class);
            return;
        }
        p = p->next;
    }
    printf("未找到该学号的学生！\n");
}

void show_all_stu(LinkNode *L)
{
    printf("=== 显示所有学生信息 ===\n");
    DispList(L);
}

void batch_modify_stu(LinkNode *&L)
{
    char grade[MAX_SIZE];
    char major[MAX_SIZE], new_value[MAX_SIZE];
    int choice;
    
    printf("=== 批量修改学生信息 ===\n");
    printf("1. 按年级批量修改\n");
    printf("2. 按专业批量修改\n");
    printf("请选择修改方式: ");
    scanf("%d", &choice);
    system(CLEAR_SCREEN);
    LinkNode *p = L->next;
    if (choice == 1) {
        printf("请输入要修改的年级: ");
        scanf("%s", grade);
        printf("请输入新的专业名称: ");
        scanf("%s", new_value);
        
        while (p != NULL)
        {
            if (strcmp(p->data.Grade, grade) == 0)
            {
                strcpy(p->data.Major, new_value);
            }
            p = p->next;
        }
    }
    else if(choice == 2)
    {
        printf("请输入要修改的专业: ");
        scanf("%s", major);
        printf("请输入新的年级: ");
        scanf("%s", grade);
        while (p != NULL)
        {
            if (strcmp(p->data.Major, major) == 0)
            {
                strcpy(p->data.Grade, grade);
            }
            p = p->next;
        }
    }
    printf("\n批量修改完成！\n");
}

#include "../include/show_menu.h"

void main_menu()
{
    printf("欢迎来到学生、教室综合管理系统!\n");
    printf("================================\n");
    printf("1. 学生信息管理\n");
    printf("2. 教室资源管理\n");
    printf("0. 退出系统\n");
    printf("================================\n");
    printf("请输入您的选择: ");
}

void student_menu()
{
    printf("==== 学生信息管理 ====\n");
    printf("1. 添加学生信息\n");
    printf("2. 删除学生信息\n");
    printf("3. 查询学生信息\n");
    printf("4. 修改学生信息\n");
    printf("5. 显示所有学生\n");
    printf("6. 批量修改信息\n");
    printf("0. 返回主菜单\n");
    printf("==================\n");
    printf("请输入您的选择: ");
}

void classroom_menu()
{
    printf("==== 教室资源管理 ====\n");
    printf("1. 添加教室信息\n");
    printf("2. 删除教室信息\n");
    printf("3. 查询教室信息\n");
    printf("0. 返回主菜单\n");
    printf("==================\n");
    printf("请输入您的选择: ");
}

void show_room_menu()
{
    printf("==== 教室查询 ====\n");
    printf("1. 查询多媒体教室\n");
    printf("2. 用容量查询教室\n");
    printf("3. 用编号查询教室\n");
    printf("0. 返回主菜单\n");
    printf("==================\n");
    printf("请输入您的选择: ");
}
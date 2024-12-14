#include "../include/read_write_csv.h"
#include "../include/stu_oper.h"
#include "../include/room_oper.h"
#include "../include/list.h"
#include "../include/students.h"
#include "../include/AVL.h"

// 将字符串分割成学生信息
Student parseStudent(const char* line)
{
    Student stu;
    sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%s", stu.ID, stu.Name, stu.Gender, stu.Major, stu.Grade, stu.Class);
    return stu;
}

// 将字符串分割成教室信息
BSTNode parseClassroom(const char* line)
{
    BSTNode classroom;
    sscanf(line,  "%d,%[^,],%[^,],%[^,],%[^,],%d,%s\n", &classroom.key, classroom.sec, classroom.name, classroom.lei, classroom.mutimedia, &classroom.size, classroom.pos);
    return classroom;
}

// 创建CSV文件
void createCSV(const char* filename)
{
    FILE* file = fopen(filename, "w");
    if (file) {
        cout << "文件 " << filename << " 创建成功。\n";
        fclose(file);
    } else {
        cerr << "文件 " << filename << " 创建失败。\n";
    }
}

// 读取学生CSV文件，并统计有多少行
int read_stu_CSV(const char* filename, LinkNode*& L)
{
    FILE* file = fopen(filename, "r");
    if (!file) {
        cerr << "文件 " << filename << " 不存在。\n";
        return 0;
    }

    char line[256];
    int lineCount = 0;
    while (fgets(line, sizeof(line), file)) {
        // 移除行尾的换行符
        line[strcspn(line, "\n")] = 0;
        Student stu = parseStudent(line);
        // 假设add_stu函数已经定义好
        auto_add_student(L, stu); // 修改add_stu函数以接受一个Student参数
        lineCount++;
    }
    fclose(file);
    return lineCount;
}

// 写入学生CSV文件（清空源文件再写入）
void write_stu_CSV(const char* filename, LinkNode*& L)
{
    FILE* file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "文件 %s 打开失败。\n", filename);
        return;
    }
    // 遍历链表并写入文件
    LinkNode* p = L->next;
    while (p != NULL)
    {
        Student stu = p->data;
        fprintf(file, "%s,%s,%s,%s,%s,%s\n", stu.ID, stu.Name, stu.Gender, stu.Major, stu.Grade, stu.Class);
        p = p->next;
    }
    fclose(file);
    printf("内容已写入文件 %s。\n", filename);
}

// 读取教室CSV文件，并统计有多少行
int read_room_CSV(const char* filename, BSTNode*& b)
{
    FILE* file = fopen(filename, "r");
    if (!file) {
        cerr << "文件 " << filename << " 不存在。\n";
        return 0;
    }

    char line[256];
    int lineCount = 0;
    while (fgets(line, sizeof(line), file))
    {
        line[strcspn(line, "\n")] = 0; // 移除行尾换行符
        BSTNode new_room = parseClassroom(line);
        //BSTNode *&p, KeyType key, char pos[Maxsize], int size, char mutimedia[2]
        auto_add_room(b, new_room.key, new_room.sec, new_room.name, new_room.lei, new_room.mutimedia, new_room.size, new_room.pos);
        lineCount++;
    }
    fclose(file);
    return lineCount;
}

// 写入教室CSV文件（清空源文件再写入）
void write_room_CSV(const char* filename, BSTNode*& b)
{
    FILE* file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "文件 %s 打开失败。\n", filename);
        return;
    }
    write_sigle_room(b, file);
    fclose(file);
    printf("内容已写入文件 %s。\n", filename);
}

void write_sigle_room(BSTNode*b, FILE* file)
{
    if (b!=NULL)
    {
        fprintf(file, "%d,%s,%s,%s,%s,%d,%s\n", b->key, b->sec, b->name, b->lei, b->mutimedia, b->size, b->pos);
        if (b->lchild!=NULL || b->rchild!=NULL)
        {
            write_sigle_room(b->lchild, file);
            write_sigle_room(b->rchild, file);
        }
    }
}

#include "../include/init.h"

int init(LinkNode *&L, BSTNode *&b, const char* filename1, const char* filename2)
{
    
    int line_sum[2] = {0, 0};
    // 检查文件是否存在
    FILE* file1 = fopen(filename1, "r"); // 以只读模式尝试打开文件
    if (!file1)
    {
        createCSV(filename1);
        line_sum[0] = 0;
    }
    else
    {
        line_sum[0] = read_stu_CSV(filename1, L);
    }
    FILE* file2 = fopen(filename2, "r"); // 以只读模式尝试打开文件
    if (!file2)
    {
        createCSV(filename2);
        line_sum[1] = 0;
    }
    else
    {
        line_sum[1] = read_room_CSV(filename2, b);
    }
    printf("初始化完成!\n");
    return line_sum[2];
}
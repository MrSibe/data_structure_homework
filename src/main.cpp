#include "../include/switch_choice.h"
#include "../include/init.h"

const char* filename1 = "stu.csv";
const char* filename2 = "room.csv";
LinkNode *L;
BSTNode *b=NULL;

// 程序主入口
int main()
{
    InitList(L);
    init(L, b, filename1, filename2);
    main_switch(L, b, filename1, filename2);
    return 0;
}
#include "../include/room_oper.h"

void add_room(BSTNode *&b)
{
    int key;
    char sec[Maxsize];
    char name[Maxsize];
    char lei[Maxsize];
    char mutimedia[2];
    int size;
    char pos[Maxsize];
    printf("\n=== 添加教室 ===\n");
    printf("请输入教室编号: ");
    scanf("%d", &key);
    printf("请输入教室所在校区: ");
    scanf("%s", sec);
    printf("请输入教室名称: ");
    scanf("%s", name);
    printf("请输入教室类别: ");
    scanf("%s", lei);
    printf("请输入是否有多媒体(Y/N): ");
    scanf("%s", mutimedia);
    printf("请输入教室容量: ");
    scanf("%d", &size);
    printf("请输入教室所在教学楼: ");
    scanf("%s", pos);
    auto_add_room(b, key, sec, name, lei, mutimedia, size, pos);
}

void auto_add_room(BSTNode *&b, KeyType key, char sec[Maxsize], char name[Maxsize], char lei[Maxsize], char mutimedia[2], int size, char pos[Maxsize])
{
    int taller = 0;
    InsertAVL(b, key, sec, name, lei, mutimedia, size, pos, taller);
}

void delete_room(BSTNode *&b)
{   
    int taller = 0;
    int id;
    printf("\n=== 删除教室信息 ===\n");
    printf("请输入要删除的教室编号: ");
    scanf("%d", &id);
    int flag = DeleteAVL(b, id, taller);
    if(flag == 0) printf("\n未找到该编号的教室！\n");
    else printf("\n教室信息删除成功！\n");
}

void show_media_room(BSTNode *b)
{
    if (b!=NULL)
    {
        if(strcmp(b->mutimedia, "Y") == 0) printf("%d\t%20s\t%20s\t%20s\t%s\t%d\t%s\n", b->key, b->sec, b->name, b->lei, b->mutimedia, b->size, b->pos);
        if (b->lchild!=NULL || b->rchild!=NULL)
        {
            show_media_room(b->lchild);
            show_media_room(b->rchild);
        }
    }
}

void show_size_room(BSTNode *b, int size)
{
    if (b!=NULL)
    {
        if((b->size) >= size) printf("%d\t%20s\t%20s\t%20s\t%s\t%d\t%s\n", b->key, b->sec, b->name, b->lei, b->mutimedia, b->size, b->pos);
        if (b->lchild!=NULL || b->rchild!=NULL)
        {
            show_size_room(b->lchild, size);
            show_size_room(b->rchild, size);
        }
    }
}

void show_id_room(BSTNode *b, int id)
{
    if (b!=NULL)
    {
        if(b->key == id)
        {
            printf("%d\t%20s\t%20s\t%20s\t%s\t%d\t%s\n", b->key, b->sec, b->name, b->lei, b->mutimedia, b->size, b->pos);
        }
        if (b->lchild!=NULL || b->rchild!=NULL)
        {
            show_id_room(b->lchild, id);
            show_id_room(b->rchild, id);
        }
    }
}
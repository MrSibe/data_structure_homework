#include "../include/switch_choice.h"
#include "../include/clear_screen.h"

void main_switch(LinkNode *&L, BSTNode *&b, const char* filename1, const char* filename2)
{   
    int choice;
    do
    {
        main_menu();
        scanf("%d", &choice);
        system(CLEAR_SCREEN);
        switch(choice)
        {
        case 1:
            student_switch(L);
            break;
            
        case 2:
            classroom_switch(b);
            break;
            
        case 0:
            end_switch(L, b, filename1, filename2);
            printf("\n感谢使用本系统，再见！\n");
            break;
            
        default:
            printf("\n无效的选择，请重试！\n");
            break;
        }
    } while (choice != 0);
}

void student_switch(LinkNode *&L)
{
    int choice;
    do
    {
        student_menu();
        scanf("%d", &choice);
        system(CLEAR_SCREEN);
        switch(choice)
        {
        case 1:
            add_stu(L);
            printf("==== 按q回车退出 ====\n");
            while(1)
            {
                if (getchar() == 'q') break;
            }
            system(CLEAR_SCREEN);
            break;

        case 2:
            delete_stu(L);
            printf("==== 按q回车退出 ====\n");
            while(1)
            {
                if (getchar() == 'q') break;
            }
            system(CLEAR_SCREEN);
            break;  

        case 3:
            query_stu(L);
            printf("==== 按q回车退出 ====\n");
            while(1)
            {
                if (getchar() == 'q') break;
            }
            system(CLEAR_SCREEN);
            break;

        case 4:
            modify_stu(L);
            printf("==== 按q回车退出 ====\n");
            while(1)
            {
                if (getchar() == 'q') break;
            }
            system(CLEAR_SCREEN);
            break;

        case 5:
            show_all_stu(L);
            printf("==== 按q回车退出 ====\n");
            while(1)
            {
                if (getchar() == 'q') break;
            }
            system(CLEAR_SCREEN);
            break;

        case 6:
            batch_modify_stu(L);
            printf("==== 按q回车退出 ====\n");
            while(1)
            {
                if (getchar() == 'q') break;
            }
            system(CLEAR_SCREEN);
            break;

        case 0:
            break;

        default:
            printf("\n无效的选择，请重试！\n");
            break;
        }
    }
    while(choice != 0);
}

void classroom_switch(BSTNode *&b)
{
    int choice;
    do
    {
        classroom_menu();
        scanf("%d", &choice);
        system(CLEAR_SCREEN);
        switch(choice)
        {
        case 1:
            add_room(b);
            system(CLEAR_SCREEN);
            break;
        
        case 2:
            delete_room(b);
            system(CLEAR_SCREEN);
            break;  

        case 3:
            show_room(b);
            break;

        case 0:
            break;
                
        default:
                printf("\n无效的选择，请重试！\n");
            break;
        }
    }
    while(choice != 0);
}   

void show_room(BSTNode *&b)
{
    int choice;
    do
    {
        show_room_menu();
        scanf("%d", &choice);
        system(CLEAR_SCREEN);
        switch(choice)
        {
        case 1:
            printf("id\t\t\t校区\t\t\t名称\t\t\t类型\t多媒体\t容量\t教学楼\n");
            printf("=======================================================================================================\n");
            show_media_room(b);
            printf("==== 按q回车退出 ====\n");
            while(1)
            {
                if (getchar() == 'q') break;
            }
            system(CLEAR_SCREEN);
            break;
        
        case 2:
            int size;
            printf("请输入想查找的最小容量：");
            scanf("%d", &size);
            system(CLEAR_SCREEN);
            printf("id\t\t\t校区\t\t\t名称\t\t\t类型\t多媒体\t容量\t教学楼\n");
            printf("=======================================================================================================\n");
            show_size_room(b, size);
            printf("==== 按q回车退出 ====\n");
            while(1)
            {
                if (getchar() == 'q') break;
            }
            system(CLEAR_SCREEN);
            break;  

        case 3:
            int id;
            printf("请输入想查找的教室编号：");
            scanf("%d", &id);
            system(CLEAR_SCREEN);
            printf("id\t\t\t校区\t\t\t名称\t\t\t类型\t多媒体\t容量\t教学楼\n");
            printf("=======================================================================================================\n");
            show_id_room(b, id);
            printf("==== 按q回车退出 ====\n");
            while(1)
            {
                if (getchar() == 'q') break;
            }
            system(CLEAR_SCREEN);
            break;

        case 0:
            break;
                
        default:
                printf("\n无效的选择，请重试！\n");
            break;
        }
    }
    while(choice != 0);
}

void end_switch(LinkNode *&L, BSTNode *&b, const char* filename1, const char* filename2)
{
    char choice[2];
    while(1)
    {
        printf("是否保存修改(Y/n):");
        scanf("%s", choice);
        if((strcmp("y", choice) == 0) || (strcmp("Y", choice) == 0))
        {
            write_stu_CSV(filename1, L);
            write_room_CSV(filename2, b);
            return;
        }
        else if((strcmp("n", choice) == 0) || (strcmp("N", choice) == 0))
        {
            return;
        }
        else
        {
            printf("\n无效的选择，请重试！\n");
        }
    }
}
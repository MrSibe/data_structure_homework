#include "../include/AVL.h"

#ifndef ROOM_OPER_H
#define ROOM_OPER_H

void add_room(BSTNode *&b);
void auto_add_room(BSTNode *&b, KeyType key, char sec[Maxsize], char name[Maxsize], char lei[Maxsize], char mutimedia[2], int size, char pos[Maxsize]);
void delete_room(BSTNode *&b);
void show_media_room(BSTNode *b);
void show_size_room(BSTNode *b, int size);
void show_id_room(BSTNode *b, int id);

#endif
#ifndef DE_LIST_H
#define DE_LIST_H

#include <stdio.h>

#include "student.h"

typedef student node_type;

// Структура узла
struct node {
    node *next;
    node *prev;
    node_type val;
};

// Структура списка
struct circularly_list {
    node *begin;
    node *end;
    int size;
};

// Создание нового узла
//node *create_node(node*, node*, node_type);
// Удаление узла
void free_node(node*);


// Создание ссписка
circularly_list *create_list();
// Удаление списка
void free_list(circularly_list*);

// добавление элемента в конец
void push_back(circularly_list*, node_type);
// Вывод списка
void print_list(circularly_list*, FILE*);


#endif // DE_LIST_H


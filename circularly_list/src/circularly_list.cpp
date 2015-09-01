#include <stdio.h>

#include "circularly_list.h"

//node *create_node(node *next, node *prev, node_type val) {
//    node *n = new node;

//    n->next = next;
//    n->prev = prev;
//    n->val = val;

//    return n;
//}

void free_node(node *n) {
    delete n;
}

circularly_list *create_list() {
    circularly_list *l = new circularly_list;

    l->begin = NULL;
    l->end = NULL;

    l->size = 0;

    return l;
}

void free_list(circularly_list *l) {
    if (l->begin != NULL || l->size == 0) {
        node *p = l->begin;
        int size = l->size;
        for (int i = 0; i < size; i++) {
            node *next = p->next;
            delete p;
            p = next;

            l->size--;
        }
    }
}

void push_back(circularly_list *l, node_type val) {
    node *n = new node;
    n->val = val;

    // Если голова списка - пуста
    if (l->begin == NULL) {

        n->next = n;
        n->prev = n;

        l->begin = l->end = n;

    // Если вставка идёт в хвост
    } else {
        n->next = l->begin;
        n->prev = l->end;

        l->end->next = n;

        l->end = n;
        l->begin->prev = n;
    }
    // Увеличиваем размер списка
    l->size++;
}

void print_list(circularly_list *l, FILE *f) {
    if (l->begin == NULL || l->size == 0) {
        fprintf(f, "List is empty!\n");
    } else {
        node *p = l->begin;
        for (int i = 0; i < l->size; i++) {
            output_st(p->val, f);

            fprintf(f, "{prev: %p cur: %p next: %p}\n", p->prev, p, p->next);
            p = p->next;
        }
    }
}

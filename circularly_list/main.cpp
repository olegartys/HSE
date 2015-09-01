#include <stdio.h>

#include "student.h"
#include "circularly_list.h"

void delete_invalid_students(circularly_list*);
bool to_delete(node*);

int main()
{
    // Открываем файл для чтения
    char fin_name[MAX_SIZE];
    printf("Enter input filename: ");
    gets(fin_name);
    FILE *fin = fopen(fin_name, "r");

    // если файла не существует
    if (fin == NULL) {
        puts("File doesn't exist!");
    } else {

        // Открываем файл для записи
        char fout_name[MAX_SIZE];
        printf("Enter output filename: ");
        gets(fout_name);
        FILE *fout = fopen(fout_name, "w");

        circularly_list *queue = create_list();
        while (!feof(fin)) {
            student st;
            st = input_st(fin);
            push_back(queue, st);
        }


        fputs("***Read list: ***\n", fout);
        print_list(queue, fout);

        delete_invalid_students(queue);

        fputs("***List after delete***:\n", fout);
        print_list(queue, fout);

        free_list(queue);
    }

    return 0;
}

bool to_delete(node *n) {
    bool flag = false;
    for (int i = 0; i < MARK_K && !flag; i++) {
        if (n->val.progress.B[i] < 4)
            flag = true;
    }
    return flag;
}

void delete_invalid_students(circularly_list *l) {
    node *p = l->begin;

    // Для головы
    while (to_delete(p) && l->size != 0) {

        p->next->prev = l->end;
        p->prev->next = p->next;

        l->begin = p->next;

        delete p;

        p = l->begin;
        l->size--;
    }

    if (l->size != 0)
        // Смотрим хвост списка
        while (p->next != l->begin) {

            if (to_delete(p->next)) {

                node *n = p->next;

                p->next->next->prev = p;
                p->next = p->next->next;

                delete n;

                l->size--;
            }
            else
                p = p->next;
    }
}

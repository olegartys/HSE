#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

#define MAX_SIZE 216
#define MARK_K 5

struct student {
    struct {
        char surname[MAX_SIZE];
        char name[MAX_SIZE];
        char sec_name[MAX_SIZE];
    } initials;
    int group;
    struct {
        int B[MARK_K];
        double average;
    } progress;
};

// Считыание структуры из файла
student input_st(FILE*);

// Вывод струтуры в файл
void output_st(student, FILE*);

#endif // STUDENT_H


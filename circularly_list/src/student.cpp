#include <stdio.h>

#include "student.h"

student input_st(FILE *f) {
    student st; // создаём структуру студент

    // Считыаем ФИО
    fgets(st.initials.surname, MAX_SIZE, f);
    fgets(st.initials.name, MAX_SIZE, f);
    fgets(st.initials.sec_name, MAX_SIZE, f);

    fscanf(f, "%d", &st.group); //считываем группу

    // считывеам массив оценок и считаем СА
    int sum = 0;
    for (int i = 0; i < MARK_K; i++) {
        fscanf(f, "%d", &st.progress.B[i]);
        sum += st.progress.B[i];
    }

    st.progress.average = sum / MARK_K;

    fscanf(f, "%*d");

    return st;
}

void output_st(student st, FILE *f) {
    fputs(st.initials.surname, f);
    fputs(st.initials.name, f);
    fputs(st.initials.sec_name,  f);

    fprintf(f, "%d\n", st.group);

    for (int i = 0; i < MARK_K; i++) {
        fprintf(f, "%d ", st.progress.B[i]);
    }

    //fprintf(f, "\n%f ", st.progress.average);

    fputs("\n", f);
}

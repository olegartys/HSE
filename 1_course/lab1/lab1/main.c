/*
 * lab1.c
 *
 * Copyright 2015 olegartys <olegartys@olegartys-HP>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>

#define STDIN_INPUT

/*
 * Формирование массива C.
 * A, B - исходные массив, n - их размерность.
 * arraySize - размерность нового массива.
 */
int* GenArray (const int* A, const int* B, const size_t n, size_t* arraySize);

int main(void)
{
    //ввод размерности
    size_t n, i;
    printf ("Введите число элементов массива A и B: ");
    scanf ("%ld", &n);

    int* A = (int*) malloc (sizeof(int) * n);
    if (A == NULL) {
        perror (NULL);
        return errno;
    }
    int* B = (int*) malloc (sizeof(int) * n);
    if (B == NULL) {
        perror (NULL);
        return errno;
    }
    //инициализация исходных массивов
#ifdef STDIN_INPUT
    //стандартный поток ввода
    printf ("Введите элементы массива A: ");
    for (i = 0; i < n; i++)
        scanf ("%d", &A[i]);
    printf ("Введите элементы массива B: ");
    for (i = 0; i < n; i++)
        scanf ("%d", &B[i]);
#else
    //случайные числа
    srand (time(NULL));

    for (i = 0; i < n; i++) {
        A[i] = rand () / 100000;
        B[i] = rand () / 100000;
    }

    printf ("\nМассив A: ");
    for (i = 0; i < n; i++)
        printf ("%d ", A[i]);
    printf ("\nМассив B: ");
    for (i = 0; i < n; i++)
        printf ("%d ", B[i]);
    fflush (stdout);
#endif

    //формирование нового массива
    size_t arraySize = 0;
    int* C = GenArray (A, B, n, &arraySize);
    if (C == NULL) {
        perror (NULL);
        return errno;
    }

    if (arraySize == 0)
        fprintf (stderr, "\nМассив C пуст.\n");
    else {
        printf ("\nМассив C: \n");
        for (i = 0; i < arraySize; i++)
            printf ("\tC[%ld] = %d\n", i, C[i]);
    }

    //освобождение динамической памяти
    free (A);
    free (B);
    free (C);
    return 0;
}

int* GenArray (const int* A, const int* B, const size_t n, size_t* arraySize)
{
    size_t i;
    //заполнение результирующего массива
    int* C = (int*) malloc (sizeof(int) * n);
    if (C == NULL) {
        return NULL;
    }

    for (i = 0; i < n; i++) {
        size_t j;
        int k = 0;
        for (j = 0; j < n && k <= 1; j++)
            if (A[i] == B[j])
                k++;

        if (k <= 1)
            C[(*arraySize)++] = A[i];
    }

    return C;
}

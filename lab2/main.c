#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#define STDIN_INPUT

enum {
    CHANGED,
    ONE_POSITIVE,
    NO_POSITIVE
};

/*
 * A - исходная матрица
 * m и n - количество строк и столбцов соответственно
 */
int MatrixChange (int** A, const size_t m, const size_t n);

int main(void)
{
    size_t m, n, i, j;
    printf ("Введите число строк и число столбцов матрицы: ");
    scanf ("%ld %ld", &m, &n);

    //выделение памяти под матрицу
    int** A = (int**) malloc (sizeof(int*) * m);
    if (A == NULL) {
        perror (NULL);
        return errno;
    }
    for (i = 0; i < m; i++)
        if ((A[i] = (int*) malloc (sizeof(int) * n)) == NULL) {
            perror (NULL);
            return errno;
        }
#ifdef STDIN_INPUT
    printf ("Введите элементы матрицы A: ");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf ("%ld", &A[i][j]);
#else
    srand (time(NULL));
    printf ("Элементы матрицы: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = - rand() / 10000;
            printf ("%d\t", A[i][j]);
        }
        puts("");
    }
#endif
    int res = MatrixChange (A, m, n);

    //анализ результата замены
    switch (res) {
        case CHANGED:
            printf ("\nПерестановка удачна. Полученная матрица:\n");
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++)
                    printf ("%d\t", A[i][j]);
                puts("");
            }
            break;
        case ONE_POSITIVE:
            printf ("\nМатрица содержит только один положительнй элемент. Изменений нет.\n");
            break;
        case NO_POSITIVE:
            printf ("\nПоложительные элементы отсутствуют. Изменений нет.\n");
            break;
    }

    //освобождение динамической памяти
    for (i = 0; i < m; i++)
        free (A[i]);
    free (A);
    return 0;
}

int MatrixChange (int** A, const size_t m, const size_t n)
{
    //координаты первого и последнего положительных
    struct {
        int row, col;
    } firstPositive = {-1, -1},
      lastPositive  = {-1, -1};

    //нахождение первого и последнего положительных
    size_t i, j;
    for (i = 0; i < m; i++)
        for  (j = 0; j < n; j++)
            if (A[i][j] > 0) {
                if (firstPositive.row == -1)
                    firstPositive.row = i, firstPositive.col = j;
                else
                    lastPositive.row = i, lastPositive.col = j;
            }

    //возвращаем результат
    if (firstPositive.row != -1 && lastPositive.row != -1) {
        //перестановка их местами
        int c = A[firstPositive.row][firstPositive.col];
        A[firstPositive.row][firstPositive.col] = A[lastPositive.row][lastPositive.col];
        A[lastPositive.row][lastPositive.col] = c;

        return CHANGED;
    }
    else if (firstPositive.row != -1 && lastPositive.col == -1)
        return ONE_POSITIVE;
    else
        return NO_POSITIVE;
}


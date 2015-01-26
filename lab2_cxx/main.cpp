#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

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
    size_t m, n;
    printf ("Введите число строк и число столбцов матрицы: ");
    cin >> m >> n;

    //выделение памяти под матрицу
    int** A;
    try {
        A = new int*[m];
    } catch (std::bad_alloc& e){
        cerr << e.what() << endl;
        return errno;
    }

    for (int** i = A; i != A+m; i++)
        try {
            *i = new int[n];
        } catch (std::bad_alloc& e) {
            cerr << e.what() << endl;
        }

#ifdef STDIN_INPUT
    cout << "Введите элементы матрицы A: ";
    for (size_t i = 0; i < m; i++)
        for (int* j = A[i]; j != A[i]+n; j++)
            cin >> *j;
#else
    srand (time(NULL));
    cout << "Элементы матрицы: \n";
    for (int** i = A; i != A+m; i++) {
        for (int* j = *i; j != *i+n; j++) {
            *j = rand() / 10000;
            cout << *j << "\t";
        }
        cout << endl;
    }
#endif
    int res = MatrixChange (A, m, n);

    //анализ результата замены
    switch (res) {
        case CHANGED:
            cout << "\nПерестановка удачна. Полученная матрица:\n";
            for (size_t i = 0; i < m; i++) {
                for (const int* j = A[i]; j != A[i]+n; j++)
                    cout << *j << "\t";
                cout << endl;
            }
            break;
        case ONE_POSITIVE:
            cout << "\nМатрица содержит только один положительнй элемент. Изменений нет.\n";
            break;
        case NO_POSITIVE:
            cout << "\nПоложительные элементы отсутствуют. Изменений нет.\n";
            break;
    }

    //освобождение динамической памяти
    for (size_t i = 0; i < m; i++)
        delete[] A[i];
    delete[] A;

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
    for (size_t i = 0; i < m; i++)
        for  (size_t j = 0; j < n; j++)
            if (A[i][j] > 0) {
                if (firstPositive.row == -1)
                    firstPositive.row = i, firstPositive.col = j;
                else
                    lastPositive.row = i, lastPositive.col = j;
            }

    //возвращаем результат
    if (firstPositive.row != -1 && lastPositive.row != -1) {
        //перестановка их местами
        int c = *(*(A + firstPositive.row) + firstPositive.col);
        *(*(A + firstPositive.row) + firstPositive.col) = *(*(A + lastPositive.row) + lastPositive.col);
        *(*(A + lastPositive.row) + lastPositive.col) = c;

        return CHANGED;
    }
    else if (firstPositive.row != -1 && lastPositive.col == -1)
        return ONE_POSITIVE;
    else
        return NO_POSITIVE;
}


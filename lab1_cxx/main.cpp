#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cerrno>
#include <cstdio>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

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
    size_t n;
    cout << "Введите число элементов массива A и B: ";
    cin >> n;

    //инициализация исходных массивов
    int* A, *B;
    try {
        A = new int [n];
    } catch (std::bad_alloc& e) {
        perror(e.what());
        return errno;
    }

    try {
        B = new int [n];
    } catch (std::bad_alloc& e) {
        perror(e.what());
        return errno;
    }

#ifdef STDIN_INPUT
    //стандартный поток ввода
    cout << "Введите элементы массива A: ";
    for (int* i = A; i != A+n; i++)
        cin >> *i;
    cout << "Введите элементы массива B: ";
    for (int* i = B; i != B+n; i++)
        cin >> *i;
#else
    //случайные числа
    srand (time(NULL));

    for (int* i = A; i != A+n; i++)
        *i = rand () / 100000;
    for (int* i = B; i != B+n; i++)
        *i = rand () / 100000;

    cout << "\nМассив A: ";
    for (int* i = A; i != A+n; i++)
        cout << *i << " ";
    cout << "\nМассив B: ";
    for (int* i = B; i != B+n; i++)
        cout << *i << " ";
#endif

    //формирование нового массива
    size_t arraySize = 0;
    int* C = GenArray (A, B, n, &arraySize);
    if (C == NULL) {
        perror (NULL);
        return errno;
    }

    if (arraySize == 0)
        cerr << "\nМассив C пуст.\n";
    else {
        cout << "\nМассив C: \n";
        size_t j = 0;
        for (int* i = C; i != C+arraySize; i++)
            cout << "\tC[" << j++ << "] = " << *i << endl;
    }

    //освобождение динамической памяти
    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}

int* GenArray (const int* A, const int* B, const size_t n, size_t* arraySize)
{
    int* C;
    try {
        C = new int [n];
    } catch (std::bad_alloc& e) {
        cerr << "Ошибка выделения памяти. " << e.what() << endl;
        return NULL;
    }

    //заполнение результирующего массива
    for (const int* i = A; i != A+n; i++) {
        int k = 0;
        for (const int* j = B; j != B+n; j++)
            if (*i == *j)
                k++;

        if (((k % 2) == 0) && k != 0) {
            const int* j;
            for (j = C; j != C+*arraySize && *i == *j; j++);
            if (*j == *arraySize)
                *(C + (*arraySize)++) = *i;
        }
    }

    return C;
}

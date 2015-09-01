#include <iostream>

using namespace std;

#define INPUT_INVITE_SYMBOL '>'

typedef unsigned long long ullong;

ullong f_akkerman(const ullong n, const ullong m);

int main()
{
    ullong n, m;
    cout << INPUT_INVITE_SYMBOL << "Введите n и m: ";
    cin >> n >> m;

    cout << INPUT_INVITE_SYMBOL << "Результат функции Аккермана: "
         << f_akkerman(n, m) << endl;
    return 0;
}

/**
 * @brief f_akkerman
 * @param n
 * @param m
 * @return результат функции Аккермана
 */
ullong f_akkerman(const ullong n, const ullong m) {
    if (n == 0) {
        return m+1;
    } else if (n != 0 && m == 0) {
        return f_akkerman(n-1, 1);
    } else if (n > 0 && m > 0) {
        return f_akkerman(n-1, f_akkerman(n, m-1));
    }
}


#include <iostream>
#include "my_list.h"

using namespace std;

int main()
{
    my_list<int> list(2);
    list.push_back(3);
    list.push_back(4);

    my_list<int>::iterator iter(list.begin());

    for (; !(iter == list.end() + 1); ++iter)
        cout << *iter << ' ';


    cout.flush();
    return 0;
}


#include <iostream>
#include "my_list.h"

using namespace std;

int main()
{
    my_list<int> list(2);
    list.push_back(3);

    my_iterator<int> iter(list.begin());


    cout << *iter << endl;
    ++iter;
    cout << *iter << endl;


    cout.flush();
    return 0;
}


#include <iostream>
#include <my_list.h>
#include <string>
#include <sstream>

using namespace std;

int main()
{
   //my_list list = new my_list();
    stringstream* _str = new stringstream();
    stringstream& str = *_str;

    str << "12321" << "hello nworld" << 1488;
    cout << str.str() << endl;
    //cout << "Hello World!" << endl;
    return 0;
}


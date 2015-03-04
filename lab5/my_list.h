#ifndef MY_LIST
#define MY_LIST

#include <cstdlib>

template <typename T>
class my_list {
private:

    class node {
        T element;
        T* next;
    };

    node* begin;
    node* end;

    size_t size;

public:
    my_list();
    my_list(const T x);
    ~my_list();
    
    /*void insert_after(const T* pred, const T element);
    T erase_after(const T* pred);
    
    void push_front(const T x);
    T pop_front();
    
    void push_back(const T x);
    T pop_back(const T x);*/
    
};

#endif // MY_LIST


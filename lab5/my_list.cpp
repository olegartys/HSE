#include "my_list.h"

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
    my_list() {
        begin = new node();
        end = new node();
        
        end = NULL;
        begin->next = NULL;
        begin->element = 0;
    }

    my_list(const T x);

    ~my_list() {
        delete begin;
        delete end;
    }
    
    /*void insert_after(const T* pred, const T element);
    T erase_after(const T* pred);
    
    void push_front(const T x);
    T pop_front();
    
    void push_back(const T x);
    T pop_back(const T x);*/
    
};

#ifndef MY_STACK_H
#define MY_STACK_H

#include "my_list.h"

template <typename node_type>
class my_stack {
private:

    typedef my_stack<node_type> stack;
    my_list<node_type>* base_list;

public:
    my_stack();
    my_stack(const node_type& element);
    //my_stack(const stack& copy_stack);
    ~my_stack();

    bool is_empty();
    size_t get_size();
    node_type get_top();

    void push(const node_type& x);
    node_type pop();
};

template <typename node_type>
my_stack<node_type>::my_stack() {
    base_list = new my_list<node_type>();
}

template <typename node_type>
my_stack<node_type>::my_stack(const node_type& element) {
    base_list = new my_list<node_type>(element);
}

template <typename node_type>
void my_stack<node_type>::push(const node_type& element) {
    base_list->push_back(element);
}

template <typename node_type>
node_type my_stack<node_type>::pop() {
    return base_list->pop_back();
}

template <typename node_type>
bool my_stack<node_type>::is_empty() {
    return base_list->is_empty();
}

template <typename node_type>
size_t my_stack<node_type>::get_size() {
    return base_list->get_size();
}

template <typename node_type>
node_type my_stack<node_type>::get_top() {
    return base_list->_end->element;
}

template <typename node_type>
my_stack<node_type>::~my_stack() {
    delete base_list;
}

#endif // MY_STACK_H

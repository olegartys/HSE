#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include "my_list.h"

template <typename node_type>
class my_queue
{
private:

    typedef my_queue<node_type> queue;
    my_list<node_type>* base_list;

public:
    my_queue();
    my_queue(const node_type& x);
    ~my_queue();

    bool is_empty();
    size_t get_size();
    node_type get_front();
    node_type get_back();

    void push(const node_type& x);
    node_type pop();
};

template <typename node_type>
my_queue<node_type>::my_queue() {
    base_list = new my_list<node_type>();
}

template <typename node_type>
my_queue<node_type>::my_queue(const node_type& element) {
    base_list = new my_list<node_type>(element);
}

template <typename node_type>
void my_queue<node_type>::push(const node_type& element) {
    base_list->push_back(element);
}

template <typename node_type>
node_type my_queue<node_type>::pop() {
    return base_list->pop_front();
}

template <typename node_type>
bool my_queue<node_type>::is_empty() {
    return base_list->is_empty();
}

template <typename node_type>
node_type my_queue<node_type>::get_front() {
    return *base_list->begin();
}

template <typename node_type>
node_type my_queue<node_type>::get_back() {
    return *base_list->end();
}

template <typename node_type>
my_queue<node_type>::~my_queue() {
    delete base_list;
}

#endif // MY_QUEUE_H

#ifndef MY_LIST
#define MY_LIST

#include <cstdlib>
#include <iostream>

template <class node_type> class my_iterator;
template <class node_type> class my_list;

template <class node_type>
struct node {
    node_type element;
    node<node_type>* next;
};

/*
 * Реализация однонаправленного списка.
 */
template <class node_type>
class my_list {

    typedef my_iterator<node_type> iterator;

private:

    friend class my_iterator<node_type>;


    node<node_type>* _begin;
    node<node_type>* _end;

    size_t size;

public:
    my_list();
    my_list(const node_type x);
    ~my_list();
    
    iterator begin();
    iterator end();
    void push_back(const node_type x);
    /*void insert_after(const T* pred, const T element);
    T erase_after(const T* pred);
    
    void push_front(const T x);
    T pop_front();
    

    T pop_back(const T x);*/
    
};

template <typename node_type>
my_list<node_type>::my_list() {

    begin = new node<node_type>;

    begin = NULL;
    end = begin;

    size = 0;

}

template <typename node_type>
my_list<node_type>::my_list(const node_type x) {

    _begin = new node<node_type>;

    _begin = NULL;
    _end = _begin;

    size = 0;

    this->push_back(x);
}

template <typename node_type>
void my_list<node_type>::push_back(const node_type x) {

    node<node_type>* p = new node<node_type>;
    p->next = NULL;
    p->element = x;

    if (_begin == NULL)
        _begin = _end = p;
    else {
        _end->next = p;
        _end = p;
    }

   // std::cout << _end->element << std::endl;

    size++;
}

template <typename node_type>
my_iterator<node_type> my_list<node_type>::begin() {
    my_iterator<node_type> it (_begin);
    return it;
}

template <typename node_type>
my_list<node_type>::~my_list() {

    delete _begin;
    //delete end;

}

/*********************************************************/

/*
 * Реализация итератора списка.
 */
template <class node_type>
class my_iterator {

typedef my_iterator<node_type> iterator;

private:

    node<node_type>* current_pos;

public:
    my_iterator();// {current_pos = NULL;}
    my_iterator(node<node_type>* src)  {current_pos = src;}
    my_iterator(iterator* src) {current_pos = src;}

    node_type& operator*();
    iterator& operator= (const iterator& it);
    iterator& operator++ ();
};

template<class node_type>
node_type& my_iterator<node_type>::operator *() {
    return this->current_pos->element;
}

template <class node_type>
my_iterator<node_type>& my_iterator<node_type>::operator =(const my_iterator<node_type>& it) {
    this->current_pos = it->current_pos;
    return *this;
}

template <class node_type>
my_iterator<node_type>& my_iterator<node_type>::operator ++() {
    this->current_pos = this->current_pos->next;
    return *this;
}

#endif // MY_LIST


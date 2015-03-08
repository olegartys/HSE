#ifndef MY_ITERATOR
#define MY_ITERATOR

#include "my_list.h"


template <typename node_type> class my_list;
template <typename node_type> struct node;


template <class node_type>
/**
 * @brief The my_iterator class итератор для обхода списка
 */
class my_iterator {

typedef my_iterator<node_type> iterator;

private:

    friend class my_list<node_type>;
    node<node_type>* current_pos;

public:
    my_iterator();
    my_iterator(node<node_type>* src) : current_pos (src) {}
    //my_iterator(iterator* src) {current_pos = src;}

    node_type& operator* ();
    iterator& operator=  (const iterator& it);
   // iterator& operator+  (const iterator& it);
    iterator& operator+  (const size_t x);
    iterator& operator-  (const iterator& it);

    bool operator== (const iterator& it);
    bool operator!= (const iterator& it);

  //  iterator& operator+= (const iterator& it);

    iterator& operator++ ();
    iterator& operator-- ();

};

template <typename node_type>
node_type& my_iterator<node_type>::operator *() {
    return this->current_pos->element;
}

template <typename node_type>
my_iterator<node_type>& my_iterator<node_type>::operator =(const my_iterator<node_type>& it) {
    this->current_pos = it.current_pos;
    return *this;
}

template <typename node_type>
my_iterator<node_type>& my_iterator<node_type>::operator ++() {
    this->current_pos = this->current_pos->next;
    return *this;
}

//Линейная сложность!
template <typename node_type>
my_iterator<node_type>& my_iterator<node_type>::operator+ (const size_t x) {
    for (int i = 0; i < x; i++)
        this->current_pos = this->current_pos->next;
    return *this;
}

/*template <typename node_type>
my_iterator<node_type>& my_iterator<node_type>::operator- (const size_t x) {

}*/

template <typename node_type>
bool my_iterator<node_type>::operator ==(const iterator& it) {
    return this->current_pos == it.current_pos;
}

template <typename node_type>
bool my_iterator<node_type>::operator !=(const iterator& it) {
    return this->current_pos != it.current_pos;
}

#endif // MY_ITERATOR


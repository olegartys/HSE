#ifndef MY_LIST
#define MY_LIST

//#define DEBUG

#include <cstdlib>
#include <stdexcept>
#include <cstring>
#include "my_iterator.h"
#ifdef DEBUG
    #include <iostream>
#endif

template <typename node_type> class my_list;
template <typename node_type> class my_iterator;
template <typename node_type> class my_stack;
template <typename node_type> class my_queue;

template <typename node_type>
/**
 * @brief The node struct Элемент списка.
 * @detailed element - содержимое элемента,
 * next - указатель на следующий элемент.
 */
struct node {
    node_type element;
    node<node_type>* next;
};

template <class node_type>
/**
 * @brief The my_list class Реализация однонаправленного списка.
 */
class my_list {
private:

    friend class my_iterator<node_type>;
    friend class my_stack<node_type>;
    friend class my_queue<node_type>;

    node<node_type>* _begin;
    node<node_type>* _end;

    size_t size;

public:
    typedef my_iterator<node_type> iterator;

    my_list();
    my_list(std::initializer_list<node_type> li);
    my_list(const node_type x);
    my_list(my_list<node_type>& list);
    ~my_list();

    my_iterator<node_type> get_iter_by_pos(const int pos);
    
    iterator begin();
    iterator end();
    size_t get_size();
    bool is_empty();

    void push_back(const node_type& x);
    node_type pop_back();
    void push_front(const node_type& x);
    node_type pop_front();

    node_type& operator [](const int index);

    void insert_after(iterator& pred, const node_type& element);
    node_type erase_after(iterator& pred);
};

template <typename node_type>
/**
 * @brief my_list<node_type>::insert_after вставка элемента в список
 * @param pred элемент, после которого нужно вставить новый элемент
 * @param element элемент для вставки
 */
void my_list<node_type>::insert_after(iterator& pred, const node_type& element) {

    node<node_type>* p = new node<node_type>;
    p->element = element;
    p->next = pred.current_pos->next;

    pred.current_pos->next = p;

    size++;

}

template <typename node_type>
/**
 * @brief my_list<node_type>::erase_after удаляет элемент, идущий после pred
 * @param pred элемент, после которого нужно произвести удаление
 * @return значение, которое было в удалённом элементе
 */
node_type my_list<node_type>::erase_after(iterator& pred) {
    node<node_type>* t = pred.current_pos->next->next;
    node_type x = pred.current_pos->next->element;
    delete pred.current_pos->next;
    pred.current_pos->next = t;
    size--;
    return x;
}

template <typename node_type>
/**
 * @brief my_list<node_type>::get_iter_by_pos
 * @detailed !!!Линейная сложность!
 * @param pos номер элемента в списке.
 * @throw std::range_error в случае выхода за границы списка
 * @return итератор, указывающий на элемент списка с номером pos.
 */
my_iterator<node_type> my_list<node_type>::get_iter_by_pos(const int pos) {
    if (pos < 0 || pos >= size) {
        throw std::range_error("Выход за границы списка!");
    } else {
        iterator it = this->begin();
        for (int i = 0; i < pos; i++) {
            ++it;
        }
        return it;
    }
}

template <typename node_type>
/**
 * @brief my_list<node_type>::my_list Конструктор по умолчанию.
 */
my_list<node_type>::my_list() {

    _begin = new node<node_type>;

    _begin = NULL;
    _end = _begin;

    size = 0;

}

template <typename node_type>
my_list<node_type>::my_list(std::initializer_list<node_type> li) {
    _begin = new node<node_type>;

    _begin = NULL;
    _end = _begin;

    size = 0;

    for (auto it = li.begin(); it != li.end(); ++it)
        this->push_back(*it);
}

//FIXME: как запустить конструктор внутри конструктора? чтобы не дублирвоать код
template <typename node_type>
/**
 * @brief my_list<node_type>::my_list Конструктор, инициализирующий голову списка.
 * @param x - голова списка
 *
 */
my_list<node_type>::my_list(const node_type x) {

    _begin = new node<node_type>;

    _begin = NULL;
    _end = _begin;

    size = 0;

    this->push_back(x);
}

template <typename node_type>
/**
 * @brief my_list<node_type>::my_list Конструктор копии
 * @param copy_list список для копирования.
 */

my_list<node_type>::my_list(my_list<node_type>& copy_list) {
    _begin = new node<node_type>;

    _begin = NULL;
    _end = _begin;

    iterator iter_copy_list = copy_list.begin();
    for (size_t i = 0; i < copy_list.get_size(); i++) {
        this->push_back(*iter_copy_list);
        ++iter_copy_list;
    }
    //копируем размер
    this->size = copy_list.size;
}

template <typename node_type>
/**
 * @brief my_list<node_type>::~my_list деструктор.
 * @detailed С помощью метода pop_back освобождает занятую динамическую память.
 */
my_list<node_type>::~my_list() {
    while (!this->is_empty()) {
#ifdef DEBUG
        std::cout << this->pop_back() << std::endl;
#else
        this->pop_back();
#endif
    }
}

template <typename node_type>
/**
 * @brief my_list<node_type>::is_empty
 * @return пуст ли список.
 */
bool my_list<node_type>::is_empty() {
    return size == 0 ? true : false;
}

template <typename node_type>
/**
 * @brief my_list<node_type>::get_size
 * @return количество элементов.
 */
size_t my_list<node_type>::get_size() {
    return size;
}

template <typename node_type>
/**
 * @brief my_list<node_type>::pop_back удаление элемента с конца списка
 * @return значение, хранившееся в этом элементе
 * @throw std::length_error в случае пустого списка
 */
node_type my_list<node_type>::pop_back() {
    if (size <= 0) {
        throw std::length_error("Попытка удаления элемента из пустого списка!");
    }
    //Запоминаем значение удаляемого элемента
    node_type x = _end->element;

    //удаляем его
    delete _end;

    if (size >= 2) {
        //деляем предпоследний элемент последним
        this->get_iter_by_pos(size-2).current_pos->next = NULL;
        _end = this->get_iter_by_pos(size-2).current_pos;
    } else {
        _begin->next = NULL;
        _end = _begin;
    }
    //уменьшаем размер списка
    size--;
    return x;
}

template <typename node_type>
/**
 * @brief my_list<node_type>::pop_front удаление головы списка
 * @return значение, хранившееся в голове
 */
node_type my_list<node_type>::pop_front() {
    if (size <= 0) {
        throw std::length_error("Попытка удаления элемента из пустого списка!");
    }
    //Запоминаем значение удаляемого элемента
    node_type x = _begin->element;

    //Осовбождаем память
    delete _begin;

    //теперь начало - следующий элемент
    this->_begin = _begin->next;

    //уменьшаем размер списка
    size--;
    return x;
}

template <typename node_type>
/**
 * @brief my_list<node_type>::push_back добавление элемента в конец списка
 * @param x элемент для добавления в список
 */
void my_list<node_type>::push_back(const node_type& x) {

    //Создаём новую ячейку списка
    node<node_type>* p = new node<node_type>;
    p->next = NULL;
    //memcpy((void*)&p->element, (void*)&x, sizeof(x));
    p->element = x;

    //если это первый элемент спсика - инициализируем голову
    if (_begin == NULL)
        _begin = _end = p;
    //иначе теперь конец списка - новый элемент, и next для предыдущего конца - новый элемент
    else {
        _end->next = p;
        _end = p;
    }

    //увеличиваем размер списка
    size++;
}

template <typename node_type>
/**
 * @brief my_list<node_type>::push_front добавление элемента в начало списка
 * @param x элемент для добавления
 */
void my_list<node_type>::push_front(const node_type& x) {
    //Создаём новую ячейку списка
    node<node_type>* p = new node<node_type>;
    p->next = _begin;
    p->element = x;

    //если это первый элемент спсика - инициализируем голову
    if (_begin == NULL)
        _begin = _end = p;
    //иначе теперь конец списка - новый элемент, и next для предыдущего конца - новый элемент
    else {
        _begin = p;
    }

    //увеличиваем размер списка
    size++;
}

//FIXME: не получается воспользоваться my_list<node_type>::iterator вместо my_iterator<node_type>
template <typename node_type>
/**
 * @brief my_list<node_type>::begin
 * @return итератор на начало списка
 */
my_iterator<node_type> my_list<node_type>::begin() {
    my_list<node_type>::iterator it (_begin);
    return it;
}

template <typename node_type>
/**
 * @brief my_list<node_type>::end
 * @return !!!ВАЖНО!!!! итератор на элемент, идущий после конец списка
 */
my_iterator<node_type> my_list<node_type>::end() {
    my_list<node_type>::iterator it (_end->next);
    return it;
}

template <typename node_type>
/**
 * @brief my_list<node_type>::operator []
 * @param index индекс необходимого элемента в списке
 * @detailed !!!Линейная сложность! Не следует использовать для циклического обхода
 * @return элемент списка по индексу
 */
node_type& my_list<node_type>::operator [](const int index) {
    iterator it = this->get_iter_by_pos(index);
    return *it;
}

#endif // MY_LIST


#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cerrno>
#include "my_list.h"
#include "my_stack.h"
#include "my_queue.h"
#include "student.h"

#define INPUT_INVITE_SYMBOL '>'

using namespace std;

my_queue<student> get_ex_students(my_stack<student>& stud_stack);

int main(int argc, char**argv)
{
    //открытие файла
    string input_f_name;
    cout << INPUT_INVITE_SYMBOL << "Введите имя файла: ";
    cin >> input_f_name;
    ifstream input_f(input_f_name);

    if (access(input_f_name.c_str(), F_OK | R_OK) != 0) {
        cerr << argv[0] << ": не могу открыть файл для чтения!" << endl;
        return errno;
    }

    //заполнение стека
    my_stack<student> student_stack;
    while (!input_f.eof()) {
        student st;
        //читаем из файла структуру
        input_f >> st;

        //считаем среднее арифметическое
        size_t sum = 0;
        for (unsigned short i : st.progress.B)
            sum += i;
        st.progress.average = sum / st.progress.mark_count;

        //добавляем её в стек
        student_stack.push(st);

        //FIXME: некорректное считывание структуры из файла
        //проверяем конец ли файла
        char c;
        input_f >> c;
        if (input_f.eof()) {
            break;
        } else
            input_f.unget();
    }

    //открытие файла для вывода
    string output_f_name = input_f_name + ".out";
    ofstream output_f(output_f_name.c_str());
    if (access(input_f_name.c_str(), F_OK | W_OK) != 0) {
        cerr << argv[0] << ": не могу открыть файл для записи!" << endl;
        return errno;
    }

    //формирование и вывод очереди
    my_queue<student> student_queue = get_ex_students(student_stack);
    while (!student_queue.is_empty()) {
        output_f << student_queue.pop() << endl;
    }

    input_f.close();
    output_f.close();
    return 0;
}

/**
 * @brief get_ex_students формирование из стека очереди из отличников
 * @param student_stack стек для обработки
 * @return полученная очередь
 */
my_queue<student> get_ex_students(my_stack<student>& student_stack) {
    my_queue<student> student_queue;
    while (!student_stack.is_empty()) {
        if (student_stack.get_top().progress.average >= 8.0) {
            student_queue.push(student_stack.pop());
        } else {
            student_stack.pop();
        }
    }
    return student_queue;
}


/*my_list<int> list {100, 101, 102};
for (int i = 0; i < 15; i++)
    list.push_back(i);

while (!list.is_empty()) {
    cout << list.pop_front() << endl;
}*/

/*my_stack<int> stack;
for (int i = 0; i < 15; i++)
    stack.push(i);
while (!stack.is_empty()) {
    cout << stack.get_top() << endl;
    stack.pop();
   // cout << stack.pop() << endl;
}*/

/*my_queue<int> queue;
for (int i = 0; i < 15; i++)
    queue.push(i);
while (!queue.is_empty()) {
    cout << queue.pop() << endl;
}*/

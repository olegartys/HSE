#ifndef STUDENT
#define STUDENT

#include <string>
#include <fstream>
#include <iostream>


/**
 * @brief The student struct структура студент
 * @detailed описывает структуру данных о студенте
 */
struct student {
    struct {
        std::string surname;
        std::string name;
        std::string sec_name;
    } initials;
    size_t group;
    struct {
        static const size_t mark_count = 5;
        unsigned short B[mark_count];
        double average;
    } progress;

    /**
     * @brief operator << перегрузка вывода структуры в поток
     * @param out поток для вывода
     * @param st структура для вывода
     * @return поток
     */
    friend std::ostream& operator<< (std::ostream& out, const student& st) {
        out << st.initials.surname << std::endl;
        out << st.initials.name << std::endl;
        out << st.initials.sec_name << std::endl;
        out << st.group << std::endl;
        for (size_t i = 0; i < st.progress.mark_count; i++)
            out << st.progress.B[i] << " ";
        out << std::endl;
        return out;
    }

    /**
     * @brief operator >> перегрузка ввода структуры из поток
     * @param input_f поток для ввода структуры
     * @param st сттруктура для ввода
     * @return поток
     */
    friend std::ifstream& operator>> (std::ifstream& input_f, student& st) {
        input_f >> st.initials.surname;
        input_f >> st.initials.name;
        input_f >> st.initials.sec_name;
        input_f >> st.group;
        for (size_t i = 0; i < st.progress.mark_count; i++) {
            input_f >> st.progress.B[i];
        }
        return input_f;
    }
};

#endif // STUDENT


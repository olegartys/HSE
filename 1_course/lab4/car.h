#ifndef CAR_H
#define CAR_H

/*
 * Структура данных о машине
 */
#define FIRM_LEN 32
#define COLOR_LEN 32

typedef struct {
    char firm[FIRM_LEN];

    struct {
        size_t series;
        size_t number;
    } model;

    size_t price;
    struct {
        size_t year;
        size_t month;
    } date;

    char color[COLOR_LEN];

    size_t volume;
} Car;

/*
 * Считывание данных о машине в структуру
 *
 */
void input_car_info(Car *car, FILE *input_file);

/*
 * вывод структуры
 */
void output_car_info(const Car car, FILE *output_file);

#endif // CAR_H


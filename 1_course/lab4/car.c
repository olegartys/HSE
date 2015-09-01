#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "car.h"
#include "task2.h"

#define INPUT_INVITE_SYMBOL '>'

void input_car_info(Car *car, FILE *input_file)
{
    char _c;
#ifndef TASK2
    printf("%c ", INPUT_INVITE_SYMBOL);
    printf("Firm: ");
#endif
    fgets(car->firm, FIRM_LEN-1, input_file);

#ifndef TASK2
    printf("Series: ");
#endif
    fscanf(input_file, "%ld%c", &car->model.series, &_c);

#ifndef TASK2
    printf("Number: ");
#endif
    fscanf(input_file, "%ld%c", &car->model.number, &_c);

#ifndef TASK2
    printf("Price: ");
#endif
    fscanf(input_file, "%ld%c", &car->price, &_c);

#ifndef TASK2
    printf("Year: ");
#endif
    fscanf(input_file, "%ld%c", &car->date.year, &_c);

#ifndef TASK2
    printf("Month: ");
#endif
    fscanf(input_file, "%ld%c", &car->date.month, &_c);

#ifndef TASK2
    printf("Color: ");
#endif
    fgets(car->color, COLOR_LEN-1, input_file);

#ifndef TASK2
    printf("Volume: ");
#endif
    fscanf(input_file, "%ld%c", &car->volume, &_c);

}

void output_car_info(const Car car, FILE *output_file)
{
    fprintf(output_file, "%s", car.firm);
    fprintf(output_file, "%ld\n", car.model.series);
    fprintf(output_file, "%ld\n", car.model.number);
    fprintf(output_file, "%ld\n", car.price);
    fprintf(output_file, "%ld\n", car.date.year);
    fprintf(output_file, "%ld\n", car.date.month);
    fprintf(output_file, "%s", car.color);
    fprintf(output_file, "%ld\n", car.volume);
}


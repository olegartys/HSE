#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "car.h"

#define INPUT_INVITE_SYMBOL '>'

int input_car_info(Car *car, FILE *input_file)
{
#ifndef TASK2
    printf("%c ", INPUT_INVITE_SYMBOL);
    printf("Firm: ");
#endif
    char s[32];
    fgets(s, 32, stdin);
    puts(s);

#ifndef TASK2
    printf("Series: ");
#endif
    fscanf(input_file, "%ld", &car->model.series);

#ifndef TASK2
    printf("Number: ");
#endif
    fscanf(input_file, "%ld", &car->model.number);

#ifndef TASK2
    printf("Price: ");
#endif
    fscanf(input_file, "%ld", &car->price);

#ifndef TASK2
    printf("Year: ");
#endif
    fscanf(input_file, "%ld", &car->date.year);

#ifndef TASK2
    printf("Month: ");
#endif
    fscanf(input_file, "%ld", &car->date.month);

#ifndef TASK2
    printf("Color: ");
#endif
    fgets(car->color, COLOR_LEN-1, input_file);

#ifndef TASK2
    printf("Month: ");
#endif
    fscanf(input_file, "%ld", &car->volume);

    return 0;
}



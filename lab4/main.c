#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "car.h"
#include "task2.h"

#ifdef TASK2
    #define INPUT_FILE_NAME "input"
    #define OUTPUT_FILE_NAME "output"
#endif

int main(void)
{
#ifdef TASK2
    FILE *input_file  = fopen(INPUT_FILE_NAME, "r");
    FILE *output_file = fopen(OUTPUT_FILE_NAME, "w");
    if (input_file == NULL || output_file == NULL) {
        perror(NULL);
        return errno;
    }
#else
    FILE *input_file  = stdin;
    FILE *output_file = stdout;
#endif
    //FIXME: символ перехода на новую строку (который при нажатии на энтер) автоматически считывается fgets в качестве входных данныых. Как исправить?
    size_t n;
    char _c;
    printf("Input number of cars: ");
    scanf("%ld%c", &n, &_c);

    Car *cars = (Car*)malloc(sizeof(Car)*n);
    if (cars == NULL) {
        perror (NULL);
        return errno;
    }

    //считываем структуры из входного потока
    size_t i;
    for (i = 0; i < n; i++)
        input_car_info(&cars[i], input_file);

    //выводим искомые структуры
    printf("Input color: ");
    char color[COLOR_LEN];
    fgets(color, COLOR_LEN-1, stdin);
    for (i = 0; i < n; i++)
        if (!strncmp(color, cars[i].color, COLOR_LEN))
            output_car_info(cars[i], output_file);

    free(cars);
    fclose(input_file);
    fclose(output_file);

    return 0;
}


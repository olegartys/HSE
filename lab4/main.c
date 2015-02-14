#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "car.h"

//#define TASK2
#ifdef TASK2
    #define INPUT_FILE_NAME "input"
    #define OUTPUT_FILE_NAME "output"
#endif

int main(void)
{
    size_t n;
    printf("Input number of cars: ");
    scanf("%ld", &n);

    Car *cars = (Car*)malloc(sizeof(Car)*n);
    char s[32];
    fgets(s, 32, stdin);
    puts(s);

    //считываем структурыы из входного потока
    size_t i;
#ifdef TASK2
    FILE *input_file  = fopen(INPUT_FILE_NAME, "r");
    FILE *output_file = fopen(OUTPUT_FILE_NAME, "w");
#else
    FILE *input_file  = stdin;
    FILE *output_file = stdout;
#endif
    for (i = 0; i < n; i++)
        if (input_car_info(&cars[i], input_file) != 0) {
            perror(NULL);
            return errno;
        }

    //выводим искомые структуры
    printf("Input color: ");
    char color[COLOR_LEN];
    fgets(color, COLOR_LEN-1, input_file);
    for (i = 0; i < n; i++)
        if (!strncmp(color, cars[i].color, COLOR_LEN));
            //output_car_info(cars[i], output_file);

    free(cars);
    fclose(input_file);
    fclose(output_file);

    return 0;
}


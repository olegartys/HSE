#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>

#define BUFF_SIZE 1024
#define INPUT_INVITE_SYMBOL '>'

char **GetSubstrs (const char *s, size_t *n);

size_t GetValidSymbolsCount (const char *s);

const char *ReplaceWords(const char *s);

int main(void)
{
    //структура для подстроки, удовлетворяющей условию
    struct {
        size_t count;
        char *substr;
        char src[BUFF_SIZE];
    } validSubstr = {0, NULL, "\0"};

    puts ("Input strings: ");
    printf("%c ", INPUT_INVITE_SYMBOL);

    char s[BUFF_SIZE];
    //пока не введена пустая строка
    while (strcmp(fgets(s, BUFF_SIZE-1, stdin), "\n")) {
        //получаем подстроки из считанного буфера
        size_t n;
        char **substr = GetSubstrs(s, &n);
        if (substr == NULL) {
            perror(NULL);
            return errno;
        }
        
        //выводим их и ищем подстроку с минимальным количеством заданных символов в начале
        printf ("\t");
        size_t i;
        for (i = 0; i < n; i++) {
            printf ("subs[%d]: %s\n\t", i, substr[i]);
            if (GetValidSymbolsCount(substr[i]) > validSubstr.count) {

                validSubstr.count = GetValidSymbolsCount(substr[i]);

                //осовбождаем памяь старой подстроки
                free(validSubstr.substr);

                //присваиваем новую
                validSubstr.substr = substr[i];

                //копируем исходник
                strncpy(validSubstr.src, s, BUFF_SIZE);
            } else
                free(substr[i]);
        }
        printf ("\r%c ", INPUT_INVITE_SYMBOL);
        free(substr);
    }

    if (validSubstr.substr == NULL)
        puts("Substring not founded!");
    else {
        printf("\nResult substring: %s\n", validSubstr.substr);
        printf("Modified source string: %s\n", ReplaceWords(validSubstr.src));
    }

    return 0;
}

/*
 * Возвращает массив удовлетворяющих условию подстрок из строки s;
 * n - количество подстрок
 */
char **GetSubstrs (const char *s, size_t *n)
{
    *n = 0;
    char **substr = NULL;//malloc (sizeof(char*)*1024);//NULL;

    int i;
    for (i = 0; s[i] != '\n';) {
        if (isdigit(s[i]))
            i++;
        else {
            const char *iter = &s[i];
            while (*iter != '\n' && !isdigit(*iter)) iter++;

            int len = iter - &s[i];

            *n = *n + 1;
            substr = (char**)realloc(substr, *n*sizeof(char*));
            substr[*n-1] = (char*)malloc(sizeof(char)*(len+1));
            //проверяем, удалось ли выделить память под новую подстроку
            if (substr == NULL || substr[*n-1] == NULL) {
                return NULL;
            }
            memset(substr[*n-1], '\0', sizeof(char)*(len+1));
            strncpy(substr[*n-1], &s[i], len);

            i += len;
        }
    }

    return substr;
}

/*
 * Возвращает количество находящихся в начале заданных по условию
 * символов в строке s
 */
size_t GetValidSymbolsCount(const char *s)
{
    size_t k = 0;
    while ((*s == '+' || *s == '-' ||
            *s == '*' || *s == '/') && *s != '\0') {
        k++;
        s++;
    }
    return k;
}

/*
 * Заменяет begin и end на { и } и возвращает полученную строку
 */
const char *ReplaceWords(const char *s)
{
    //копируем исходник
    char *_s = (char*)malloc(sizeof(char)*(strlen(s)+1));
    strcpy(_s, s);
    size_t _len = strlen(_s);

    //искомые токены
    struct {
        const size_t len;
        const char *src;
        const char replace;
    } beg = {strlen("begin"), "begin", '{'},
      end = {strlen("end"), "end", '}'};

    int i;
    for (i = 0; _s[i] != '\0'; i++) {
        //если найден токен
        if (!memcmp(&_s[i], beg.src, beg.len)) {
            //заменяем его первую символ на требуемый
            _s[i] = beg.replace;
            //копируем на его место часть строки, идущую после него
            memcpy(&_s[i+1], &_s[i+beg.len], (_len-beg.len-i+1)*sizeof(char));

        } else if (!memcmp(&_s[i], end.src, end.len)) {
            _s[i] = end.replace;
            memcpy(&_s[i+1], &_s[i+end.len], (_len-end.len-i+1)*sizeof(char));
        }

    }

    return _s;
}

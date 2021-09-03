#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <windows.h>
#include <cfloat>

const int NUM_SLOTS = 1000;

///выводит строку и переходит на новую строку
int f_puts(char s[]);
///возвращает длину строки оканчивающейся нулевым символом
int f_strlen(char s[]);
///копирует строку s2 в строку s1
int f_strcpy(char s1[], char s2[]);
///добавляет строку s2 в конец строки s1
int f_strcat(char s1[], char s2[]);
///считывает файл stream до n-1 символов
///пока не встретиться символ новой строки или EOF и записывает их в массив s
int f_fgets(char s[], int n, FILE* stream);
///дублирует строку
char* f_strdup(char s[]);

///1 если s1 раньше, 2 если s2 раньше
int sortirovka(char s1[], char s2[]);

int main()
{
    char s[NUM_SLOTS][NUM_SLOTS];
    int num_strings = 0;
    
    //ввод в массив
    FILE* input_file = fopen("qwe.txt","r");
    int ret = 0;
    while (ret == 0)
    {
        ret = f_fgets(s[num_strings], NUM_SLOTS, input_file);
        num_strings++;
    }
    fclose(input_file);
    
    //проверка
    for (int i = 0; i < num_strings; i++)
        printf("%s\n", s[i]);
    printf("\n\n\n");

    //сортировка
    for (int i = 0; i < num_strings; i++)
        for (int j = 0; j < (num_strings - 1); j++)
            if (sortirovka(s[j], s[j + 1]) == 2)
            {
                char work[NUM_SLOTS];
                f_strcpy(work, s[j]);
                f_strcpy(s[j], s[j + 1]);
                f_strcpy(s[j + 1], work);
            }

    //проверка
    for (int i = 0; i < num_strings; i++)
        printf("%s\n", s[i]);

    return 0;
}

int f_puts(char s[])
{
    assert(&s[0] != NULL);

    for (int i = 0; s[i] != '\0'; i++)
        putchar(s[i]);
    putchar('\n');
}

int f_strlen(char s[])
{
    assert(&s[0] != NULL);

    int len = 0;

    while (s[len] != '\0')
        len++;

    return len;
}

int f_strcpy(char s1[], char s2[])
{
    assert(&s1[0] != NULL);
    assert(&s2[0] != NULL);
    assert(&s1[0] != &s2[0]);

    int i;
    for (i = 0; s2[i] != '\0'; i++)
        s1[i] = s2[i];

    s1[i] = '\0';
}

int f_strcat(char s1[], char s2[])
{
    assert(&s1[0] != NULL);
    assert(&s2[0] != NULL);
    assert(&s1[0] != &s2[0]);

    int len_s1 = f_strlen(s1);

    for (int i = 0; s2[i] != '\0'; i++)
        s1[i + len_s1] = s2[i];
}

int f_fgets(char s[], int n, FILE* stream)
{
    assert(&s[0] != NULL);
    assert(stream != NULL);

    int i;
    int in;
    for (i = 0; i < n; i++)
    {
        in = getc(stream);
        if (in != '\n' && in != EOF)
            s[i] = in;
        else
            i = n;
    }
    s[i] = '\0';

    if (in == EOF)
        return -1;
    return 0;
}

char* f_strdup(char s[])
{
    assert(&s[0] != NULL);

    return &s[0];
}

int sortirovka(char s1[], char s2[])
{
    assert(&s1[0] != NULL);
    assert(&s2[0] != NULL);
    assert(&s1[0] != &s2[0]);

    int length = min(f_strlen(s1), f_strlen(s2));
    for (int i = 0; i < length; i++)
    {
        char a = s1[i];
        char b = s2[i];
        if (a < b)
            return 1;
        if (a > b)
            return 2;
    }
}

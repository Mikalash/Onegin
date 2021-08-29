#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <windows.h>
//#include <cfloat>

const int NUM_SLOTS = 10000;

///выводит строку и переходит на новую строку
int f_puts(char s[]);                                         //ok
///возвращает длину строки оканчивающейся нулевым символом
int f_strlen(char s[]);                                       //ok
///копирует строку s2 в строку s1
int f_strcpy(char s1[], char s2[]);                           //ok
///добавляет строку s2 в конец строки s1
int f_strcat(char s1[], char s2[]);                           //ok
///считывает файл stream до n-1 символов
///пока не встретиться символ новой строки или EOF и записывает их в массив s
int f_fgets(char *s[], int n, FILE* stream);                  //gon't understend
///дублирует строку
char* f_strdup(char s[]);                                     //ok

int main()
{
    char s1[NUM_SLOTS] = "lol kek cheburek";
    char s2[NUM_SLOTS] = "ded really cool prepod";

    printf("%s", f_strdup(s2));

    return 0;
}

int f_puts(char s[])
{
    int len_s = f_strlen(s);

    for (int i = 0; i < len_s; i++)
        putchar(s[i]);
    putchar('\n');
}

int f_strlen(char s[])
{
    int len = 0;

    while (s[len] != '\0')
        len++;

    return len;
}

int f_strcpy(char s1[], char s2[])
{
    int len_s2 = f_strlen(s2);

    for (int i = 0; i < len_s2; i++)
        s1[i] = s2[i];
}

int f_strcat(char s1[], char s2[])
{
    int len_s1 = f_strlen(s1);
    int len_s2 = f_strlen(s2);

    for (int i = len_s1; i < (len_s1 + len_s2); i++)
        s1[i] = s2[i - len_s1];
}

int f_fgets()
{

}

char* f_strdup(char s[])
{
    return &s[0];
}

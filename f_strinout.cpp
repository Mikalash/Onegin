/**
@file
библиотека для считывания и вывода данных и приветсвия пользователю
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <windows.h>

/**
\brief считывает строчку из файл
\param s
\param stream
\return количество считанных элементов
*/
int my_getline(char* s, int n, FILE* stream);

/**
\brief помещает строку в файл
\param s указател на первый элемент строки которую нужно поместить
\param stream указатель на файл
\return нуль
*/
int my_putline(char* s, FILE* stream);

/**
\brief получение имени файлов и приветсвие
\param in указатель на первый элемент строки с названием входного файла
\param out указатель на первый элемент строки с названием выходного файла
\return нуль
*/
int hello(char in[], char out[]);

int my_getline(char* s, int n, FILE* stream)
{
    assert(s != NULL);

    int in = EOF;
    int i;
    for (i = 0; in != '\n' && in != '\0'; i++)
    {
        in = getc(stream);
        if (in == EOF)
            return EOF;
        s[i] = in;
    }

    return i;
}

int my_putline(char* s, FILE* stream)
{
    assert(s != NULL);

    int n = strlen(s);
    int i;
    for (i = 0; i < n; i++)
        putc(s[i], stream);
    if (s[i - 1] != '\n')
        putc('\n', stream);

    return 0;
}

int hello(char in[], char out[])
{
    printf("Hello, this programm sorts strings alphabetically.");
    printf("\nPress enter to continue.");
    printf("\n\n\nMade by Bozhik Nikolay 2021\n");
    while (getchar() != '\n');
    system("cls");

    printf("Print the name of the file to sort.");
    printf("\nFile must located in the same folder as a program.");
    printf("\nExample: read.txt\n");
    scanf("%s", in);
    system("cls");

    printf("Print the name of the file to put result.");
    printf("\nFile will be located in the same folder as a program.");
    printf("\nExample: write.txt\n");
    scanf("%s", out);
    system("cls");

    printf("Check the result!");

    return 0;
}

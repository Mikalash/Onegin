/**
@file
библиотека для сортировки, сравнения строк
*/

#include <assert.h>
#include <string.h>

/**
\brief сортирует массив индексов строк
\param pointer_poem указатель на первый элемент строки индексов
\param num_strings количество строк
\return нуль
*/
void my_strsort (char* pointer_poem[], int num_strings);

/**
\brief алфавитно сравнивает строки
\param s1 указатель на первый элемент первой строки
\param s2 указатель на первый элемент второй строки
\return 1 если 1я строка старше, 2 если 2я
*/
int my_strcmp (char s1[], char s2[]);

/**
\brief проверяет является ли символ буквой или цифрой
\param s проверяемый символ
\return 1 - является, 2 - не является
*/
int my_char_check (char s);

void my_strsort (char* pointer_poem[], int num_strings)
{
    assert(pointer_poem != NULL);

    char* memory = NULL;

    for (int i = 0; i < num_strings; i++)
        for (int j = 0; j < num_strings - 1; j++)
            if (my_strcmp(pointer_poem[j], pointer_poem[j + 1]) == 2)
            {
                memory = pointer_poem[j];
                pointer_poem[j] = pointer_poem[j + 1];
                pointer_poem[j + 1] = memory;
            }

    return 0;
}

int my_strcmp (char s1[], char s2[])
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    int i1 = 0;
    int i2 = 0;

    while (1)
    {
        while (my_char_check(s1[i1]) == 0)
            i1++;
        while (my_char_check(s2[i2]) == 0)
            i2++;

        if (s1[i1] == '\0')
            return 2;
        if (s2[i2] == '\0')
            return 1;

        if (s1[i1] > s2[i2])
            return 2;
        if (s1[i1] < s2[i2])
            return 1;

        i1++;
        i2++;
    }
}

int my_char_check(char s)
{
    char not_true[] = "\"\n\t ,.!?<>»«()[]:;";
    int not_true_len = strlen(not_true);
    int ans = 1;
    for (int i = 0; i <= not_true_len; i++)
        if (s == not_true[i])
            ans = 0;
    return ans;
}

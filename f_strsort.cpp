#include <assert.h>
#include <string.h>

///сортирует массив индексов строк
void my_strsort (char* pointer_poem[], int num_strings);
///алфавитно сравнивает строки 1 - 1я 2 -2я
int my_strcmp (char s1[], char s2[]);
///проверяет является ли символ буквой или цифрой да - 1, нет - 0
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

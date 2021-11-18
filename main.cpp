#include "f_strinout.cpp"
#include "f_strsort.cpp"

int NUM_SLOTS = 1000;

int main()
{
    char poem[NUM_SLOTS][NUM_SLOTS];
    int num_strings = 0;
    char input_file_name[NUM_SLOTS];
    char output_file_name[NUM_SLOTS];

    //приветствие
    hello(input_file_name, output_file_name);

    //считывание строк из файла
    FILE* input_file = fopen(input_file_name, "r");
    while (my_getline(poem[num_strings], NUM_SLOTS, input_file) != EOF)
        num_strings++;
    num_strings++;
    fclose(input_file);

    //размещение индексов строк
    char* pointer_poem[num_strings];
    for (int i = 0; i < num_strings; i++)
        pointer_poem[i] = &poem[i][0];

    //сортировка строк
    my_strsort(pointer_poem, num_strings);

    //вывод результата
    FILE* output_file = fopen(output_file_name, "w");
    for (int i = 0; i < num_strings; i++)
        my_putline(pointer_poem[i], output_file);
    fclose(output_file);
}

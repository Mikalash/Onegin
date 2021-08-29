#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <windows.h>
//#include <cfloat>

const int NUM_SLOTS = 10000;

///������� ������ � ��������� �� ����� ������
int f_puts(char s[]);                                         //ok
///���������� ����� ������ �������������� ������� ��������
int f_strlen(char s[]);                                       //ok
///�������� ������ s2 � ������ s1
int f_strcpy(char s1[], char s2[]);                           //ok
///��������� ������ s2 � ����� ������ s1
int f_strcat(char s1[], char s2[]);                           //ok
///��������� ���� stream �� n-1 ��������
///���� �� ����������� ������ ����� ������ ��� EOF � ���������� �� � ������ s
int f_fgets(char *s[], int n, FILE* stream);                  //gon't understend
///��������� ������
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

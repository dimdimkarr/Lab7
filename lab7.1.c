#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int classifySymbol(char c);

int main(void)
{
    char c;
    int type;

    setlocale(LC_ALL, "");

    printf("ЗАДАНИЕ 1. Определение символа\n");
    printf("Введите символ: ");

    if (scanf(" %c", &c) != 1)
    {
        printf("Ошибка ввода!\n");
        return 1;
    }

    type = classifySymbol(c);

    switch (type)
    {
    case 1:
        printf("Это цифра.\n");
        break;

    case 2:
        printf("Это буква.\n");
        break;

    default:
        printf("Неизвестный символ.\n");
        break;
    }

    return 0;
}

int classifySymbol(char c)
{
    int type;

    switch (c)
    {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        type = 1;
        break;

    default:
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z'))
            type = 2;
        else
            type = 0;
        break;
    }

    return type;
}
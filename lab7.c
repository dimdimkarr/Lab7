#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <math.h>
int main(void) 
{ 
    char c, op; 
    float x, y;

//ЗАДАНИЕ 1. Распознавание символов
printf("ЗАДАНИЕ 1. Определение символа\n");
printf("Введите символ: ");

if (scanf(" %c", &c) != 1)
{
    printf("Ошибка ввода!\n");
    return 1;
}

switch (c)
{
case '0': case '1': case '2': case '3': case '4':
case '5': case '6': case '7': case '8': case '9':
    printf("Это цифра.\n");
    break;

default:
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z'))
        printf("Это буква.\n");
    else
        printf("Неизвестный символ.\n");
    break;
}

// ЗАДАНИЕ 2. Калькуляторprintf("\nЗАДАНИЕ 2. Калькулятор\n");
printf("Введите выражение (например, 5+3 или 2^3): ");

if (scanf("%f %c %f", &x, &op, &y) != 3)
{
    printf("Ошибка ввода!\n");
    return 1;
}

switch (op)
{
case '+':
    printf("Результат: %.2f\n", x + y);
    break;

case '-':
    printf("Результат: %.2f\n", x - y);
    break;

case '*':
    printf("Результат: %.2f\n", x * y);
    break;

case '/':
    if (y != 0)
        printf("Результат: %.2f\n", x / y);
    else
        printf("Ошибка: деление на ноль!\n");
    break;

case '^':
    if (x == 0 && y < 0)
        printf("Ошибка: ноль нельзя возвести в отрицательную степень!\n");
    else
        printf("Результат: %.2f\n", pow(x, y));
    break;

default:
    printf("Неизвестная операция!\n");
    break;
}

return 0;
}
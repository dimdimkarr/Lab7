#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

float calculate(float x, char op, float y);

int main(void)
{
    float x, y, result;
    char op;
    int valid = 1;

    setlocale(LC_ALL, "");

    printf("ЗАДАНИЕ 2. Калькулятор\n");
    printf("Введите выражение (например, 5+3 или 2^3): ");

    if (scanf("%f %c %f", &x, &op, &y) != 3)
    {
        printf("Ошибка ввода!\n");
        return 1;
    }

    switch (op)
    {
    case '+':
    case '-':
    case '*':
        break;

    case '/':
        if (y == 0)
        {
            printf("Ошибка: деление на ноль!\n");
            valid = 0;
        }
        break;

    case '^':
        if (x == 0 && y < 0)
        {
            printf("Ошибка: ноль нельзя возвести в отрицательную степень!\n");
            valid = 0;
        }
        break;

    default:
        printf("Неизвестная операция!\n");
        valid = 0;
        break;
    }

    if (valid)
    {
        result = calculate(x, op, y);
        printf("Результат: %.2f\n", result);
    }

    return 0;
}

float calculate(float x, char op, float y)
{
    float result;

    switch (op)
    {
    case '+':
        result = x + y;
        break;

    case '-':
        result = x - y;
        break;

    case '*':
        result = x * y;
        break;

    case '/':
        result = x / y;
        break;

    case '^':
        result = (float)pow(x, y);
        break;

    default:
        result = 0;
        break;
    }

    return result;
}
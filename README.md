# Lab7
## Условие задач
Задание 1. Написать программу, определяющую тип введённого символа: цифра, буква или неизвестный символ.
## Реализация программы
```c
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
```
## Пример работы программы
Пример 1. Введена цифра  

ЗАДАНИЕ 1. Определение символа  
Введите символ: 7  
Это цифра  

Пример 2. Введена буква  

ЗАДАНИЕ 1. Определение символа  
Введите символ: A  
Это буква  

Пример 3. Введён неизвестный символ  

ЗАДАНИЕ 1. Определение символа  
Введите символ: #  
Неизвестный символ  
## Условие задачи
Задание 2.Написать программу-калькулятор для выполнения операций сложения, вычитания, умножения, деления и возведения числа в степень.
## Реализация программы
```c
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
```
## Пример работы программы  
Пример 1. Сложение  

ЗАДАНИЕ 2. Калькулятор  
Введите выражение (например, 5+3 или 2^3): 5+3  
Результат: 8.00  

Пример 2. Возведение в степень  

ЗАДАНИЕ 2. Калькулятор  
Введите выражение (например, 5+3 или 2^3): 2^3  
Результат: 8.00  

Пример 3. Деление на ноль  

ЗАДАНИЕ 2. Калькулятор  
Введите выражение (например, 5+3 или 2^3): 10/0  
Ошибка: деление на ноль!  

## Индивидуальное задание. Вариант 7
## Условие задачи
Определить название месяца, если с января 2000 года прошло n месяцев и заданное количество дней. Учесть возможность перехода на следующий месяц и високосные годы.
## Реализация программы
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int daysInMonth(int month, int year);
int calculateMonth(int n, int days, int *year);

int main(void)
{
    int n, days;
    int month, year;

    setlocale(LC_ALL, "");

    printf("ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ. Вариант 7\n");

    printf("Введите количество прошедших месяцев с января 2000 года: ");

    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Ошибка ввода!\n");
        return 1;
    }

    printf("Введите количество прошедших дней (от 0 до 31): ");

    if (scanf("%d", &days) != 1 || days < 0 || days > 31)
    {
        printf("Ошибка ввода! Допустимое количество дней: от 0 до 31.\n");
        return 1;
    }

    month = calculateMonth(n, days, &year);

    if (month == -1)
    {
        printf("Ошибка определения месяца!\n");
        return 1;
    }

    printf("Месяц: ");

    switch (month)
    {
    case 1: printf("Январь"); break;
    case 2: printf("Февраль"); break;
    case 3: printf("Март"); break;
    case 4: printf("Апрель"); break;
    case 5: printf("Май"); break;
    case 6: printf("Июнь"); break;
    case 7: printf("Июль"); break;
    case 8: printf("Август"); break;
    case 9: printf("Сентябрь"); break;
    case 10: printf("Октябрь"); break;
    case 11: printf("Ноябрь"); break;
    case 12: printf("Декабрь"); break;

    default:
        printf("Неизвестный месяц");
        break;
    }

    printf(" %d года\n", year);

    return 0;
}

int daysInMonth(int month, int year)
{
    int days;

    switch (month)
    {
    case 1: case 3: case 5: case 7:
    case 8: case 10: case 12:
        days = 31;
        break;

    case 4: case 6: case 9: case 11:
        days = 30;
        break;

    case 2:
        if (year % 400 == 0 ||
            (year % 4 == 0 && year % 100 != 0))
            days = 29;
        else
            days = 28;
        break;

    default:
        days = -1;
        break;
    }

    return days;
}

int calculateMonth(int n, int days, int *year)
{
    int month;
    int max_days;

    month = (n % 12) + 1;
    *year = 2000 + n / 12;

    max_days = daysInMonth(month, *year);

    if (max_days == -1)
        return -1;

    if (days >= max_days)
    {
        month++;

        if (month > 12)
        {
            month = 1;
            (*year)++;
        }
    }

    return month;
}
```
## Пример работы программы
Пример 1. Прошло 3 дня  

ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ. Вариант 7  
Введите количество прошедших месяцев с января 2000 года: 0  
Введите количество прошедших дней (от 0 до 31): 3  
Месяц: Январь 2000 года  

Пример 2. Переход на следующий месяц  

ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ. Вариант 7  
Введите количество прошедших месяцев с января 2000 года: 0  
Введите количество прошедших дней (от 0 до 31): 31  
Месяц: Февраль 2000 года  

Пример 3. Переход на следующий год  

ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ. Вариант 7  
Введите количество прошедших месяцев с января 2000 года: 12  
Введите количество прошедших дней (от 0 до 31): 3  
Месяц: Январь 2001 года  

## Информация о разработчике  
Жукова Дарья, бИД-261

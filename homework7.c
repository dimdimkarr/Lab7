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
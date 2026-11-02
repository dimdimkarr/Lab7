#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main(void) 
{ 
    int n, days; 
    int month, year; 
    int days_in_month;

printf("ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ. Вариант 7\n");

printf("Введите количество прошедших месяцев с января 2000 года: ");

if (scanf("%d", &n) != 1 || n < 0)
{
    printf("Ошибка ввода!\n");
    return 1;
}

printf("Введите количество прошедших дней (по условию 3): ");

if (scanf("%d", &days) != 1 || days < 0)
{
    printf("Ошибка ввода!\n");
    return 1;
}

month = (n % 12) + 1;
year = 2000 + n / 12;

while (1)
{
    switch (month)
    {
    case 1: case 3: case 5: case 7:
    case 8: case 10: case 12:
        days_in_month = 31;
        break;

    case 4: case 6: case 9: case 11:
        days_in_month = 30;
        break;

    case 2:
        if (year % 400 == 0 ||
            (year % 4 == 0 && year % 100 != 0))
            days_in_month = 29;
        else
            days_in_month = 28;
        break;
    }

    if (days < days_in_month)
        break;

    days -= days_in_month;
    month++;

    if (month > 12)
    {
        month = 1;
        year++;
    }
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
}

printf(" %d года\n", year);

return 0;
}
//
//  Petuhov_Lesson_2.cpp
//  AlgorithmsDataStructures-GB
//
//  Created by Василий Петухов on 15.09.2021.
//

#include <stdio.h>
#include <math.h>

void menu();
void solution1();
void solution2();

int main()
{
    int selected = 0;
    do
    {
        menu();
        printf("Enter your choice: ");
        scanf("%i", &selected);
        
        switch (selected)
        {
            case 1:
                solution1();
                break;
            case 2:
                solution2();
                break;
            case 0:
                printf("Finished, Bye!\n");
                break;
                
            default:
                printf("Wrong option selected\n");
        }
        
    } while (selected != 0);
    return  0;
}

// MARK: Menu of the programm
void menu()
{
    printf("\n1 — Conversion decimal to binary\n");
    printf("2 — Raising the number `a` to the power `b`\n");
    printf("0 — Exit\n");
}


// MARK: 1. Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.
// этот вариант просто печатает последовательность
void decimalToBinary(int number)
{
    int resultDivision, remainderDivision;
    
    resultDivision = number / 2;
    remainderDivision = number % 2;
    
    if (number >= 2) {
        decimalToBinary(resultDivision);
    }
    printf("%d", remainderDivision);
}

// этот вариант возвращает значение, для дальнейшего использования
// но при очень большом числе выведет случайный набор цифр
long long decimalToBinary2(int number)
{
    int resultDivision, remainderDivision;
    long long result;
    
    resultDivision = number / 2;
    remainderDivision = number % 2;
    
    if (number == 0)
        return 0;
    else
        result = decimalToBinary2(resultDivision) * 10 + remainderDivision;
        return (result);
}

void solution1()
{
    int number;
    long long result;
    
    printf("\nConversion decimal number to binary.\n");
    
    printf("Enter decimal number (example: 49): ");
    scanf("%d", &number);
    
    printf("Result by print: ");
    decimalToBinary(number); // функция сама печатает результат
    printf("\n");
    
    result = decimalToBinary2(number); // функция возвращает значение
    printf("Result by return `number`: %llu\n", result);
}


// MARK: 2. Реализовать функцию возведения числа a в степень b:
// a. без рекурсии;
// b. рекурсивно;
// c. *рекурсивно, используя свойство четности степени.

long powerByCycle(int a, int b)
{
    long result = 1;
    
    while (b > 0) {
        result = a * result;
        b--;
    }
    
    return result;
}

long powerByRecursion(int a, int b)
{
    long result = 1;
        
    if (b > 0)
        result = powerByRecursion(a, b - 1) * a;

    return result;
}

long powerByRecursionQuick(int a, int b)
{
    long result = 1;
        
    if (b > 0)
    {
        if (result % 2 == 0)
            result = powerByRecursion(a, b / 2) * a;
        else
            result = powerByRecursion(a, b - 1) * a;
    }
    
    return result;
}

void solution2()
{
    int a, b;
    long result;
    
    printf("\nRaising the number `a` to the power `b`.\n");
    
    printf("Enter `a` (example: 2): ");
    scanf("%d", &a);
    
    printf("Enter `b` (example: 3): ");
    scanf("%d", &b);
    
    result = powerByCycle(a, b);
    printf("Result `a^b` by cycle: %ld\n", result);
    
    result = powerByRecursion(a, b);
    printf("Result `a^b` by Recursion: %ld\n", result);
    
    result = powerByRecursionQuick(a, b);
    printf("Result `a^b` by Recursion Quick: %ld\n", result);
}

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

// этот вариант возвращает int значение, для дальнейшего использования
int decimalToBinary2(int number)
{
    int resultDivision, remainderDivision;
    
    resultDivision = number / 2;
    remainderDivision = number % 2;
    
    if (number == 0)
        return 0;
    else
        return (decimalToBinary2(resultDivision) * 10 + remainderDivision);
}

void solution1()
{
    int number, result;
    
    printf("\nConversion decimal number to binary.\n");
    
    printf("Enter decimal number (example: 49): ");
    scanf("%d", &number);
    
    printf("Result by print: ");
    decimalToBinary(number); // функция сама печатает результат
    printf("\n");
    
    result = decimalToBinary2(number); // функция возвращает значение int
    printf("Result by return `int`: %d\n", result);
}


// MARK: 2-
void solution2()
{
}

//
//  Petuhov_Lesson_1.c
//  Petuhov_Lesson_1
//
//  Created by Василий Петухов on 11.09.2021.
//

#include <stdio.h>
#include <math.h>

void menu();
void solution1();
void solution2();
void solution3();

int main()
{
    int selected = 0;
    do
    {
        menu();
        scanf("%i", &selected);
        
        switch (selected)
        {
            case 1:
                solution1();
                break;
            case 2:
                solution2();
                break;
            case 3:
                solution3();
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

void menu()
{
    printf("\n1 — Body Mass Index\n");
    printf("2 — The maximum of four numbers\n");
    printf("3 — Swap two numbers\n");
    printf("0 — Exit\n");
}


//1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.
void solution1()
{
    double m;
    double h;
    
    printf("\nBody Mass Index.\n");
    
    printf("Enter weight in kilograms (example: 75):");
    scanf("%lf", &m);

    printf("Enter height in meters (example: 1.75):");
    scanf("%lf", &h);
    
    double i = m/(h*h);

    printf("Body Mass Index: %.2f\n", i);
}

// 2. Найти максимальное из четырех чисел. Массивы не использовать.
void solution2()
{
    int a, b, c, d;
    int firstCandidate, secondCandidate;

    printf("\nThe maximum of four numbers.\n");
    
    printf("Enter 1st number:");
    scanf("%i", &a);
    
    printf("Enter 2nd number:");
    scanf("%i", &b);
    
    printf("Enter 3rd number:");
    scanf("%i", &c);
    
    printf("Enter 4st number:");
    scanf("%i", &d);
    
    if (a > b) {
        firstCandidate = a;
    } else {
        firstCandidate = b;
    }
    
    if (c > d) {
        secondCandidate = c;
    } else {
        secondCandidate = d;
    }
    
    if (firstCandidate > secondCandidate) {
        printf("Largest number: %i\n", firstCandidate);
    } else {
        printf("Largest number: %i\n", secondCandidate);
    }
    
}

// 3. Написать программу обмена значениями двух целочисленных переменных:
//  a. с использованием третьей переменной;
//  b. *без использования третьей переменной.
void solution3()
{
    int a, b;
    int temp_a;
    
    // 1
    printf("\n1) Swap method with an additional variable.\n");
    printf("Enter 1st number:");
    scanf("%i", &a);
    
    printf("Enter 2nd number:");
    scanf("%i", &b);
    
    temp_a = a;
    a = b;
    b = temp_a;
    
    printf("Method 1. Swap result: %i and %i\n", a, b);
    
    // 2*
    printf("\n2) Swap method without additional variable.\n");
    printf("Enter 1st number:");
    scanf("%i", &a);
    
    printf("Enter 2nd number:");
    scanf("%i", &b);
    
    a = a + b;
    b = a - b;
    a = a - b;
    
    printf("Method 2. Swap result: %i and %i\n", a, b);
}

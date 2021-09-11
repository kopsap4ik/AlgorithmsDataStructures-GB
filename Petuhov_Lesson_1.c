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
    printf("1 — Task 1\n");
    printf("2 — Task 2\n");
    printf("3 — Task 3\n");
    printf("0 — Exit\n");
}


//1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.
void solution1()
{
    double m;
    double h;
    
    printf("Enter weight in kilograms (example: 75):");
    scanf("%lf", &m);

    printf("Enter height in meters (example: 1.75):");
    scanf("%lf", &h);
    
    double i = m/(h*h);
//    double i = h*h;
    
//    printf("Body Mass Index: %d\n", i);
    printf("Body Mass Index: %.2f\n", i);
}

void solution2()
{
    printf("Solution: 2\n");
}

void solution3()
{
    printf("Solution: 3\n");
}

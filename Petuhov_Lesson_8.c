//
//  Petuhov_Lesson_8.c
//  AlgorithmsDataStructures-GB
//
//  Created by Василий Петухов on 08.10.2021.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
//#include <ctype.h>

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
        printf("Enter your choice: ");
        scanf("%i", &selected);
        printf("\n");
        
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
    printf("\n1 — Counting Sort\n");
    printf("2 — Quick Sort\n");
    printf("3 — Analysis of sorting metods\n");
    printf("0 — Exit\n");
}


// MARK: 1. Реализовать сортировку подсчетом.

void solution1()
{

}


// MARK: 2. Реализовать быструю сортировку.

void solution2()
{
 
}

// MARK: 3. Проанализируйте время работы каждого из вида сортировок для 100, 1000, 1000000 элементов.
// Заполните таблицу (смотри методичку).

void solution3()
{

}




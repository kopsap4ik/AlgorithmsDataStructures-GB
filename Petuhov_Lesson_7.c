//
//  Petuhov_Lesson_7.c
//  AlgorithmsDataStructures-GB
//
//  Created by Василий Петухов on 05.10.2021.
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
    printf("\n1 — Print of matrix from file\n");
    printf("2 — Depth traversal of the graph\n");
    printf("3 — Width traversal of the graph\n");
    printf("0 — Exit\n");
}


// MARK: 1. Написать функцию, которая считывают матрицу смежности из файла и выводят ее на экран.

void solution1()
{

}


// MARK: 2. Написать рекурсивную функцию обхода графа в глубину.

void solution2()
{
    
}

// MARK: 3. Написать функцию обхода графа в ширину.

void solution3()
{
    
}



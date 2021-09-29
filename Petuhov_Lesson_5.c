//
//  Petuhov_Lesson_5.c
//  AlgorithmsDataStructures-GB
//
//  Created by Василий Петухов on 28.09.2021.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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
    printf("\n1 — Converting from decimal to binary using a stack\n");
    printf("2 — Checking for memory allocation in a singly linked list\n");
    printf("3 — Checking the correct sequence of parentheses\n");
    printf("0 — Exit\n");
}


// MARK: 1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
#define size 100
int position = -1;
int Stack[size];

void PushStack(int data){
    if(position < size) Stack[++position] = data;
    else printf("Stack overflow \n");
}

int PopStack(){
    if(position != -1) return Stack[position--];
    else{
        printf("Stack is empty! \n");
        return -1;
    }
}


void solution1()
{
    int userDecimal = 0;

    printf("Enter a number in decimal format (for example 15): ");
    scanf("%d", &userDecimal);

    while(userDecimal > 0){
        if(userDecimal % 2 == 0) PushStack(0);
        else PushStack(1);
        
        userDecimal = userDecimal / 2;
    }

    printf("Binary format: ");
    while(position != -1){
        printf("%d", PopStack());
    }
    printf("\n");
}


// MARK: 2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти.
// Если память не выделяется, то выводится соответствующее сообщение.

void solution2()
{

    
}


// MARK: 3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
// Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]),
// неправильных: )(, ())({), (, ])}), ([(]) для скобок [,(,{.
// Примеры входных выражений: (2+(2*2)) или [2/{5*(4+7)}]

void solution3()
{
    
}

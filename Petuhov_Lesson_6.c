//
//  Petuhov_Lesson_6.c
//  AlgorithmsDataStructures-GB
//
//  Created by Василий Петухов on 02.10.2021.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>

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

void menu()
{
    printf("\n1 — Simple hash function\n");
    printf("2 — Binary search tree\n");
    printf("0 — Exit\n");
}


// MARK: 1. Реализовать простейшую хеш-функцию.
// На вход функции подается строка, на выходе сумма кодов символов.

unsigned long hash(char *lineText){
    int i = 0;
    unsigned long counter = 0;

    while(lineText[i] != '\0'){
        counter += lineText[i];
        i++;
    }
    return counter;
}

void solution1()
{
    char inputText[100];
    
    printf("\nSimple hash function\n");
    printf("Enter a string for generate hash: ");
    scanf("%s", inputText);
    
    unsigned long hashValue = hash(inputText);
    printf("Hash: %lu\n", hashValue);
}


// MARK: 2. Переписать программу, реализующую двоичное дерево поиска.
// а) Добавить в него обход дерева различными способами;
// б) Реализовать поиск в двоичном дереве поиска;


void solution2()
{
    
}


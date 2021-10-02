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


// MARK: 1. Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.

unsigned long getHashFrom(char* lineText) {
    unsigned long result = 0;
    unsigned long textLength = strlen(lineText);
    
    for (int i = 0; i < textLength; i++) {
        result = result + lineText[i];
    }
    return result;
}

unsigned long hash(char* lineText)
{
    unsigned long hashval;

    for (hashval = 0; *lineText != '\0'; lineText++)
        hashval = *lineText + 31*hashval;
    return hashval;
}

//unsigned long getHashFrom_2(char* lineText){
//    int i = 0;
//    unsigned long counter = 0;
//
//    while(lineText[i] != '\0'){
//        counter += lineText[i];
//        i++;
//    }
//    return counter;
//}

void solution1()
{
    char inputText[] = "abc";
    
    printf("\nVariant 1:\nEnter a string for generate hash: ");
    scanf("%s", inputText);
//    printf("Hash: %lu\n", getHashFrom(inputText));
    
    unsigned long hash = getHashFrom(inputText);
    printf("Hash: %lu\n", hash);
}


// MARK: 2. Переписать программу, реализующую двоичное дерево поиска.
// а) Добавить в него обход дерева различными способами;
// б) Реализовать поиск в двоичном дереве поиска;


void solution2()
{
    
}


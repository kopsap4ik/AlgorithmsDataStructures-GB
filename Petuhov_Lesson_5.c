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
#include <ctype.h>

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
#define size_1 100
int position = -1;
int Stack[size_1];

void PushStack(int data){
    if(position < size_1) Stack[++position] = data;
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

typedef struct TNode_3 Node_3;

struct TNode_3 {
    char value;
    struct TNode_3 *next;
};

struct Stack_3 {
    Node_3 *head;
    int size_3;
    int maxSize;
};

struct Stack_3 stack3;

void pushStack_3(char value) {
    if (stack3.size_3 >= stack3.maxSize) {
        printf("Stack overflow\n");
        return;
    }
    Node_3 *tmp = (Node_3*)malloc(sizeof(Node_3));
    
    if (tmp == NULL) {
        printf("No memory allocated\n");
    } else {
        tmp->value = value;
        tmp->next = stack3.head;
        
        stack3.head = tmp;
        stack3.size_3++;
    }
}

char popStack_3(void) {
    if (stack3.size_3 == 0) return '!';
    
    Node_3* next = NULL;
    
    char value;
    value = stack3.head->value;
    next = stack3.head;
    
    stack3.head = stack3.head->next;
    free(next);
    
    stack3.size_3--;
    return value;
}

void printR(Node_3* current) {
    if (current != NULL) {
        printR(current->next);
        printf("%i ", current->value);
    }
}

int isForwardBracket(char symbol) {
    if (symbol == '(' || symbol == '[' || symbol == '{') return 1;
    else return 0;
}

int isBackwardBracket(char symbol) {
    if (symbol == ')' || symbol == ']' || symbol == '}') return 1;
    else return 0;
}

int isNumber(char *str) {
    int i = 0;
    while (str[i] != '\0')
        if (!isdigit(str[i++])) return 0;
    return 1;
}

void solution3()
{
    stack3.maxSize = 100;
    stack3.head = NULL;
    int backwardIsFirst = 0;
    char buffer[100];
    
    printf("Enter a sequence of brackets (for example (2+(2*2))): ");
    scanf("%s", buffer);
    
    for (int i = 0; i < strlen(buffer); i++) {
        if (isForwardBracket(buffer[i])) {
            printf("Forward bracket %c is in %i position\n", buffer[i], i+1);
            pushStack_3(buffer[i]);
        }
        
        if (isBackwardBracket(buffer[i])) {
            printf("Backward bracket %c is in %i position\n", buffer[i], i+1);
            char charFromStack = popStack_3();
            if (charFromStack == '!') {
                backwardIsFirst = 1;
                break;
            }
            if ((charFromStack == '(' && buffer[i] != ')') ||
                (charFromStack == '[' && buffer[i] != ']') ||
                (charFromStack == '{' && buffer[i] != '}')) {
                printf("Bracket %c in %i position is set incorrectly\n", buffer[i], i+1);
                break;
            }
        }
    }
    
    char lastCharFromStack = popStack_3();
    
    if (lastCharFromStack != '!') printf("Error: missing closing bracket\n");
    else {
        if (backwardIsFirst) printf("Error: backward bracket cannot come before forward bracket\n");
        else printf("All brackets are set correctly\n");
    }
}

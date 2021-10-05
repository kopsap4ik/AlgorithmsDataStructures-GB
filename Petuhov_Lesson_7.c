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

#define MAX_SIZE 100

int matrix[MAX_SIZE][MAX_SIZE];
int countNodes = 0;
const char* fileName = "Matrix.txt";

void readMatrixFrom(const char *fileName, int array[MAX_SIZE][MAX_SIZE]) {
    FILE *file;
    file = fopen(fileName,"r");
    if (file == NULL) {
        printf("File not found\n");
        exit(1);
    }
    
    fscanf(file, "%i", &countNodes);
    if (countNodes > MAX_SIZE) {
        printf("Too large matrix in file, change the `MAX_SIZE` parameter\n");
        exit(1);
    }
    
    for (int i = 0; i < countNodes; i++) {
        for (int j = 0; j < countNodes; j++) {
            fscanf(file, "%i", &array[i][j]);
        }
    }
    fclose(file);
}

void printFrom(int matrix[MAX_SIZE][MAX_SIZE], int numberOfVertices) {
    printf("%s", "        ");
    for (int i = 0; i < numberOfVertices; i++) {
        printf("%c(%i) ", 65 + i, i);
    }
    printf("\n");
    for (int i = 0; i < numberOfVertices; i++) {
        printf("%c(%i) ", 65 + i, i);
        for (int j = 0; j < numberOfVertices; j++) {
            printf("%5i", (matrix[i][j] == INFINITY) ? 0 : matrix[i][j]);
        }
        printf("\n");
    }
    getchar();
}

void solution1()
{
    printf("\nThe matrix will be read from the file: %s\n", fileName);
    readMatrixFrom(fileName, matrix);
    printFrom(matrix, countNodes);
    printf("\n");
}


// MARK: 2. Написать рекурсивную функцию обхода графа в глубину.

void solution2()
{
    
}

// MARK: 3. Написать функцию обхода графа в ширину.

void solution3()
{
    
}



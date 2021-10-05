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

#define MAX_SIZE 100

const char* fileName = "Matrix.txt";
// граф из методички
//                   ( 1 )
//                  /    \
//                 /      \
//               (5)      (2)
//                | \    / |
//                |   (6)  |
//                |        |
//               (4) ---- (3)

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
    printf("\n1 — Print of matrix from file\n");
    printf("2 — Depth traversal of the graph\n");
    printf("3 — Width traversal of the graph\n");
    printf("0 — Exit\n");
}


// MARK: 1. Написать функцию, которая считывают матрицу смежности из файла и выводят ее на экран.
int matrix[MAX_SIZE][MAX_SIZE];
int countNodes = 0;


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
}

void solution1()
{
    printf("The matrix will be read from the file: %s\n", fileName);
    readMatrixFrom(fileName, matrix);
    printFrom(matrix, countNodes);
}


// MARK: 2. Написать рекурсивную функцию обхода графа в глубину.

int stateMatrix[MAX_SIZE];

#define whiteNode 1
#define grayNode 2
#define blackNode 3

void depthGraphTraversal(int adjacencyMatrixArray[MAX_SIZE][MAX_SIZE], int countNodes, int currentNode) {
    for (int j = 0; j < countNodes; j++) {
        if (currentNode != 0 && stateMatrix[currentNode] == blackNode) {
            currentNode -= 1;
            printf("Back to node %c(%i)\n", 65 + currentNode, currentNode);
        }
        
        if (currentNode < countNodes - 1) {
            if (adjacencyMatrixArray[currentNode][j] != 0 && stateMatrix[j] == whiteNode) {
                stateMatrix[j] = grayNode;
                printf("%c(%i) -> %c(%i)\n", 65 + currentNode, currentNode, 65 + j, j);
                stateMatrix[currentNode] = blackNode;
                currentNode = j;
                depthGraphTraversal(adjacencyMatrixArray, countNodes, currentNode);
            }
        } else {
            printf("Farthest node: %c(%i)\n", 65 + currentNode, currentNode);
        }
    }
    
    stateMatrix[currentNode] = blackNode;
}

void solution2()
{
    int initialNode = 0;
    readMatrixFrom(fileName, matrix);
    printFrom(matrix, countNodes);
    printf("\n");
    
    if (countNodes != 0) {
        for (int i = 0; i < countNodes; i++) {
            stateMatrix[i] = whiteNode;
        }
        stateMatrix[initialNode] = grayNode;
    } else {
        printf("Matrix empty!\n");
        exit(1);
    }
    
    depthGraphTraversal(matrix, countNodes, initialNode);
}

// MARK: 3. Написать функцию обхода графа в ширину.

typedef struct Queue Queue;
typedef struct VertexGraph VertexGraph;

struct VertexGraph {
    struct VertexGraph* nextVertexNode;
    struct VertexGraph* previousVertexNode;
    int value;
};

struct Queue {
    VertexGraph* head;
    VertexGraph* tail;
    int size;
};

Queue queue_3;

void enQueue(Queue* queue, int value) {
    VertexGraph* tmp = (VertexGraph*)malloc(sizeof(VertexGraph));
    
    if (tmp == NULL) {
        printf("No memory allocated\n");
    } else {
        tmp->nextVertexNode = queue->head;
        tmp->previousVertexNode = NULL;
        tmp->value = value;
        if (queue->head == NULL) {
            queue->tail = tmp;
        } else {
            queue->head->previousVertexNode = tmp;
        }
        queue->head = tmp;
        queue->size++;
    }
}

int deQueue(Queue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    
    int value = queue->tail->value;
    VertexGraph* tmp = queue->tail;
    queue->tail = queue->tail->previousVertexNode;
    
    if (queue->size > 1) queue->tail->nextVertexNode = NULL;
    else queue->head = NULL;
    
    queue->size--;
    free(tmp);
    
    return value;
}

void widthGraphTraversal(int matrix[MAX_SIZE][MAX_SIZE], int countNodes) {
    if (countNodes != 0) {
        for (int i = 0; i < countNodes; i++) {
            stateMatrix[i] = whiteNode;
        }
    } else {
        printf("Graph is empty\n");
        exit(1);
    }
    
    stateMatrix[0] = grayNode;
    enQueue(&queue_3, 0);
    
    while (queue_3.size > 0) {
        int currentNode = deQueue(&queue_3);
        
        if (stateMatrix[currentNode] == grayNode) {
            for (int j = 0; j < countNodes; j++) {
                if (matrix[currentNode][j] != 0 && stateMatrix[j] == whiteNode) {
                    enQueue(&queue_3, j);
                    stateMatrix[j] = grayNode;
                    printf("%c(%i) -> %c(%i)\n", 65 + currentNode, currentNode, 65 + j, j);
                }
            }
            stateMatrix[currentNode] = blackNode;
        }
    }
}


void solution3()
{
    readMatrixFrom(fileName, matrix);
    printFrom(matrix, countNodes);
    printf("\n");
    
    widthGraphTraversal(matrix, countNodes);
}



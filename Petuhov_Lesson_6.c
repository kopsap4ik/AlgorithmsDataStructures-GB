//
//  Petuhov_Lesson_6.c
//  AlgorithmsDataStructures-GB
//
//  Created by Василий Петухов on 02.10.2021.
//

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
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
    unsigned long hashValue = 0;

    while(lineText[i] != '\0'){
        hashValue += lineText[i];
        i++;
    }
    return hashValue;
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

#define size 20
typedef struct Node Node;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};

Node* createTreeNode(int value, Node *parent) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

void insertNode(Node **head, int value) {
    Node *tmp = NULL;
    if (*head == NULL) {
        *head = createTreeNode(value, NULL);
        return;
    }

    tmp = *head;
    while (tmp) {
        if (value > tmp->data) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = createTreeNode(value, tmp);
                return;
            }
        } else if (value < tmp->data) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = createTreeNode(value, tmp);
                return;
            }
        } else {
            exit(2); // The tree is not built correctly
        }
    }
}

void printTreeBrackets(Node *root) {
    if (root) {
        printf("%d", root->data);
        if (root->left || root->right) {
            printf("(");
            
            if (root->left)
                printTreeBrackets(root->left);
            else
                printf("NULL");
            printf(",");

            if (root->right)
                printTreeBrackets(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}
//preOrderTravers
void preOrderTraversal(Node* root) {
    if (root) {
        printf("%i ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%i ", root->data);
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node* root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%i ", root->data);
    }
}

Node* searchNodeOnTree(Node* root, int nodeKey) {
    if (root == NULL || nodeKey == root->data) {
        printf("%i\n", root->data);
        return root;
    }
    if (nodeKey < root->data) {
        printf("%i -> turn left -> ", root->data);
        return searchNodeOnTree(root->left, nodeKey);
    } else {
        printf("%i -> turn right -> ", root->data);
        return searchNodeOnTree(root->right, nodeKey);
    }
}

void solution2()
{
    Node *Tree = NULL;
    int elements[size] = {54, 20, 72, 34 ,9, 89, 74, 8, 27, 36, 70, 3, 80, 69, 73, 83, 71, 45, 56, 66};
    int searchedElement;
    
    for (int j = 0; j < size; j++) {
        insertNode(&Tree, elements[j]);
    }
    
    printf("\nTree with brackets:\n");
    printTreeBrackets(Tree);
    
    printf("\n\nPreorder Traversal:\n");
    preOrderTraversal(Tree);
    
    printf("\n\nInorder Traversal:\n");
    inOrderTraversal(Tree);
    
    printf("\n\nPostorder Traversal:\n");
    postOrderTraversal(Tree);
    
    printf("\n\nEnter the element for search in tree: ");
    scanf("%d", &searchedElement);
    printf("\nPath to searched element (%i) through tree:\n", searchedElement);
    searchNodeOnTree(Tree, searchedElement);
}


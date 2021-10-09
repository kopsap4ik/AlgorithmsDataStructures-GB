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

#define MaxArraySize 1000

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

void countingSort(int* initialArray, int *sortedArray, int arrayLength) {
    int tempArray[MaxArraySize];
    
    for (int i = 0; i < MaxArraySize + 1; i++) {
        tempArray[i] = 0;
    }
    
    for (int j = 0; j < arrayLength; j++) {
        tempArray[initialArray[j]] = tempArray[initialArray[j]] + 1;
    }
    
    for (int i = 1; i < MaxArraySize + 1; i++) {
        tempArray[i] = tempArray[i] + tempArray[i - 1];
    }
    
    for (int j = arrayLength - 1; j >= 0; j--) {
        sortedArray[tempArray[initialArray[j]] - 1] = initialArray[j];
        tempArray[initialArray[j]] = tempArray[initialArray[j]] - 1;
    }
}

void solution1()

{
    int arrLenght;
    
    printf("Enter count elements for generate unsorted array: ");
    scanf("%d", &arrLenght);
    
    int unsortedArray[arrLenght];
    int sortedArray[arrLenght];
    
    printf("Unsorted array:\n");
    for (int i = 0 ; i < arrLenght; i++) {
        unsortedArray[i] = rand() % 1000;
        printf("%i ", unsortedArray[i]);
    }
    
    countingSort(unsortedArray, sortedArray, arrLenght);
    
    printf("\n\nSorted array:\n");
    for (int i = 0; i < arrLenght; i++) {
        printf("%i ", sortedArray[i]);
    }
    printf("\n");
}


// MARK: 2. Реализовать быструю сортировку.

void quickSort(int *numbersArray, int left, int right) {
    int pivot;
    int lHold = left;
    int rHold = right;
    
    pivot = numbersArray[left];
    
    while (left < right) {
        while ((numbersArray[right] >= pivot) && (left < right)) {
            right--;
        }
        
        if (left != right) {
            numbersArray[left] = numbersArray[right];
            left++;
        }
        
        while ((numbersArray[left] <= pivot) && (left < right)) {
            left++;
        }
        
        if (left != right) {
            numbersArray[right] = numbersArray[left];
            right--;
        }
    }
    
    numbersArray[left] = pivot;
    pivot = left;
    left = lHold;
    right = rHold;
    
    if (left < pivot) quickSort(numbersArray, left, pivot);
    if (right > pivot) quickSort(numbersArray, pivot + 1, right);
}

void solution2()
{
    
    int arrLenght;
    
    printf("Enter count elements for generate unsorted array: ");
    scanf("%d", &arrLenght);
    
    int unsortedArray[arrLenght];
//    int sortedArray[arrLenght];
    
    printf("Unsorted array:\n");
    for (int i = 0 ; i < arrLenght; i++) {
        unsortedArray[i] = rand() % 1000;
        printf("%i ", unsortedArray[i]);
    }

    quickSort(unsortedArray, 0, arrLenght - 1);
    
    printf("\n\nSorted array:\n");
    for (int i = 0 ; i < arrLenght; i++) {
        printf("%i ", unsortedArray[i]);
    }
}

// MARK: 3. Проанализируйте время работы каждого из вида сортировок для 100, 1000, 1000000 элементов.
// Заполните таблицу (смотри методичку).

void solution3()
{
    
}




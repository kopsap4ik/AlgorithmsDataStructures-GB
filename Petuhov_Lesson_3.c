//
//  Petuhov_Lesson_3.cpp
//  AlgorithmsDataStructures-GB
//
//  Created by Василий Петухов on 18.09.2021.
//

#include <stdio.h>
#include <math.h>

#define MaxN 100

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
    printf("\n1 — Bubblesort\n");
    printf("2 — Shaker\n");
    printf("3 — Binary search\n");
    printf("0 — Exit\n");
}


// MARK: 1. Попробовать оптимизировать пузырьковую сортировку.
// Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
// Написать функции сортировки, которые возвращают количество операций.


int readArrayFromeFile(int *array, char *fileName)
{
    int number = 0;
    int newLenght = 0;
    
    FILE *file = fopen(fileName, "r");

    // проходим по файлу пока он не закончится, чтобы узнать количество чисел
    // этот вариант нормально читает большинство последователеностей (на каждой новой строке, через запятые, через пробелы)
    while (fscanf(file, "%i,", &number) > 0) {
        array[newLenght] = number; // добавляет число в массив
        newLenght++;
    }
        
    fclose(file);
    return newLenght;
}

void printArray(int *array, int arrayLenght)
{
    int i;
    for (i = 0; i < arrayLenght; i++) {
        printf("%6i", array[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sortBubbleClasic(int *array, int arrayLenght){
    int i, j;
    int operationsСounter = 0;
    
    for (i = 0; i < arrayLenght; i++) {
        operationsСounter++; // проход первого цикла
        
        for (j = 0; j < (arrayLenght - 1); j++) {
            operationsСounter++; // проход второго цикла
            
            if (array[j] > array[j + 1]) {
                operationsСounter++; // операции обмена элементов
                swap(&array[j], &array[j + 1]);
            }
        }
    }
    
    return operationsСounter;
}

int sortBubbleOptimized(int *array, int arrayLenght){
    int i, j;
    int operationsСounter = 0;
    
    for (i = 0; i < arrayLenght; i++) {
        int isSorted = 1; //  1) Булевый стопор для проверки, если массив уже отсортирован или частично отсортирован
        operationsСounter++; // проход первого цикла
        
        for (j = 0; j < (arrayLenght - 1); j++) {
            operationsСounter++; // проход второго цикла
            
            if (array[j] > array[j + 1]) {
                operationsСounter++; // операции обмена элементов
                swap(&array[j], &array[j + 1]);
                isSorted = 0;
            }
        }
        if (isSorted) {
            break;
        }
    }
    
    return operationsСounter;
}

int sortBubbleOptimized_2(int *array, int arrayLenght){
    int i, j;
    int operationsСounter = 0;
    int lastSwap = arrayLenght - 1;  // для запоминания последней позиции обмена
    
    for (i = 0; i < arrayLenght; i++) {
        int currentSwap = -1;
        int isSorted = 1;
        operationsСounter++;
        
        // После каждого вложенного цикла справа окажется некоторое количество больших отсортированных элементов,
        // которые не нужно сортировать повторно и можно сократить цикл до значения lastSwap (где был последний обмен)
        for (j = 0; j < lastSwap; j++) {
            operationsСounter++;
            
            if (array[j] > array[j + 1]) {
                operationsСounter++;
                swap(&array[j], &array[j + 1]);
                currentSwap = j; // помечаем позицию обмена
                isSorted = 0;
            }
        }
        if (isSorted) {
            break;
        }
        lastSwap = currentSwap; //
    }
    
    return operationsСounter;
}

void solution1()
{
    int arrayNumbers[MaxN];
    int arrayLenght;
    
    int selected = 0;
    do
    {
        printf("\n1 — Bubblesort clasic\n");
        printf("2 — Bubblesort optimized with flag\n");
        printf("3 — Bubblesort optimized with flag and saved last Swap\n");
        printf("0 — Exit to main menu\n");
        
        printf("Enter your choice: ");
        scanf("%i", &selected);
        
        switch (selected)
        {
            case 1:
                arrayLenght = readArrayFromeFile(arrayNumbers, "UnsortedArray.txt");
                
                puts("Array before sorting");
                printArray(arrayNumbers, arrayLenght);
                
                // Обыная сортировка пузырьком
                int operationsСounter = sortBubbleClasic(arrayNumbers, arrayLenght);
                
                puts("Array after sorting");
                printArray(arrayNumbers, arrayLenght);
                printf("Number of array elements: %d\n", arrayLenght);
                printf("Number of operations (Bubble Sort Clasic): %d\n", operationsСounter);
                
                break;
            case 2:
                arrayLenght = readArrayFromeFile(arrayNumbers, "UnsortedArray.txt");
                
                puts("Array before sorting");
                printArray(arrayNumbers, arrayLenght);
                
                int operationsСounterOptimized = sortBubbleOptimized(arrayNumbers, arrayLenght);
                
                puts("Array after sorting");
                printArray(arrayNumbers, arrayLenght);
                printf("Number of array elements: %d\n", arrayLenght);
                printf("Number of operations (Bubble Sort Optimized - flag): %d\n", operationsСounterOptimized);
                
                break;
            case 3:
                arrayLenght = readArrayFromeFile(arrayNumbers, "UnsortedArray.txt");
                
                puts("Array before sorting");
                printArray(arrayNumbers, arrayLenght);
                
                int operationsСounterOptimized_2 = sortBubbleOptimized_2(arrayNumbers, arrayLenght);
                
                puts("Array after sorting");
                printArray(arrayNumbers, arrayLenght);
                printf("Number of array elements: %d\n", arrayLenght);
                printf("Number of operations (Bubble Sort Optimized - flag and save position swap): %d\n", operationsСounterOptimized_2);

                break;
            case 0:
                printf("Exit in main menu!\n");
                break;
                
            default:
                printf("Wrong option selected\n");
        }
        
    } while (selected != 0);
}

// MARK: 2. Реализовать шейкерную сортировку.
int sortShakerClasic(int *array, int arrayLenght){
    int leftMark = 1;
    int rightMark = arrayLenght - 1;
    int operationsСounter = 0;
    
    while (leftMark <= rightMark) {
        operationsСounter++;
        for (int i = rightMark; i >= leftMark; i--) {
            operationsСounter++;
            if (array[i - 1] > array[i]) {
                operationsСounter++;
                swap(&array[i - 1], &array[i]);
            }
        }
        leftMark++;
        
        for (int i = leftMark; i <= rightMark; i++) {
            operationsСounter++;
            if (array[i - 1] > array[i]) {
                operationsСounter++;
                swap(&array[i - 1], &array[i]);
            }
        }
        rightMark--;
    }
    
    return operationsСounter;
}

void solution2()
{
    int arrayNumbers[MaxN];
    int arrayLenght;
    
    arrayLenght = readArrayFromeFile(arrayNumbers, "UnsortedArray.txt");
    
    puts("Array before sorting");
    printArray(arrayNumbers, arrayLenght);
    
    int operationsСounter = sortShakerClasic(arrayNumbers, arrayLenght);
    
    puts("Array after sorting");
    printArray(arrayNumbers, arrayLenght);
    
    printf("Number of array elements: %d\n", arrayLenght);
    printf("Number of operations (Shaker Sort Clasic): %d\n", operationsСounter);
    
}

// MARK: 3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.
// Функция возвращает индекс найденного элемента или -1, если элемент не найден.

int binarySearch(int *array, int arrayLenght, int searchItem)
{
    int min = 0;
    int max = arrayLenght - 1;
    int middle;
    
    int operationsСounter = 0;
    
    while (min <= max) {
        operationsСounter++;
        middle = (max - min) / 2 + min;

        if (searchItem == array[middle]) {
            printf("Number of operations: %d\n", operationsСounter);
            return middle;
        }

        if (searchItem > array[middle]) min = middle + 1;

        if (searchItem < array[middle]) max = middle - 1;
    }

    
    return -1;
}

void solution3()
{
    int arrayNumbers[MaxN];
    int arrayLenght;
    int searchItem;
    int searchedItemPosition;
    
    arrayLenght = readArrayFromeFile(arrayNumbers, "UnsortedArray.txt");
    
    sortShakerClasic(arrayNumbers, arrayLenght);
    printArray(arrayNumbers, arrayLenght);
    
    printf("Enter the number to find: ");
    scanf("%i", &searchItem);
    
    searchedItemPosition = binarySearch(arrayNumbers, arrayLenght, searchItem);
    
    printf("Your number ");
    if (searchedItemPosition == -1) printf("not found!\n");
    else printf("founded in position [%d]\n", searchedItemPosition);
}


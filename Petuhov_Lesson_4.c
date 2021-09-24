//
//  Petuhov_Lesson_4.c
//  AlgorithmsDataStructures-GB
//
//  Created by Василий Петухов on 23.09.2021.
//

#include <stdio.h>
#include <math.h>
#include <string.h>

#define RowsMax 6
#define ColumnsMax 6

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
    printf("\n1 — Calculating the number of routes on the map\n");
    printf("2 — Finding the longest common subsequence\n");
    printf("0 — Exit\n");
}


// MARK: 1. Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.
// Например, карта:
// размер: 3x3
//  1 1 1
//  0 1 0
//  0 1 0

int barriersMap[RowsMax][ColumnsMax] =
{
    {1, 1, 1, 1, 1, 1},
    {0, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0},
    {1, 1, 0, 1, 1, 1},
    {0, 1, 1, 1, 1, 1}
};

int moveMap[RowsMax][ColumnsMax];


void printMap(int numberRows, int numberColumns, int array[RowsMax][ColumnsMax])
{
    int row, column;
    for (row = 0; row < numberRows; row++)
    {
        for (column = 0; column < numberColumns; column++)
        {
            printf("%6d", array[row][column]);
        }
        printf("\n");
    }
    
}

void countRoutes()
{
    int row, column;
    
    // заполнение 1-го ряда
    for (column = 0; column < ColumnsMax; column++) {
        if (barriersMap[0][column] == 0) moveMap[0][column] = 0;
        else moveMap[0][column] = 1;
    }
    
    // заполнение 1-го колонки
    for (row = 0; row < ColumnsMax; row++) {
        if (barriersMap[row][0] == 0) moveMap[row][0] = 0;
        else moveMap[row][0] = 1;
    }

    // заполнение оставшейся части
    for (row = 1; row < RowsMax; row++)
    {
        for (column = 1; column < ColumnsMax; column++) {
            if (barriersMap[row][column] == 1)
            {
                moveMap[row][column] = moveMap[row - 1][column] + moveMap[row][column - 1];
            }

            else moveMap[row][column] = 0;

        }
    }
}

void solution1()
{
    printf("\nInitial map with barriers (`1` - allow move and `0` - disallow):\n");
    printMap(RowsMax, ColumnsMax, barriersMap);
    
    countRoutes();
    
    printf("\nFinal calculation with numbers of routes:\n");
    printMap(RowsMax, ColumnsMax, moveMap);
}


// MARK: 2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.
// longest common subsequence — наибольшая общая подпоследовательность

int row, column, lengthText1, lengthText2, textsMap[20][20];
char text1[20], text2[20], directionMap[20][20];

void printMapLCS(int row, int column)
{
    if (row == 0 || column == 0) {
        return;
    }
    
    if (directionMap[row][column] == 'c') {
        printMapLCS(row - 1, column - 1);
        printf("%c", text1[row - 1]);
    } else if (directionMap[row][column] == 'u') {
        printMapLCS(row - 1, column);
    } else {
        printMapLCS(row, column - 1);
    }
}

void lcs()
{

    lengthText1 = strlen(text1);
    lengthText2 = strlen(text2);

    // заполнение столбца и ряда карты textMaps
    for (row = 0; row <= lengthText1; row++)
        textsMap[row][0] = 0;
    for (column = 0; column <= lengthText2; column++)
        textsMap[0][column] = 0;
    
    // Обозначение вариантов движения в карте directionMap: `c`, `u`, `l` — cross, upper, left
    for (row = 0; row <= lengthText1; row++) {
        for (column = 0; column <= lengthText2; column++) {
            
            if (text1[row - 1] == text2[column - 1]) {
                textsMap[row][column] = textsMap[row - 1][column - 1] + 1;
                directionMap[row][column] = 'c';
            } else if (textsMap[row - 1][column] >= textsMap[row][column - 1]){
                textsMap[row][column] = textsMap[row - 1][column];
                directionMap[row][column] = 'u';
            } else {
                textsMap[row][column] = textsMap[row][column - 1];
                directionMap[row][column] = 'l';
            }
            
        }
    }
    
}

void solution2()
{
    printf("\nFinding the longest common subsequence of two sequences.\n");
    
    printf("Enter 1-st sequence of symbols: ");
    scanf("%s", text1);
    
    printf("Enter 2-nd sequence of symbols: ");
    scanf("%s", text2);
    
    printf("\nThe longest common subsequence from two sequences: ");
    lcs();
    printMapLCS(lengthText1, lengthText2);
    
    printf("\n");
    
}

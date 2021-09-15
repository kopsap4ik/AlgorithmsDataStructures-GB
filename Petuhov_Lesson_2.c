//
//  Petuhov_Lesson_2.cpp
//  AlgorithmsDataStructures-GB
//
//  Created by Василий Петухов on 15.09.2021.
//

#include <stdio.h>
#include <math.h>

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
    printf("\n1 — Conversion decimal to binary\n");
    printf("2 — Raising the number `a` to the power `b`\n");
    printf("0 — Exit\n");
}

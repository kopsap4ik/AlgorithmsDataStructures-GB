# Алгоритмы и структуры данных
Учебный курс школы GeekBrains на языке C

## Домашние задания

### Урок 1. Простые алгоритмы
1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h). Где m-масса тела в килограммах, h - рост в метрах.
2. Найти максимальное из четырех чисел. Массивы не использовать.
3. Написать программу обмена значениями двух целочисленных переменных:  
    a. с использованием третьей переменной;  
    b. *без использования третьей переменной.

### Урок 2. Асимптотическая сложность алгоритма. Рекурсия
1. Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.
2. Реализовать функцию возведения числа a в степень b:  
    a. без рекурсии;  
    b. рекурсивно;    
    c. *рекурсивно, используя свойство четности степени.  

### Урок 3. Поиск в массиве. Простые сортировки
1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.
2. Реализовать шейкерную сортировку. Можно с оптимизациями из пузырьковой сортировки.
3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.

### Урок 4. Динамическое программирование. Поиск возвратом
1. Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.  
Например, карта размером 3 x 3 (или больше):  
1   1    1  
0   1    0  
0   1    0  
2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.

### Урок 5. Динамические структуры данных
1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
2. Добавить в программу «реализация стека на основе односвязного списка» проверку на выделение памяти. Если память не выделяется, то выводится соответствующее сообщение. 
3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.  
Например: (2+(2*2)) или [2/{5*(4+7)}]

### Урок 6. Деревья
1. Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов.
2. Переписать программу, реализующую двоичное дерево поиска.  
а) Добавить в него обход дерева различными способами;  
б) Реализовать поиск в двоичном дереве поиска;

### Урок 7. Графы. Алгоритмы на графах.
1. Написать функцию, которая считывают матрицу смежности из файла и выводят ее на экран.
2. Написать рекурсивную функцию обхода графа в глубину.
3. Написать функцию обхода графа в ширину.


//1.9.1 Реализовать решение числа фибоначчи через вектор-столбец. ("ручками")

// ( 0 1 )^n   (F0)   (Fn  )
// ( 1 1 )   * (F1) = (Fn+1)
#include <stdio.h>


//Из формулы выше следует, что Fn = [0][0] * F0 + [0][1] * F1, т.е. [0][1] * F1
int matrix_fibonacci(int arr[2][2], int  matr[2][2], int num) {

    if (num == 0) {return 0;}
    if (num == 1) {return 1;}
    /*
    arr *   (0 1) =
            (1 1)
    arr[0][0] * 0 + arr[0][1] * 1
    arr[0][0] * 1 + arr[0][1] * 1
    arr[1][0] * 0 + arr[1][1] * 1
    arr[1][0] * 1 + arr[1][1] * 1
     */

    for (int i = 0; i < num-2; i++) {
    matr[0][0] = arr[0][1];
    matr[0][1] = arr[0][1] + arr[0][0];
    matr[1][0] = arr[1][1];
    matr[1][1] = arr[1][0] + arr[1][1];

    arr[0][0] = matr[0][0];
    arr[0][1] = matr[0][1];
    arr[1][0] = matr[1][0];
    arr[1][1] = matr[1][1];
    }
    return matr[1][0];
}

int main() {
    int arr[2][2] = {0, 1, 1, 1};
    int matr[2][2] = {0, 1, 1, 1};
    int num;

    printf("Введите номер желаемого числа фибоначчи");
    scanf("%d", &num);

    printf("%d", matrix_fibonacci(arr, matr, num));
    return 0;
}
// 1.1.1 Пусть имеется массив A длиной N элементов. Найти номер первого вхождения элемента со значением P.

#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int length, P;
    printf("Введите длину массива \n");
    scanf("%d", &length);
    char arr[length];

    printf("Введите элементы массива \n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Введите значение искомого элемента \n");
    scanf("%d", &P);

    for (int i = 0; i < length; i++) {
        if (arr[i] == P) {
            printf("Номер искомого элемента: %d \n", (i+1));
            break;
        }
    }
    return 0;
}

// 1.1.2 Пусть имеется N предметов, каждый из которых имеет объём Vi и стоимость Ci, предметы неделимы.
// Имеется рюкзак вместимостью V. Требуется поместить в рюкзак набор предметов максимальной стоимости,
// суммарный объём которых не превышает объёма рюкзака.

#include <stdio.h>
#include <windows.h>
#include <math.h>

int max_capacity, max_value = 0; // Максимальные значения, которые и будут результатом.
int capacity, value; // Переменные для суммирования и проверки с максимальным значением.
int elements; // Число элементов для рюкзака.

// Перевод в двоичную СС
int num_sys_conv(int number) {
    int bin_num = 0, k = 1;
    while (number != 0) {
        bin_num += (number % 2) * k;
        k *= 10;
        number /= 2;
    }
    return bin_num;
}

// Метод из книжки O(2^N)
void second_method(int arr[2][elements]) {
    int bin_num, k, backpack_counter = 1;
    while (backpack_counter != pow(2, elements)) {
        value = 0;
        capacity = 0;
        k = 0;
        bin_num = num_sys_conv(backpack_counter);
        while (bin_num != 0) {
            if (bin_num % 10 == 1) {
                capacity += arr[0][k]; value += arr[1][k];
            }
            bin_num /= 10;
            k++;
        }
        if ((capacity <= max_capacity) && (value > max_value)) {max_value = value;}
        backpack_counter++;
    }
    printf("Максимальная стоимость элементов: %d", max_value);
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    printf("Введите максимальный объем рюкзака \n");
    scanf("%d", &max_capacity);
    printf("Введите количество элементов \n");
    scanf("%d", &elements);
    int arr[2][elements];

    printf("Введите объем и стоимость предмета через пробел \n");
    for (int i = 0; i < elements; i++) {
        scanf("%d %d", &arr[0][i], &arr[1][i]);
    }

    second_method(arr);
    return 0;
}
//1.6 Реализовать решение числа фибоначчи.
#include <iostream>
#include <windows.h>

int fibonacci_static_arr(int *num_arr, int n) {
    if (n == 0 or n == 1)  {return n;}
    else if (num_arr[n] > 0) {return num_arr[n];}
    return num_arr[n] = fibonacci_static_arr(num_arr, n-1) + fibonacci_static_arr(num_arr, n-2);
}

int main() {
    static int num_arr[1000] = {0, 1, 1};
    int num;

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::cout << "Введите номер желаемого числа фибоначчи" << std::endl;
    // number: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10...
    // result: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55...
    std::cin >> num;
    std::cout << fibonacci_static_arr(num_arr, num) << std::endl;
    return 0;
}

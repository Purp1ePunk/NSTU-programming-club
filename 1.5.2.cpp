#include <iostream>
#define max_length 100

class SetofNumbers {
//Данный класс расчитан на множество чисел N
private:
    int arr[max_length];
    int top = -1;

    //Функция возвращает индекс элемента в множестве
    int find_num(int num) {
        if (top != max_length) {
            for (int i = 0; i <= top; i++) {
                if (num == arr[i])
                    return i;
            }
        }
        //Возвращает -1 в случае, если элемент не найден
        return -1;
    };

public:

    void insert(int num){
        if (find_num(num) == -1 and top != max_length) {
            arr[top+1] = num;
            top++;
        }
    }

    void remove(int num) {
        if (find_num(num) != -1) {
            //Все элементы массива после данного сдвигаются влево
            for (int i = find_num(num); i < top; i++) {
                arr[i] = arr[i+1];
            }
            arr[top] = -1;
            top--;
        }
    }

    int size() {
        return top+1;
    }

    bool in(int num) {
        if (find_num(num) != -1) {return 1;};
        return 0;
    }

    void print() {
        for (int i = 0; i <= top; i++) {
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }
};
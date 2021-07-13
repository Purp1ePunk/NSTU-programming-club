#include <iostream>
#define max_length 100

class Stack {

private:
    float arr[max_length];
    int top = -1;

public:

    void push (float push_num) {
        arr[top+1] = push_num;
        top++;
    }

    void pop() {
        if (top >= 0) top--;
        else std::cout << "Стек пуст." << std::endl;
    }

    float peek () {
        if (top >= 0) return arr[top];
    }

    bool is_empty () {
        if (top >= 0) return false;
        else return true;
    }

    void destroy () {
        top = -1;
    }
};

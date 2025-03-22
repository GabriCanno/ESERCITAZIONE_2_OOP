#include <iostream>

#define STACK_SIZE 8

struct stack {
    int     data[STACK_SIZE];
    int     top;

            stack();
            stack(const stack& other);
    void    push(int value);
    int     pop();
    bool    empty();
    bool    full();
};

stack::stack() {
    top = 0;
}

stack::stack(const stack& other) {
    for (int i = 0; i < STACK_SIZE; i++)
        data[i] = other.data[i];
}

void stack::push(int value) {
    if (top < STACK_SIZE)
        data[top++] = value;
}

int stack::pop() {
    if (top > 0)
        return data[--top];

    return 0;
}

bool stack::empty() {
    return (top == 0);
}

bool stack::full() {
    return (top == STACK_SIZE);
}

int main(void)
{
    stack s;
    std::cout << "Is empty: " << std::boolalpha << s.empty() << "\n";
    std::cout << "Pushing 10 and 20\n";
    s.push(10);
    s.push(20);
    std::cout << s.pop() << "\n";
    std::cout << "Is empty: " << std::boolalpha << s.empty() << "\n";
    std::cout << s.pop() << "\n";
    std::cout << "Is empty: " << std::boolalpha << s.empty() << "\n";

    return 0;
}


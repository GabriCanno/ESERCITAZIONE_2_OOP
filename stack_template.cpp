#include <iostream>

#define STACK_SIZE 8

template<typename T>
struct stack {
    T       data[STACK_SIZE];
    int     top;

    stack()
        : top(0)
    {}
    
    stack(const stack& other) {
        for (int i = 0; i < STACK_SIZE; i++)
            data[i] = other.data[i];
    }
    
    /* Not a good implementation: push should signal a failure */
    void push(const T& value) {
        if (top < STACK_SIZE)
            data[top++] = value;
    }
    
    /* Not a good implementation: pop should signal a failure */
    T pop() {
        if (top > 0)
            return data[--top];

        return {};
    }

    bool empty() const {
        return (top == 0);
    }

    bool full() const {
        return (top == STACK_SIZE);
    }
};

struct meteo_data {
    std::string location;
    double      temperature;
    double      pressure;
};

int main(void)
{
    std::cout << "--- Stack of integers ---" << std::endl;
    stack<int> si;
    std::cout << "Is empty: " << std::boolalpha << si.empty() << "\n";
    std::cout << "Pushing 10 and 20\n";
    si.push(10);
    si.push(20);
    std::cout << si.pop() << "\n";
    std::cout << "Is empty: " << std::boolalpha << si.empty() << "\n";
    std::cout << si.pop() << "\n";
    std::cout << "Is empty: " << std::boolalpha << si.empty() << "\n";

    std::cout << "--- Stack of meteo_data ---" << std::endl;
    stack<meteo_data> sm;
    std::cout << "Is empty: " << std::boolalpha << sm.empty() << "\n";
    sm.push({"Torino", 25.1, 1013.0});
    sm.push({"Milano", 23.1, 1015.0});
    std::cout << "Is empty: " << std::boolalpha << sm.empty() << "\n";
    meteo_data md = sm.pop();
    std::cout << md.location << ", " << md.temperature << ", ";
    std::cout << md.pressure << std::endl;
    
    return 0;
}


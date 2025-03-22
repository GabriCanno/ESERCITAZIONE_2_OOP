#include <iostream>
#include <optional>

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
    
    /* Better implementation: push can notify a failure */
    bool push(const T& value) {
        if (top < STACK_SIZE) {
            data[top++] = value;
            return true;
        }

        return false;
    }
    
    /* Better implementation: pop can signal a failure by
     * returning an empty std::optional
     */
    std::optional<T> pop() {
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
    std::cout << "--- Stack of meteo_data ---" << std::endl;
    stack<meteo_data> sm;
    std::cout << "Is empty: " << std::boolalpha << sm.empty() << "\n";
    sm.push({"Torino", 25.1, 1013.0});
    sm.push({"Milano", 23.1, 1015.0});
    std::cout << "Is empty: " << std::boolalpha << sm.empty() << "\n";
    std::optional<meteo_data> mdo = sm.pop();
    if (mdo) {
        meteo_data md = mdo.value();
        std::cout << md.location << ", " << md.temperature << ", ";
        std::cout << md.pressure << std::endl;
    } else {
        std::cout << "Error: popped an empty stack" << std::endl;
        return 1;
    }
    
    return 0;
}


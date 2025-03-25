#include <iostream>
#include "complex.hpp"
 
int main() {
    complex_number<double> num1(1.0, 2.0);
    complex_number<double> num2(2.0, -3.0);

    std::cout << "Num1: " << num1 << std::endl;
    std::cout << "Num2: " << num2 << std::endl;

    complex_number<double> sum = num1 + num2;
    std::cout << "Somma: " << sum << std::endl;

    complex_number<double> product = num1 * num2;
    std::cout << "Prodotto: " << product << std::endl;

    complex_number<double> conjugate = num1.coniugato();
    std::cout << "Coniugato di " << num1 << " = " << conjugate << std::endl;

    return 0;
}

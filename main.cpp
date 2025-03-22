#include <iostream>

template<typename T>
class complex_number {    
public:
	T real;
    T imag;


	complex_number()   // costruttore di default
		: real(0), imag(0)
	{}
	
	complex_number (T r, T j)   // costruttore user defined
		: real(r), imag(j)
	{}

	T Re() const {      // parte reale
        return real;
    }

    T Im() const {      // parte immaginaria
        return imag;
    }

    complex_number<T> coniugato() const {    // coniugato
        return complex_number<T>(real, -imag);
    }

    
    complex_number<T>& operator+=(const complex_number<T>& other) {    //overload di +=
        real += other.real;
        imag += other.imag;
        return *this;
    }


    complex_number<T> operator+(const complex_number<T>& other) const {    // overload di + (in termini di +=)
        complex_number<T> result = *this;
        result += other;
        return result;
    }


    complex_number<T>& operator*=(const complex_number<T>& other) {     // overload di *=
        T newReal = real * other.real - imag * other.imag;
        T newImag = real * other.imag + imag * other.real;
        real = newReal;
        imag = newImag;
        return *this;
    }


    complex_number<T> operator*(const complex_number<T>& other) const {    // Overload dell'operatore * (in termini di *=)
        complex_number<T> result = *this;
        result *= other;
        return result;
    }
};


template<typename T>     // overload di <<
std::ostream& 
operator<<(std::ostream& os, const complex_number<T>& num) {
	os << num.real;	
	
	if (num.imag >= 0)
		os << "+" << num.imag << "i";
	else
		os << num.imag << "i";
	return os;
}


int main() {      // esempio
    complex_number<double> num1(1.0, 2.0);
    complex_number<double> num2(3.0, -2.0);

    std::cout << "Num1: " << num1 << std::endl;
    std::cout << "Num2: " << num2 << std::endl;

    complex_number<double> sum = num1 + num2;
    std::cout << "Somma: " << sum << std::endl;

    complex_number<double> product = num1 * num2;
    std::cout << "Prodotto: " << product << std::endl;

    complex_number<double> coniugato = num1.coniugato();
    std::cout << "Coniugato di " << num1 << " = " << coniugato << std::endl;

    return 0;
}

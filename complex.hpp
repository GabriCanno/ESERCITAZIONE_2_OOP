#pragma once

template<typename T>
class complex_number {    

	T real, imag;

public:

	explicit complex_number(T num)
	{
		real = num, imag = 0;
		std::cout << "Convertito in numero complesso dal convertitore \n";
	}
	
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

    // Overload dell'operatore +=
    complex_number& operator+=(const complex_number& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    // Overload dell'operatore + (in termini di +=)
    complex_number operator+(const complex_number& other) const { 
        complex_number result = *this;
        result += other;
        return result;
    }

    // Overload dell'operatore *=
    complex_number& operator*=(const complex_number& other) {
        T newReal = real * other.real - imag * other.imag;
        T newImag = real * other.imag + imag * other.real;
        real = newReal;
        imag = newImag;
        return *this;
    }

    // Overload dell'operatore * (in termini di *=)
    complex_number operator*(const complex_number& other) const {
        complex_number result = *this;
        result *= other;
        return result;
    }
	
	// Overload dell'operatore + nel caso di z2 non complesso
    complex_number operator+(const T non_compl) const { 
        return complex_number(real + non_compl, imag);
    }
	
	// Overload dell'operatore * nel caso di z2 non complesso
	complex_number operator*(const T non_c) const {
		return complex_number(real*non_c, imag*non_c);
	}
	
};

// Overload dell'operatore <<
template<typename T>
std::ostream& 
operator<<(std::ostream& os, const complex_number<T>& num) {	
	
	if (num.Re() == 0 && num.Im() == 0)
		os << 0 << "\n";
	else if (num.Re() == 0 && num.Im() > 0)
		os << num.Im() << "i";
	else if (num.Re() == 0 && num.Im() < 0)
		os << num.Im() << "i";
	else if (num.Re() != 0 && num.Im() == 0)
		os << num.Re();
	else if (num.Re() != 0 && num.Im() > 0)
		os << num.Re() << "+" << num.Im() << "i";
	else
		os << num.Re() << num.Im() << "i";
	return os;
}


// Overload di + nel caso di z1 non complesso
template<typename T>
complex_number<T>
operator+(const T& z1, const complex_number<T>& z2)
{
	return z2 + z1;
}


// Overload di * nel caso di z1 non complesso
template<typename T>
complex_number<T>
operator*(const T& z1, const complex_number<T>& z2)
{
	return z2 * z1;
}


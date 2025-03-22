#pragma once

/* Templates: recall that where you see `template<typename T>` you should
 * read `for all T`.
 * C++20 introduces a feature called "concepts", which in some way allows
 * you to put constraints on the universal quantifier. For example, when you
 * see
 *
 *      template<typename T> requires std::integral<T>
 *
 * you should read it as
 *
 *      for all T   such that   std::integral<T> is true
 *
 * In addition, std::integral<T> is true if and only if the type T is some
 * kind of integer (short, int, long...)
 */
  
/* This function computes the Greatest Common Divisor between two numbers.
 * GCD is defined only on integers, so we constrain I to be an integer
 * type (short, int, long, ...) */
template<typename I> requires std::integral<I>
I gcd(I a, I b) {
    if (b == 0)
       return a;

    return gcd(b, a%b);
}

/* A class modeling a rational number. Remember that a class is the same of
 * a struct but all of its members are private by default. */
template<typename I> requires std::integral<I>
class rational
{
    /* Private members */
    I m_num, m_den;
    
    /* Private method */
    void adjust_signs(void) {
        if (m_den >= 0)
            return;

        m_num = -m_num;
        m_den = -m_den;
	}
	
public:
    /* Default constructor */
    rational()
        : m_num(0), m_den(1)
    {}
    
    /* User-defined constructor. This is marked `explicit` to avoid
     * making a "converting constructor". Without `explicit`, if we
     * assign an object of type I (which is `int` in our case) to a
     * rational, the "converting constructor" gets called. Take a
     * look to the point (3) in rational.cpp.
     */
    explicit rational(I n)
        : m_num(n), m_den(1)
    {
        std::cout << "converting constructor called" << std::endl;
    }
    
    /* User-defined constructor. Takes two parameters, numerator and
     * denominator */
    rational(I n, I d)
        : m_num(n), m_den(d)
    {}
    
    /* Return the numerator. The `const` means that this function does
     * not modify the instance on which it is called.
     */
    I num(void) const {
        return m_num;
    }
    
    /* Return the denominator. The `const` means that this function does
     * not modify the instance on which it is called.
     */
    I den(void) const {
        return m_den;
    }
    
    /* Simplify, i.e. 3/6 -> 1/2 */
    void simplify(void) {
        I g = gcd(m_num, m_den);
        m_num /= g;
        m_den /= g;
        adjust_signs();
    }
    
    /* Define the += operator between rationals. When you do
     * 
     *  r1 += r2
     *
     * this function gets called. Notice that this function
     * takes only one parameter: we take the instance `other`
     * and we add it to the instance on which += is called.
     */
    rational& operator+=(const rational& other) {
        I a = m_num;
        I b = m_den;
        I c = other.m_num;
        I d = other.m_den;
        m_num = a*d + b*c;
        m_den = b*d;
        simplify();
        return *this;
	}
	
	/* Define operator+ in terms of operator +=. Notice that + does
	 * not modify the instance on which is called, therefore is marked
	 * const (the second const). */
	rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }

    /* Define the += operator between a rational on the left
     * and an I on the right. When you do
     * 
     *  r1 += i
     *
     * this function gets called. Notice that this function
     * takes only one parameter: we take the instance `other`
     * and we add it to the instance on which += is called.
     */
     rational& operator+=(const I& other) {
        m_num += other*m_den;
        simplify();
        return *this;
	}
	
	/* Define operator+ in terms of operator +=. Notice that + does
	 * not modify the instance on which is called, therefore is marked
	 * const (the second const). */
	rational operator+(const I& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }
    
    /* This is the UNARY minus. It computes the opposite: r2 = -r1; Notice
     * that the UNARY minus does not modify the instance on which is called,
     * therefore it is marked const.
     */
    rational operator-() const {
        return rational(-m_num, m_den);
    }
    
    /* Exercise: implement the BINARY minus */
    
    /* Comparison operator between rationals */
    bool operator<(const rational& other) const {
        I a = m_num;
		I b = m_den;
        I c = other.m_num;
        I d = other.m_den;

        return a*d < b*c;
	}
};

/* This operator is defined outside the rational class and is needed
 * to compute the sum of an I on the left and a rational<I> on the
 * right. */
template<typename I>
rational<I>
operator+(const I& i, const rational<I>& r)
{
    return r + i;
}

/* Free function (not member of rational) computing the absolute value
 * of a rational. Note how it uses the UNARY minus we implemented before
 */
template<typename I>
rational<I>
abs(const rational<I>& r) {
    if (r < rational<I>(0))
        return -r;

    return r;
}

/* Free function to compute the inverse of a rational */
template<typename I>
rational<I> inv(const rational<I>& r) {
    return rational<I>(r.den(), r.num());
}

/* Overload of <<, to make the rationals printable. */
template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r) {
    if (r.den() != 1)
        os << r.num() << "/" << r.den();
    else
        os << r.num();

    return os;
}


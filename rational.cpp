#include <iostream>
#include "rational.hpp"

/* TOPIC: Operator overloading. Documentation at the address
 *   https://en.cppreference.com/w/cpp/language/operators
 */


/* /!\ NOTE: THIS CODE MUST BE COMPILED IN C++20 MODE /!\
 * USE THE FOLLOWING COMMAND TO COMPILE:
 *
 *     g++ -std=c++20 -o rational rational.cpp
 */

int main(void) {
    using rat = rational<int>;
    
    rat r1(1,3);
    rat r2(1,6);
    
    /* (1) Remember rational is a class: we are not allowed to access
     * its members, therefore if you try to access r1.m_num or r1.m_den
     * you will get an error.
     * Try to uncomment the following code and see what happens:
     */ 
     
    //std::cout << r1.m_num << std::endl;
    
    /* (2) Thanks to operator overloading, operations on rationals are
     * possible. Not only: as we overloaded also the stream insertion
     * operator, rationals are printed like all the other C++ basic
     * types. Try to comment the whole definition of operator<< in
     * rational.hpp and see what happens.
     */
     
    std::cout << r1 << " + " << r2 << " = " << r1+r2 << std::endl;
    rat r3 = r1+r2;
    std::cout << "The inverse of " << r3 << " is " << inv(r3) << "; ";
    std::cout << "its opposite is " << -r3 << std::endl; 
    
    /* (3) Converting constructors: traditionally, one-parameter constructors
     * not marked explicit and which are not the copy constructors are called 
     * "converting constructors". See this page:
     *    https://en.cppreference.com/w/cpp/language/converting_constructor
     * Sometimes converting constructors have unintended consequences,
     * therefore you should be aware of the keyword `explicit`. If the
     * constructor taking a single `int` parameter is *not* marked `explicit`
     * and you do something like
     *
     *  rat r4 = 7;
     *
     * the effect is exactly the same as
     *
     *  rat r4(7);
     *
     * Uncomment the following code and try to compile it before and after
     * removing the keyword `explicit` from the single-parameter constructor
     * of rational.
     */
    
    //rat r4 = 7;
    

    /* (4) Commutative property in operations. Operators defined inside the
     * classes/structs take only one parameter, which is the right operand of
     * the operation. The left operand is implicit and is the current instance.
     * Operators defined outside the classes on the other hand, take two
     * parameters, which are the left and the right operands of the operation.
     *
     * When (for example) the sum is made between two rational<I>, defining the
     * operator inside the class poses no issue. Also if the sum is beetwen a
     * rational<I> and an I there is no problem, because the right operand can
     * have the type we want. But what happens if we want to sum an I and a rational<I>?
     */

    /* To do this sum, the operator+ defined INSIDE the class gets called */
    rat r5 = rat(3,4) + 2;
    std::cout << "3/4 + 2 = " << r5 << std::endl;

    /* To do this sum, the operator+ defined OUTSIDE the class gets called.
     * Try to comment it in the rational.hpp file and see what happens when
     * the code is compiled. */
    rat r6 = 3 + rat(5,8);
    std::cout << "3 + 5/8 = " << r6 << std::endl;
    
    return 0;
}

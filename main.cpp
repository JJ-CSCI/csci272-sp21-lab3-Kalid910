//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
#include "csci373.h"
using namespace std;
using Catch::Matchers::Equals;
//------------------------------

//------------------------------
//  DO NOT MODIFY RING CLASS
//------------------------------
class Ring {
public:
    virtual ~Ring() {}
    // a heap-allocated copy of this element
    virtual Ring* copy() const = 0;
    // the string representation of this element
    virtual std::string str() const = 0;
    // the constant of the type of this element and the inverse of this element
    virtual Ring* zero() const = 0;
    virtual Ring* operator-() const = 0; // unary operator
    // sum and product of this element and c
    virtual Ring* operator+(Ring* c) const = 0;
    virtual Ring* operator*(Ring* c) const = 0;
    // comparison function
    virtual bool operator==(Ring* c) const = 0;
};

//--------------------------------
// Implement the following classes
//--------------------------------
class Integer: public Ring {
long n;
public:
    // integer with value n (default 0)
    Integer(long n = 0) : n{n} {}

    Ring * copy() const {
        return new Integer(n);
    }

    std::string str() const {
        return std::to_string(n);
    }
    Ring* zero() const {
        return new Integer(0);
    }
    Ring* operator-() const {
        return new Integer(n * -1);
    }
    
    Ring* operator+(Ring * c) const {
        return new Integer(this->n + dynamic_cast<Integer*>(c)->n);
    }
    Ring * operator*(Ring * c) const {
        return new Integer(this->n * dynamic_cast<Integer*>(c)->n);
    }
    bool operator==(Ring * c) const {
       return (this->n == dynamic_cast<Integer*>(c)->n);
    }
};

class Polynomial {
    int dim;
    Ring** coeffs;
public:
    // polynomial with n>=0 coefficients
    Polynomial(int n, Ring** cs) {
        dim = n;
        coeffs = new Ring*[n];

        for (unsigned int i = 0; i < n; i++) {
            coeffs[i] = cs[i]->copy();
        }
    }
    virtual ~Polynomial() {
        for (unsigned int i = 0; i < dim; i++) {
            delete coeffs[i];
        }

        delete [] coeffs;
    }
    // evaluate this polynomial on c
    Ring* eval(Ring* c) {
        return nullptr;
    }
    // the string representation of the polynomial
    std::string str() const {
        string solution = "";
        for (unsigned int i = dim - 1; i >= 0; i--) {
                if (coeffs[i]->str() != "0") {
                    solution += coeffs[i]->str();
                    if (i != 0) {
                        solution += "x^" + i;
                    }
                    if (i != dim - 1 && i != 0) {
                        solution += " + ";
                    }
            }
        }
        return solution;
    }
};


//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    // Define polynomial coefficients
    Ring* ii[] = { new Integer(-5), new Integer(2), new Integer(0), new Integer(-3) };

    SECTION( "a1" ) {
        // start tracking memory usage
        csci373::allocation_table.start_recording();

        // create polynomial object
        Polynomial* p = new Polynomial(4, ii);

        // deallocate polynomial object
        delete p;

        // stop tracking memory usage
        csci373::allocation_table.stop_recording();

        // all memory was clearedd
        REQUIRE( csci373::allocation_table.memory_alloc() == 0 );
        csci373::allocation_table.reserve(128);
    }

    SECTION( "b1" ) {
        // start tracking memory usage
        csci373::allocation_table.start_recording();

        try {
            // create polynomial object
            Polynomial* p = new Polynomial(4, ii);

            // test string output
            REQUIRE_THAT( p->str(), Equals("-3x^3+2x^1+-5") );

            // deallocate polynomial object
            delete p;

            // stop tracking memory usage
            csci373::allocation_table.stop_recording();

            // all memory was clearedd
            REQUIRE( csci373::allocation_table.memory_alloc() == 0 );
            csci373::allocation_table.reserve(128);
        } catch (...) {
            // stop tracking memory usage
            csci373::allocation_table.stop_recording();
            // rethrow exception
            throw;
        }
    }

    SECTION( "c1" ) {
        // start tracking memory usage
        csci373::allocation_table.start_recording();

        try {
            // create polynomial object
            Polynomial* p = new Polynomial(4, ii);

            // evaluate polynomial
            Integer* val = new Integer(5);
            Integer* answer = new Integer(-370);
            Integer* result = dynamic_cast<Integer*>(p->eval(val));
            REQUIRE( (*result) == answer );

            // deallocate allocated objects
            delete p; delete answer; delete val; delete result;

            // stop tracking memory usage
            csci373::allocation_table.stop_recording();

            // all memory was clearedd
            REQUIRE( csci373::allocation_table.memory_alloc() == 0 );
        } catch (...) {
            // stop tracking memory usage
            csci373::allocation_table.stop_recording();
            // rethrow exception
            throw;
        }
    }

    // Delete polynomial coefficients
    for(auto &i : ii) delete dynamic_cast<Integer*>(i);
}

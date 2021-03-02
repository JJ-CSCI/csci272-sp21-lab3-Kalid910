//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
#include <iostream>
//------------------------------
using namespace std;

// Put the assignment code here

class Quaternion {
private:
    double a, b, c, d;

public: 

    Quaternion(double one, double two, double three, double four) {
        a = one;
        b = two;
        c = three;
        d = four;
    }

     bool operator==(const Quaternion& q) const {
        return ((getA() == q.getA()) && (getB() == q.getB()) && (getC() == q.getC()) && (getD() == q.getD()));
    }
    
     Quaternion operator+(const Quaternion& q) const {
        Quaternion newQ(getA() + q.getA(), getB() + q.getB(), getC() + q.getC(), getD() + q.getD());
        return newQ;
    }

     Quaternion operator-(const Quaternion& q) const {
        Quaternion newQ(getA() - q.getA(), getB() - q.getB(), getC() - q.getC(), getD() - q.getD());
        return newQ;
    }

     Quaternion operator*(const double val) const {
        Quaternion newQ(getA() * val, getB() * val, getC() * val, getD() * val);
        return newQ;
    }

    double getA() const {
        return a;
    }
    
    double getB() const {
        return b;
    }

    double getC() const {
        return c;
    }

    double getD()  const {
        return d;
    }


};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "q1" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        REQUIRE( q == p );
    }
    SECTION( "q2" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        Quaternion r{2.0, 4.0, 6.0, 8.0};
        REQUIRE( (q + p) == r );
    }
    SECTION( "q3" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion p{1.0, 2.0, 3.0, 4.0};
        Quaternion r{0.0, 0.0, 0.0, 0.0};
        REQUIRE( (q - p) == r );
    }
    SECTION( "q3" ) {
        Quaternion q{1.0, 2.0, 3.0, 4.0};
        Quaternion r{2.0, 4.0, 6.0, 8.0};
        REQUIRE( (q * 2.0) == r );
    }
}
//------------------------------

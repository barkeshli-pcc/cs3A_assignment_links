#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
#include "../../includes/poly/poly.h"
#include "../../includes/array_functions/array_functions.h"
using namespace std;
bool stub(bool debug = false){
  return true;
}

bool basic_test(bool debug = false){
  double coefs1[] = {8.0,5.0,6.0,0.0,4.0};
  double coefs2[] = {2.0,7.0,3.0,0.0, 1.0, 9.0};
  Poly p(coefs1, 4);
  Poly q(coefs2, 5);
  cout << "p: " << p << endl;
  cout << "q: " << q << endl;
  cout << "--------------------------------" << endl;
  cout << "p + q   : " << p + q << endl;
  cout << "p - q   : " << p - q << endl;
  cout << "p * q   : " << p * q << endl;
  cout << "p / q   : " << p / q << endl;
  cout << "p % q   : " << p % q << endl;
  cout << "q / p   : " << q / p << endl;
  cout << "q % p   : " << q % p << endl;
  cout << endl;
  cout << "(p+q) - p == q? " << boolalpha << ((p + q) - p == q) << endl;
  cout << "        p != q? " << boolalpha << (p != q) << endl;
  cout << "        p != p? " << boolalpha << (p != p) << endl;
  double *c = p.get_coefs();
  cout << "        p.order(): " << p.order() << endl;

  double coefs3[] = {0.0,0.0,0.0,4.0,5.0,0.0,0.0};
  Poly r(coefs3, 6);
  cout << "r: " << r << endl;
  cout << "r.order(): " << r.order() << endl;
  r.fix_order(); //should be called from the object
  cout << "r.fixorder(): " << r << endl;

  cout
      << "\n\n---------------- D O N E -------------" << endl;
  return true;
}
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 
//Lord help me! 
bool debug = false;
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 

TEST(TEST_BASIC_TEST, BasicTest) {
  bool success = basic_test(debug);
  EXPECT_EQ(success, true);
}


int main(int argc, char **argv) {
  if (argc>1){
    debug = argv[1][0]=='t';
  }
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}




/*

includes
├── array_functions
│   └── array_functions.h
└── poly
    ├── poly.cpp
    ├── poly.h
    ├── term.cpp
    └── term.h




----------running basic_test.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TEST_BASIC_TEST
[ RUN      ] TEST_BASIC_TEST.BasicTest
p: [+4.0X^4 +0.0X^3 +6.0X^2 +5.0X +8.0 ]
q: [+9.0X^5 +1.0X^4 +0.0X^3 +3.0X^2 +7.0X +2.0 ]
--------------------------------
p + q   : [+9.0X^5 +5.0X^4 +0.0X^3 +9.0X^2 +12.0X +10.0 ]
p - q   : [-9.0X^5 +3.0X^4 +0.0X^3 +3.0X^2 -2.0X +6.0 ]
p * q   : [+36.0X^9 +4.0X^8 +54.0X^7 +63.0X^6 +105.0X^5 +34.0X^4 +57.0X^3 +71.0X^2 +66.0X +16.0 ]
p / q   : [+0.0 ]
p % q   : [+4.0X^4 +0.0X^3 +6.0X^2 +5.0X +8.0 ]
q / p   : [+2.2X +0.2 ]
q % p   : [-13.5X^3 -9.8X^2 -12.2X +0.0 ]

(p+q) - p == q? true
        p != q? true
        p != p? false
        p.order(): 4
r: [+5.0X^4 +4.0X^3 +0.0X^2 +0.0X +0.0 ]
r.order(): 4
r.fixorder(): [+5.0X^4 +4.0X^3 +0.0X^2 +0.0X +0.0 ]


---------------- D O N E -------------
[       OK ] TEST_BASIC_TEST.BasicTest (0 ms)
[----------] 1 test from TEST_BASIC_TEST (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.
➜  build git:(begin_submodule) ✗ 

*/



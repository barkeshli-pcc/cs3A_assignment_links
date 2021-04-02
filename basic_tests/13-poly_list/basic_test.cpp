#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
using namespace std;

#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include "../../includes/list_sorted/list_sorted.h"
#include "../../includes/poly_list/poly.h"
//------------------------------------------------------------------------------------------
//Files we are testing:
bool basic_test(bool debug = false){
  double coefs1[] = {2.0,0.0,0.0,2.0,4.0,0.0,5.0};
  double coefs2[] = {3.0, 4.0, 5.0, 6.0};
  Poly p(coefs1, 6);
  Poly q(coefs2, 3);
  Poly r;
  cout << "p: " << p << endl;
  cout << "q: " << q << endl;
  cout << "----------------------------------" << endl;
  cout << "p + q: " << p + q << endl;
  cout << "p - q: " << p - q << endl;
  cout << "p * q: " << p * q << endl;
  cout << "p / q: " << p / q << endl;
  cout << "p % q: " << p % q << endl;
  cout << "q / p: " << p / q << endl;
  cout << "q % p: " << p % q << endl;
  cout << "p != p: " << boolalpha << (p != p) << endl;
  cout << "(p+q)-q == p? " << boolalpha<<((p+q)-q==p) << endl;
  cout << "10.0/3 == 20.0/6: " << boolalpha << double_equals(10.0 / 3, 20.0 / 6) << endl;
  cout << "\n\n-------- DONE ---------\n\n"
       << endl;
  return true;
}
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 
//Lord help me! 
bool debug = false;
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 


TEST(BASIC_TEST, BasicTest) {
  bool success = basic_test(debug);
  EXPECT_EQ(success, true);
}




int main(int argc, char **argv) {
  if (argc>1){
    debug = argv[1][0]=='t';
  }
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testA.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}



/*

build git:(master) ✗  😊 $> tree ../includes
../includes
├── linked_list_functions
│   └── linked_list_functions.h
├── list_sorted
│   └── list_sorted.h
├── node
│   └── node.h
└── poly_list
    ├── poly.cpp
    ├── poly.h
    ├── term.cpp
    └── term.h

4 directories, 7 files
build git:(master) ✗  😊 $> ./bin/basic_test


----------running testA.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from BASIC_TEST
[ RUN      ] BASIC_TEST.BasicTest
p: +5.0X^6 +4.0X^4 +2.0X^3 +2.0 : [6]
q: +6.0X^3 +5.0X^2 +4.0X +3.0 : [3]
----------------------------------
p + q: +5.0X^6 +4.0X^4 +8.0X^3 +5.0X^2 +4.0X +5.0 : [6]
p - q: +5.0X^6 +4.0X^4 -4.0X^3 -5.0X^2 -4.0X -1.0 : [6]
p * q: +30.0X^9 +25.0X^8 +44.0X^7 +47.0X^6 +26.0X^5 +20.0X^4 +18.0X^3 +10.0X^2 +8.0X +6.0 : [9]
p / q: +0.8X^3 -0.7X^2 +0.7X -0.2 : [3]
p % q: +0.3X^2 -1.3X +2.6 : [2]
q / p: +0.8X^3 -0.7X^2 +0.7X -0.2 : [3]
q % p: +0.3X^2 -1.3X +2.6 : [2]
p != p: false
(p+q)-q == p? true
10.0/3 == 20.0/6: true


-------- DONE ---------


[       OK ] BASIC_TEST.BasicTest (1 ms)
[----------] 1 test from BASIC_TEST (1 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (1 ms total)
[  PASSED  ] 1 test.
build git:(master) ✗  😊 $> 

*/






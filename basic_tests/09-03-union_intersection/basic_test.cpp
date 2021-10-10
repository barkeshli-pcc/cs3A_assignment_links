#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>

#include "../../includes/set/set.h"
/*
array_print();
array_union();
intersection();
*/
using namespace std;


bool test_basic_union_intersection(bool debug = false){
  int a[] = {0, 2, 4, 6, 8, 9};  //6
  int b[] = {0, 1, 2, 3, 8, 9, 10}; //7

  cout << "           a: ";
  array_print(a, 6);
  cout << "           b: ";
  array_print(b, 7);

  
  int size = 0;
  int c[20];
  array_union(a, 6, b, 7, c, size);
  cout << "       union: ";
  array_print(c, size);

  intersection(a, 6, b, 7, c, size);
  cout << "intersection: ";
  array_print(c, size);

  cout << "----- end of function --------" << endl;
  
  return true;
}

TEST(TEST_BASIC, TestBasic){
  bool success =test_basic_union_intersection();
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n---------- running basic_test ---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


/*

includes
├── set
    ├── set.cpp
    └── set.h



---------- running basic_test ---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TEST_BASIC
[ RUN      ] TEST_BASIC.TestBasic
           a: 0. 2. 4. 6. 8. 9. 
           b: 0. 1. 2. 3. 8. 9. 10. 
       union: 0. 1. 2. 3. 4. 6. 8. 9. 10. 
intersection: 0. 2. 8. 9. 
----- end of function --------
[       OK ] TEST_BASIC.TestBasic (0 ms)
[----------] 1 test from TEST_BASIC (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.*/
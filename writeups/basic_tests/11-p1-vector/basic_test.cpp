#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
#include "../../includes/vector/vector_class.h"

using namespace std;
bool stub(bool debug = false){
  return true;
}
bool test_vector(bool debug = false){
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  Vector<int> v(a, 10);
  cout << v << endl;
  v[0] = 100;
  cout << v << endl;
  v.at(1) = 101;
  cout << v << endl;
  v.front() = 1000;
  v.back() = 99;
  cout << v << endl;
  v += 10;
  cout << v << endl;
  v.insert(3, 300);
  cout << v << endl;
  v.erase(5);
  cout << v << endl;
  cout << "8 is at index: [" << v.index_of(8) << "]"<<endl;
  cout << "vector size is now: " << v.size() << endl;
  cout << "vector capacity is now: " << v.capacity() << endl;
  v += 12;
  v += 13;
  cout << "vector capacity is now: " << v.capacity() << endl;
  cout << v << endl;
  cout << "vector is empty: " << boolalpha << v.empty() << endl;
  cout << "\n\n-------- D O N E -------------\n" << endl;
  return true;
}
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 
//Lord help me! 
bool debug = false;
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 

TEST(TEST_BASIC_TEST, BasicTest) {
  bool success = test_vector(debug);
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
├── add_entry
│   └── add_entry.h
├── array_functions
│   └── array_functions.h
└── vector
    └── vector_class.h


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TEST_BASIC_TEST
[ RUN      ] TEST_BASIC_TEST.BasicTest
(10/12) [    0     1     2     3     4     5     6     7     8     9 ]

(10/12) [  100     1     2     3     4     5     6     7     8     9 ]

(10/12) [  100   101     2     3     4     5     6     7     8     9 ]

(10/12) [ 1000   101     2     3     4     5     6     7     8    99 ]

(11/12) [ 1000   101     2     3     4     5     6     7     8    99    10 ]

(12/12) [ 1000   101     2   300     3     4     5     6     7     8    99    10 ]

(11/12) [ 1000   101     2   300     3     5     6     7     8    99    10 ]

8 is at index: [8]
vector size is now: 11
vector capacity is now: 12
vector capacity is now: 24
(13/24) [ 1000   101     2   300     3     5     6     7     8    99    10    12    13 ]

vector is empty: false


-------- D O N E -------------

[       OK ] TEST_BASIC_TEST.BasicTest (0 ms)
[----------] 1 test from TEST_BASIC_TEST (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (1 ms total)
[  PASSED  ] 1 test.
➜  build git:(master) ✗ 


*/





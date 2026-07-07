#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>


//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/delete_repeats/delete_repeats.h"
#include "../../includes/array_functions/array_functions.h"


//------------------------------------------------------------------------------------------

using namespace std;

bool test_delete_repeat(){
  char a[20] = "aababcabcdabcdef";
  int size = strlen(a);
  cout << "\n\noriginal list: ";
  print_array(a, size);
  cout << endl;

  delete_repeats(a, size);
  cout << "\n\nunique values: ";
  print_array(a, size);
  cout << endl;

  int b[30] = {0,1,1,2,1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,4,5};
  size = 21;
  cout << "\n\noriginal list: ";
  print_array(b, size);
  cout << endl;

  delete_repeats(b, size);
  cout << "\n\nunique values: ";
  print_array(b, size);
  cout << endl;


  return true;
}
TEST(TEST_DELETE_REPEATS, TestDeleteRepeat) {
  bool success = test_delete_repeat();
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


/*
includes
├── array_functions
│   └── array_functions.h
└── delete_repeats
    └── delete_repeats.h


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TEST_DELETE_REPEATS
[ RUN      ] TEST_DELETE_REPEATS.TestDeleteRepeat


original list: (16) [    a     a     b     a     b     c     a     b     c     d     a     b     c     d     e     f ]



unique values: (6) [    a     b     c     d     e     f ]



original list: (21) [    0     1     1     2     1     2     3     1     2     3     4     1     2     3     4     5     1     2     3     4     5 ]



unique values: (6) [    0     1     2     3     4     5 ]

[       OK ] TEST_DELETE_REPEATS.TestDeleteRepeat (0 ms)
[----------] 1 test from TEST_DELETE_REPEATS (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (1 ms total)
[  PASSED  ] 1 test.



*/

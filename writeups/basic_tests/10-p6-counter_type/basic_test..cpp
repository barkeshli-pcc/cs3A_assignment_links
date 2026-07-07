#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>

#include "../../includes/counter_type/counter_type.h"

using namespace std;
bool stub(bool debug = false){
  return true;
}
bool basic_test_counter_type(bool debug = false){
  cout << "\n\nInstantiation: " << endl;
  Counter_Type c(5);
  cout <<"*count: "<< c.count() << endl;
  
  cout << "\nincrementing: " << endl;
  for (int i = 0; i < 5; i++){
    c.inc();
    cout << "+count: " << c.count() << ", is_error: " << c.is_error()<< endl;
  }
  
  cout << "\ndecrementing: " << endl;
  c.dec();
  while (!c.is_error()){
    cout << "-count: " << c.count() << ", is_error: " << c.is_error()<< endl;
    c.dec();
  }
  
  cout << "\nAfter the loop: " << endl;
  cout << "count: " << c.count() << ", is_error: " << c.is_error()<< endl;
  
  cout << "\nresetting: " << endl;
  c.reset();
  cout << "count: " << c.count() << ", is_error: " << c.is_error() << endl;
  cout << "\n\n--------------- D O N E ---------------" << endl;
  return true;
}
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 
//Lord help me! 
bool debug = false;
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 

TEST(TEST_BASIC_TEST, BasicTest) {
  bool success = basic_test_counter_type(debug);
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
10_e3_counter_type git:(master)  😊 $> tree  includes
includes
└── counter_type
    ├── counter_type.cpp
    └── counter_type.h

1 directory, 2 files



----------running basic_test.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TEST_BASIC_TEST
[ RUN      ] TEST_BASIC_TEST.BasicTest


Instantiation: 
*count: 5

incrementing: 
+count: 6, is_error: 0
+count: 7, is_error: 0
+count: 8, is_error: 0
+count: 9, is_error: 0
+count: 10, is_error: 0

decrementing: 
-count: 9, is_error: 0
-count: 8, is_error: 0
-count: 7, is_error: 0
-count: 6, is_error: 0
-count: 5, is_error: 0
-count: 4, is_error: 0
-count: 3, is_error: 0
-count: 2, is_error: 0
-count: 1, is_error: 0
-count: 0, is_error: 0

After the loop: 
count: 0, is_error: 1

resetting: 
count: 0, is_error: 0


--------------- D O N E ---------------
[       OK ] TEST_BASIC_TEST.BasicTest (0 ms)
[----------] 1 test from TEST_BASIC_TEST (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.
build git:(master)  😊 $> 




*/
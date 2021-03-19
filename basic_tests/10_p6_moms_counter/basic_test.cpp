#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>

#include "../../includes/mcounter/mcounter.h"

using namespace std;
bool stub(bool debug = false){
  return true;
}
bool basic_test_mcounter(bool debug = false){

  MCounter m;
  cout << "count after add 1:     " << m.add_1() << endl;
  cout << "count after add 10:    " << m.add_10() << endl;
  cout << "count after add 100:   " << m.add_100() << endl;
  cout << "count after add 1000:  " << m.add_1000() << endl;
  cout <<"count: "<< m.count() << endl;
  if (m.error()){
    cout << "an error occured: " << endl;
  }
  else{
    cout << "no error yet" << endl;
  }

  cout << "error state: " << boolalpha << m.error() << endl;
  cout << endl;
  for (int i = 0; i < 20 && !m.error(); i++)
  {
    cout << "adding another 1000: " << m.add_1000() << endl;
    if (m.error()){
      cout << "an error occured: " << endl;
    }
    else{
      cout << "no error yet" << endl;
    }
  }
  cout << endl;
  cout << "error state: " << boolalpha << m.error() << endl;
  cout << "adding another 1000: " << m.add_1000() << endl;
  m.reset();
  cout << endl;
  cout << "counter reset: " << m.count() << endl;
  cout << "error state: " << boolalpha << m.error() << endl;
  cout << "\n\n--------------- D O N E ---------------" << endl;
  return true;
}
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 
//Lord help me! 
bool debug = false;
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 

TEST(TEST_BASIC_TEST, BasicTest) {
  bool success = basic_test_mcounter(debug);
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
build git:(master) ✗  😊 $> tree ../includes
../includes
└── mcounter
    ├── mcounter.cpp
    └── mcounter.h

1 directory, 2 files
build git:(master) ✗  😊 $> ./bin/basic_test 


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TEST_BASIC_TEST
[ RUN      ] TEST_BASIC_TEST.BasicTest
count after add 1:     1
count after add 10:    11
count after add 100:   111
count after add 1000:  1111
count: 1111
no error yet
error state: false

adding another 1000: 2111
no error yet
adding another 1000: 3111
no error yet
adding another 1000: 4111
no error yet
adding another 1000: 5111
no error yet
adding another 1000: 6111
no error yet
adding another 1000: 7111
no error yet
adding another 1000: 8111
no error yet
adding another 1000: 9111
no error yet
adding another 1000: -9999
an error occured: 

error state: true
adding another 1000: -9999

counter reset: 0
error state: false


--------------- D O N E ---------------
[       OK ] TEST_BASIC_TEST.BasicTest (0 ms)
[----------] 1 test from TEST_BASIC_TEST (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.
build git:(master) ✗  😊 $> 
*/
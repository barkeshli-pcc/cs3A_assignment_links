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

➜  build git:(master) ✗ ./bin/basic_test true


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TEST_LAB_N_PLANE
[ RUN      ] TEST_LAB_N_PLANE.BasicTest


----- basic_test_lab_n_plane(): 
sizes:     3    4    5    1    3
    0    0    0
    0    0    0    0
    0    0    0    0    0
    0
    0    0    0

logging in lab: 2, station 1: 
    0    0    0
    0    0    0    0
    0 1234    0    0    0
    0
    0    0    0

write labs[0][2] <- 99: 
    0    0   99
    0    0    0    0
    0 1234    0    0    0
    0
    0    0    0

get_twod(4,2) <- 33: 
    0    0   99
    0    0    0    0
    0 1234    0    0    0
    0
    0    0   33

reading labs[4][2]: 33

get(0,2): 99

found 33 at: [4][2]

loggin out id: 1234
    0    0   99
    0    0    0    0
    0    0    0    0    0
    0
    0    0   33

Deallocating two-d array 'labs' 


---------- D O N E ----------
[       OK ] TEST_LAB_N_PLANE.BasicTest (4 ms)
[----------] 1 test from TEST_LAB_N_PLANE (4 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (4 ms total)
[  PASSED  ] 1 test.
➜  build git:(master) ✗ 


*/
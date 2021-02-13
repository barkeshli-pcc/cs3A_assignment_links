#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>

#include "../../includes/lab/lab.h"

using namespace std;


bool basic_test_lab_n_plane(bool debug = false){
  int sizes[] = {3,4,5,1,3,-1};
  int **labs = allocate_twod<int>(sizes);
  int id = 1234;
  if (debug){
    cout << "\n\n----- basic_test_lab_n_plane(): " << endl;
    cout << "sizes: ";
    print_array(sizes);
  }

  init_twod(labs, sizes);
  print_twod(labs, sizes);
  
  cout << "\nlogging in lab: 2, station 1: " << endl;
  login(labs, 2, 1, id); //lab 2, station 1
  print_twod(labs, sizes);

  cout << "\nwrite labs[0][2] <- 99: " << endl;
  write_twod(labs, 0, 2, 99);
  print_twod(labs, sizes);
  
  cout << "\nget_twod(4,2) <- 33: " << endl;
  get_twod(labs, 4, 2) = 33;
  print_twod(labs, sizes);
  
  cout << "\nreading labs[4][2]: " << read_twod(labs, 4, 2) << endl;
  
  cout << "\nget(0,2): " << get_twod(labs, 0, 2) << endl;
  int row, col;
  bool found = search_twod(labs, sizes, 33, row, col);
  if (found){
    cout << "\nfound 33 at: [" << row << "][" << col << "]" << endl;
  }
  
  cout << "\nloggin out id: 1234" << endl;
  logout(labs, sizes, id);
  print_twod(labs, sizes);

  cout << "\nDeallocating two-d array 'labs' " << endl;
  int size = array_size(sizes);
  deallocate_twod(labs, size);
  cout << "\n\n---------- D O N E ----------" << endl;
  return true;
}

//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 
//Lord help me! 
bool debug = false;
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 

TEST(TEST_LAB_N_PLANE, BasicTest) {
  bool success = basic_test_lab_n_plane(debug);
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
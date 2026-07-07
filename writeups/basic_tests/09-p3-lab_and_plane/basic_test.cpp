#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>

#include "../../includes/lab/lab.h"
#include "../../includes/plane/plane.h"
#include "../../includes/two_d_functions/two_d_functions.h"

using namespace std;

bool basic_test_two_d_array(bool debug = false){
  int sizes[] = {4,5,3,6,-1};
  int **td = allocate_twod<int>(sizes);
  init_twod(td, sizes, -1);
  print_twod(td, sizes);
  write_twod(td, 0, 3, 3);
  write_twod(td, 1, 4, 14);
  write_twod(td, 3, 1, 31);
  cout << endl;
  print_twod(td, sizes);
  
  cout << endl;
  cout << "[0][3]: " << read_twod(td, 0, 3)<<endl;
  cout << "[1][4]: " << read_twod(td, 1, 4)<<endl;
  cout << "[3][1]: " << read_twod(td, 3, 1)<<endl;
  get_twod(td, 3, 4)= 34;
  cout << "[3][4]: "<<get_twod(td, 3, 4) << endl;
  int row, col;
  bool found = search_twod(td, sizes, 31, row, col);
  if (found){
    cout << "\nfound 33 at: [" << row << "][" << col << "]" << endl;
  }

  bool valid;
  row = 3;
  col = 4;
  valid = index_is_valid(sizes, row, col);
  if (valid){
    cout << "td[" << row << "][" << col << "] is a valid location." << endl;
  }
  else{
    cout << "td[" << row << "][" << col << "] is NOT a valid location." << endl;
  }

  row = 13;
  col = 4;
  valid = index_is_valid(sizes, row, col);
  if (valid){
    cout << "td[" << row << "][" << col << "] is a valid location." << endl;
  }
  else{
    cout << "td[" << row << "][" << col << "] is NOT a valid location." << endl;
  }

  row = 3;
  col = 14;
  valid = index_is_valid(sizes, row, col);
  if (valid){
    cout << "td[" << row << "][" << col << "] is a valid location." << endl;
  }
  else{
    cout << "td[" << row << "][" << col << "] is NOT a valid location." << endl;
  }

  td = deallocate_twod(td, 4); //4 rows

  cout << "---- end test two d functions ----------" << endl;
  return true;
}

bool basic_test_lab(bool debug = false){
  int stations[] = {3,4,5,1,3,-1};
  if (debug){
    cout << "\n\n----- basic_test_lab(): " << endl;
    cout << "stations: ";
    print_array(stations);
  }

  int** labs = init_lab(stations);
  print_twod(labs, stations);
  int lab;
  int station;
  int id;
  cout << "================ test login() =====================" << endl;

  lab = 2;
  station = 1;
  id = 2121;
  cout << "\nlogging in lab: <<lab<<, station <<station<<: " << endl;
  login(labs, lab, station, id); 
  print_twod(labs, stations);

  lab = 4;
  station = 2;
  id = 4242;
  cout << "\nlogging in lab: <<lab<<, station <<station<<: " << endl;
  login(labs, lab, station, id); 
  print_twod(labs, stations);

  lab = 4;
  station = 2;
  id = 6666;
  cout << "\nlogging in lab: <<lab<<, station <<station<<: " << endl;
  if(login(labs, lab, station, id)){
    cout << "FAILED: logged in (" << id << ") into an occupied  station" << endl;
  }
  else{
    cout << "login() correctly refused to log in a new user into "
          <<"an already occupied station" << endl;
  }
  print_twod(labs, stations);

  cout << "================ test login() =====================" << endl;
  
  id = 6666;
  cout << "\nlogging out user : "<<id << endl;
  if(logout(labs, stations, id)){ 
    cout << "FAILED: logged out (" << id << ") who was not logged in!" << endl;
  }
  else{
    cout << "logout() correctly refused to log out a user who was not logged in." << endl;
  }
  print_twod(labs, stations);

  id = 4242;
  cout << "\nlogging out user: "<<id << endl;
  logout(labs, stations, id); 
  print_twod(labs, stations);

  cout << "\nDeallocating two-d array 'labs' " << endl;
  int size = array_size(stations);
  labs = deallocate_twod(labs, size);
  cout << "\n\n---------- D O N E ----------" << endl;
  return true;
}
bool basic_test_plane(bool debug = false){

  bool** plane = init_plane();
  print_plane(plane);
  int row;
  int seat;
  cout << "\n\n============ test reserve() =======================" << endl;
  row  = 0;
  seat = 0;
  cout << "\nreserved "<<row+1<<char('A'+seat)<< "(["<<row<<"]["<<seat<<"]" << endl;
  reserve(plane, row, seat); 
  print_plane(plane);

  row  = 3;
  seat = 2;
  cout << "\nreserved "<<row+1<<char('A'+seat)<< "(["<<row<<"]["<<seat<<"]" << endl;
  reserve(plane, row, seat); 
  print_plane(plane);

  row  = 6;
  seat = 3;
  cout << "\nreserved "<<row+1<<char('A'+seat)<< "(["<<row<<"]["<<seat<<"]" << endl;
  reserve(plane, row, seat); 
  print_plane(plane);

  row  = 6;
  seat = 3;
  cout << "\nreserved "<<row+1<<char('A'+seat)<< "(["<<row<<"]["<<seat<<"]" << endl;
  if(reserve(plane, row, seat)){
    cout << "  FAIL: this seat was occupied!" << endl;
  }
  else{
    cout<<"   reserve() correctly refused to reserve an already occupied seat."<<endl;
  }
  print_plane(plane);
  cout << "\n\n============ test cancel() =======================" << endl;
  row = 3;
  seat = 3;
  cout << "\ncancelled "<<row+1<<char('A'+seat)<< "(["<<row<<"]["<<seat<<"]" << endl;
  if(cancel(plane, row, seat)){
    cout << "  FAIL: this seat was not occupied, but canceled!" << endl;
  }
  else{
    cout<<"   cancel() correctly refused to cancel unoccupied seat."<<endl;
  }
  print_plane(plane);

  row  = 3;
  seat = 2;
  cout << "\ncancelled "<<row+1<<char('A'+seat)<< "(["<<row<<"]["<<seat<<"]" << endl;
  cancel(plane, row, seat); 
  print_plane(plane);

  cout << "\nDeallocating two-d array 'plane' " << endl;
  plane = deallocate_twod(plane, 7);
  cout << "\n\n---------- D O N E ----------" << endl;
  return true;
}

//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 
//Lord help me! 
bool debug = false;
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 


TEST(TWO_D_ARRAYS, BasicTest) {
  bool success = basic_test_two_d_array(debug);
  EXPECT_EQ(success, true);
}


TEST(TEST_LAB_N_PLANE, BasicTestLab) {
  bool success = basic_test_lab(debug);
  EXPECT_EQ(success, true);
}

TEST(TEST_LAB_N_PLANE, BasicTestPlane) {
  bool success = basic_test_plane(debug);
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

09_p3_p5_lab_and_plane git:(master) ✗  😊 $> cd build
build git:(master) ✗  😊 $> tree ../includes
../includes
├── lab
│   ├── lab.cpp
│   └── lab.h
├── plane
│   ├── plane.cpp
│   └── plane.h
└── two_d_functions
    ├── two_d_functions.cpp
    └── two_d_functions.h

3 directories, 6 files
build git:(master) ✗  😊 $> ./bin/basic_test


----------running basic_test.cpp---------


[==========] Running 3 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 1 test from TWO_D_ARRAYS
[ RUN      ] TWO_D_ARRAYS.BasicTest
   -1   -1   -1   -1
   -1   -1   -1   -1   -1
   -1   -1   -1
   -1   -1   -1   -1   -1   -1

   -1   -1   -1    3
   -1   -1   -1   -1   14
   -1   -1   -1
   -1   31   -1   -1   -1   -1

[0][3]: 3
[1][4]: 14
[3][1]: 31
[3][4]: 34

found 33 at: [3][1]
td[3][4] is a valid location.
td[13][4] is NOT a valid location.
td[3][14] is NOT a valid location.
---- end test two d functions ----------
[       OK ] TWO_D_ARRAYS.BasicTest (0 ms)
[----------] 1 test from TWO_D_ARRAYS (0 ms total)

[----------] 2 tests from TEST_LAB_N_PLANE
[ RUN      ] TEST_LAB_N_PLANE.BasicTestLab
    0    0    0
    0    0    0    0
    0    0    0    0    0
    0
    0    0    0
================ test login() =====================

logging in lab: <<lab<<, station <<station<<: 
    0    0    0
    0    0    0    0
    0 2121    0    0    0
    0
    0    0    0

logging in lab: <<lab<<, station <<station<<: 
    0    0    0
    0    0    0    0
    0 2121    0    0    0
    0
    0    0 4242

logging in lab: <<lab<<, station <<station<<: 
login() correctly refused to log in a new user into an already occupied station
    0    0    0
    0    0    0    0
    0 2121    0    0    0
    0
    0    0 4242
================ test login() =====================

logging out user : 6666
logout() correctly refused to log out a user who was not logged in.
    0    0    0
    0    0    0    0
    0 2121    0    0    0
    0
    0    0 4242

logging out user: 4242
    0    0    0
    0    0    0    0
    0 2121    0    0    0
    0
    0    0    0

Deallocating two-d array 'labs' 


---------- D O N E ----------
[       OK ] TEST_LAB_N_PLANE.BasicTestLab (1 ms)
[ RUN      ] TEST_LAB_N_PLANE.BasicTestPlane

[  1]  X X X X
[  2]  X X X X
[  3]  X X X X
[  4]  X X X X
[  5]  X X X X
[  6]  X X X X
[  7]  X X X X


============ test reserve() =======================

reserved 1A([0][0]

[  1]  A X X X
[  2]  X X X X
[  3]  X X X X
[  4]  X X X X
[  5]  X X X X
[  6]  X X X X
[  7]  X X X X

reserved 4C([3][2]

[  1]  A X X X
[  2]  X X X X
[  3]  X X X X
[  4]  X X C X
[  5]  X X X X
[  6]  X X X X
[  7]  X X X X

reserved 7D([6][3]

[  1]  A X X X
[  2]  X X X X
[  3]  X X X X
[  4]  X X C X
[  5]  X X X X
[  6]  X X X X
[  7]  X X X D

reserved 7D([6][3]
   reserve() correctly refused to reserve an already occupied seat.

[  1]  A X X X
[  2]  X X X X
[  3]  X X X X
[  4]  X X C X
[  5]  X X X X
[  6]  X X X X
[  7]  X X X D


============ test cancel() =======================

cancelled 4D([3][3]
   cancel() correctly refused to cancel unoccupied seat.

[  1]  A X X X
[  2]  X X X X
[  3]  X X X X
[  4]  X X C X
[  5]  X X X X
[  6]  X X X X
[  7]  X X X D

cancelled 4C([3][2]

[  1]  A X X X
[  2]  X X X X
[  3]  X X X X
[  4]  X X X X
[  5]  X X X X
[  6]  X X X X
[  7]  X X X D

Deallocating two-d array 'plane' 


---------- D O N E ----------
[       OK ] TEST_LAB_N_PLANE.BasicTestPlane (0 ms)
[----------] 2 tests from TEST_LAB_N_PLANE (1 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 2 test cases ran. (1 ms total)
[  PASSED  ] 3 tests.
build git:(master)  😊 $> 
*/
#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

using namespace std;


//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include "../../includes/list_sorted/list_sorted.h"


//------------------------------------------------------------------------------------------

using namespace std;

bool basic_test(bool debug = false){
  List<int> list;
  cout << "list.empty(): " << boolalpha << list.empty() << endl;
  for (int i = 1; i < 6; i++)
  {
    list.insert(i);
    list.insert(i * 10);
    list.insert(i * 100);
    cout << list << endl;
  }
  List<int>::Iterator it = list.search(4);
  cout << "found 4: " << *it << endl;
  it = list.prev(it);
  cout << "previous to 4: " << *it << endl;
  list.Delete(it);
  cout << "deleted the prev: " << list << endl;
  cout << endl;
  cout << "iterating all the nodes: " << endl;
  for (it = list.begin(); it != list.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;
  cout << "list.empty(): " << boolalpha << list.empty() << endl;





  cout << "\n\n---------- D O N E ---------------\n\n"
       << endl;
  return true;
}


//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 
//Lord help me! 
bool debug = false;
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 



TEST(BASIC_TEST, BasicTest){
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
└── node
    └── node.h

3 directories, 3 files
build git:(master) ✗  😊 $> ./bin/basic_test


----------running testA.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from BASIC_TEST
[ RUN      ] BASIC_TEST.BasicTest
list.empty(): true
[1]-> [10]-> [100]-> |||

[1]-> [2]-> [10]-> [20]-> [100]-> [200]-> |||

[1]-> [2]-> [3]-> [10]-> [20]-> [30]-> [100]-> [200]-> [300]-> |||

[1]-> [2]-> [3]-> [4]-> [10]-> [20]-> [30]-> [40]-> [100]-> [200]-> [300]-> [400]-> |||

[1]-> [2]-> [3]-> [4]-> [5]-> [10]-> [20]-> [30]-> [40]-> [50]-> [100]-> [200]-> [300]-> [400]-> [500]-> |||

found 4: 4
previous to 4: 3
deleted the prev: [1]-> [2]-> [4]-> [5]-> [10]-> [20]-> [30]-> [40]-> [50]-> [100]-> [200]-> [300]-> [400]-> [500]-> |||


iterating all the nodes: 
1 2 4 5 10 20 30 40 50 100 200 300 400 500 
list.empty(): false


---------- D O N E ---------------


[       OK ] BASIC_TEST.BasicTest (0 ms)
[----------] 1 test from BASIC_TEST (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.
build git:(master) ✗  😊 $> 
*/
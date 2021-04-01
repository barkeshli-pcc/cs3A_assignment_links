#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
using namespace std;

#include "../../includes/list_simple/list_simple.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include "../../includes/node/node.h"

//------------------------------------------------------------------------------------------
//Files we are testing:
bool basic_test(bool debug = false){

  List<int> list;
  node<int> *marker;
  cout << "list.empty(): " << boolalpha << list.empty() << endl;
  for (int i = 1; i < 6; i++)
  {
    list.insert_head(i);
    list.insert_after(i * 10, list.begin());
    list.insert_before(i * 100, list.begin());
    cout << list << endl;
  }
  marker = list.search(4);
  cout << "found 4: " << *marker << endl;
  marker = list.prev(marker);
  cout << "previous to 4: " << *marker << endl;
  list.Delete(marker);
  cout << "deleted the prev: " << list << endl;
  cout << endl;
  cout << "iterating all the nodes: " << endl;
  for (marker = list.begin(); marker != list.end(); marker=marker->next)
  {
    cout << *marker << " ";
  }
  cout << endl;
  cout << "list.empty(): " << boolalpha << list.empty() << endl;


  cout << "\n\n-------- DONE ---------\n\n" << endl;
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

13_03_simple_list_class git:(master)  😊 $> tree includes
includes
├── linked_list_functions
│   └── linked_list_functions.h
├── list_simple
│   └── list_simple.h
└── node
    └── node.h

3 directories, 3 files
13_03_simple_list_class git:(master)  😊 $> ./build/bin/basic_test


----------running testA.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from BASIC_TEST
[ RUN      ] BASIC_TEST.BasicTest
list.empty(): true
[100]-> [1]-> [10]-> |||

[200]-> [2]-> [20]-> [100]-> [1]-> [10]-> |||

[300]-> [3]-> [30]-> [200]-> [2]-> [20]-> [100]-> [1]-> [10]-> |||

[400]-> [4]-> [40]-> [300]-> [3]-> [30]-> [200]-> [2]-> [20]-> [100]-> [1]-> [10]-> |||

[500]-> [5]-> [50]-> [400]-> [4]-> [40]-> [300]-> [3]-> [30]-> [200]-> [2]-> [20]-> [100]-> [1]-> [10]-> |||

found 4: [4]-> 
previous to 4: [400]-> 
deleted the prev: [500]-> [5]-> [50]-> [4]-> [40]-> [300]-> [3]-> [30]-> [200]-> [2]-> [20]-> [100]-> [1]-> [10]-> |||


iterating all the nodes: 
[500]->  [5]->  [50]->  [4]->  [40]->  [300]->  [3]->  [30]->  [200]->  [2]->  [20]->  [100]->  [1]->  [10]->  
list.empty(): false


-------- DONE ---------


[       OK ] BASIC_TEST.BasicTest (1 ms)
[----------] 1 test from BASIC_TEST (1 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (1 ms total)
[  PASSED  ] 1 test.
*/










#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
using namespace std;

#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linked_list_functions.h"
#include "../../includes/list_iterated/list_iterated.h"

bool basic_test(bool debug = false)
{
  List<int> list;
  cout << "list.empty(): " << boolalpha << list.empty() << endl;
  for (int i = 1; i < 6; i++)
  {
    list.insert_head(i);
    list.insert_after(i * 10, list.begin());
    list.insert_before(i * 100, list.begin());
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
  cout << "\n\n--------- D O N E ----------------" << endl;
  return true;
}
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 
//Lord help me! 
bool debug = false;
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 



TEST(ITERATED_LIST, TestInsertHead){
  bool success = basic_test(debug);
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
build git:(master)  😊 $> tree ../includes 
../includes
├── linked_list_functions
│   └── linked_list_functions.h
├── list_iterated
│   └── list_iterated.h
└── node
    └── node.h

3 directories, 3 files
build git:(master)  😊 $> ./bin/basic_test


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from ITERATED_LIST
[ RUN      ] ITERATED_LIST.TestInsertHead
list.empty(): true
[100]-> [1]-> [10]-> |||

[200]-> [2]-> [20]-> [100]-> [1]-> [10]-> |||

[300]-> [3]-> [30]-> [200]-> [2]-> [20]-> [100]-> [1]-> [10]-> |||

[400]-> [4]-> [40]-> [300]-> [3]-> [30]-> [200]-> [2]-> [20]-> [100]-> [1]-> [10]-> |||

[500]-> [5]-> [50]-> [400]-> [4]-> [40]-> [300]-> [3]-> [30]-> [200]-> [2]-> [20]-> [100]-> [1]-> [10]-> |||

found 4: 4
previous to 4: 400
deleted the prev: [500]-> [5]-> [50]-> [4]-> [40]-> [300]-> [3]-> [30]-> [200]-> [2]-> [20]-> [100]-> [1]-> [10]-> |||


iterating all the nodes: 
500 5 50 4 40 300 3 30 200 2 20 100 1 10 
list.empty(): false


--------- D O N E ----------------
[       OK ] ITERATED_LIST.TestInsertHead (0 ms)
[----------] 1 test from ITERATED_LIST (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (1 ms total)
[  PASSED  ] 1 test.
build git:(master)  😊 $> 
*/
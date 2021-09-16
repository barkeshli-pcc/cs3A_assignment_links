#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>

#include "../../includes/add_entry/add_entry.h"

using namespace std;


bool test_basic_add_entry_int(bool debug = false){
  cout << "MINIMUM_CAPACITY: " << MINIMUM_CAPACITY << endl;
  int capacity = MINIMUM_CAPACITY;
  int *arr = allocate<int>(capacity);
  int size = 0;
  for (int i = 0; i < 15; i++){
    cout << "adding [" << i << "] ";
    arr = add_entry(arr, i, size, capacity);
    print_array(arr, size, capacity);
  }

  int* index = search_entry(arr, size, 4);
  cout << endl
       << "search_entry returned: " << *index << endl;

  arr = remove_entry(arr, 4, size, capacity);
  cout << "removed [4]: ";
  print_array(arr, size, capacity);
  cout << endl
       << endl;
  arr = insert_entry(arr, 99, 4, size, capacity);
  cout << "inserted 99 at position 4: ";
  print_array(arr, size, capacity);
  cout << endl
       << endl;
  arr = erase_entry(arr, 4, size, capacity);
  cout << "removed item at position 4 (the 99): ";
  print_array(arr, size, capacity);
  cout << endl
       << endl;

  for (int i = size - 1; i >= 0; i--)
  {
    int item;
    ;

    arr = remove_last_entry(arr, item, size, capacity);
    cout << "removed: [" << item << "] ";
    print_array(arr, size, capacity);
  }
    cout << "----- end of function --------" << endl;

  return true;
}

bool test_basic_add_entry_string(bool debug = false){
  cout << "MINIMUM_CAPACITY: " << MINIMUM_CAPACITY << endl;
  int capacity = MINIMUM_CAPACITY;
  string *arr = allocate<string>(capacity);
  string list[10] = {"vector", "BST", "Pair", "Map", "Multimap", "Stack", "Queue"};
  int size = 0;
  for (int i = 0; i < 7; i++){
    cout << "adding [" << i << "] ";
    arr = add_entry(arr, string(list[i]), size, capacity);
    print_array(arr, size, capacity);
  }

  string* index = search_entry(arr, size,string("Map"));
  cout << endl
       << "search_entry returned: " << *index << endl;

  arr = remove_entry(arr, string("Map"), size, capacity);
  cout << "removed [Map]: ";
  print_array(arr, size, capacity);
  cout << endl
       << endl;

  for (int i = size - 1; i >= 0; i--)
  {
    string item;
    arr = remove_last_entry(arr, item, size, capacity);
    cout << "removed: [" << item << "] ";
    print_array(arr, size, capacity);
  }
    cout << "----- end of function --------" << endl;

  return true;
}


//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 
//Lord help me! 
bool debug = false;
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 


TEST(TEST_BASIC, TestBasicInt){
  bool success =test_basic_add_entry_int(debug);
  EXPECT_EQ(success, true);
}


TEST(TEST_BASIC, TestBasicString){
  bool success =test_basic_add_entry_string(debug);
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  if (argc>1){
    debug = argv[1][0]=='t';
  }
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n---------- running basic_test ---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


/*


build git:(master) ✗  😊 $> tr ..
..
├── _tests
│   ├── _test_files
│   ├── _test_includes
│   └── other
│       └── cmake
├── build
│   ├── bin
│   └── lib
├── cmake
└── includes
    ├── add_entry
    └── array_functions

12 directories, 0 files
build git:(master) ✗  😊 $> ./bin/basic_test



---------- running basic_test ---------


[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from TEST_BASIC
[ RUN      ] TEST_BASIC.TestBasicInt
MINIMUM_CAPACITY: 3
adding [0] ( 1/ 3) [    0 ]
adding [1] ( 2/ 3) [    0     1 ]
adding [2] ( 3/ 3) [    0     1     2 ]
adding [3] ( 4/ 6) [    0     1     2     3 ]
adding [4] ( 5/ 6) [    0     1     2     3     4 ]
adding [5] ( 6/ 6) [    0     1     2     3     4     5 ]
adding [6] ( 7/12) [    0     1     2     3     4     5     6 ]
adding [7] ( 8/12) [    0     1     2     3     4     5     6     7 ]
adding [8] ( 9/12) [    0     1     2     3     4     5     6     7     8 ]
adding [9] (10/12) [    0     1     2     3     4     5     6     7     8     9 ]
adding [10] (11/12) [    0     1     2     3     4     5     6     7     8     9    10 ]
adding [11] (12/12) [    0     1     2     3     4     5     6     7     8     9    10    11 ]
adding [12] (13/24) [    0     1     2     3     4     5     6     7     8     9    10    11    12 ]
adding [13] (14/24) [    0     1     2     3     4     5     6     7     8     9    10    11    12    13 ]
adding [14] (15/24) [    0     1     2     3     4     5     6     7     8     9    10    11    12    13    14 ]

search_entry returned: 4
removed [4]: (14/24) [    0     1     2     3     5     6     7     8     9    10    11    12    13    14 ]


inserted 99 at position 4: (15/24) [    0     1     2     3    99     5     6     7     8     9    10    11    12    13    14 ]


removed item at position 4 (the 99): (14/24) [    0     1     2     3     5     6     7     8     9    10    11    12    13    14 ]


removed: [14] (13/24) [    0     1     2     3     5     6     7     8     9    10    11    12    13 ]
removed: [13] (12/24) [    0     1     2     3     5     6     7     8     9    10    11    12 ]
removed: [12] (11/24) [    0     1     2     3     5     6     7     8     9    10    11 ]
removed: [11] (10/24) [    0     1     2     3     5     6     7     8     9    10 ]
removed: [10] ( 9/24) [    0     1     2     3     5     6     7     8     9 ]
removed: [9] ( 8/24) [    0     1     2     3     5     6     7     8 ]
removed: [8] ( 7/24) [    0     1     2     3     5     6     7 ]
removed: [7] ( 6/12) [    0     1     2     3     5     6 ]
removed: [6] ( 5/12) [    0     1     2     3     5 ]
removed: [5] ( 4/12) [    0     1     2     3 ]
removed: [3] ( 3/ 6) [    0     1     2 ]
removed: [2] ( 2/ 6) [    0     1 ]
removed: [1] ( 1/ 6) [    0 ]
removed: [0] ( 0/ 6) []
----- end of function --------
[       OK ] TEST_BASIC.TestBasicInt (0 ms)
[ RUN      ] TEST_BASIC.TestBasicString
MINIMUM_CAPACITY: 3
adding [0] ( 1/ 3) [vector ]
adding [1] ( 2/ 3) [vector   BST ]
adding [2] ( 3/ 3) [vector   BST  Pair ]
adding [3] ( 4/ 6) [vector   BST  Pair   Map ]
adding [4] ( 5/ 6) [vector   BST  Pair   Map Multimap ]
adding [5] ( 6/ 6) [vector   BST  Pair   Map Multimap Stack ]
adding [6] ( 7/12) [vector   BST  Pair   Map Multimap Stack Queue ]

search_entry returned: Map
removed [Map]: ( 6/12) [vector   BST  Pair Multimap Stack Queue ]


removed: [Queue] ( 5/12) [vector   BST  Pair Multimap Stack ]
removed: [Stack] ( 4/12) [vector   BST  Pair Multimap ]
removed: [Multimap] ( 3/ 6) [vector   BST  Pair ]
removed: [Pair] ( 2/ 6) [vector   BST ]
removed: [BST] ( 1/ 6) [vector ]
removed: [vector] ( 0/ 6) []
----- end of function --------
[       OK ] TEST_BASIC.TestBasicString (1 ms)
[----------] 2 tests from TEST_BASIC (1 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (2 ms total)
[  PASSED  ] 2 tests.
build git:(master) ✗  😊 $> 
*/
#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>


//------------------------------------------------------------------------------------------
//Files we are testing:

#include "../../includes/array_functions/array_functions.h"


//------------------------------------------------------------------------------------------

using namespace std;

void fill_array(int* src, int size){
  for (int i = 0; i<size; i++){
    src[i] = i*10;
  }
}
bool pointer_array_functions_basic_test(bool debug = true)
{
  int size = 7;
  int capacity = 10;

  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- 
  cout << "\n\n -- allocate(), print_array() -----" << endl;
  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- 
  
  int *a = allocate<int>(capacity);
  fill_array(a, size);
  print_array(a, size, capacity);
  
  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- 
  cout << "\n\n -- search_entry() -----" << endl;
  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- 

  int key;
  int *found;

  key = 30;
  found = search_entry(a, size, key);
  if (found){
    cout << key << " was found: " << *found << endl;
  }
  else{
    cout << key << " was not found" << endl;
  }

  key = 35;
  found = search_entry(a, size, key);
  if (found){
    cout << key << " was found: " << *found << endl;
  }
  else{
    cout << key << " was not found" << endl;
  }
  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- 
  cout << "\n\n -- search() -----" << endl;
  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- 

  int found_index;

  key = 30;
  found_index = search(a, size, key);
  if (found_index>=0){
    found = a + found_index;
    cout << key << " was found: " << *found << endl;
  }
  else{
    cout << key << " was not found" << endl;
  }

  key = 35;
  found_index = search(a, size, key);
  if (found_index>=0){
    found = a + found_index;
    cout << key << " was found: " << *found << endl;
  }
  else{
    cout << key << " was not found" << endl;
  }

  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- 
  cout << "\n\n -- copy function()  (@@)-----" << endl;
  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- 
  
  int copy_1_static[20];
  cout << " void copy_array(dest, src, size):  ";
  copy_array(copy_1_static, a, size); //would also work with dynamic
  print_array(copy_1_static, size);  //default capacity

  cout << " T* copy_array(src, siae):       ";
  int *copy_2_dynamic = copy_array(copy_1_static, size);
  print_array(copy_2_dynamic, size, size);

  cout << endl;

  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- 
  cout << "\n\n -- shift_right()" << endl;
  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- 

  int *mark;

  key = 30;
  cout << " - shift right at "<<key<<":";
  mark = search_entry(a, size, key);
  shift_right(a, size, mark);
  print_array(a, size, capacity);

  key = 60;
  cout << " - shift right at "<<key<<":";
  mark = search_entry(a, size, key);
  shift_right(a, size, mark);
  print_array(a, size, capacity);

  key = 0;
  cout << " - shift right at  "<<key<<":";
  mark = search_entry(a, size, key);
  shift_right(a, size, mark);
  print_array(a, size, capacity);

  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- 
  cout << "\n\n -- reallocate()" << endl;
  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- 
  capacity *= 2;
  a = reallocate(a, size, capacity);
  cout << " --- after reallocation: ";
  print_array(a, size, capacity);

  key = 20;
  cout << " - one more shift at " << key << ": ";
  mark = search_entry(a, size, key);
  shift_right(a, size, mark);
  print_array(a, size, capacity);




  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- 
  cout << "\n\n -- shift_left()" << endl;
  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- ---

  cout << "        array now:  " ;
  print_array(a, size, capacity);


  key = 60;
  cout << " - shift left at "<<key<<":";
  mark = search_entry(a, size, key);
  shift_left(a, size, mark);
  print_array(a, size, capacity);



  key = 60;
  cout << " - shift left at "<<key<<":";
  mark = search_entry(a, size, key);
  shift_left(a, size, mark);
  print_array(a, size, capacity);



  key = 20;
  cout << " - shift left at "<<key<<":";
  mark = search_entry(a, size, key);
  shift_left(a, size, mark);
  print_array(a, size, capacity);


  key = 20;
  cout << " - shift left at "<<key<<":";
  mark = search_entry(a, size, key);
  shift_left(a, size, mark);
  print_array(a, size, capacity);


  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- 
  cout << "\n\n -- array_string()" << endl;
  //-- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- ---

  cout << "        array now:  " ;
  print_array(a, size, capacity);
  array_string(a, size);
  cout << "  array to string: " << array_string(a, size) << endl;
  cout << " Feel free to change the way the string is constructed: " << endl;
  cout << "                          commas, better spacing, etc." << endl;

  cout << "\n\n\n\n ==========  end basic test  =================" << endl;
  return true;
}

TEST(POINTER_ARRAY_FUNCS, PointerArrayFuncsTest) {
  bool success = pointer_array_functions_basic_test(true);
  EXPECT_EQ(success, true);
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}
/*
<pre>
09_00_array_functions git:(master) ✗  😊 $> tree includes 
includes
└── array_functions
    └── array_functions.h

1 directory, 1 file
09_00_array_functions git:(master) ✗  😊 $> ./build/bin/basic_test


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from POINTER_ARRAY_FUNCS
[ RUN      ] POINTER_ARRAY_FUNCS.PointerArrayFuncsTest


 -- allocate(), print_array() -----
( 7/10) [   0   10   20   30   40   50   60 ]


 -- search_entry() -----
30 was found: 30
35 was not found


 -- search() -----
30 was found: 30
35 was not found


 -- copy function()  (@@)-----
 void copy_array(dest, src, size):  ( 7) [   0   10   20   30   40   50   60 ]
 T* copy_array(src, siae):       ( 7/ 7) [   0   10   20   30   40   50   60 ]



 -- shift_right()
 - shift right at 30:( 8/10) [   0   10   20   30   30   40   50   60 ]
 - shift right at 60:( 9/10) [   0   10   20   30   30   40   50   60   60 ]
 - shift right at  0:(10/10) [   0    0   10   20   30   30   40   50   60   60 ]


 -- reallocate()
 --- after reallocation: (10/20) [   0    0   10   20   30   30   40   50   60   60 ]
 - one more shift at 20: (11/20) [   0    0   10   20   20   30   30   40   50   60   60 ]


 -- shift_left()
        array now:  (11/20) [   0    0   10   20   20   30   30   40   50   60   60 ]
 - shift left at 60:(10/20) [   0    0   10   20   20   30   30   40   50   60 ]
 - shift left at 60:( 9/20) [   0    0   10   20   20   30   30   40   50 ]
 - shift left at 20:( 8/20) [   0    0   10   20   30   30   40   50 ]
 - shift left at 20:( 7/20) [   0    0   10   30   30   40   50 ]


 -- array_string()
        array now:  ( 7/20) [   0    0   10   30   30   40   50 ]
  array to string: [0 0 10 30 30 40 50 ][7]
 Feel free to change the way the string is constructed: 
                          commas, better spacing, etc.




 ==========  end basic test  =================
[       OK ] POINTER_ARRAY_FUNCS.PointerArrayFuncsTest (1 ms)
[----------] 1 test from POINTER_ARRAY_FUNCS (1 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (2 ms total)
[  PASSED  ] 1 test.
09_00_array_functions git:(master)  😊 $> 


</pre>
*/
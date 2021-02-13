#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

#include "../_test_includes/random.h"
#include "../_test_includes/utilities.h"
#include "../_test_includes/timer.h"
using namespace std;


//------------------------------------------------------------------------------------------
//Files we are testing:
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

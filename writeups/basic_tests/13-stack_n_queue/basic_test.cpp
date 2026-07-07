#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
using namespace std;

#include "../../includes/stack/MyStack.h"
#include "../../includes/queue/MyQueue.h"


bool basic_test(bool debug = false)
{
  Stack<int> s;
  Queue<int> q;
  cout << "stack.push(): " << endl;
  for (int i = 0; i < 5; i++)
  {
    s.push(i);
    cout << s << endl;
  }
  cout << "top of stack: " << s.top() << endl;
  cout << "pop stack: " << s.pop() << endl;
  cout << s << endl;
  cout << "size of the stack: " << s.size() << endl;
  cout << "is stack empty? " << boolalpha << s.empty() << endl;
  Stack<int>::Iterator s_it = s.begin();
  cout << "stack top to bottom: " << endl;
  for (; s_it != s.end(); s_it++)
  {
    cout << "<" << *s_it << "> " << endl;
  }
  cout << "\n\n" << endl;
  
  cout << "queue.push(): " << endl;
  for (int i = 0; i < 5; i++)
  {
    q.push(i);
    cout << q << endl;
  }
  cout << "front of queue: " << q.front() << endl;
  cout << "rear of queue: " << q.back() << endl;
  cout << "pop queue: " << q.pop() << endl;
  cout << q << endl;
  cout << "size of the queue: " << q.size() << endl;
  cout << "is queue empty? " << boolalpha << q.empty() << endl;
  Queue<int>::Iterator q_it = q.begin();
  cout << "queue top to bottom: " << endl;
  for (; q_it != q.end(); q_it++)
  {
    cout << "<" << *q_it << "> " << endl;
  }

    cout << "\n\n--------- D O N E ----------------\n\n" << endl;
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
  std::cout<<"\n\n----------running testA.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

/*


build git:(master) ✗  😊 $> tree ../includes
../includes
├── linked_list_functions
│   └── linked_list_functions.h
├── node
│   ├── bogus.txt
│   └── node.h
├── queue
│   ├── MyQueue.h
└── stack
    └── MyStack.h

4 directories, 5 files
build git:(master) ✗  😊 $> ./bin/basic_test


----------running testA.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from ITERATED_LIST
[ RUN      ] ITERATED_LIST.TestInsertHead
stack.push(): 
Stack:Head->[0]-> |||

Stack:Head->[1]-> [0]-> |||

Stack:Head->[2]-> [1]-> [0]-> |||

Stack:Head->[3]-> [2]-> [1]-> [0]-> |||

Stack:Head->[4]-> [3]-> [2]-> [1]-> [0]-> |||

top of stack: 4
pop stack: 4
Stack:Head->[3]-> [2]-> [1]-> [0]-> |||

size of the stack: 4
is stack empty? false
stack top to bottom: 
<3> 
<2> 
<1> 
<0> 



queue.push(): 
Queue:Head->[0]-> |||

Queue:Head->[0]-> [1]-> |||

Queue:Head->[0]-> [1]-> [2]-> |||

Queue:Head->[0]-> [1]-> [2]-> [3]-> |||

Queue:Head->[0]-> [1]-> [2]-> [3]-> [4]-> |||

front of queue: 0
rear of queue: 4
pop queue: 0
Queue:Head->[1]-> [2]-> [3]-> [4]-> |||

size of the queue: 4
is queue empty? false
queue top to bottom: 
<1> 
<2> 
<3> 
<4> 


--------- D O N E ----------------


[       OK ] ITERATED_LIST.TestInsertHead (0 ms)
[----------] 1 test from ITERATED_LIST (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (0 ms total)
[  PASSED  ] 1 test.
build git:(master) ✗  😊 $> 

*/

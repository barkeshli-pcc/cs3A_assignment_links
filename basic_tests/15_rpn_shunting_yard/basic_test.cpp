#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>


//------------------------------------------------------------------------------------------
//Files we are testing:

#include "../../includes/token/token.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"

#include "../../includes/queue/MyQueue.h"

#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"


//------------------------------------------------------------------------------------------

using namespace std;
bool test_RPN(bool debug = false){
  Queue<Token *> postfix;
  postfix.push(new Integer(3));
  postfix.push(new Integer(5));
  postfix.push(new Operator("*"));
  RPN rpn(postfix);
  cout << "3 5 *: " << rpn() << endl;
  cout << "-------------" << endl;
  Queue<Token *> postfix2;
  postfix2.push(new Integer(3));
  postfix2.push(new Function("X"));
  postfix2.push(new Operator("*"));
  rpn.set_input(postfix2);
  cout << "3 x *: (x=2): " << rpn(2) << endl;



  return true;
}
bool test_shunting_yard(bool debug=false){
  Queue<Token *> infix;
  infix.push(new Integer(3));
  infix.push(new Operator("*"));
  infix.push(new Integer(5));
  ShuntingYard sy(infix);
  Queue<Token*> postfix = sy.postfix();
  RPN rpn(postfix);
  cout << "3 * 5: " << rpn() << endl;
  Queue<Token *> infix2;
  infix2.push(new Integer(3));
  infix2.push(new Operator("*"));
  infix2.push(new LeftParen());
  infix2.push(new Integer(5));
  infix2.push(new Operator("+"));
  infix2.push(new Integer(6));
  infix2.push(new Operator("-"));
  infix2.push(new Function("X"));
  infix2.push(new RightParen());
  infix2.push(new Operator("/"));
  infix2.push(new Integer(9));
  sy.infix(infix2);
  postfix = sy.postfix();
  rpn.set_input(postfix);
  cout << "3*(5+6-X)/9 (x=2): " << rpn(2) << endl;

  ShuntingYard sy2;
  postfix = sy2.postfix(infix2);
  for (Queue<Token *>::Iterator it = postfix.begin(); it != postfix.end(); it++){
    cout <<setw(3)<< *it;
  }
  cout << endl;

  return true;
}
TEST(TEST_RPN, TestRPN) {
  bool success = test_RPN();
  EXPECT_EQ(success, true);
}

TEST(TEST_SHUNTING_YARD, TestShuntingYard) {
  bool success = test_shunting_yard();
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

/*


build git:(master) ✗  😊 $> tree ../includes
../includes
├── array_functions
│   └── array_functions.h
├── exceptions
│   ├── dividebyzero.cpp
│   ├── dividebyzero.h
│   ├── missingparan.cpp
│   └── missingparan.h
├── linked_list_functions
│   └── linked_list_functions.h
├── node
│   └── node.h
├── queue
│   ├── MyQueue.h
│   └── queue_composition.h
├── rpn
│   ├── rpn.cpp
│   └── rpn.h
├── shunting_yard
│   ├── shunting_yard.cpp
│   └── shunting_yard.h
├── stack
│   ├── MyStack.h
│   └── stack_composition.h
└── token
    ├── alpha.cpp
    ├── alpha.h
    ├── constants.h
    ├── function.cpp
    ├── function.h
    ├── integer.cpp
    ├── integer.h
    ├── leftparen.cpp
    ├── leftparen.h
    ├── operator.cpp
    ├── operator.h
    ├── rightparen.cpp
    ├── rightparen.h
    ├── tk_string.cpp
    ├── tk_string.h
    ├── token.cpp
    └── token.h

9 directories, 32 files
build git:(master) ✗  😊 $> ./bin/basic_test


----------running basic_test.cpp---------


[==========] Running 2 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 1 test from TEST_RPN
[ RUN      ] TEST_RPN.TestRPN
3 5 *: 15
-------------
3 x *: (x=2): 6
[       OK ] TEST_RPN.TestRPN (0 ms)
[----------] 1 test from TEST_RPN (0 ms total)

[----------] 1 test from TEST_SHUNTING_YARD
[ RUN      ] TEST_SHUNTING_YARD.TestShuntingYard
3 * 5: 15
3*(5+6-X)/9 (x=2): 3
  3  5  6  +  X  -  *  9  /
[       OK ] TEST_SHUNTING_YARD.TestShuntingYard (0 ms)
[----------] 1 test from TEST_SHUNTING_YARD (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 2 test cases ran. (1 ms total)
[  PASSED  ] 2 tests.
build git:(master) ✗  😊 $> 


*/
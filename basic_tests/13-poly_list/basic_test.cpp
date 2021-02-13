#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
using namespace std;

#include "../../includes/poly_list/poly.h"
//------------------------------------------------------------------------------------------
//Files we are testing:
bool basic_test(bool debug = false){
  double coefs1[] = {2.0,0.0,0.0,2.0,4.0,0.0,5.0};
  double coefs2[] = {3.0, 4.0, 5.0, 6.0};
  Poly p(coefs1, 6);
  Poly q(coefs2, 3);
  Poly r;
  cout << "p: " << p << endl;
  cout << "q: " << q << endl;
  cout << "----------------------------------" << endl;
  cout << "p + q: " << p + q << endl;
  cout << "p - q: " << p - q << endl;
  cout << "p * q: " << p * q << endl;
  cout << "p / q: " << p / q << endl;
  cout << "p % q: " << p % q << endl;
  cout << "q / p: " << p / q << endl;
  cout << "q % p: " << p % q << endl;
  cout << "p != p: " << boolalpha << (p != p) << endl;
  cout << "(p+q)-q == p? " << boolalpha<<((p+q)-q==p) << endl;
  cout << "10.0/3 == 20.0/6: " << boolalpha << double_equals(10.0 / 3, 20.0 / 6) << endl;
  cout << "\n\n-------- DONE ---------\n\n"
       << endl;
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










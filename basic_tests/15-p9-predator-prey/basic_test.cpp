#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

// #include "../_test_includes/random.h"
#include "../_test_includes/utilities.h"
#include "../_test_includes/timer.h"

//------------------------------------------------------------------------------------------
//Files we are testing:

#include "../../includes/creatures/grid.h"
#include "../../includes/creatures/creature.h"


//------------------------------------------------------------------------------------------

using namespace std;
bool test_predator_prey()
{
    srand(time(0));
    grid world;
    char comm='\0';
    world.fillGrid();
    int gen=0;

    while(comm!='x' && world.anyAlive() && !world.allAlive())
    {
        cout<<"generation: "<<gen<<endl<<endl;
        cout<<world<<endl;gen++;
        world.Step();
        comm=cin.get();
    }

    cout<<"generation: "<<gen<<endl<<endl;
    cout<<world<<endl;

    cout << "Goodbye World!" << endl;
    return true;
}



TEST(Predator, Test) {
  bool success = test_predator_prey();
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testA.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


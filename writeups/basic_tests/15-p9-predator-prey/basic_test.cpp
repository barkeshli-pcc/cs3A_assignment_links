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

/*


build git:(master)  😊 $> tree ../includes
../includes
├── Random
│   ├── random.cpp
│   └── random.h
└── creatures
    ├── animal_types.cpp
    ├── animal_types.h
    ├── const.h
    ├── creature.cpp
    ├── creature.h
    ├── grid.cpp
    ├── grid.h
    └── loc.h

2 directories, 10 files
build git:(master)  😊 $> ./bin/basic_test


----------running testA.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from Predator
[ RUN      ] Predator.Test
generation: 0

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | |o|o| |X| | | |o| | | | | | |Z|
|Z|o|o| | | |o| | |o|o| | | | |o| |o| |Z|
|Z| | | | | |o| |o| |o|o| | | |o| | | |Z|
|Z| | |o|o|o|o| | |X| | | | | | | |o| |Z|
|Z| | |o| | | | | |o|o| | |o| |o| | | |Z|
|Z|o| |o| | | | | |o| | | | | | |o|o| |Z|
|Z| |o|o| | | |o|o| | | | | | | |o| | |Z|
|Z| | | |o| | | | | | | | | |o| | | | |Z|
|Z| | | |o| | | | | |o| |o| |o| | | | |Z|
|Z| | | | | | | | |o| | |o| | |o| | | |Z|
|Z| | | | | | | | | | | | | | | |o| |o|Z|
|Z|o| | | |o|o| |o|o| | | | | | |o|o|o|Z|
|Z| | | | |o| |o| | | | |o| | | |o|o| |Z|
|Z| |o|o| | | |o|o| | |o|o| | | |X| |o|Z|
|Z| |o| | | | | | | | | | | |o| | |o| |Z|
|Z|o| |o|o|o|o| | |X|o| |o| | |o| | | |Z|
|Z| | | |o| |o| | | | | | | | | | | | |Z|
|Z| | | | | |o| | | | | | | |X| | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 1

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| |o| |o|o| | | | |o| | |o| | | |o| |Z|
|Z| | | | | |o| | |X| | | | | | | | | |Z|
|Z|o| | |o|o| |o| | | | |o| |o| | | | |Z|
|Z| |o|o|o| | | | | |o| |o| | | |o| |o|Z|
|Z| |o| | | |o| | |X|o| | | | | | |o| |Z|
|Z| |o| | | | | | | |o| | | |o|o| | | |Z|
|Z| | | | | | |o| | | | | | | | | | | |Z|
|Z| |o|o| | |o| | | |o| | | | |o| |o| |Z|
|Z| | |o| |o| | | |o| |o| | | | | | | |Z|
|Z| | | | | | | | | | | | | |o| |o| |o|Z|
|Z| | | |o| | | |o|o| |o| | | | |o|o| |Z|
|Z| |o| | |o| | |o| | | | | | | |o|o| |Z|
|Z| |o| | | | | | | | |o|o| | | |X| |o|Z|
|Z|o| |o| |o| |o| | | | | | | | | |o| |Z|
|Z| | | | | |o| | | |o| | |o| | | | |o|Z|
|Z| |o| |o| | | | | |X|o| | | | |o| | |Z|
|Z| | |o| |o|o|o| | | | | | | |X| | | |Z|
|Z| | | | |o| |o| | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 2

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | |o| | | | |X| | | | | | | | |Z|
|Z|o|o| |o|o| | | | | | | |o|o| | |o| |Z|
|Z| | |o| | |o| | | | | | | | | | | | |Z|
|Z| |o| | |o|o| |o| |X|o| |o| |o|o|o| |Z|
|Z|o|o|o| | | | | | |o|o| | | | | | | |Z|
|Z| | | | | | |o| | | | | |o| | | | | |Z|
|Z| |o| | | |o| | | | | | | |o|o| | | |Z|
|Z|o|o| | | |o| | | | |o|o| | | | | | |Z|
|Z| | | | | | | | | | | | | | |o| |o| |Z|
|Z| | | | | | | | |o|o| |o| | | | |o| |Z|
|Z| | | | |o| | |o| | | | | | |o|o| |o|Z|
|Z| | |o| | | | | |o| | | | | | | | |o|Z|
|Z| | |o|o|o|o| |o| |o| | | | | |o| | |Z|
|Z| |o| | | | | | | | | |o|o| | | |X|o|Z|
|Z|o| | | | | | | | |X| |o| | | | |o| |Z|
|Z| | | | | |o|o| | | | | | | | |X| | |Z|
|Z| | | |o|o| | |o| | | | | | | | | | |Z|
|Z| |o| | | |o| |o| | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 3

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | |o|o| |o| | | | | | | | | | | | |Z|
|Z| |o|o|o|o|o|o| |X| | | | |o| | |o| |Z|
|Z|o|o|o|o| | | | | | |o|o| |o|o|o|o|o|Z|
|Z|o|o|o| |o|o| |o|o| | | | |o| | |o|o|Z|
|Z|o|o|o| |o| | | | |X| |o| |o|o| |o| |Z|
|Z|o|o|o| |o|o|o| |o|o|o|o|o| |o| | | |Z|
|Z|o|o|o|o| | | | | |o| | | | |o| | | |Z|
|Z|o| | | |o|o| | | |o|o| | |o| | |o|o|Z|
|Z| | | | |o|o| |o| |o|o| | | |o|o|o| |Z|
|Z| | | |o| | |o|o|o|o| | | |o|o|o| | |Z|
|Z| |o|o| |o|o| |o|o| | |o| | | |o|o| |Z|
|Z| |o| | |o|o| | | | |o| | | | |o|o| |Z|
|Z| | | |o| |o|o| | | | |o| | | |o|o|o|Z|
|Z| | | |o|o| | | |o|o|o| | |o| | |o|X|Z|
|Z| |o|o| |o|o| | | | | | |o| | | |X| |Z|
|Z| |o|o| | | |o|o| |X| |o|o| | | | | |Z|
|Z| | |o|o|o|o|o|o|o| | | | | | | | | |Z|
|Z| | |o|o| |o|o|o| |o| | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 4

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o| |o|o|o|o| | | | | | | | | |o|Z|
|Z| |o| |o| | | | | |o| | | |o| | | | |Z|
|Z|o|o|o|o|o|o|o| |X| | | |o|o| |o|o| |Z|
|Z| |o|o|o| |o| | |X| |o|o|o|o| |o|o| |Z|
|Z|o|o| | | |o|o| | |o| | |o| |o|o| | |Z|
|Z|o|o|o| | | | |o| |o| | | |o| |o| | |Z|
|Z|o| | | |o|o|o| | | |o| | |o| |o| |o|Z|
|Z| |o| |o| |o|o| |o|o| | | | |o|o|o| |Z|
|Z|o| |o|o| | | |o|o| | |o| |o|o| | | |Z|
|Z| | | |o|o|o|o|o|o| |o|o| | | |o| |o|Z|
|Z|o| | |o| | |o| | |o| | |o| |o|o| |o|Z|
|Z|o| | | |o| |o| | |o| | | | |o| |o|o|Z|
|Z| | | | |o| | | | | |o| | | | | |X| |Z|
|Z| |o| |o|o| |o|o| | | |o|o| | | |X| |Z|
|Z| |o| |o|o| |o| | |o|o| |o|o| | | | |Z|
|Z|o| | | | |o|o|o| | | | | | | | | | |Z|
|Z| |o|o|o| |o|o| |X|o|o| | | | | | | |Z|
|Z| |o|o| |o|o| | |o| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 5

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o| |o| | | | |o| | | | | | | | | |Z|
|Z|o| |o|o| |o|o|o| |X| |o|o|o| | | |o|Z|
|Z|o|o|o| |o|o| | | | | | |o| |o| | |o|Z|
|Z|o|o|o| |o| |o| | | |o| | |o|o|o| |o|Z|
|Z|o|o|o| | |o| | |o|X|o| | |o|o| |o| |Z|
|Z| |o| |o|o|o| | | |o| | |o|o| | | |o|Z|
|Z| |o| | |o|o| | |o|o| | | | | |o|o| |Z|
|Z|o|o|o|o| |o| |o|o| |o| | | | | | | |Z|
|Z| | | |o|o|o|o| | | |o|o| | | |o|o|o|Z|
|Z| | |o|o| | |o| | |o|o| | |o|o|o|o|o|Z|
|Z| | | | |o| | |o|o| | | | | | | | | |Z|
|Z| |o| | | |o| | | | | |o|o| | |o|X| |Z|
|Z| |o|o| |o|o|o|o| |o| |o|o|o| | | |o|Z|
|Z| | | | | |o|o|o|o| | |o| | | | | | |Z|
|Z|o| | |o|o|o| | | |o| | | | | |X| | |Z|
|Z|o|o| | |o|o|o| | | | | | |o| | | | |Z|
|Z|o| |o|o|o|o| |o| |X| | | | | | | | |Z|
|Z| |o| |o| | | | | | |o| | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 6

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|X| | |o| | |o| |o|o|Z|
|Z|o|o|o|o|o|o|o| | | |o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o| | |o| |o| | |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o| |o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o| |o|o|o| |o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | |o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o| | |o|o| | | |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o| |o|o|o|o|o|o| |o|o| |Z|
|Z| |o|o|o|o|o|o|o| |o|o|o|o| |o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o| |o|o|o|o|o| |o|o| |Z|
|Z| |o| | |o|o|o|o| |o|o|o|o|o| | |o|o|Z|
|Z|o|o|o|o|o|o|o|o| |o|o|o|o| | | | |X|Z|
|Z|o|o|o|o|o|o|o|o| |o|o| | |o| | |X| |Z|
|Z|o|o|o|o|o|o|o|o|o| | |o| |o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| | |o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o| | | | | | | | | | |Z|
|Z|o|o|o|o|o|o| |o| | |X| | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 7

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|X| | | |o| | |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o| |o| |o| | |o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| | |o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| | |X| |o|o|o| |o|Z|
|Z|o|o|o|o|o|o| | |o| |o|o| | |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o| |o|o|o|o| | |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|Z|
|Z| |o|o|o|o|o| | |o|o|o|o| |o| | |o|o|Z|
|Z|o|o|o|o|o|o|o| |o|o|o| |o|o| | | |X|Z|
|Z|o|o|o|o|o|o|o|o|o| |o| | |o|o| | | |Z|
|Z|o|o|o|o|o|o| | |o|o| |o| |o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o| | |o| | | |o| | | |Z|
|Z|o|o|o|o|o|o| |o|o|X|o| |o| | | | | |Z|
|Z|o|o|o|o|o| |o| | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 8

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|X|o|o| |o| | |o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o| |o| |o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o| | | | | |o| | |o|o|Z|
|Z|o|o|o|o|o|o|o| |o|X|o|o|o| |o|o| |o|Z|
|Z|o|o|o|o|o| |o|o|o|o|X|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o| |o|o|o|o|o|o| |o| |o|Z|
|Z|o|o|o|o|o|o| | |o| |o| |o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o| |o|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o| | |o| | |o|o|X| |Z|
|Z|o|o|o|o|o| |o|o|o|o|o|o|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| |o| | | | | | | |Z|
|Z|o|o|o|o|o|o| |o|o| | | | |o| | | | |Z|
|Z|o|o|o|o|o|o|o| |o|o|X| | | | | | | |Z|
|Z|o|o|o|o|o|o|o| | |o|X| | |o| | | | |Z|
|Z|o|o| | | |o| | |o| | | |o| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 9

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o| |o|o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o| |o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| | | |o| | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 10

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|X|o| | |o| | |o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o| | |o| | | |Z|
|Z|o|o|o|o|o|o|o|o| | |o|o|o| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 11

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|X| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|o|Z|
|Z|o|o|o|o|o|o|o|o| | | | | | | | |o| |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o| | |o| | | | |Z|
|Z|o|o|o|o|o|o|o|o| |X|o| |o| | |o| | |Z|
|Z|o|o|o|o|o| |o| |o|o|o| | |o| | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 12

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 13

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | |o| |o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 14

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|X|o| |o|o| | |o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o| | |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o| |o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 15

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 16

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|X|X|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 17

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o| |o| | |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 18

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 19

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o| |o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 20

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o| |o|o|o|o| |o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X| |o|o|o|X| | |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | |o| |o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 21

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 22

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o| | |o|o|o|o|o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 23

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o| |o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|X|o| | |o|o|o|Z|
|Z|o|o|o|o|X|o|o| |o|o| |o|o| | |o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 24

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 25

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|X| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X| |o|o|Z|
|Z|o|o|o|o|X|o|o|o| |o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o| | |o|o| |X| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 26

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o| |o|o| |X|Z|
|Z|o|o|o|o|o|o| |o|X| | | | | | |o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 27

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|X|o|X|o|o|o|o|o|o|o|o| |X|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 28

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| | |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o| |X|o|Z|
|Z|o|o|o|o| |o|o|o|X|o|o|o|o|o| | |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 29

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o| |o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| | |X|o|o|X| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o| | |o|o|X|Z|
|Z|o|o|o| |o|o|X|o|o|o|o|o|o| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 30

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 31

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o| |X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o| | | |X|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 32

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|X|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o| | |o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X| | |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o| |o|o|o|X|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o| |X|X|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o| | |o|o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 33

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|X|o|X|o|X| |Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|X|o|o|X|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o| |o|X| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 34

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X| | |o| |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o| | | |o|X| | |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|X|X|o|X| | |Z|
|Z|o|o|o|o|o|o|o|o| |o| |o| |o|X| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 35

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|X|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X| | | | | |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o| | |X| |Z|
|Z|o|o|o|o|o|o|o|o|o| | |o| | |X| |X| |Z|
|Z|o|o|o|o|o|o|X|o| |o|o|o| | |X| | | |Z|
|Z|o|o|o|o|o|o|o| |o| |o| | |X| |X| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 36

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |X|o|o|Z|
|Z|o|o|o|o|o|X|X|o|o|o|o|o|o|X| |X| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |X| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 37

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |X| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |X|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | |o| | | | |Z|
|Z|o|o|o|o|o|X|X|o|o|o|o|X|o|X| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 38

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|X|o|o|o|o|X|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o| |X| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | |o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o| | | | |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o| | | |o|X| |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o| | |o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|X| | | | | |Z|
|Z|o|o|o| |X|o|o|X| |o|o| | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 39

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o| |o| |X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|X|o| |X| | | |Z|
|Z|o|o|o|X|o|o|o|o|X|o|o|o|o|o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 40

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o| |o|X|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|o|o|X|X| | | |Z|
|Z|o|o|o|o|o|o|o|X|X|o|o| |X|o| | | |o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|X|X| | | | | | |Z|
|Z|o|o|o|o|o|o|o| |o|o|o|o| |o| | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 41

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |Z|
|Z|o|o|o|X|o|o|o|o|o|X|o|o|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X| |X|Z|
|Z|o|o|o|o|o|o|o| |o| | |o|X| | |X| | |Z|
|Z|o|o|o|o|o|o|o|X|o|o|X|X| | | | | |o|Z|
|Z|o|o|o|o|o|X|o|o|o|X|X| | |X| | | | |Z|
|Z|o|o|o|o|o|o|X|o|o|o|o| | |o| | | | |Z|
|Z|o|o|o|o| | | |o| |o| |X| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 42

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X| | |o| |X|o|Z|
|Z|o|o|o|o|o|o|o|o|X|X|X|o| | | |X|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | | | | | | |Z|
|Z|o|o|o|o|X|o|o|X|o|X|X| |X|X| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 43

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|X|X|o|o|o|X|o| |X|Z|
|Z|o|o|o|o|o|o|o| |o|o|o| | | | | |X| |Z|
|Z|o|o|o|o|o|o|o| |X|X|X| |X| | | | | |Z|
|Z|o|o|o|o|o|X|o|o|X| | | | | | | | | |Z|
|Z|o|o|o|o|o|o| | |X| |o| | |X| | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 44

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X| | |X| |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o| | |o| |o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o| |o| | | |Z|
|Z|o|o|o|o|o|o|o|o| |o|o| | |X| |X| | |Z|
|Z|o|o|o|o|o|o|o|o|X|X|X|o|X| | | | |X|Z|
|Z|o|o|o|o|X|o| |o| | | |X| | | | | | |Z|
|Z|o|o|o|o|o|o| |X|X| |o| | | | | | | |Z|
|Z|o|o|o|o| | |o| | |X| | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 45

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o| |o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| | | |Z|
|Z|o|o|o|o|o|o|o|X|o|o|X|o| |o|o| |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|X|o| | | | | | | | |X|Z|
|Z|o|o|o|o|X|o|o|o| |X|X| | | | | | | |Z|
|Z|o|o|o|o|o|o| |X|o| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 46

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o| |Z|
|Z|o|o|o|X|o|o|o|o|o|o|o| |o|o| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|X| |o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X| | |X| | | |Z|
|Z|o|o|o|o|o|o|o|X| | | | | | | |X| | |Z|
|Z|o|o|o|o|o|X| |o|X| |X| | | | | | | |Z|
|Z|o|o|o|o|o| | |X| | | | | | | | | | |Z|
|Z|o|o|o|o|o| |o|o|X| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 47

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|X|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |X|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o| | | | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X| |o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|X|X|o| |o| |Z|
|Z|o|o|o|o|o|o|o| | | |X| | | | |o| | |Z|
|Z|o|o|o|o|o|o|X|o|o| |X| | | | | | | |Z|
|Z|o|o|o|o|o|o| |X| |X| | | | | | | | |Z|
|Z|o|o|o|o| |o| | | | | | | | | | | | |Z|
|Z|o| |o| | |o|X|X| | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 48

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|X|o| |X|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|X|X| | |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|X|X|X|X|o|o| |Z|
|Z|o|o|o|o|o|o|X|o|o|X|o|X| | | | |o|o|Z|
|Z|o|o|o|o|o|o|o|X|X|o| | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|X| |X| | | | | | | | |Z|
|Z|o|o|o|o|o|X|o|o| | | | | | | | | | |Z|
|Z|o|o|o|o|o|X|o|o|X|X| | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 49

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X| |X|o| | |X|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o| |o|X| | |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X| |X|o| |o|X|o|o| |Z|
|Z|o|o|o|o|o|X|o| | | |X|X| | | |X| | |Z|
|Z|o|o|o|o|o|o|o|X|X|o|X| | | | | | | |Z|
|Z|o|o|o|o|o|o| |o| |X|X| | | | |o| |o|Z|
|Z|o|o|o|o|o| | |o| | | | | | | | | | |Z|
|Z|o|o|o|o|X|o|X|X|X| | | | | | | | | |Z|
|Z|o|o|o|o|X|o| | |o| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 50

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o| |X|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|X| | |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o| |o| | |o|o| |Z|
|Z|o|o|o|o|o|o|o| |X| |o|X| | |o| | |X|Z|
|Z|o|o|o|o|o|X|o| |o| | |X| |X|o|X|X| |Z|
|Z|o|o|o|o|X|o|o|o| | |X| | | | | | | |Z|
|Z|o|o|o|o|o| |X|o| |X| | |X| | | | | |Z|
|Z|o|o|o|o| | |o|X|X| | | | | | | |o| |Z|
|Z|o|o|o|o| |o| |X| |X| | | | | | |o| |Z|
|Z|o|o|o|X|o|X| | | | | | | | | | | | |Z|
|Z|o|o| | |o|X| | |X| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 51

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X| |o| |X|o|o| |Z|
|Z|o|o|o|o|X|o|o|o|X| | | |X| |X| | | |Z|
|Z|o|o|o|o|o|X|o|X|X| | |X| | | | | |X|Z|
|Z|o|o|o|o|o|o|o|X| | | | | | | | | |o|Z|
|Z|o|o|o|o|o|o|X| | |X| | | | | |o| |o|Z|
|Z|o|o|X|o|o|X| | | | | | | | | |o| | |Z|
|Z|o|o|o|o|X|o| | | |X| | | | | | | | |Z|
|Z| |o|o|o|o| | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 52

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o| |X| |o| |Z|
|Z|o|o|o|o|o|o|o| | |X| |o|X| | |X| |o|Z|
|Z|o|o|o|o|o|X|X|X|o| | | | | | | | |o|Z|
|Z|o|o|o|o|o|o|X| | | | | | |X| | | | |Z|
|Z|o|o|o|o|o|X|X| | | | | | | | | | |X|Z|
|Z|o|o|X|o| |X| | | | | | | | | | |o| |Z|
|Z|o|o|o|X|o|o| | |X| | | | | |o| |o| |Z|
|Z|o|o|o| |o| | | | | | | | | | | | | |Z|
|Z|o| |o|o| | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 53

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X| |Z|
|Z|o|o|o|o|o|o|o|o| |o|X|o| |X| | | |o|Z|
|Z|o|o|o|o|o|o|o| |X|o| | |X| | | |X|o|Z|
|Z|o|o|o|o|o|X|X|o| | |o| |o| | | | | |Z|
|Z|o|o|o|o|o|o| | |X| | | | | | | | | |Z|
|Z|o|o|o| |X|X| |X| | | | | | |X| |o| |Z|
|Z|o|o|o| | | | | | | | | | | | | | | |Z|
|Z|o|o|o|X| |o|o|X| | | | | | | |o|X| |Z|
|Z|o|X|o|o|X| | | | | | | | | | | | | |Z|
|Z|o|o| |o| | | | | | | | | | | |o| | |Z|
|Z| |o|o| | |o| | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 54

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o| | | |o|Z|
|Z|o|o|o|o|o|X|X|o|o|X| |o| |o|o| | |X|Z|
|Z|o|o|o|o|o|o| |X|o|o|o| |X| | | | | |Z|
|Z|o|o|o|o|X|X|o| | |o|o| | | | | |o| |Z|
|Z|o|o|o|o|o|o| | | | | | | | | |o| | |Z|
|Z|o|o|o|o|o| | |X| | | | | | | | | | |Z|
|Z|o|o|o|o|o|o|X| | | | | | | | |X| | |Z|
|Z|o|o|X|X|o|o| | | | | | | | | | |o| |Z|
|Z|o|X|o| |o| | | | | | | | | | | |o| |Z|
|Z| |o| |o|o|o| | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 55

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|o| |Z|
|Z|o|o|o|o|o|X|o| |X|o|o| |X|o|o| |o|X|Z|
|Z|o|o|o|o|o|o|o|X|X|o|o| | |X| | | | |Z|
|Z|o|o|o|o| |X| |o|o| | |o| | | | |o| |Z|
|Z|o|o|o|o|o|o|X| | | | | | | | | | | |Z|
|Z|o|o|o|X| | | | | |o|o| | | | | |o| |Z|
|Z|o|o|o|o|o|o| | | | | | | | | | | | |Z|
|Z|o|o| |o| |X| | | | | | | | | | | | |Z|
|Z| |X|o|o| |o|o| | | | | | | | | |X|o|Z|
|Z| |o|X| | |o| | | | | | | | | | | | |Z|
|Z| |X|o|o|o| | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 56

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|X|Z|
|Z|o|o|o|o|o|X|o|o|X|o| |o| | |o| |X|o|Z|
|Z|o|o|o|o|o|o|X|o|o|X|o|o| |X|X| | | |Z|
|Z|o|o|o|o|o|X|X|o|X| | |o|o|X|X|X|o| |Z|
|Z|o|o|o|X|o|X|X|X|X|X|o| | |X| | | | |Z|
|Z|o|o|o| |X| |o| |o| | | | | | | | |o|Z|
|Z|o|o|o|o|o| | | | |o| | | | | | | | |Z|
|Z|o|X|o| |o| | | | | | | | | | | | | |Z|
|Z|X| |o| |o|o| | | | | | | | | | | | |Z|
|Z|o|o|X|X| |o|X|X| | | | | | | | | |X|Z|
|Z| |X| | |o| | | | | | | | | | | | |X|Z|
|Z| |o|X|o| | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 57

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|X| |Z|
|Z|o|o|o|o|X|o|o|X|o|o|o|o| |o|X|o| |X|Z|
|Z|o|o|o|o|o|X|o|o|X|o|X|o|o|X| | | | |Z|
|Z|o|o|o|o|X|o|o|X|o| |o|o|X|X| | |X| |Z|
|Z|o|o|o|o|X| |o| |o| |X| | | | | |o| |Z|
|Z|o|o|o|o|o|X|X|X|X| | | | | |X| | |o|Z|
|Z|o|o|o|X|o|o| | | | | | | | | | | | |Z|
|Z|X|o|o| |o|o| | | |o|o| | | | | | | |Z|
|Z|o| |X|o|X| | |X| | | | | | | | | | |Z|
|Z|X|X|o|o|o|X| | | | | | | | | | | | |Z|
|Z| |o| |o| |o| | | | | | | | | | |X| |Z|
|Z|o| | |X| | | | | | | | | | | | | |X|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 58

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| | |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o| |o|X|o|o|Z|
|Z|o|o|o|o|o|o| |o|X|X| | |o|X| |X| | |Z|
|Z|o|o|o|o|X|o| | |o|X|o|X|X| |X| | |X|Z|
|Z|o|o|o| |o|X|X|o| | |X| | | | | | | |Z|
|Z|o|o|o|X|o| |X| |X|o| | | | | | |X|o|Z|
|Z|o|o|o| |X| | | | | | | | | | | | | |Z|
|Z| |o|o|o|X|X| | | | |o| | | | | | | |Z|
|Z| | |o|o|X| | | |X| | |o| | | | | | |Z|
|Z|X| |o| | | |o| | | | | | | | | | | |Z|
|Z|X| |X| |X| | | | | | | | | | | | | |Z|
|Z| |X| |X| | | | | | | | | | | | | |X|Z|
|Z| |o| | | | |o| | | | | | | | | |X| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 59

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|Z|
|Z|o|o|o|o|o|X| |o| |X| | | | |X| |X| |Z|
|Z|o|o|o|o|o| |o| |o|o|o|X|X| | | |o| |Z|
|Z|o|o|o| |o| |o| |X| |X|X| | | | |X| |Z|
|Z|o|o|X|o|X| | |X| | | | | | | | | | |Z|
|Z|o|o| |o|X| | |X| |X| | | | | | | |X|Z|
|Z|o| | |o| | | | |X| |o| | | | | | | |Z|
|Z|o|o| |X| | | | | | | | |o| | | | | |Z|
|Z|o|X| |X| |X|X|o| | | | | | | | | | |Z|
|Z| |X|X|o| | | | | | | | | | | | | | |Z|
|Z| | | |X| | | | | | | | | | | | | | |Z|
|Z| | | | |X| | | | | | | | | | | | | |Z|
|Z| |X| | | | | |o| | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 60

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|X|Z|
|Z|o|o|o|o|X|o|o|o|o|o|X|o| |X|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|X|X| | | | |o|X| |Z|
|Z|o|X|o|o|X|o|X| | | | | | | | | | | |Z|
|Z|o|o|o|o|o| |o| |X| | |X| | | | | | |Z|
|Z|o|o|o|o| | | | | |X| | |o| | | | | |Z|
|Z|o|o|o|X|X| | | | | |X|o| | | | | |X|Z|
|Z|X|o|o|o| | | | | | | | | | | | | | |Z|
|Z|X|o| | | | | |X| | | | | | | | | | |Z|
|Z| | | |X| | |X| | | | | | | | | | | |Z|
|Z| |X| | |X| | | | | | | | | | | | | |Z|
|Z| | | | | | | |o|o| | | | | | | | | |Z|
|Z| | |X| | |X| | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 61

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|X| |Z|
|Z|o|o|o|o|o|X|o|o|o|X|o| |X|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|X| | |X| | |o|Z|
|Z|o| |o|o| |X| | |o| | | | | |o|X| | |Z|
|Z|X|o|o|o|o|X| |o| | | | | | | | | | |Z|
|Z|o|o|o| | |o| | | | | | | | | | | | |Z|
|Z|o|o| |X|o| | |o| | | | |X| | | | | |Z|
|Z| |o| |o| | | | | | | |X| | | | | | |Z|
|Z|o|X| |X| | | | | | | | | | | | | |X|Z|
|Z| |X|o| | | |X| | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | |X| | | | |o| | | | | | | | | | |Z|
|Z|X| | | | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | |o| | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 62

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|X| |o|o| |o| |Z|
|Z|o|o|o|o|o|o|o| | |o|X| |o|o| | | |o|Z|
|Z|o|o|o|o|X| |X| | | |X| | | | | |X| |Z|
|Z| |o|o|o|o|o|o| |X| | | | | |X| | | |Z|
|Z|o|X|o| |X|o| | | | | | | | | | | | |Z|
|Z|o|o|X| | | |o| |o| | |X| | | | | | |Z|
|Z|o| | |o| | | | | | | | | | | | | | |Z|
|Z| |X| |X| | | | | | | | | | | | | | |Z|
|Z| |o| | | | | |X| | | | |X| | | | | |Z|
|Z| | |X| | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 63

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|X|o|o|o|o|X|o|o|o|o|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|X| |o| |o|o|X| | |Z|
|Z|o|o|o|o|o|X|o|o|o| | | | |o| | | | |Z|
|Z|X|o|X|o|o|X|o|X| |o| | | | | | | | |Z|
|Z|o|o|o| |o| |o| | |o| | | | | | | | |Z|
|Z|X|o| |X| | | | | | | | |X| | | | | |Z|
|Z|o| | | | | | | | | | | |X| | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | |o| | | | | | | | | | |Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 64

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|X|o|o|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|X|X|Z|
|Z|o|o|o|o|o|o|o|o|X|o|X|o|o| |X|o| | |Z|
|Z|o|o|o|o|X|X|X|o|X|X| |X|o|X| | | | |Z|
|Z| |o|X|X|o|o|X|o|X|o| |o|o| |o| | | |Z|
|Z|o|X|o|o|X|o|X|o| | | | | | | | | | |Z|
|Z|o| |X|o| |o| | | | |o| | | | | | | |Z|
|Z|o|X| |X| | | | | | | | | | | | | | |Z|
|Z|X|X| | | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | |o| | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | | | | |o| | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 65

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o| |o|o| |X|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o| |o|o|X|X|o|X| | |X| |Z|
|Z|o|o|o|o|o|X|X|X|o| | |X| | |o|X| | |Z|
|Z|o| | | |o|o| |X| | | |o|X| |o| | | |Z|
|Z|o| |o| |X|X| |X| |X|o| | | | | | | |Z|
|Z|X|o|X|X| |X| |X| | | | | | | | | | |Z|
|Z| | | |X| | |o| | | | | | | | | | | |Z|
|Z|X|X| | | | | | | |o| | | | | | | | |Z|
|Z| | |X| |X| |o| | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|X| | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | |o| |o| | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 66

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X| |Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|X|o|o|o|X|o| |Z|
|Z|o|o|o|o|o|X|X|o|X|o| | |X|o|o|X| |X|Z|
|Z|o|o|o|o|o|o| |o|X| |o|o| | |X| | | |Z|
|Z|o|o|o|o|X|X|o| | | | |X| | |X| | | |Z|
|Z|X|o|X|o|o| | |X| | |X|X| | | | | | |Z|
|Z| |X| | | | |X| | | | | | | | | | | |Z|
|Z| | | | | | |X| | | | |o| | | | | | |Z|
|Z| | |X|X| | |o| | | |o| | | | | | | |Z|
|Z|X|X| | | | |o| | | | | | | | | | | |Z|
|Z| | | |X| | | | | | |o| | | | | | | |Z|
|Z| |X| | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | |o| | | | | |Z|
|Z| | | | | | | | | |o| | |o| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 67

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|X| |Z|
|Z|o|o|o|o|o|o|o|o|o| |X| |o| |X| | | |Z|
|Z|o|o|o|o|X|o| |X|X|o|X|o|o| | |o|X| |Z|
|Z|o|o|o|o| |o|o| |o| | |o| |X|X|o| | |Z|
|Z|o|o|o|X| |X| |X|o| |X|X| | | | |X| |Z|
|Z| |X|o| |o| |X| | | | | | | | |X| | |Z|
|Z|o|X|o| | | | | | | | | | | | | | | |Z|
|Z| | | |o|o| | | | | |X|X| | | | | | |Z|
|Z| |X|X| | | | |X| | | | |o| | | | | |Z|
|Z| | | | | | |X| | | | | | | | | | | |Z|
|Z| | | | | |o| | | | |o| | | | | | | |Z|
|Z| |X| | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | |o| | | | |Z|
|Z| | | | | | | | |o| | | |o| | | | | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 68

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X| | |Z|
|Z|o|o|o|o|o|X|o|o| |X|o| | | |o| | | |Z|
|Z|o|o|o|o|o|X| |X|X|o|o|o| | |o| | | |Z|
|Z|o|o|o| |o| |o|o| | | |X|X| |X|X| | |Z|
|Z|o|o| | |o| |X| | |o| |X| | | |X| | |Z|
|Z| | |X| |o|X| | |X|o| | |X| | | | | |Z|
|Z|o|o|X|o| | | | | | | | | | | | |X| |Z|
|Z| | |X| | |o| | | | | | | | | | | | |Z|
|Z| |o| |X| | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | |X|X| | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | |X| | | |o| |o| | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | | | | | |o| | | | | |Z|
|Z| | | | | | | |o| | | | | | |o| | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 69

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|X|o|o| |o|o|o|X| |X| |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|X|X| |X|X| | |Z|
|Z|o|o|o|o|o|o|X|X|o|o|o|X| | | |X| | |Z|
|Z|o|o|o|o|o|X|o| | |X|o| | | | | | | |Z|
|Z|o|o|o|o|X|o|o| | |o| | | | | | | | |Z|
|Z|o|X| |X|o|o| | | | | | | |X| | | | |Z|
|Z| |o| | | | | | | | | | | | | | | | |Z|
|Z| |X|o| | | | | | | | | | | | | | | |Z|
|Z| | | |X| | | | | | | | | |X| | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | |X| | | | | |o| |o| | | | | |Z|
|Z| | | | | | | | | |o| | | |o| | | | |Z|
|Z| | | | | | | | |o| |o| | | | | | | |Z|
|Z| | | | | | | | |o| | |o| |o| | | | |Z|
|Z| | | | | | | | | | | | | |o| | | | |Z|
|Z| | | | | | |o|o| |o| | | | | | | | |Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 70

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o| | | | |Z|
|Z|o|o|o|o|o| | |o|o|X|o|o|X|X|o|X| | |Z|
|Z|o|o|o|o|o|X|X|X|X|o| |o| | | | |X| |Z|
|Z|o|o|o|o|o| |o| |X| |X| | | | | |X| |Z|
|Z|o|o|o| |X| | |o| |o|X| | | | | |X| |Z|
|Z| | |X|X|o|o| | | | | | | | | | | | |Z|
|Z| |o|o| | | |o| |o| | | | | | | | | |Z|
|Z|o|X| | |o| | | | | | | | | | | | | |Z|
|Z| | |X| | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | |X| | | | |o| | |X| | | | | |Z|
|Z| | | | | |X| | |o| | | | | | | | | |Z|
|Z| | | | | | | | | |o| | |o| |o| | | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z| | | | | | | | | | |o| |o| | | | | |Z|
|Z| | | | | | | |o|o|o| | | | | | | | |Z|
|Z| | | | | | | | |o|o| | | |o| | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 71

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|X|X| | | |Z|
|Z|o|o|o|o|o|o|o|X|X| | | |o| |X| | | |Z|
|Z|o|o|o| | |o| | | |X| |X| | | | | | |Z|
|Z|o|o|o|X|X| |X| | | | | | | | | | | |Z|
|Z| |X| |o|o| | |X| |X| | | | | | | | |Z|
|Z|o| | | | | | | | | | | | | | | | | |Z|
|Z| |X|X| |o| | | | |o| | | | | | | | |Z|
|Z| | | | | | |o| | | | | | | | | | | |Z|
|Z|o| | | | |o| | | | | | | | | | | | |Z|
|Z| | |X| | | | | | | |o| | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | |o| | | | |Z|
|Z| | | | | | | | | | |o| | |o| | | | |Z|
|Z| | | | | | | | |o|o| | | | | | | | |Z|
|Z| | | | | | |o| | | | | | | | | | | |Z|
|Z| | | | | | | |o|o|o| | |o| | | | | |Z|
|Z| | | | | | | |o| | | | | | | | | | |Z|
|Z| | | | | | | | | | | | |o| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 72

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|o| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|X|X|X|X|o|X| | | |Z|
|Z|o|o|o|o|o|X|o|o|X|o|X| |X|X|o| | | |Z|
|Z|X|o|o|o|o|o|X|X|X|X|X| | | | | | | |Z|
|Z|X|o|o|o|X|X|X|X| | | | | | | | | | |Z|
|Z|X|o|o|o| |X| | | | | | | | | | | | |Z|
|Z| |X|o| |X| | | |o| | | | | | | | | |Z|
|Z| | | |X| | |o| |o| | | | | | | | | |Z|
|Z| |o|X|X|o| |o| | | | | | | | | | | |Z|
|Z| | |o| |o| | | | | |o| | | | | | | |Z|
|Z| | | | | | | | | |o|o| | | | | | | |Z|
|Z| | | | | | | | | | |o| | | |o|o| | |Z|
|Z| | | | | | |o| |o|o|o|o| | |o| | | |Z|
|Z| | | | | | | |o| | | | | | |o| | | |Z|
|Z| | | | | | | |o|o|o|o|o| | | | | | |Z|
|Z| | | | | | |o|o|o| | |o| | | | | | |Z|
|Z| | | | | | |o|o| | |o| | | | | | | |Z|
|Z| | | | | | | |o| | | |o| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 73

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o| |o| |X|X| | | | | | |Z|
|Z|o|o|o|o|X|o| |X|X| |X| | |X| | | | |Z|
|Z|o|X|o|o|o|o|X|X|X|X| |X|X| |X| | | |Z|
|Z|o|o|o| |X|X| |X|X| | | | |X| | | | |Z|
|Z| |X|o|o|o| | | | |X| | | | | | | | |Z|
|Z| |X| |X| | | | |o| | | | | | | | | |Z|
|Z| | |X|X| |X| |o| | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| |X| | |X| | | | | | | | | | | | | |Z|
|Z| | |X|o| |o| | |o|o| | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | |o| | |Z|
|Z| | | | | | | | | |o|o|o|o| | | | | |Z|
|Z| | | | | | | |o| | | | | |o| |o| | |Z|
|Z| | | | | |o| |o| | | | | |o| | | | |Z|
|Z| | | | | | |o|o|o|o| | | | | | | | |Z|
|Z| | | | | | |o|o|o|o|o| | | | | | | |Z|
|Z| | | | | |o| | | | | |o|o| | | | | |Z|
|Z| | | | | | | | |o| |o| | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 74

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|X| | | |o|X|X| | |X| | | | | |Z|
|Z|o|o|o| |o| |o|X|X|X| | |X| | |X| | |Z|
|Z|o|o|o| |X|X|o| | | |X| |X| | | | | |Z|
|Z|X| |X|o| | | | | | |X| | | | | | | |Z|
|Z|o| |X|X|X| | |X| | | | | | | | | | |Z|
|Z| | |X|X| | | |o|X| | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | |X| | | | | | | | | | | | |Z|
|Z|X| | | | | | | | |o|o| | | | | | | |Z|
|Z| | | |X| |X| | | |o|o| | | | | | | |Z|
|Z| | | | | | | | | | |o| |o| | | | | |Z|
|Z| | | | | | | | |o|o| |o| | |o| |o| |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | |o| |o|o|o|o| | | |o| | | |Z|
|Z| | | | |o|o| | |o| |o|o| | |o| | | |Z|
|Z| | | | | | | | | | | |o| | | | | | |Z|
|Z| | | | |o| |o|o| |o| |o| | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 75

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o| |X|X| | |X| |X| | | | |Z|
|Z|o|o|X|o| | |X| | | | | | | | | | | |Z|
|Z|X|o|X|o| | |X| |X|X| | | | | |X| | |Z|
|Z| |o|X|X| | | | | | | | | | | | | | |Z|
|Z| | |o|X| | | | | | | | | | | | | | |Z|
|Z| |o| | |X| | |X| | | | | | | | | | |Z|
|Z|o|X| | | | | | | |X| | | | | | | | |Z|
|Z| |X| | | | | | |o|o| | | | | | | | |Z|
|Z| | | | | | |X|o| | |o|o| | | | | | |Z|
|Z| | | | | | | | | | | |o|o|o| | | | |Z|
|Z| | | |X| | | | |o|o|o|o| |o|o| | | |Z|
|Z| | | | | | |o| | |o|o|o| |o| | |o| |Z|
|Z| | | | | | | |o|o|o|o|o|o| | | |o| |Z|
|Z| | | | |o|o|o|o|o|o|o| | |o| | | | |Z|
|Z| | | |o| | |o|o|o|o|o|o|o|o| | | | |Z|
|Z| | |o| |o|o|o|o|o| |o|o| | |o| | | |Z|
|Z| | | |o| |o|o| | | |o|o| | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 76

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o| |o| |X|X| | | | | | | | | | | |Z|
|Z| |X|o| |o|X| | | | | | | | | | | | |Z|
|Z|o|X| |X|o| | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z|o| |X| |X| | |X| | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|X| | | |X| | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |X|o| | | | | | | |Z|
|Z| | | | | | | |X| |o|o| |o| |o| | | |Z|
|Z| | | |X| | | | | |o|o|o|o|o| | | | |Z|
|Z| | | | | |o| | |o|o| | |o| |o| | |o|Z|
|Z| | | | | | |o| |o| |o| |o|o| | | | |Z|
|Z| | | | | | |o|o| | |o|o| |o| | | |o|Z|
|Z| | | | | |o|o|o|o|o|o|o|o| | | | | |Z|
|Z| | |o|o|o|o| |o|o| |o|o| | | | | | |Z|
|Z| | | |o|o| | |o| |o| | |o|o| |o| | |Z|
|Z| | | | |o| | | | |o| | |o| | | | | |Z|
|Z| | | | |o| | | | | |o|o| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 77

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| |X| | |o|X| | | | | | | | | | | | |Z|
|Z| |o|X| |X| | | | | | | | | | | | | |Z|
|Z|X| | | |X| | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|X| | | | | |X| | | | | | | | | | | |Z|
|Z| | | |X| | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|X| | | | | | |X|o| | |o| | | | | | |Z|
|Z| | | | | | | | | |o|X| |o|o|o|o| | |Z|
|Z| | | | | | | | | |o| | | | |o| |o| |Z|
|Z| | | | | | | | |o| |o|o| |o| | | | |Z|
|Z| | | | | |o|o|o| |o| |o|o|o| | | | |Z|
|Z| | | | | |o| | |o|o|o| | | | | | | |Z|
|Z| |o| |o| |o|o| |o|o|o|o| |o| | |o| |Z|
|Z| | | |o|o| |o|o|o|o| | | |o| | | | |Z|
|Z| | |o|o| |o| | |o| | |o| |o| | |o| |Z|
|Z| | | | |o| |o| |o| | | | |o| | | | |Z|
|Z| | | | | | | | | |o| | |o| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 78

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | |X|X| | | | | | | | | | | | | |Z|
|Z|X|X| |X| | | | | | | | | | | | | | |Z|
|Z| | | | | |X| | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | |X| | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z|X| | | | | | | | | |o|o| |o| | | | |Z|
|Z| | | | | | | | |X| | |o|o| | | | | |Z|
|Z| | | | | | |o| | |X| |o|o|o|o|o| | |Z|
|Z| | | | | | | |o| |o|o|o| |o| |o|o|o|Z|
|Z| | | |o| | | | |o|o|o|o|o| |o|o| | |Z|
|Z| | | |o|o|o|o|o|o|o|o|o|o| | |o| | |Z|
|Z| | | |o|o|o|o|o|o|o|o|o|o|o| | | | |Z|
|Z| | |o|o|o| |o|o|o|o|o|o|o| |o| |o| |Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o|Z|
|Z|o| |o|o| |o|o|o|o|o|o|o|o| | | | |o|Z|
|Z| | | |o| |o|o| |o| |o|o|o|o| | | | |Z|
|Z| | |o| | | |o|o| | |o|o|o|o| | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 79

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| |X| | |X| | | | | | | | | | | | | |Z|
|Z| | |X| | |X| | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | |X| | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | |o| |o| | | | | |Z|
|Z| |X| | | | | | | | | |o| | | | | | |Z|
|Z| | | | | | | | | |o|o| |o|o| | | | |Z|
|Z| | | | | |o| | |X| |o|o| |o| | |o| |Z|
|Z| | | | | | | | |o|X| |o|o| |o|o|o| |Z|
|Z| | |o| | |o|o|o|o| |o|o| |o|o| |o| |Z|
|Z| | |o|o|o|o| |o|o| |o|o|o| |o| |o| |Z|
|Z| | | | |o|o|o|o|o|o|o|o|o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z| |o| |o|o|o|o|o|o| |o| |o| | | |o| |Z|
|Z| |o|o| |o|o|o|o| |o| |o|o|o|o| | | |Z|
|Z|o| |o| |o|o|o|o| | |o|o|o|o| | |o| |Z|
|Z| | | | | | |o| |o|o| |o| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 80

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|X| | | | |X|X| | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z| | | | | | | | | | | |o| | | | | | |Z|
|Z| | | | | | | | | | |o|o| |o| | | | |Z|
|Z| | | | | | |o| | | | |o|o| | | | | |Z|
|Z| | | | | | | | |X|o| |o| |o| |o| |o|Z|
|Z| | | | | |o|o|o|X|o| | |o|o|o|o| |o|Z|
|Z| | | |o|o| | |o|o| |X|o|o|o|o| | | |Z|
|Z| |o| | |o|o|o| |o|o|X|o| |o|o|o| | |Z|
|Z| | |o|o|o|o|o|o|o|o|o|o| |o| |o|o|o|Z|
|Z| | |o|o|o|o|o|o|o|o| |o|o| | | | | |Z|
|Z|o| |o| |o|o|o| | | |o|o|o|o|o| | | |Z|
|Z|o|o| |o|o|o|o| |o| |o|o| | | |o| |o|Z|
|Z| |o| |o| |o|o| | | | |o|o| | | | | |Z|
|Z| | | |o|o|o| |o|o| |o| |o|o| |o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 81

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | |X| | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | |X| | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z| | | | | | | | | |o|o|o| | | | | | |Z|
|Z| | | | | | | | | | |o| | | |o| | | |Z|
|Z| | | | | | | | | | |o| | | |o| | | |Z|
|Z| | | | | |o| | |o|o|o|o|o|o|o|o|o| |Z|
|Z| | | | |o|o|o| |o|o|o|o|o|o|o|o|o|o|Z|
|Z| | | |o|o|o|o|X|o|o|o|o|o|o|o| |o|o|Z|
|Z| | | |o|o|o|o|X|o|o|o|o|o|o|o|o|o| |Z|
|Z|o| | |o|o|o|o|o|o|X|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 82

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | |X| | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | |o|o| | | | | | | | |Z|
|Z| | | | | | | | | | | |o| |o| | | | |Z|
|Z| | | | | | | | | | |o| |o| | | | | |Z|
|Z| | | | | | | | | |o|o|o|o|o|o|o|o| |Z|
|Z| | | | |o|o|o|o| | |o|o|o|o|o|o| | |Z|
|Z| | | |o| |o| |o| | | | |o|o|o|o|o| |Z|
|Z| | |o| |o|o|X|o|o|o|o|o| |o|o|o|o| |Z|
|Z| | |o|o|o| |X|o| |X|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| | | | | |o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 83

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | |o| | |o| | | | | | | |Z|
|Z| | | | | | | | | |o| |o| | | | | | |Z|
|Z| | | | | | | | | |o| |o|o|o|o| |o|o|Z|
|Z| | | | |o|o| | |o|o|o| |o|o|o|o| | |Z|
|Z| | |o|o| |o| |o|o| | |o| |o| | |o|o|Z|
|Z| | | | |o|o| | |o| |o|o|o|o|o|o| |o|Z|
|Z| |o| |o| |o| |X| | | |o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o| |o|X|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o| |o|o|o|o|o|X|o|o|o|X|o|o| | |o|Z|
|Z|o|o|o|o|o|o| |o|o|o|o| |o|o| |o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o| |o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| | | |o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o| |o|o| | |o| |o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 84

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | |o|o| | | | | | | | |Z|
|Z| | | | | | | | | | |o| |o| | | | | |Z|
|Z| | | | | | | | | | |o|o|o|o| | | | |Z|
|Z| | | | | |o|o|o|o|o|o|o|o| |o| | | |Z|
|Z| | | | |o| |o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z| | | |o|o| |o|o|o|o| |o|o|o|o|o|o|o|Z|
|Z| | | |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 85

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z| | | | | | | |o| | |o|o| | |o| | | |Z|
|Z| | | | | | |o| | |o|o|o|o| | |o| | |Z|
|Z| | | | |o|o|o| |o|o|o|o|o|o|o|o| | |Z|
|Z| | |o|o| |o| |o|o|o|o|o|o|o| |o|o|o|Z|
|Z| | | |o|o|o|o|o|o| |o|o|o|o|o|o|o|o|Z|
|Z| |o|o|o| |o|o| |o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o| | |X|o|o| |o|o|o|o| |Z|
|Z|o|o|o|o|o| | |X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 86

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | |o| | | | | | |Z|
|Z| | | | | | | | |o| |o| | | | |o| | |Z|
|Z| | | | | | | |o| |o|o|o| | | | |o| |Z|
|Z| | | | | |o| | |o|o|o|o| | | | |o| |Z|
|Z| | | |o|o| |o|o|o|o|o|o|o|o|o| | |o|Z|
|Z| | |o| |o| |o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o| |o| |o|o|o| |o|o|o|o|o| |o|o|o| |Z|
|Z|o|o| |o|o|o| |o|o|o|o| |o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o| |X|o|o| |o|o|o| |o| |Z|
|Z|o|o|o|o|o| | |o|o|o|o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o| |X|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|X|o|o| |o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o| | | |o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 87

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | |o|o|o|o|o|o| | | | |o|Z|
|Z| | | | | | | |o|o|o|o|o|o| | | |o| |Z|
|Z| | | | | |o| |o|o|o|o|o|o|o|o| |o|o|Z|
|Z| | | |o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z| | |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 88

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | |o|o|o|o|o| |o| | |o|o| |Z|
|Z| | | | | | |o|o|o|o|o|o|o|o|o|o| | |Z|
|Z| | | |o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z| | |o|o|o|o|o|o| |o|o|o|o|o|o|o|o| |Z|
|Z|o| |o|o|o|o| |o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|X|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 89

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | |o|o|o|o|o| |o|o|o|o| |o| |Z|
|Z| | |o|o| |o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z| | |o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|Z|
|Z| |o|o|o|o|o|o|o|o| |o|o|o|o|o| |o|o|Z|
|Z|o|o|o| |o|o|o|o|o|o|o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | | |o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o| |o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o| | |o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|X|o|o|o|o|X|o|o| | |Z|
|Z|o|o|o|o|o|o|o|X| |o|o| |o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o| |o|o|o|X|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 90

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 91

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|o|o| |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 92

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o| |o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o| |o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 93

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|X|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 94

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|X|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 95

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o| |o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o| |o|o| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 96

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 97

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 98

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o| |o| | |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|o| |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | | | |o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 99

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 100

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o| |o| |X|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 101

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o| | |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o| | |o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 102

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 103

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 104

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|X|o|o|o| |o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 105

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 106

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |X| |o|o|o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 107

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o| | |o|o|o| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 108

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 109

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |X|o|o|o| |o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 110

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X| |o|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o| |o|o|o|o| |o| |o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 111

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 112

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|X|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 113

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o| | |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o| |o|o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 114

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 115

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o| |o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o| | |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 116

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|X|o|o| | |o|o|Z|
|Z|o|o|o|o|o|o| |o|o| |o|o|o| |o| | |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 117

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 118

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 119

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o| |o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 120

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 121

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o| | |X|o|o|o|o| | |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 122

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o| | |o|o|o| |o| |o| |Z|
|Z|o|o|o|X|o|o| |o|o|o|X|o|o| |o|o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 123

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 124

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|X|o|o|o|o| |Z|
|Z|o| |o|o|o|o|o|o|o|o| |o|o|o|o|o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 125

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o| |o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o| |o|Z|
|Z| |o|o|o|o|o|o|o|o| |o|o| | |o| | |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 126

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 127

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|o| |Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |X|o|o|o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 128

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o| |o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|X|X| |o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 129

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 130

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|X|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o| |o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |X| |X|o|o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 131

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |X|o| |o|o|o|Z|
|Z|o|o|o|X|o|o|o|o| | |o| | |o|X| | |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 132

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|X| |o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 133

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| | |o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|X| |X|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 134

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o| | |o| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| | |o|o|X|o|X| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 135

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|X|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 136

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|X|o|o| |X| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 137

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X|o| | | |Z|
|Z|o|o|X|o|o|o|o|o|o|X| |o| | | | | |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 138

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|X| |X|o| |Z|
|Z|o|o|X|o|o|o|o|o|o|X|o|o|o|o| | | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 139

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| | |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o| | | |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o|o| | |Z|
|Z|o|o|o|X|o|o| |o|o| |o|o| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 140

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o| |o| |X| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X| | |o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| | |o| | |X|o| |Z|
|Z|o|o|X|o|o| |o| | |o| |X| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 141

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|X|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | |Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|X|o|o| |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 142

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|X|o| |X|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|X|o|X| | |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | |o| | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 143

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|X|o| | |X|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|X|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |X|o| | | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o| | |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|o| |Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o| | | | | | |Z|
|Z|o|o|o|o|o|o|o| | |o| |o| | |o| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 144

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|X|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|X| | | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|X|X| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |X|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o| | |Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 145

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X| |o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o| | |X| |X|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|X| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X| | | |o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|X| | |o| |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o| |o|o|o|X| | |Z|
|Z|o|o| |o|o|o|o|o|o|o|o| | | | |o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 146

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X| | |o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o| |o| |o|X|X| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|X| |X| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |X| | | | | |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X| | | | |X| |Z|
|Z|o|o|o|o|o|X|o|o|o|o|X|o|o|o| | |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| | |X| | | |Z|
|Z|o| |o|o|o| |o|o| |o| | | | | | |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 147

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|X|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o| | | |X| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o| | | | | | |Z|
|Z|o|o|o|o|X|o|o|o|o|o|X|o|o| | | | |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|X| |X| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | |o| |o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 148

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| | |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o| |o|X|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|X|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| |X| | |o| | | |X|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o| | | | |X| | |Z|
|Z|o|o|o|X|o|o|o|o|o|o|X|X|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X| | | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o| | | | | |o| | |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 149

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o| |X|o| |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|X|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|X|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o| |o| | | |o| |o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| | | | | | | | |Z|
|Z|o|o|o|o|X|o|o|o|o|o|X| | |o| | | | |Z|
|Z|o|o|o|o|o|o| |o|X|o|o| |X| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| |X|X| | |o| | |o|Z|
|Z|o|o|o|o|o| | |o| |o| | | | | | |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 150

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|X|o| |X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |X| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o| |o| | | |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X| | | | |Z|
|Z|o|o|o|o|o|o|o|X|o|X|X| |X| |o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| | | |o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | | | | | |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 151

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|X|o| |o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o| | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|X| | |Z|
|Z|o|o|o|o|o|o|o|o|o| | |o| |o| | | | |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o| | |o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|X| |X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | | |X| |o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o| | | |X| | |o| |Z|
|Z|o|o|o|o|o| |o|o| | | |o| | |o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 152

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|X|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|X|o| | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | |X| | |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|X|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |X|o|X|X| | |Z|
|Z|o|o|o|o|o|X|o|o|o|o| | |o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o| |X|X| | |X| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X| | |X|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| | | | | | |o| | |Z|
|Z|o|o|o|o| |o| |X|X| | | |o|X|X|o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 153

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |X|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | | | |X| | |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|X|X|o| | | |X| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|X| |X|X| | | |o|o|Z|
|Z|o|o|o|o|o|o|o|X|X| | | | | | | |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| | | |X| | |X| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 154

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|X|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|X|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|X| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|X| | |X| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |X| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| | | | | |X|Z|
|Z|o|o|o|o|X|o|o|o| | |o|o|o|X| | | | |Z|
|Z|o|o|o|o|o|o|o|o|X| |X| | |o| | |X| |Z|
|Z|o|o|o|o|o|o|o|o|o| |X|o| |X| | |o| |Z|
|Z|o|o|o|o|o|o|o| | | | | | | | | |o|o|Z|
|Z|o|o|o|o|o|o|o|o| |o| |X| |X| | |X| |Z|
|Z|o|o|o|o|o|o| |X|X| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 155

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |X|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|X|X|X|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o| | |X| | |X|Z|
|Z|o|o|o|X|o|o|o| | |o| |X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o| |o|o| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|X| | |o|X|o|X|X| | | |Z|
|Z|o|o|o|o|o|o|o|o| | | |X| | | | |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o| | | | |X| | | |X|Z|
|Z|o|o|o|o|o|o| |X| |X| | | | | | | | |Z|
|Z|o|o|o|o| | |o| | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 156

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | |X| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o| | |X| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | | | | | | |Z|
|Z|o|o|X|o|o|o|o|o|o|o|X| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| |X| |X| | | | | |Z|
|Z|o|o|o|o|o|o|o|X|o| | | |X| | | | |X|Z|
|Z|o|o|o|o|o|o|o|o|X|X| | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| | | | | | | |X| |Z|
|Z|o|o|o|o|o|o|o|o|o| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 157

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o| |X| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |X| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o| |X| |o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o| |X| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o| | | | | | |Z|
|Z|o|o|o|X|o|o|o|o| |X| | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o| |o| |X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|X| |X| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|X| | | |X| | | | | |X|Z|
|Z|o|o|o|o|o|o|o|o|X| | | | | | | | | |Z|
|Z|o|o|o|o|o|o|o| | |o| | | | | | | |X|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 158

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | | | |o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X| |o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o| | |X| | | |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|X| | | | | |Z|
|Z|o|o|o|o|o|o|o|o| |o| | | | | | | | |Z|
|Z|o|o|X|o|o|o|o|o|X| |o| |o| | | | | |Z|
|Z|o|o|o|o|o|o|o| |o| |o| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|X| |X|X| | | | | | | |Z|
|Z|o|o|o|o|o|o| | |o| | | | | | | |X| |Z|
|Z|o|o|o|o|o|o| |o| | | | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|X| | | | | | | | | | |Z|
|Z|o|o|o|o|o|o| | | |X| | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 159

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|X|o|o| | |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | | |Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|X| |X| |o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| | | |o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|X| | | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|X| | | | | | | | | | |Z|
|Z|o|o|o|o|o|o|o| |X| | | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o| | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 160

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|X|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o| | |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o| | | |o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o| |X| |o| | |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o| | | | |Z|
|Z|o|o|o|o|o|o|o|o| |o|X|X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|X|X| |o| | | | | |Z|
|Z|o|o|X|o|o|o|o|o|o|o| |o| | | | | | |Z|
|Z|o|o|o|o|o|o|X| |X|X| |o| | | | | | |Z|
|Z|o|o|o|o|o|o|X|X|o| | | |o| | | | | |Z|
|Z|o|o|o|o|o|o|X|o| | | | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|X| | | | | | | | | | |Z|
|Z|o|o|o|o|o|o| |X| | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 161

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o|X|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o| |o| |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X| |X| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o| |o| | |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o| |X| | |o| |Z|
|Z|o|o|o|o|o|o|o| |o| |o|o| | |o| |o| |Z|
|Z|o|o|o|o|o|o|o|X|o|X| |X|X| | | | | |Z|
|Z|o|o|o|o|o|o|o|o| |o| | | |o| | | | |Z|
|Z|o|o|o|o|o|o|o|o| | |o| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|X|X|X| | | |o| | | | |Z|
|Z|o|o|X|o|o|o| | | | |o| |o| | | | | |Z|
|Z|o|o|o|o|o|X| | |X| | | | | | | | | |Z|
|Z|o|o|o|o| |X| |X| | | | | |o| | | | |Z|
|Z|o|o|o|o|o|X|X|X| | | | | | | | | | |Z|
|Z|o|o|o|o| | |o| | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 162

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| | | |Z|
|Z|o|o|o|o|o|o|o|X|o|o|X|o|X|o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o| | | | |o| |Z|
|Z|o|o|o|o|o|o|X|o|o|o|o| | |X| | | | |Z|
|Z|o|o|o|o|o|o|o|X|o|X|X| | | |o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o| | |o| |o| | | | |Z|
|Z|o|o|o|X|X|o|o|X| | | |o| | |o| | | |Z|
|Z|o|o|o|o|o|o|o| |X| | | | |o| | | | |Z|
|Z|o|o|o|o|o|o|o| | | | | | | | | | | |Z|
|Z|o|o|o|o|X|o|X| | | | | |o| | | | | |Z|
|Z|o|o|o|o|o|X|X| | | | |o| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 163

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |X| |Z|
|Z|o|o|o|o|o|o|X|o|o|o| |o|X|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o| | |X|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|X| | | |o| |Z|
|Z|o|o|o|o|o|X|o| |o|o| | |o|o| |o| |o|Z|
|Z|o|o|o|o|o|o|o| |X| | | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|X| |o|o| | |X| | | |Z|
|Z|o|o|X|X|o|o| |o|X| | |X| | |o| | | |Z|
|Z|o|o|o|o|o|o| |o|X| |o| | | | | | | |Z|
|Z|o|o|o|o|o|o|X| | | | | | | | |o| | |Z|
|Z|o|o|o|X|o| | |o| | | | | | |o| | | |Z|
|Z|o|o|o|o| |X| | | | | | | |o| | | | |Z|
|Z|o|o|o| |X|X| | | | | | |o| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 164

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o| | | |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X| | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| | |o|o|o| | | |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o| | | | |X| |Z|
|Z|o|o|o|o|o|o|o|o|X| | | |X|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| | |o|o|X| | | |Z|
|Z|o|o|o|o|o|o|X|o| |o| | |o|o| | | |o|Z|
|Z|o|o|o|o|o|o|o|o|X| | |o| |X|o| |o| |Z|
|Z|o|o|o|o| | |o| | | |o| | | | | |o| |Z|
|Z|o|o|o|o|X|o| |X| | |X| | | | | | | |Z|
|Z|o|o|o|o|o|o| |X| | |o|o| | |X| | | |Z|
|Z|o|o|X| |o|X|o|X| | | | | | |o| | | |Z|
|Z|o|o|X|o|o| |o| | | | | | | |o| | | |Z|
|Z|o|o| |o|X| | | | | | | | | | | | | |Z|
|Z|o|o|o|X| |X| | | | | | | | |o| | | |Z|
|Z|o|o| | | | | | | | | |o| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 165

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o| |Z|
|Z|o|o|o|o|X|o|o|o|X|o|o|X|o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|X| | |Z|
|Z|o|o|o|o|o|o|o|X|o|o| |o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X| |o|o| |o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o| |o| |o| |o|X|o| |o|Z|
|Z|o|o|o|o|o|o|X|o|o| | | | | |o| |o| |Z|
|Z|o|o|o|o|o|X|o| | |o| | | | | | | |o|Z|
|Z|o|o|o|X| |o| | |o| | |X| | |o| |o| |Z|
|Z|o|o|o|o|o|o|X| | | |o| | | |X|o| | |Z|
|Z|o|o|o|o|o|o|X|X| | | |o| | | | | | |Z|
|Z|o|X|o|X| |o| | | | | | | | | | | | |Z|
|Z|o|o|X|o| |o| | | | | | | |o| | | | |Z|
|Z|o|o|o|o| | | | | | |o|o| | |o| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 166

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X| |X| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o| | |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|X|o| | | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o| |X| | | |Z|
|Z|o|o|o|o|o|o|X|o|o|X| |o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o| |o|o| |o|o| |o| | |o|o|Z|
|Z|o|o|o|o|o|o| |o| |o| |o|o|o|X|X|o| |Z|
|Z|o|o|o|o|o|X|X| | |o|o| | | | | |o|o|Z|
|Z|o|o|o|o| |X|o| |o| | | | |o| |o| | |Z|
|Z|o|o|o|o| |o| | |o| | | | | | | | | |Z|
|Z|o|o|o|o|o|X| |o| |o| | | | |X| | |o|Z|
|Z|o|o|X|o|o|X| | | | |X| | | | | |o| |Z|
|Z|o|o|X| | | |X| | | | | | | | |o| | |Z|
|Z|o|o| |o|o|o|o| | | | | |o| | | | | |Z|
|Z|o| |o|X|o| | | | | | | |o|o| | | | |Z|
|Z|o| |X| |o| | | | |o|o| | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 167

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o| |X| | |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|X| | |X|o| |Z|
|Z|o|o|o|o|o|o|o|o| |o|o|o|o|X| |o| | |Z|
|Z|o|o|o|o|o|o| |X|o| |o|o| |o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o| | |o| |o|o|X| |o| |Z|
|Z|o|o|o|o| |o|o| | |o|X| |o|o| | | | |Z|
|Z|o|o|o|o|o| |o|X|o|o| |o| |X| |o|X| |Z|
|Z|o|o|o|o|X| | |o|o| | |o| | | |o| | |Z|
|Z|o|o|o|o|o| | | | |o| | |o| | | |o|o|Z|
|Z|o|o|o|o| |X| |o|o| | | | | | | | | |Z|
|Z|o|o|o| |X| | | | |X| | | | | | |o|o|Z|
|Z|o|o| |X|X| | | | | | | | |X| | | | |Z|
|Z| |X|o| |o|o| | | | | | | |o|o| | | |Z|
|Z| |o| |o| | |X| | | | | |o| | | | | |Z|
|Z| |o|X|o|X| | | | | | | | | | | | | |Z|
|Z| |o| | | | | | |o| | |o| |o| | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 168

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X| | | |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|X|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|X|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|X|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o| |o|o|X|X| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| | |Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|X|o|X|X|X| | |Z|
|Z|o|o|o|o|o|o|o|X|o| | |X| |o| |o|o| |Z|
|Z|o|o|o|o|X|o|X|o|o| | |o| | | |o|o| |Z|
|Z|o|o|o|X|X| |o| |X|o|o| | | | | |o|o|Z|
|Z|o|o|o|o|X| | | |o|X| | | | | | |o| |Z|
|Z|o|o|o| | |X| |X| |o| | | | |X|o|o|o|Z|
|Z|o|o|o|X|X|X|X| | | | | | |X| | | | |Z|
|Z|o|X|o|X|X| | | | | | | |o|o| | | | |Z|
|Z|o|o|X|X| | | | | | | | | |o|o| | | |Z|
|Z| |o|o|X| | |o|o| | | |o|o| |o|o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 169

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X|X| | | |Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o| |X| |X| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X| | |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |X|o| |X|X| |Z|
|Z|o|o|o|o|o|o|o|X| |o| |o| | | | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X| |X|o|X|X| | |o|Z|
|Z|o|o|o|o|X|o|o|o| | |X| |X| | |o| | |Z|
|Z|o|o|o|o| |o| |o| |o| | | |X| |X| |o|Z|
|Z|o|o|o|X|o|X|o|X| | | |X| | | | |o|o|Z|
|Z|o|o|o|o| | |X|o|o| |X| | | |o| |o| |Z|
|Z|o|o|X|X| | |X| |X| | | | | | |o|o|o|Z|
|Z|o| |X| |X|X| | | | | | | | | |X| | |Z|
|Z|o|o|X| |X| | |X| | |o| |o| | | | | |Z|
|Z|X|o| | | |X| | | | | | |X| | | | | |Z|
|Z| |X|o| |X|o| | | | | |o|o|o|o| | | |Z|
|Z|o| |X| | | |o| | | | | | |o| | |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 170

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|X|X| |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o| | | | |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |X|X| | |X| |X|Z|
|Z|o|o|o|o|o|o|o|o| | |o|o| |X| | | | |Z|
|Z|o|o|o|o|o| |o|o|o| | | |o| | | |X| |Z|
|Z|o|o|o|o| |o|X| |X| | | |X| | | | | |Z|
|Z|o|o|o| |o|o|o| |o| | | | |X|X|X|o|o|Z|
|Z|o|o|X|X|o| |o| | |X| |X| | | | | | |Z|
|Z|o|o|o|o| | |X|o| | | | | |o| | |X|o|Z|
|Z|o|o| |X| |o| |X|X| | |X| | | | | |o|Z|
|Z|o|X| | | |X|X|X| | | |X| | | |X|o| |Z|
|Z| |o| | | | | | |X|o| | | | | | |o| |Z|
|Z|X|X| | | |X| | | | | | |X| | | | | |Z|
|Z| |X| | |X|X| | | | | |o| | | | | | |Z|
|Z|o| |X| | |X| | | | | |o|o|o|o| | | |Z|
|Z| | | |X| | | |o| | | | | | | |o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 171

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|X| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o| | | |X| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o| | | |X| |Z|
|Z|o|o|o|o|o|o|o|X|X|o|o| |X| | | | | |Z|
|Z|o|o|o|o|o|o|o|o| | |o|X|X|X| |X|o| |Z|
|Z|o|o|o|o|X|o|o| |X| | | | |o| |o|X| |Z|
|Z|o|o|o|o|o|o|o| | | | | |X| |o| | | |Z|
|Z|o|X|X|o|o|o|o|X|X| | | | | | | |o| |Z|
|Z| |o|o|o| |X|X| | | | | | | | |o|o|X|Z|
|Z|X|o| | | | | | | | |X| | | | | |o| |Z|
|Z| |X| | | | | | | |X| |X| | | | |X| |Z|
|Z| | | | | | | | | | | | |o| | |o|o| |Z|
|Z| |X|X| | | | | | | |o|X|o| |o|o| | |Z|
|Z|X| | |X| | | | |o|o|o| | |o|o| | | |Z|
|Z| | | | | | |X| | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 172

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X| | |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o| | | | | | |Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|X|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X| | |o| | | | |Z|
|Z|o|o|o|o|o|o|o| | | |o| |X| | | | | |Z|
|Z|o|o|o|o|o|o|X|o|o| | |o| | | | | | |Z|
|Z|o|o|o|o|X|o|o|X| |o|X| | | | | |X| |Z|
|Z|o|o|o|o|o|o| |X| | | | | |X| |X| | |Z|
|Z|o|o|X|o|o|o| |o| | | | | | | | | | |Z|
|Z| |o|o|o| |X|X|X| | | | | | | |o|o| |Z|
|Z| | |X| | |o| |X| | | | | | | |o| |o|Z|
|Z|o|X| | | | | | | | | | | | | | |X| |Z|
|Z|X| | | | | | | | | | | | | | | | | |Z|
|Z| | | |X| | | | | |o|X| |X|o| |X| | |Z|
|Z|X| | | | | | |o| | | | |X| |o| | |o|Z|
|Z| | |X| | |X| | | |o| | | | | | | | |Z|
|Z| | | | | | | | | | |o| | | |o|o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 173

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o| | |X| |X| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o| |o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o| |X|o|o|X| | | | | |Z|
|Z|o|o|o|o|o|X|o| | | |o| | | |o| | | |Z|
|Z|o|o|o|o|o|o|o|o| |o| | | | | | | | |Z|
|Z|o|o|o|o|X| |o|o|X| | |X| | | | |X| |Z|
|Z|o|o|o|o|o|X| |o| |X| | | | |X| | | |Z|
|Z|o|o| |o|o|o| | | | | | |X| | | | | |Z|
|Z|o| |o| | |X|o|X| | | | | | | |o| | |Z|
|Z|o| |X|X| | | | | | | | | | | | |o| |Z|
|Z|o| | | | |X| | | | | | | | | |X|o| |Z|
|Z|X|X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |X| | | |X| | | | |Z|
|Z| | | | | | | | | | | | | | |X| | | |Z|
|Z|X| | | | | | |o| | | |o|X| | | |o|o|Z|
|Z| | | | | | | | | |o| | | |o| | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 174

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|X| |X| |o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o| |o| | | | | |Z|
|Z|o|o|o|o|o|o|X|o|o|o|X|X|o|o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | | |Z|
|Z|o|o|o|X|o|o|o|o|o|o| |X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|X|o|o|X| | | | |X| | |Z|
|Z|o|o|o|o|o|o|o|o| | | | | | |o|X| | |Z|
|Z|o|o|o|o|X|o| | |X| | | | |X| |o| | |Z|
|Z| |o|X|o|o| |X| | | | | | | | | | |o|Z|
|Z|o|o|X| | | | | | | | | | | | | |X|o|Z|
|Z|X|o|o| | | | | | | | | | | | | | | |Z|
|Z| | |o| |X| | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |X| | | | | | | | |Z|
|Z| | | | | | | | | | | | |X| | |X|o| |Z|
|Z| | | | | | | | | | | | | | | |o| | |Z|
|Z| | | | | | | | | | | |X| |o| | | | |Z|
|Z| | | | | |o|o| | |o|o| | | |o| |o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 175

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|X|o| | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| | |X|o|o| | | | |Z|
|Z|o|o|o|o|o|o|X|o|o|X|X|o|o|o|o| | | |Z|
|Z|o|o|o|o|o| |o|o|o|X|o| |o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |X| | | | | | |Z|
|Z|o|o|X|o|o|o|X|o| |o|o| | | | | | | |Z|
|Z|o|o|o|o|o| | |o| |X| | | | | | | | |Z|
|Z|o|o|o|o|o| | |X| | | | | | |X| | | |Z|
|Z| |o|X|o|o|X| |o| | | | | | | |X| | |Z|
|Z|o| |o| |X| | | | | | | | | | | |o|X|Z|
|Z| | |o| |o| | | | | | | | | | | | | |Z|
|Z|o|X|X|X| | | | | | | | | | | | | | |Z|
|Z| | | | | | | | |X| | | | | | | | | |Z|
|Z| | | |o| | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | |X| |Z|
|Z| | | | | | | | | | | | | |X|o| | | |Z|
|Z| | | | | |o|o| | | | | | | |o|o| |o|Z|
|Z| | | | | | | | |o| |X| | | | | |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 176

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o| |o| | | |o| | | |Z|
|Z|o|o|o|o|o|X|o|o|X|X| |o| |o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|X|X| |X| | | |o| | |Z|
|Z|o|o|o|o|o|o| |o|o|X|X|X|X|o| | | | |Z|
|Z|o|o|X|o|o|X|X| | |X|X|o|X| | | | | |Z|
|Z|o|o|o|o|o| |o| |o|X| | | | | | | | |Z|
|Z|o|o|o|o| |o|o|X| |X| | | | | | | | |Z|
|Z| |o|o|o|X| | |o|X| | | | | |X| | | |Z|
|Z|o|X|o|X| | | | | | | | | | |X| | |X|Z|
|Z| |o|X| |X|o| | | | | | | | | | |X|X|Z|
|Z| | |X|X|X| | | | | | | | | | | | |X|Z|
|Z|X|X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | |o| | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | |X| |X|Z|
|Z| | | | |o| | |o| | | | | | |X| | |X|Z|
|Z| | | | | | | | |o| | |X| |o| | | | |Z|
|Z| | | | | | | | | | | |X| | |o|o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 177

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|X| |X|o|o| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|X| | |X| | | |o|o| |Z|
|Z|o|o|o|o|X|o|o|o|o| | | | | | | | | |Z|
|Z|o|o|o|o|o|X|o|o|X|o|X| | |X| |o|o| |Z|
|Z|o|o|o|o|o|o| |o|X| | |X| | | | | | |Z|
|Z|o|X|o|o|X|o|X| |X|X|X|X| | | | | | |Z|
|Z|o|o|o|X|o|o| | | | |X| | |X| | | | |Z|
|Z|o|o|o|X|o|o| |X| | | | | | | | | | |Z|
|Z|o|o|X| | |o| | | | | | | | | | |X|X|Z|
|Z|o|X|o| |X|X| | | | | | | | | |X| | |Z|
|Z|X|X| | | | | | | | | | | | | | |X| |Z|
|Z| | | |X| | | | | | | | | | | | | |X|Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | |o| | | | | | | | |X| |X| |Z|
|Z| | | |o|o| |o| | | | | | | | | | | |Z|
|Z| | | |o| | |o|o|o| | | |X| | |o|o| |Z|
|Z| | | | | | | | | | | | |X|X|o|o| |X|Z|
|Z| | | | | | | | | | | | | | | | |o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 178

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|X|o| | |X|X| | |o| | |Z|
|Z|o|o|o|o|X|o|o| |o| | | | | | |o| | |Z|
|Z|o|o|o|o|o|o| |o|X| | | | | | | |o| |Z|
|Z|o|o|o|o| |o| |X| |X| | |X| | | | | |Z|
|Z|X|o|o|X|o|X| |X| |X| |X|X| | | |o| |Z|
|Z|o|o|o|o|o| |o|X| | | | | | | | | | |Z|
|Z|o|o|X| |o|X| | |X| | | |X| | | | | |Z|
|Z|o|o| | |X| |X| | | | |X| | | | | | |Z|
|Z| |X| |o| |X| | | | | | | | | | |X| |Z|
|Z|X|X|X| | | | | | | | | | | | |X| | |Z|
|Z| | | | |X| | | | | | | | | | | | |X|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | |X|X|o| | | | | | | | | | |X| | |Z|
|Z| | | |o| |o| | | | | | | | | | | | |Z|
|Z| | | | | | | | |o| | | | | | |o| |o|Z|
|Z| | | | | |o| | | | | | | | | |o| | |Z|
|Z| | |o| | | | |o|o| | | | | |X| | |o|Z|
|Z| | | | | | | | | | | |X| | | | |X| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 179

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o| |X| | |o|X| | |X|o|o| | |Z|
|Z|o|o|o|o|o|o| |o| | | | | | | | | | |Z|
|Z|o|o|o|o|o|X|o|X|X| | | | |X| |o| | |Z|
|Z|o|o|o| |o|o|X| |X| | | | |X| | | |o|Z|
|Z|o|o|X|o| | | | | | | | | | | | | | |Z|
|Z|X|o|o|o| | |X| | | | | | | | | | | |Z|
|Z| |X|o| |X| |X| | | | | | | | | | | |Z|
|Z|X| | | | |X| |X| | | | | | | | | | |Z|
|Z| |o| |X| | | | | | | | | | | | | | |Z|
|Z| | | |X| | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| | | | |X| | | | | | | | | | | | | |Z|
|Z| | | | |X| | | | | | | | | | | | | |Z|
|Z| | | |X|o| | | | | | | | | | |o| |o|Z|
|Z| | | | |o| | | | | | | | | | | | | |Z|
|Z| |o| | | | | | | |o| | | | | |X| | |Z|
|Z| | | | | | |o|o| | | | | | | | | |X|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 180

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o| | | |X| | | | |X| | |o|Z|
|Z|o|o|o|o|o|X|o|X| | | | | | |o|o|o| |Z|
|Z|o|o|o|o|o|o|X| | | | | | | | | | | |Z|
|Z|o|o|o|o|o|X|o|X| | | | | | | | | | |Z|
|Z|X|o|o|o|o|X| | | |X| | | | | | |o| |Z|
|Z|o|X|X|X| |o| | | | | | | | | | | |o|Z|
|Z|o|o| | | | | | | | | | | | | | | | |Z|
|Z| |o| |X| | | | | | | | | | | | | | |Z|
|Z| |X| | |X| | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | |X| | | | | | | | | | | | | | |Z|
|Z|X| | | | | | | | | | | | | | | |o|o|Z|
|Z| | | | | | | | | | | | | | | | |o|o|Z|
|Z| | | | |X| | | | | | | | | | | | | |Z|
|Z| |o|o| |X| | |o| | | | | | | | | | |Z|
|Z| | | | | | | |o|o| | | | | | | |X| |Z|
|Z| | | | | | |o| |o| | | | | | | | | |Z|
|Z| | | | | | | |o| | | | | | | | | |X|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 181

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o| |X| | | | | | | |o|o|Z|
|Z|o|o|o|o|o|o|X| | | | | | | |X| | | |Z|
|Z|o|o|o|o|o|X| | | | | | | | | |o| | |Z|
|Z|X|o|o| | | |X| | | | | | | | | | | |Z|
|Z| |X|X| |X| | | | | | | | | | | | | |Z|
|Z| |o| |o| |X| | | | | | | | | |o|o| |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z|o|X| | | | | | | | | | | | | | | | |Z|
|Z| | | |X| | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | |o| |Z|
|Z| | | | | | | | | | | | | | | |o|o| |Z|
|Z| | | | | | | | | | | | | | | | |o| |Z|
|Z| | | |X| | | | | | | | | | | | | | |Z|
|Z| |o| | | | |o| |o| | | | | | | | |X|Z|
|Z|o| | | |X| |o| | | | | | | | | | | |Z|
|Z| | | | | | | |o| | | | | | | | | |X|Z|
|Z| | | | | | |o| |o| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 182

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o| | | | | | | | | | | | | |Z|
|Z|o|o|o|o|X|X|o|o|X| | | | | | | |o|o|Z|
|Z| |X|o|o| | | | | | | | | | | |X| | |Z|
|Z|o|X| |o| | | | | | | | | | | | | | |Z|
|Z| | |o| | | |X| | | | | | | | |o| | |Z|
|Z| |X| |X| | | | | | | | | | | | | | |Z|
|Z| |X| | |X| | | | | | | | | | | |o| |Z|
|Z|X| | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | |o| | |Z|
|Z| | | | | | | | | | | | | | |o| | | |Z|
|Z| | | | | | | | | | | | | | | | | |o|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | |X| | |o| | | | | | | |o| | |Z|
|Z|o| | | | |o|o| | | | | | | | | | | |Z|
|Z| |o| | | | | | |o| | | | | | | | | |Z|
|Z| | | | | |X| |o| | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 183

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|X|o| | | | | | | | | | | | |Z|
|Z|o|o|o|o|o|o|X|X| | | | | | | | |X| |Z|
|Z|o|o|o|o|o| | | | | | | | | | | |o|o|Z|
|Z|X|o|o| | | |X| | | | | | | | | |o| |Z|
|Z| | |X|o|o| | | | | | | | | | | |o| |Z|
|Z| | | | |X| | | | | | | | | | | | | |Z|
|Z| | |X| | | | | | | | | | | | |o| | |Z|
|Z| | |X| |X| | | | | | | | | | |o| |o|Z|
|Z| |X| | | | | | | | | | | | | | |o| |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | |o|o| | |Z|
|Z| | | | | | | | | | | | | |o| |o| |o|Z|
|Z|o|o| | | | |o| | | | | | | | | |o| |Z|
|Z| |o| | | |X|o| |o|o| | | | | | | | |Z|
|Z| |o| | | | | |o|o|o|o| | | | | | | |Z|
|Z| | | | | | |o| | |o| | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 184

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|X| | | | | | | | | | | | |Z|
|Z|o|o|o| |X|X|X| | | | | | | | | | | |Z|
|Z|X|o|o|o|X|o|X| | | | | | | | |o|X| |Z|
|Z|o|o| |o| |X| | | | | | | | | |X| |o|Z|
|Z| | | |X|X| | | | | | | | | | | | | |Z|
|Z| | | |X| | | | | | | | | | | | |o| |Z|
|Z| | | | | | | | | | | | | | |o| |o| |Z|
|Z| | | |X| | | | | | | | | | |o|o| | |Z|
|Z| | |X| | | | | | | | | | | | | | | |Z|
|Z| |X|X| | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | |o| | |Z|
|Z| | | | | | | | | | | | | |o| | | | |Z|
|Z|o| |o| | | | | | | | | | | |o| |o|o|Z|
|Z| | | | | | |X|o| |o| | | | |o| | | |Z|
|Z| | | | | | |X| | | |o| | | | | | | |Z|
|Z| | |o| | | |o|o|o| | |o| | | | | | |Z|
|Z| |o| | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 185

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|X| |X|X| | | | | | | | | | |Z|
|Z| |X| |o| | |X| | | | | | | | | | | |Z|
|Z|o|o| |X| |X| | | | | | | | | |X| |o|Z|
|Z| | |o|X| | |X| | | | | | | |X| | | |Z|
|Z|o|o| |X| | | | | | | | | | | | | | |Z|
|Z| | | | |X| | | | | | | | | | |o| | |Z|
|Z| | | | | | | | | | | | | |o| |o| |o|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | |X| | | | | | | | | | | |o| | | |Z|
|Z| | | |X| | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | |o| |Z|
|Z| | | | | | | | | | | | |o| |o| | |o|Z|
|Z| |o| | | | | | | |o| | | | | | | | |Z|
|Z|o| | | | | | |X| | | |o| | | | | |o|Z|
|Z| | | | | | |o| | | | | | | |o| | | |Z|
|Z| |o| | | | |X| | | | | | | | | | | |Z|
|Z| | | | | | | |o| | | |o| | | | | | |Z|
|Z|o| | | | | | | |o| |o| | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 186

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| |o|X|X| |X| | | | | | | | | | | | |Z|
|Z|o|o| |X| |X| |X| | | | | | | | | | |Z|
|Z|o|o|o| | |X| | | | | | | | |X|o| | |Z|
|Z|o|o|X| | | | | | | | | | | | | |o| |Z|
|Z|o| |o|X|X| | | | | | | | |X| |o|o|o|Z|
|Z|o| |o| | | | | | | | | | | |o|o|o| |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | |o|o|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| |X|X| | | | | | | | | | | |o| | | |Z|
|Z| | | | | | | | | | | | | |o| | | |o|Z|
|Z| |o| | | | | | | | | |o| | | |o|o| |Z|
|Z|o| | | | | | | | | | | |o|o| | |o| |Z|
|Z|o|o| | | | | | | |o| | | |o|o| | |o|Z|
|Z| | | | | | |X| |o| |o|o| | | |o| |o|Z|
|Z|o| | | | | | | | | | |o| | | | | | |Z|
|Z|o|o| | | | | |X|o| | | |o| | | | | |Z|
|Z| | |o| | | | | |o|o|o| | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 187

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| |o|X| | | | | | | | | | | | | | | |Z|
|Z|o|X|o| | | | | | | | | | | | | | | |Z|
|Z|o|o|X| |X| | | | | | | | | | |X|o| |Z|
|Z| |o|o| | | | | | | | | | | | |o|o| |Z|
|Z| | |X| | | | | | | | | | | | | |o|o|Z|
|Z| | |X| | | | | | | | | | | |X| | | |Z|
|Z|o| | | | | | | | | | | | | |o| | |o|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | |o|o| |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | |o| | | |o| |o| |Z|
|Z| |o| | | | | | | | | |o| | | | | |o|Z|
|Z| |o|o| | | | | | | | | |o| |o| | |o|Z|
|Z| | | | | | | |o| | | |o| | |o| |o| |Z|
|Z|o|o| | | | | | | |o| | |o|o| | | | |Z|
|Z| | | | | |X| | | | |o| | | | | | |o|Z|
|Z|o| |o| | | | | |o|o|o| | | | | | | |Z|
|Z|o| | | | | | |o|X| | |o| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 188

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | |o| | | | | | | | | | | | | | | |Z|
|Z|X| |X| | | | | | | | | | | | | | | |Z|
|Z|o| | | | | | | | | | | | | | |o|X| |Z|
|Z|o|X|X| | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | |o| | |Z|
|Z| | | | | | | | | | | | | | | | |o|o|Z|
|Z| | |X| | | | | | | | | | | |X| |o| |Z|
|Z| |o| | | | | | | | | | | | | | | |o|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | |o| | | | |o| |o|Z|
|Z|o| | | | | | | | | |o| | | | | | | |Z|
|Z|o| |o| | | | | | | | | | |o| | |o|o|Z|
|Z| | | | | | | | | | | | |o|o| | | | |Z|
|Z|o| | | | | | | | | | | |o|o| |o| | |Z|
|Z| | | | |X| | |o| | | | | | | | |o| |Z|
|Z| |o| | | | | |o|o|o| |o| |o| | | | |Z|
|Z| |o| | | | | | | | |o| | | | | |o| |Z|
|Z| |o| |o| | | |X| | |o| | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 189

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | |X| | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|X| | |X| | | | | | | | | | | |X| | |Z|
|Z|X| | | | | | | | | | | | | | |o| | |Z|
|Z| | | | | | | | | | | | | | |o| |o| |Z|
|Z| | | | | | | | | | | | | | | |o|o|o|Z|
|Z| | | | | | | | | | | | | | | | | |o|Z|
|Z| |X| | | | | | | | | | | |X| | |o| |Z|
|Z| | | | | | | | | | | |o| | | |o| |o|Z|
|Z| |o| | | | | | | | | | |o| |o| |o|o|Z|
|Z|o|o|o| | | | | | | | |o|o|o|o|o|o| |Z|
|Z|o|o|o| | | | | | | | | |o|o| |o| | |Z|
|Z| |o| | | | | | | | | | |o| |o| | |o|Z|
|Z| | | | | | | | | | | | | |o|o|o| |o|Z|
|Z|o| | | | | |o| | |o|o| |o| |o|o| | |Z|
|Z|o|o| | | |o|o|o| | |o|o|o|o|o| | |o|Z|
|Z| |o| | | |o| | |o| | |o| | |o| |o| |Z|
|Z|o|o| | |o| | | |X|o| | |o| | | |o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 190

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | |X| | | | | | | | | | | | | | |Z|
|Z| |X|X| | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | |o| |X| | |Z|
|Z| | | | | | | | | | | | | | | |o|o|o|Z|
|Z| | | | | | | | | | | | | | | | | |o|Z|
|Z| | | | | | | | | | | | | | | |o|o| |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z| |X| | | | | | | | | |o|X|o|o| |o|o|Z|
|Z|o|o| | | | | | | | | | | |o|o|o|o| |Z|
|Z|o|o| |o| | | | | | | | | |o|o| | | |Z|
|Z|o| | |o| | | | | | | |o| |o|o|o| |o|Z|
|Z| | | | | | | | | | | | |o|o| | | | |Z|
|Z|o|o| | | | |o| | | |o| |o|o|o|o|o| |Z|
|Z|o| | | | | |o| | |o| |o| |o|o| |o|o|Z|
|Z| | |o| | | | |o| |o| | | |o| | |o| |Z|
|Z|o| |o| |o| |o|o| | |o| |o| | | |o|o|Z|
|Z| | |o| | |o| | | |X| | | |o| |o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 191

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|X| |X| | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | |o| | | | | |Z|
|Z| | | | | | | | | | | | | | | | |X| |Z|
|Z| | | | | | | | | | | | | | | |o|o| |Z|
|Z| | | | | | | | | | | | | | | | | |o|Z|
|Z| | | | | | | | | | | | | |o| | |o|o|Z|
|Z| |o| | | | | | | |o|o| | | |o|o| |o|Z|
|Z|o|X| |o| | | | | | | | |o|X| |o| |o|Z|
|Z| |o| | | | | | | | | | |o|o| |o|o| |Z|
|Z| | |o| | | | | | | | | |o|o|o| | | |Z|
|Z| |o|o| | | | |o| | |o|o| |o|o| | |o|Z|
|Z|o| | | | | | | | | | |o|o| |o|o| | |Z|
|Z| |o| | | | | | | | | | |o| | | |o| |Z|
|Z| | | | | | |o| |o| |o|o| | |o|o| | |Z|
|Z| |o|o| | |o|o| |o| |X| |o| |o|o|o| |Z|
|Z|o| | |o| | |o|o| | | | |o| | | |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 192

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z| | | | | | | | | | | |o| | | | | | |Z|
|Z| | | | | | | | | | | | | | | |X| |o|Z|
|Z| | | | | | | | | | | | | | | |X|o| |Z|
|Z| | | | | | | | | | | | | |o| | |o|o|Z|
|Z| |o| | | | | | | | | | |o|o|X|o|o|o|Z|
|Z| | |o| | | | | |o| | |o|o|o|X|o|o|o|Z|
|Z|X|X|o| | | | | |o| | | |o|o|o|o|o|o|Z|
|Z| |o| |o| | | | | | |o|o|o|o|o|o|o|o|Z|
|Z|o| |o| | | | | | | |o|o|o|o|o|o|o|o|Z|
|Z|o|o| |o| | | | | | | |o|o|o|o|o|o|o|Z|
|Z| |o|o|o|o|o| |o|o| |o| |o|o|o|o|o|o|Z|
|Z|o| | | | | |o|o| |X| |o|o| |o| |o| |Z|
|Z|o|o|o| |o| |o|o|o| |X| |o|o|o| |o|o|Z|
|Z|o|o|o|o| | |o|o|o|o| | |o|o|o|o|o|o|Z|
|Z|o| | | | | |o|o|o|o| | |o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 193

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z| | | | | | | | | | |o| | | | | |o| |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | |X|o|Z|
|Z| | |o| | | | | | | | | | |o|o| |X|o|Z|
|Z| |o| | | | | |o| | | | |o| |o|X|o|o|Z|
|Z| | | | | | | | | | | |o|o| |o|o|o|o|Z|
|Z| | |X| | | | | | | |o|o| |o|o|X|o| |Z|
|Z| |X|o| |o| | | |o|o| |o|o|o|o|o|o|o|Z|
|Z| |o|o| | | | | | |o|o|o| |o|o|o|o|o|Z|
|Z|o| | |o|o| | |o| | |o|o|o| |o|o|o|o|Z|
|Z|o| |o|o| | | |o| | |X|o|o| |o| | |o|Z|
|Z|o|o|o| |o| |o| |o|o| |X| |o|o|o|o|o|Z|
|Z|o|o| |o| |o|o|o| | | | |o| |o|o|o|o|Z|
|Z| |o| | | |o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z| |o|o|o| |o| | | | | |o|o| | |o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 194

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | |o|Z|
|Z| | | | | | | | | | | |o| | | | | | |Z|
|Z| |o| | | | | | | | | | |o| | | |o|X|Z|
|Z| | | | | | | |o| | | | |o| | |o| | |Z|
|Z| | |o| | | | | | | | | |o|o|o|o|o|X|Z|
|Z| | | | | | | | | | | |o|o| |X|o|X| |Z|
|Z| | | | | | | | | |o| | |o| |o|o|o| |Z|
|Z| | |X|o| | | |o| |o|o|o|o|o|o|o|o|o|Z|
|Z|o|X| | |o|o| | | | | | |o|o|o|o|o|o|Z|
|Z| |o|o| |o| |o| |o| |X| | |o| | | |o|Z|
|Z|o|o| | | |o| |o|o|o|o| |X|o| |o|o| |Z|
|Z|o|o|o| |o| | |o| | | |o|o|o|o|o|o| |Z|
|Z| |o| | |o|o|o|o|o| | |o| |o|o|o|o| |Z|
|Z|o| |o|o|o| |o| | | |o|o| |o|o|o| |o|Z|
|Z|o| | | |o| |o| | |o|o| | |o|o| | |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 195

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z| | | | | | | | | | | | | | | |o|o| |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | | | |o|o|o|o| | | | |Z|
|Z|o| | | | | | | | | | | |o|o|o| |X|o|Z|
|Z| |o|o| | | | | | |o| | | |o|o| |o| |Z|
|Z| | | |o| | |o| | | |o| |o|o|o|X|X| |Z|
|Z| | | | | | |o| | | | |o|o|o|o|o|o| |Z|
|Z| | | | | | |o| |o|o|o| |o|o|o|o|X|o|Z|
|Z| |o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| |o| | |o| |o|o| | |o|o|o|o|o|o|o|o|Z|
|Z|o|X|o| |o|o|o|o|o| |o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o| |o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 196

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z| | | | | | | | | | | |o| | | |o| | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z| | | | | | | | | | | |o| |o| |o| | |Z|
|Z| | | | | | | | | | | |o|o| | |o| | |Z|
|Z| |o| | | | | | | | |o|o|o| |o| | | |Z|
|Z| |o| | |o| | | | | | | | |o| |o|X|o|Z|
|Z| | |o| | | | |o| |o| |o|o| |o|o| | |Z|
|Z| | | | | | | |o|o| |o|o|o|o|o|X|X| |Z|
|Z|o| | | | | | |o|o|o|o|o| | |o|X|o|o|Z|
|Z| | | |o|o|o| |o| |o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o| |o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o| | |o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| |o|o|o|o| | |o|o| |o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o| |o|o|o|o|o|o| |o| | |o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 197

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | |o| | |o| | | |Z|
|Z| | | | | | | | | | |o|o| | | | | | |Z|
|Z| | | | | | | | | | | | |o| | | | | |Z|
|Z| | | | | | | | | | | | | | |o| |o| |Z|
|Z| | | | | | | | | | |o|o|o| |o| | | |Z|
|Z| |o| | | |o| | | | | | |o|o| | |o|o|Z|
|Z|o| |o| | | | | | | |o|o|o|o| | | | |Z|
|Z| | | | | | |o|o| | |o| | |o|o|X| | |Z|
|Z| | | | | | | |o| |o|o|o| | | |o| | |Z|
|Z| | | | | |o|o| |o|o|o|o|o|o|X|o|X|X|Z|
|Z|o|o|o|X|o| |o|o|o| |o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o| |o|o|X|o|o| |o| |o| |Z|
|Z|o| |o|o|o|o|o|o|o|o| | |o|o|o|o|o| |Z|
|Z|o|o|X|o| |o| | |o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o| |o|o|o|o| |o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o| |o| |o|o|o|o|o| | |o| | |o|o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 198

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | |o|o|o|o| | | | |Z|
|Z| | | | | | | | | | |o|o|o| | | | | |Z|
|Z| | | | | | | | | |o| | | |o| | | | |Z|
|Z| | | | | | | | | | |o|o|o|o| |o| | |Z|
|Z|o| | | | | |o| | |o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o| | | |o| | |o|o| |o|o|o|o| |o|Z|
|Z|o|o| | | | | |o|o| |o|o|o|o| |o|o|o|Z|
|Z| | | | | |o| |o|o|o|o|o|o|o|o|o|o| |Z|
|Z| | |o| |o|o|o|o|o|o|o|o|o|o|o|X| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|X| |Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 199

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | |o|o| |o|o| | | | |Z|
|Z| | | | | | | | | | |o| | |o| | | | |Z|
|Z| | | | | | | | | | |o|o| |o|o| |o| |Z|
|Z| |o| | | | | | |o|o|o|o|o| |o| |o| |Z|
|Z|o| |o| | | | |o| | | |o|o|o|o|o|o| |Z|
|Z|o| | | | |o| | | |o|o|o|o| |o|o|o| |Z|
|Z|o| |o| | | | |o|o|o|o|o|o|o|o| | | |Z|
|Z| |o| | |o|o|o|o|o|o|o|o|o|o|o| |X|o|Z|
|Z| |o| |o|o|o|o| |o|o|o| |o| |X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| | |Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X| |o|o|o| |X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o| |o|o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 200

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | |o| | | | | | |Z|
|Z| | | | | | | | |o|o|o|o|o|o| |o| | |Z|
|Z|o| | | | | | | | |o| | |o| | | |o|o|Z|
|Z| |o| | | | | | |o|o|o| | |o|o|o| | |Z|
|Z| |o| | | | | | |o|o|o|o| |o|o|o| | |Z|
|Z| |o| | | | | | |o|o|o| |o|o|o|o| |o|Z|
|Z|o|o| | |o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z| |o|o|o|o|o|o| |o|o| | | |o|X| |o|o|Z|
|Z|o|o|o| |o|o|o|o|o|o|o|o|o|o|o|X| | |Z|
|Z|o|o|X|o|o|o|o|o| |o|o| |o|o|o|X|o| |Z|
|Z|o|o|X|o|o|o|o|o|o|X|o| | |o|X|X|o| |Z|
|Z|o|o|o|o|o|o|o|o|X| |o|o|o|X|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o| |o|o|o|X|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |X|o|o|o|o|o| |Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o| | | |o| |o| | |o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 201

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | |o|o|o|o| |o| | |Z|
|Z| |o|o|o| | |o|o|o|o|o|o|o|o|o|o| | |Z|
|Z| | |o| | | | |o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| | | | | | | |o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o| | |o| |o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|X|o|o|X|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X| |o|o|X|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 202

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o| | | | | |o| |o|o|o|o|o|o|o|o| |Z|
|Z| | | | | |o| |o|o|o|o|o|o| |o| |o| |Z|
|Z| | | |o| | |o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o| | | | |o|o|o| |o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|o| |X|X|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o| | | |X| |o|o| | |Z|
|Z|o|o|o|X|o|o|o|o|o|X| |o| |o| |o|o|X|Z|
|Z|o|o|o|o|o|o|o| |o|o|X|X|o|X|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o| |o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o| | |o|o| |o| |o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 203

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | |o|o|o|o|o|o|o|o|o| | |Z|
|Z|o| |o| |o| |o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o| | | | |o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o| |o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o| |o|o|o|o|o|o|o| |o|o|o| |X|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o| | |o| | |o|Z|
|Z|o|o|o|o|o|o|o| |o|o|o| |X| |o|X|o| |Z|
|Z|o|o|o|o|o|o| |o|o| | | |o|o|o| | | |Z|
|Z|o|o|o|o|o|o| | | | |o|o| | |o| |o| |Z|
|Z|o|o|o|o|o|o|o|o| |o| |o| |X|o|o| | |Z|
|Z|o|o|X|o|o|o|o|o|X|o|o| | |o|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|X|X|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o| |o|o|o|o|o|o|o|Z|
|Z|X|o|o|o|o|o|o|o|o|o|o|o|o| | |X|o|o|Z|
|Z|o|o|o|o|o|o|o|o| |o|o|o|o|o| | |o|o|Z|
|Z|o|o|o|o|o|o|o| |o|o| | | | |o| | |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 204

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|X|o|o|o|o|o|X|o|o|o|o|o|X|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|X|o|X|o|o|X|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|X|o|o|o|o|o|o|o|o|o|o|o|o| |o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 205

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| | |o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o| | |X|o| |o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|X|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|X|o| |o|X|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o| |o|o|o| | |o|Z|
|Z|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |Z|
|Z|o|o|o|o|o|o|o| | | |o| |o|o|o|o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 206

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X| | |o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |X|o|Z|
|Z|o|o|o|X|o|o|X|o|o|o| |X| | |o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X|o| | |o|Z|
|Z|o|o|o|o|o|o|o| |o|o|o|o| |o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o| |o| |o|o|X|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|X|X| |o| |o|X| |o| |Z|
|Z|o|X|o|o|o|o|o|o| |o|o|o| |o|X|o| |o|Z|
|Z|o|o|o|o| |o| |o| |o| |o|o|o|o| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 207

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|X|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|X|o|X| |X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o| | |o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|X|o|X|o| |Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 208

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|X|o|X|o|o|o| |o| |o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|X|X|X|o|X|X|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o|o|o|Z|
|Z|o|o|o|o|o| |o|o|o| |o|o| |o|o|X|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|X|o|o|o|o| |o| |X|X| | |o|X|o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 209

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X| | |o| |Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o| |o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|X| | |o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o| | | |o| |o|o| |Z|
|Z|o|o|o|o|o| | |o|o|o|X|o|X|X| |X|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o| |X|o|o|X| | |Z|
|Z|o|o|o|o|o|o| |o| |o|o|o| | |X| | |o|Z|
|Z|o|o|o|o|o|o| | |o|X|X| | |o|X|X|o|o|Z|
|Z|o|o|X|o| | |o| |o|o|o| | | |o|o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 210

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o| | |o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o| |X|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X| | | |o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o| |X|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|X|X| | | | |X|o|Z|
|Z|o|o|o|X|o|o|o|o|X|o|o|o| |X| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o| | | | | |X|X|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 211

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|X|Z|
|Z|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|X|o| | |o|X|Z|
|Z|o|o|o|o|o|X|X|o|o|o|o| | |X| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| | |o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| | | |o| |X| | |Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|X|X| | |X|X| |Z|
|Z|o|o|o|o|o|o|o|X|o| | | | | | | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o| |X|X|X| | |X|X|o|Z|
|Z|o|o|X|o|o| |o|o| | | | | | | | |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 212

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|X|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| | | |Z|
|Z|o|o|o|o|X|o|X|o|o|o|o|X| |X|o| |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |X|o| |o| |o| | |Z|
|Z|o|o|o|o|o|o|o|o|o| | | | |o| | |X| |Z|
|Z|o|o|o|o|o|o|o|o|X| |o| | |X| | | |o|Z|
|Z|o|o|o|o|o|o|X| |o| |X| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| |X|X| | | | |X|X|Z|
|Z|o|X|o|o|o|o|o| | |o| | | | | | | |X|Z|
|Z|o|o|o|o| |o| | | |X| | | |X| | |X| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 213

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|X|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|X|o|X|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|X|o|o|o|X| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|o| |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|X| | | | |Z|
|Z|o|o|o|o|o|o|X|o| |o|X| | |o| | | |X|Z|
|Z|o|o|o|o|o|o|o|o| |o|o| | | | | |X| |Z|
|Z|X|o|o|o|o|o|o|o|o|o| | | | | |X| | |Z|
|Z|o|o|o|o|o|o|o|o|X|X| |X| | | | |X| |Z|
|Z|o|o|o|o|o|o|o|o| | | | | | | | | |X|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 214

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|X|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|X|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X| | |o| |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o| | |Z|
|Z|o|o|o|o|o|o| |o|o|o|X|o|X|X|o| |X|o|Z|
|Z|o|o|o|o|o|o|X|o|X| |o| | | | | |X| |Z|
|Z|o|o|o|o|o|o|o|o|o| | |o|o| | | | | |Z|
|Z|X|o|o|o|o|o|o|o| |X| | | | |o| |X| |Z|
|Z|o|o|o|o|o| |o| |X|X|o| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o| | | | | | | | | |X|Z|
|Z|o|o|o|o|o| | | |o| | | | | | | |X| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 215

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|X|o|o|o| |Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o| |o| |o| | |Z|
|Z|o|o|o|o|o|X|o|o|o| |X|o|o| | |o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |X|X| |o| | | |Z|
|Z|o|o|o|o|o|X|o| | |X| | |o|o| | | |X|Z|
|Z|o|o|o|o|o|o|o|X|o|o| |o| | | |X| | |Z|
|Z|o|X|o|o|o|o|o|o| | | | | |o| | | | |Z|
|Z|o|o|o|o|o|o|o|X|X| | |o| | | | | | |Z|
|Z|o|o|o|o|o| |o|o| | |X| | | |o| | | |Z|
|Z|o|o|o|o|o| | | |o| | | | | | | | | |Z|
|Z|o|o|o|o| |o| | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 216

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|X|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|X|o|o|o|X|X|Z|
|Z|o|o|o|o|o|X|o|o|X|o|o|o| |X|o|o|X|X|Z|
|Z|o|o|o|o|o|o|o|o|o|X| |o|X| |o| |o| |Z|
|Z|o|o|X|o|o|X|o|o|o|o|o|X| |o| | | | |Z|
|Z|o|o|o|o|o|o|X|X|o| | |X| | | |o| | |Z|
|Z|o|o|o|o|o|o|o|o|X|o| |X| | |o|o| | |Z|
|Z|o|o|o|o|o|o|o|X|o|X|X| | | |o| | | |Z|
|Z|o|o|o|o|o|o|o|o|X| | | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 217

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|X|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|X|X| |Z|
|Z|o|o|o|o|o|o|X|o|o|X| |o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o| |o|o|X| | | |X| |X| |Z|
|Z|o|o| |o| |X|o|o|o|o|o|X|o|o| | |X| |Z|
|Z|o|X|o|o|o|o| | | | |X| | | |o| | | |Z|
|Z|o|o|o|o|o|o|o| |X|o|X|X|X|o| |o|o| |Z|
|Z|o|o|o|o|o|o|X|X| |X| | | | | |o| | |Z|
|Z|o|o|o|o|o| |X|o|X| | | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| | | | | | | | | |Z|
|Z|o|o|o|o|o| | |X| | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 218

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o| |o| |X|X|o| |Z|
|Z|o|o|X|o|o|o| | |o|X|X| |o|o| |o| | |Z|
|Z|o|o|o|o|o|X|o| |o|o|o|o| | |X|X| | |Z|
|Z|o|o|o| |o|o|X|o| |X| | |o| |o| | | |Z|
|Z|o|o|o|o|o|o|o|o| | |X|o| | | |X| | |Z|
|Z|o|o|o|o|o|o|o| |o|X| |X|o| | |o|X| |Z|
|Z|o|X|o|o| | |X| | |X| | | |X|o| | | |Z|
|Z|o|o|o|o|o|X| | | | |X| | | | | |o| |Z|
|Z|o|o|o|o|o|o|o| | |X| | | | | | |o| |Z|
|Z|o|o|o|o|o| |X|X|X| | | | | | | | | |Z|
|Z|o|o| |o| |o| | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 219

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|X|o|o|o|X|o|o|X|o|o|o|o|X|o|X|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|X|o|o|o| | | | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | | |X| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |X| | | | | | |Z|
|Z|o|o|o|o|o|o|X|o|X| |X| |X| | |X| | |Z|
|Z|o|o|o|o|o|o|o| | | | | | | |X|X| |o|Z|
|Z|X|o|o|o|X|o| | | | |X| | | | | | |o|Z|
|Z|o|o|o|o|o|o|X| | | | | | | | |o|o| |Z|
|Z|o|o|o|o|o|o|o| | | | | | | | | | | |Z|
|Z|o|o|o|o|o|X|o|o| |X| | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 220

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o| |o|o|o|o|o|X| |o| |Z|
|Z|o|o|X|o|o|o| | |o|o|o|o| | |X|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|X|o|o| | |o|X| |o| |Z|
|Z|o|o|o|o|o|o|o|o| | |X| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|X| |X| | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|X|o| | |X| |X|X| | | |Z|
|Z|X|o|o| |o| |o|o| | | | | | | | |X|o|Z|
|Z|o|o|o|o|o|o| | | | | | | | | | |o| |Z|
|Z|o|o|o|X| | |o| | | | | | | | | | | |Z|
|Z|o|o|o|o|X|X| |o|X| | | | | |o|o| | |Z|
|Z|o|o|o| | |o|o| | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 221

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|X|o|X|o| |o|o|o|o| | | |X|o| |Z|
|Z|o|o|o|o|o| | | |o|o|X|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o| | |o| | |X|o| |Z|
|Z|o|o|o|X|o|o|o|X|o|X| |o| |X| | | | |Z|
|Z|o|o|o|o|o| | |X| | | | | | | | |o| |Z|
|Z|o|o|o|o|o|o|X|o| | | | | | |X| | | |Z|
|Z|o|o|o|o|o|o| |o|X| | | | | | | | |o|Z|
|Z|o|o| |o|o| |o| | | | | |X|X| | | | |Z|
|Z|o|X| |o|X| | |o| | | | | | | | |X| |Z|
|Z|o|o|o|o| | |X| | | | | | | | | | | |Z|
|Z|o|o| |o|o| | |X| | | | | | | | | | |Z|
|Z| | | |o| |X| |o| | | | | | |o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 222

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|X|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|X| |o|o|o|o|Z|
|Z|o|o|o|o|o|X|X|o|o|o|o|o| | |o| |o|o|Z|
|Z|o|o|o|o|X|o| | |o| | |o| | | | | |o|Z|
|Z|o|o|o|o|o|o|o|X| |X| |o| | | | | | |Z|
|Z|o|o|o|o|o|o|o|X| | | | | | | | | | |Z|
|Z|o|X|o|o|o|o| |o| | | | | | | | |o| |Z|
|Z|o|o|o|o|o| |o|X|o| | | | | | | |o| |Z|
|Z|o|o|o|X|o| | | | | | | | |o| | |X| |Z|
|Z|o| |o|o|X| | | | | | | | | |o| | | |Z|
|Z|o|o|o| |o|o| |X| | | | | | | | |o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 223

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|X|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o| |o| |X| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|X|o|Z|
|Z|o|o|o|o|X| |X|o|o|o|o|X| |o| | |o| |Z|
|Z|o|o|o|o|o| |o| |X|o| | | |o| |o|o| |Z|
|Z|o|o|o|o|o|o|o| |X|o| | |o| | |o| | |Z|
|Z|o|o|o|X|o|o|o| |X| | | |o| | | |o| |Z|
|Z|o|o|o|o|o|o|X| | | | | | | | | |o| |Z|
|Z|o|o|X|o|o| | | | | | | | | | | | | |Z|
|Z|o|o| | |X| |X|o| | | | | | | | |X| |Z|
|Z|o|o| |o| |o| | | |o| | | | | | | | |Z|
|Z|o|o|o|X| |o|o| | | | | |o| | |o|o| |Z|
|Z| |o| |o| | |X| | | | | | | |o| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 224

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|o|o| | |o|X|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|X|X|o|o|o| |o|X|Z|
|Z|o|o|o|o|o|X|o|X|o|o|X|o|o| | | |o| |Z|
|Z|o|o|o|o|o|o|o|X| | |X| |o| |o| |X|X|Z|
|Z|o|o|o|o|o|o| |o| |X| |o| | | | | |o|Z|
|Z|o|o|o|o|o|o| | |X|X| |o| |o|o| |o| |Z|
|Z|o|o|o|o|o| | | | | |X|o| | | | | |o|Z|
|Z|o|o|o|X| |X| |o| | | | | | | | | | |Z|
|Z| |o|o|X|X|o|X| | | | | | | | |X| |o|Z|
|Z|o|o| |X|o| | |X| | | | | | | |X| | |Z|
|Z|o|o|o|X|o|o|X| | | | | | | | | | | |Z|
|Z| | |o|X|X| |X| |o| | | | | | |o| | |Z|
|Z| | |o|X| |X| | | | | |o| |o| | |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 225

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|X|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|X|X|o|X|o|o|X|o|o|o|X|o|Z|
|Z|o|o|o|o|X|o|o|o|o|X|o|X|o|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|X|X| |o|o|o|o|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|X| | | | | | | | |o|o|Z|
|Z|o|o|X|o|o| |o| | |X| |X| |o| | |o|o|Z|
|Z|o|o|o|o|o|o| |X| | | | |o| | | |X|o|Z|
|Z|o|o|X|o|o|X| |X| | | | | | | | | | |Z|
|Z|o|o|o| |X| | | | | | | | | | | | | |Z|
|Z|o|o|X| |X|X| | | | | | | | |X|o|o| |Z|
|Z|o| |X| |X|X| | | | |o| | |o|o| | | |Z|
|Z|o| |X| |X| | |o|o| |o| | | |o|o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 226

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o| |X|X|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o| | |X|o| | |o|o|o|X| |Z|
|Z|o|o|o|X|o|o|o|o|X|o|X|X|o| | |o|o| |Z|
|Z|o|o|o|o|o|o|X|o|X| |X|o|o|X|o|X|o|o|Z|
|Z|o|o|o|o|o|o| |X| |X|o|o|o|o|o| | | |Z|
|Z|o|o|o|o|o|o| |o| | | | | | |o| | |o|Z|
|Z|o|o|X|o|o|o| |o| |X|o| | | |o|o|o|X|Z|
|Z|o|o|o|o|o|o|X| |X| | | | | | | | | |Z|
|Z|o|o| | | | |o| | | | | |X| |o|o| |X|Z|
|Z|o|X|o|X|X|o|X| | | | | | | | | | | |Z|
|Z|o|X| |o|X| | | | | | | | | | | |o|o|Z|
|Z| |X| | | |X|X| | | |o| | |o| | | | |Z|
|Z|o|X| | | |X|o| | |o| |o| |X| |o| | |Z|
|Z| |o| |X| | | | | | | | | |o| | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 227

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| | |X|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o| |o| |o|o| |X| |o|X|Z|
|Z|o|o|o|o| | | |o|o|o|X|o|o|o| |o|o| |Z|
|Z|o|o|o|o|X|X| |X| |X| | |o| |o| |X| |Z|
|Z|o|o|o|o|o|o|o|X| | | |X| |o|X| | | |Z|
|Z|o|o|o|o|o|o|o| | | |X|X|o|o|X|o| |o|Z|
|Z|o|o|o|o|o|o| |X| | | | | | | |o| |X|Z|
|Z|o|o|o|o|o| | |X| | |X| | | |o| | | |Z|
|Z|o|X| | |o| | | | | | | | |X|o|o| |X|Z|
|Z|X| |o| |o| |X| | |X| | | | | | | | |Z|
|Z|X|o|X| | |X| | | | | | | | | |o| | |Z|
|Z| |o| |X| |X| | | | | | | | | |o| | |Z|
|Z| | | | | | | | | | | |o| | | | |o| |Z|
|Z|X| | | | | |X| |o| |o| |o| | | |o| |Z|
|Z| |X| | | | | | | | | | | |X| | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 228

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|X|X|o| |o|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|X|o| |o|o| |Z|
|Z|o|o|o|o|X|o|X| | | |X| | |X| | | | |Z|
|Z|o|o|o|o|o|o|X| | |X| | |X| | |X| |X|Z|
|Z|o|o|o|o|o|o|o| |X| | | |o|o|o| | | |Z|
|Z|X|o|o|o|o|o| | | | | |X| |o|X|o| | |Z|
|Z|X|o|o|o|o| |X|X| | | | | | | | |o| |Z|
|Z| |o|X|o|X|o|o| | | | | | | |o|o| |X|Z|
|Z| | |o| | | | | | | | | | | | |o|o| |Z|
|Z| |X| | |X| | |o| | | |o| |o|o| |o|o|Z|
|Z| |X| | | | | |o| | |o| | | |o|o| | |Z|
|Z| |X| | | | | |X| | | | |X| | | | | |Z|
|Z| | | | | | | | | |o|o| | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 229

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o| |X|X|o|o|Z|
|Z|o|o|o|o|o|o| |X|o|o|X|o| | | |o|o| |Z|
|Z|o|o|o|o|o|o| |X|X| |X|X|o|X|o| |X| |Z|
|Z|o|o|o|o|o|o| | | | | | | | | | | | |Z|
|Z|o|o|o|o|o|X|o| |X| | | | | | | | | |Z|
|Z| |X|o|o|o| |X| | | |X| |X|X|X| |X| |Z|
|Z|o|o|o|o|o| | | | | | | | |X| | | | |Z|
|Z|o|X| | |X|o| | | | | | | | | |o|o| |Z|
|Z|o| |o|X| |X|X| | | | | | |o| | |o| |Z|
|Z| | |X|X| | | | | | | |o| | |o| |X| |Z|
|Z| |X| | | | | | |o|o| | |o| | |o|o| |Z|
|Z|X| | | | | | |X| | | | | |X|o| |o| |Z|
|Z| | | | | | | | | | | |o| | | |o| | |Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 230

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| | | |o|X|o| |o|Z|
|Z|o|o|o|o|o|o| |X|o|X|o| | |o| |o| | |Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|X| | | |X|X|o|Z|
|Z|o|o|o|o|o|o|o| | | | | |X| |X| | | |Z|
|Z|o|o|o| |X| | | | | | | | | | | | | |Z|
|Z| |o|o|o|o| |X| | | | | | |X|X| | |X|Z|
|Z|o|o| |o|o|o| | | | | | |X| | | | | |Z|
|Z|o|X| |X| |o| | | | | | | | | | |o| |Z|
|Z|o|o| |X| |X| | | | | | | |X| | | | |Z|
|Z| | |X| | | | | | | | | | | | |o| | |Z|
|Z| |X| | | | |X| | |o| | |o|o| |o| |o|Z|
|Z| | | | | | | | |X| |o| | | |o|X| | |Z|
|Z| | | | | | | | | | | | | | |X|o| |o|Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | | | | | |o| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 231

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X| |X|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o| |X|o|X|X|o| |o|X|Z|
|Z|o|o|o|o|o|o|o|o| | | | | |X| | | | |Z|
|Z|o|o|o|o|o|o|o|o| | | | | | | | | | |Z|
|Z|o|o|o|o|X|o| | | | | | |X| | | | | |Z|
|Z|X|o|o|o|X|X| | | | | | | |X| | | | |Z|
|Z|o|o|o| | |X| | | | | |X| |X| | | | |Z|
|Z| |X| | | | | | | | | | | |o| | |o| |Z|
|Z| |o| | |X| | | | | |o|o|o| |o| | |o|Z|
|Z| |o| | | | | |X| |X|o| |o| | |X| | |Z|
|Z|X| | | | | | | | | | | | |o| |o|o|o|Z|
|Z| | | | | | | | | |o| |o| | |o|X|o|o|Z|
|Z| | | | | | | | |o| |o| | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 232

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|X|o|X|X|o|X|X|X|X| |Z|
|Z|o|o|o|o|o|o|o|X|X|o|o|X|X|X|X|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o| | |X|o| |X|X|X|o|Z|
|Z|o|o|o|o|o|o| | |o| | |o| | | |X| | |Z|
|Z|o|o|o|o|o|o|X| | | | | | | | | | | |Z|
|Z|X|o|o|X|o|X|o| | | | | | | | | | | |Z|
|Z|o|o|X| |X| | | | | | | | | | | | | |Z|
|Z|X|X| | |o|X| |X| | | | | | |X| | | |Z|
|Z|o| | |o| | |X| | | | |o| |X| | |o| |Z|
|Z|o|X| | | | | | | |X| | | | | | |o| |Z|
|Z| |X| | | | | | | |o|X|o| |o|o| |o|o|Z|
|Z| | | | | | | | | |o| | |o| | | |X|o|Z|
|Z| | | | | | | | | | | | |o| |X| |o|X|Z|
|Z| | | | | | | | | |o| | | | | |X| | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 233

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|X|o|o| |o|o| |X|X|X| |Z|
|Z|o|o|o|o|o|o|o|o|o| | |o|X|X|X| |o| |Z|
|Z|o|o|o|o|o|o| |o| |X| | | |X| |X| |X|Z|
|Z|o|o|o|o|o|o|o|X|X| | |o|X|X|X| | |X|Z|
|Z|o|o|o|o|o| | | | | | |X| | | | | | |Z|
|Z|o|o| |o|X| |o| |o| | | | | | |X| | |Z|
|Z|o|X| |o|X| |X| | | | | | | | | | | |Z|
|Z|X|X| | | | |X| | | | | | | | | | | |Z|
|Z| | | | |X|X|X| | | |o| | | | | | | |Z|
|Z|X| | | | | | | | | | | | | |X|X| |o|Z|
|Z|X|X| | |o| | | | | | | |o|o| |o| | |Z|
|Z| | | | | | | | | |X| | |o| | |o| | |Z|
|Z| | | | | | | | | |X| | | |X| | |o|X|Z|
|Z| | | | | | | | | | | | | |o| | |X| |Z|
|Z| | | | | | | | | | |o| | |o|X| | | |Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 234

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|X|o|X| | | |Z|
|Z|o|o|o|o|o|o|X|X|X|o|o|o|X|o|X| |X| |Z|
|Z|o|o|o|o|o|o|o|X|X|o|o| |X|X| |X| |X|Z|
|Z|o|o|o|o|o|o|o|o| | | |X| | | | |X| |Z|
|Z|o|o|o|o|o|o| |o| | | | | | | | | | |Z|
|Z|X|o|o|X|o|o|X| | |o| |X| | | | | | |Z|
|Z|X|o|o|X|o|o| | |o| | | | | | |X| | |Z|
|Z| | |o| |X| |X| | | | | | | | | | |o|Z|
|Z|X|X| | | | | |X|o|o| | | | |o| | |o|Z|
|Z| | | |o|o| | | | | | | | |o| | | | |Z|
|Z| | | | | | | | | | | | | |X|o|X| | |Z|
|Z|X| |X| | | | | | | |X| |X| |o| | | |Z|
|Z| | | | | | | | | | | | | | | |X|X| |Z|
|Z| | | | | | | | | |X|o|o|o| | | | | |Z|
|Z| | | | | | | | | | | | |o|X| | | | |Z|
|Z| | | | | | | | |o|o| | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 235

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X|X|o| | |Z|
|Z|o|o|o|o|o|o|o| | |X| |o|o|X| | |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|X|X| |X| | | |X|Z|
|Z|o|o|o|o|o|X|X| | | |X| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|X|o| | | | | | | | | |Z|
|Z|o| |o|o| |o|o| | |o| | | | | |X| | |Z|
|Z|o|X| |o|o| | | |o| | | | | | | | | |Z|
|Z| |X| |o|X|X| | | |o|X| | | | | | |o|Z|
|Z|X| |X|X| | | | | | |o| | | |o| |o| |Z|
|Z| | | | | | | | |X| | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z|X| | | |o|o| | | |X| | |o| |X| | | |Z|
|Z| | | | | | | | | | | | | | |X| | | |Z|
|Z| | | | | | | | | | |o| | |X| | | |X|Z|
|Z| | | | | | | | | | |X|o| | | |X| | |Z|
|Z| | | | | | | | |o| | | |X| | | | | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 236

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X| |X| |Z|
|Z|o|o|o|o|o|o|o|o|o| | | |o| | | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|X|X| | |o| |X|Z|
|Z|o|o|o|o|o|o|X| |X| |X|X| | | | | | |Z|
|Z|o|o|o|o|o|o| |o| | | | | |X| | | | |Z|
|Z|o| |o| |o|o|X| |o| | | | | | | | | |Z|
|Z| |o|o|o|o| |X|o| | | | | | | | | | |Z|
|Z|X|o| | |X|X| | | | | | | | | | | |o|Z|
|Z| | |X|X| | | |o| | |o| | | | | | | |Z|
|Z| | | | | | | | | | |X| | | | | | |o|Z|
|Z| | | | | | | | | | | | | | | |o| | |Z|
|Z| | | | | |o| | | |X| | |o| | | | | |Z|
|Z| | | |o| | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | |X| |X| |X|Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | |o| | | |X| | |X| | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | |o|X| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 237

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |X| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X| | |X|X| |Z|
|Z|o|o|o|o|o|X|o|o|X|o|X| |o| | | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X| | | | | |o| |X|Z|
|Z|o|o|o|o|o|X|o|X|o| | |X| | | | | | |Z|
|Z|o|o|o|o|o|o| | | |o| | | |X| | | | |Z|
|Z|o|X|o|o|X|o|o|X|o| | | | | | | | | |Z|
|Z|o|X| |o| |o| | | | | | | | | | |o| |Z|
|Z| | | | | |X| | | | |X| | | | | |o|o|Z|
|Z| | |X| | |o|o| | | | | | | | | |o|o|Z|
|Z| | | | | |o|o| | | | | | |o| | |o| |Z|
|Z| | | | | | | | | | |X| |o| | | | | |Z|
|Z| | | | | | | | | | | | | |X| | | | |Z|
|Z| | | |o| | |o| | | | | | | | | | | |Z|
|Z| | | | |o| | |o| | | |X| | | |X| | |Z|
|Z| | | | | | | | |o|o| | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | |X| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 238

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|X| |X|X| | | | | |X|Z|
|Z|o|o|o|o|X|o|o| |o| |o| |X| | | |X|X|Z|
|Z|o|o|o|o|o| |X| | | |o| | | | | |o| |Z|
|Z|o|o|o|o|o|o|X|o|X|o| | | | | | | | |Z|
|Z|X|o|o| |o| |o| | | | | | | | | | | |Z|
|Z|X|o| | |o|o|X| | |o| | | | | |o| | |Z|
|Z| |o| |X| | | |o| | | | | | | | |o| |Z|
|Z|o| | |X| | | | | |X| | | | | |o|o| |Z|
|Z| | | | | | |X|o| | | | | | | | |o| |Z|
|Z| | | | |o| | | | | | | | | | |o| | |Z|
|Z| | | | |o| | | | | | | |X|o| | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | |o| | |o|o| | | | | | | | | | | |Z|
|Z| | | | | |o| | | | | |X| | | | | | |Z|
|Z| | | | | | | |o| |o| | |X| | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 239

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o| | |X| |X| | | | |X| |Z|
|Z|o|o|o|o|o|o| |X|o|o|o| | | | | | | |Z|
|Z|o|o|o|o|o|X| |o| | | |X| | | | | | |Z|
|Z|o|o|o|X|o|o| |o| | | | | | | | |X| |Z|
|Z|X| | |o|o|o| |X| |X| |o| | | | | | |Z|
|Z|o|X| |o| | | | | |o| | | | | | | | |Z|
|Z|o| |o|o|X|X|o|o| | | | | | |o|o| | |Z|
|Z|o| | | | | | | | | | | | | | | |o| |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | |o| | | |X| |X| | | | |o|o|o| |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | |X| | | | |Z|
|Z| | | | | |o| | | | | | | | | | | | |Z|
|Z| | |o| | | |o| | | | | | | | | | | |Z|
|Z| | | | | |o| | | | | | | | | | | | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z| | | | | | |o| | | | | | | | | | | |Z|
|Z| | | | | | |o| | | | |X| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 240

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o| | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|X|X| |X|X| | | | |Z|
|Z|o|o|o|o|X|o|o|X|X| | |X| |o| | | | |Z|
|Z|o|X|o|o|X|o|o|X|X| | | |o| | | | |X|Z|
|Z|o|X|o|X| | |o| |X| | | | | | | | |X|Z|
|Z|X|o|o|X|X|o|o| | |X| | | | | |o|o| |Z|
|Z|X|o|o|o| |X|X| |X| | | | | | | |o|o|Z|
|Z| | |o|o|o| | |o| | | | | | | |o|o| |Z|
|Z|o|o| |o| | | | |o| | | | |o| |o|o| |Z|
|Z| | | | | | | | | |X| | | | |o| | | |Z|
|Z| | |o|o| | | | |X| | | | | |o|o| | |Z|
|Z| | | | |o| | | | | | | |X| | | | | |Z|
|Z| | | | |o|o| | | | | | |X| | | | | |Z|
|Z| | | |o| |o|o| | | | | | | | | | | |Z|
|Z| | |o| |o| | | | | | | | | | | | | |Z|
|Z| | | | | | |o| | | | | | | | | | | |Z|
|Z| | | | | | |o| | |o|o| | | | | | | |Z|
|Z| | | | | | | |o|o| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 241

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o| |X| | |X| | | | | |Z|
|Z|o|o|o|o|o|o| |X|X|o| | | | | | | | |Z|
|Z|o|o| |X|o| |X| |X| | | | |X| | |X| |Z|
|Z|X|o| | |o|X| | | | | | |X| | | | | |Z|
|Z|X|o|X|o|o|o|X|o| |X|X| | | | | | | |Z|
|Z| |X| | | | | |o| |X| | | | | |o|X| |Z|
|Z| |X|X|X| | | | | | | | | | |o| |o| |Z|
|Z| |o|o| |X| | |X| | | | |o| | | |o|o|Z|
|Z| | |o| | | | | |X| | | | | |o| | |o|Z|
|Z|o| |o|o| | | | | | | | | | | | | | |Z|
|Z| | | |o| | | |X| | | |X| |o| | | | |Z|
|Z| | |o|o| | | | | | | | | | |o|o| | |Z|
|Z| | | | |o|o| | | | | |X| | | | | | |Z|
|Z| | |o| |o| | | | | | | | | | | | | |Z|
|Z| | | | | |o| | | | | | | | | | | | |Z|
|Z| | | | | |o| | | |o| | | | | | | | |Z|
|Z| | | | | |o| |o|o| | | | | | | | | |Z|
|Z| | | | | | |o| | |o| | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 242

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o| |X| | | | | |X| | | | |Z|
|Z|o|o| |o| |X|o| | |X| | | | | | | | |Z|
|Z|o| |o|o|X| | |X| |X| | | |X| | | | |Z|
|Z|o|X| | | |o| | | |X| | | |X| | | | |Z|
|Z| |X|X|X| |X| |X|X| | | | | | | | | |Z|
|Z| | | |o| | |o| | | | | | | | |X|o| |Z|
|Z| | | | | | | | |X| |X| | | | | | | |Z|
|Z| |X|X|X| | | | | | | | | | |o|o|o| |Z|
|Z|o|o|o| |X| | | | | | | | |o| | |o| |Z|
|Z| | | | | | | | |X| | | | | | | | |o|Z|
|Z| | |o| |o| | | | | | | |o| | | | | |Z|
|Z| |o| | | |o|o| | | |X| | |o| | | | |Z|
|Z| |o| |o| |o| | | | | | | | | |o| | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | |o| | | | | | | |Z|
|Z| | | | |o| | | | | | | | | | | | | |Z|
|Z| | | | |o| | | | |o| | | | | | | | |Z|
|Z| | | | |o|o| |o|o| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 243

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|X| | | | | | | | | | | | |Z|
|Z|o|o|o|o| | |X| |X| | | | | | | | | |Z|
|Z|X|o|o|o|o| | | | | | | |X| |X| | | |Z|
|Z|X|o|X|o|o|X| | |X| | | | | | | | | |Z|
|Z| | | |o| | | | | | | | | | | | | | |Z|
|Z| | | |X| | |X|X| | | | | | | | |X|o|Z|
|Z| | | |X| | | |X| | | | | | | | |o| |Z|
|Z| | | | | | | | | | | | | | |o| |o| |Z|
|Z| |X|X| | | | | | | | |o| | |o|o| | |Z|
|Z|o| | | |X| | | | | | | |o|o| |o|o| |Z|
|Z| |o|o|o|o| | | |X| | | | | |o| |o| |Z|
|Z| | |o|o|o|o| | | | | | | | | |o| |o|Z|
|Z| | |o|o|o| |o| | | | | | | |o| | | |Z|
|Z|o| | | |o|o| | | |o|o| | | | |o|o| |Z|
|Z| |o| | | | |o| | | | | | | | | | | |Z|
|Z| | | | | |o| | |o| |o| | | | | | | |Z|
|Z| | | |o| |o| | |o|o| | | | | | | | |Z|
|Z| | |o|o|o| |o|o| |o|o| | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 244

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|X| | |X| | | | | | | | | | |Z|
|Z|X|o|o|o|o| | | | |X| | | | | | | | |Z|
|Z|o| | | | | | | | | | | | | | | | | |Z|
|Z| |X|o|X|X|o| | | | | | | | | | | | |Z|
|Z| | | |X| | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | |o| |Z|
|Z| | | | | | |X| |X| | | | | | |o|X| |Z|
|Z| | | | | | | | | | | | | |o|o| | | |Z|
|Z| | | | | | | | | | | | | |o| | | | |Z|
|Z|X|X|o|o| | | | | | | |o| | |o|o| | |Z|
|Z| | |o|o|X| | | | | | | | |o| |o|o| |Z|
|Z| |o|o| |o|o|o| | | | | | |o| | |o| |Z|
|Z| | | | | |o| | | |o| | | | | |o|o| |Z|
|Z| |o| |o|o|o| | | | | | | | |o|o| | |Z|
|Z| | | | |o| | | | | | |o| | | | | | |Z|
|Z| | |o|o| | | | | |o| | | | | | | | |Z|
|Z| |o| |o|o|o|o|o|o|o|o| | | | | | | |Z|
|Z| | | | | |o| | |o|o| | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 245

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o| |X| | |X| | | | | | | | | | | |Z|
|Z|o|X|o| | |o| | | | | | | | | | | | |Z|
|Z|X| | |o| | | | | | | | | | | | | | |Z|
|Z| | |X| | |X| | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | |X| | | | | | | | | | | | | |X| |Z|
|Z| | | | | | | | | | | | | |o| | | | |Z|
|Z| | | | | | | |X| | | | | |o| | |o| |Z|
|Z|X| | | | | | | | | | | |o| |o|o| | |Z|
|Z| | |X|o| | | | | | | | | |o| |o| |o|Z|
|Z| |o| |X|o|o|o| | | | | | | | | |o| |Z|
|Z| | | | | | |o| | | | | |o| |o|o| |o|Z|
|Z| |o| |o|o| |o| | | | | | | | |o| | |Z|
|Z| | |o|o|o| | | | | |o| |o| | | | | |Z|
|Z| | | | | | | | | | |o| | | |o| | | |Z|
|Z| |o| | |o|o| |o| |o| | | | | | | | |Z|
|Z| | |o| |o|o| |o|o| | | | | | | | | |Z|
|Z| | | | |o| |o| |o| |o| | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 246

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|X| |o| | | | | | | | | | | | | | | |Z|
|Z|X| |X|o| |X| | | | | | | | | | | | |Z|
|Z| | | |X|X| | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | |X| |Z|
|Z| | | |X| | | | | | | | |o| | | | | |Z|
|Z| | | | | | | | | | | | |o|o|o| | |o|Z|
|Z| | | | | | | | | | |o|o| | |o|o| |o|Z|
|Z|o|X| | | | | | | | | | | |o|o| |o| |Z|
|Z| |o| |X|o| | | | | | | | | |o|o|o|o|Z|
|Z| | | | |X|o|o| | | | | | |o|o|o|o| |Z|
|Z|o| | |o|o|o|o| | | | |o| | |o|o|o|o|Z|
|Z|o| |o|o| |o|o| |o| |o|o|o|o|o| | | |Z|
|Z| | |o|o|o|o| |o|o|o| |o| | |o|o| | |Z|
|Z| |o| |o|o|o|o| |o|o| |o| | | |o| | |Z|
|Z|o| | |o|o|o|o|o|o| | | | | | | | | |Z|
|Z| |o| |o|o|o|o| |o| |o|o| | | | | | |Z|
|Z| | |o| |o|o|o|o| |o| | |o| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 247

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | |o| | | | | | | | | | | | | | |Z|
|Z| |X|X|X|X|X| | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | |o|X| |Z|
|Z| | | | | | | | | | | |o| | |o|o|o| |Z|
|Z| | | | | | | | | |o| | |o|o| | | |o|Z|
|Z|X| | | | | | | | | | |o| |o| |o|o|o|Z|
|Z| | | | |X|o| | | | | | |o|o| |o|o|o|Z|
|Z|o| | | | | |o| | | | |o| | |o|o| |o|Z|
|Z| |o|o|o| |X| |o|o| |o| | |o| |o| | |Z|
|Z| |o|o|o|o|o|o|o|o|o|o| |o|o| |o| |o|Z|
|Z|o| |o|o|o|o|o| | |o| | | |o| | | | |Z|
|Z| | | | |o|o|o|o| | | | |o| | | |o| |Z|
|Z|o| |o| | |o| |o| |o|o| |o| | | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | | | | | | |Z|
|Z| | | | |o| | | |o| |o| | |o| | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 248

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|X| | |X|X| | | | | | | | | | | | | |Z|
|Z|X|X|X|X| | | | | | | | | | | | | | |Z|
|Z| | |X|X| | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | |o| | | |Z|
|Z| | | | | | | | | | |o| | | |o|X|o| |Z|
|Z| | | | | | | | | | |o|o| |o| |X|o| |Z|
|Z| | | | | | | | | | | |o| | | |o| |o|Z|
|Z| |X| | | | |X| | | | | | | |o| |o|o|Z|
|Z| | |X| | |X| | | | | |o|o| |o| |o| |Z|
|Z|o| | |o| |o| |o| |o| | | |o| | |o| |Z|
|Z|o| |o| |o|o|X| | |o|o| |o|o| | |o|o|Z|
|Z|o|o| |o|o|o|X| |o| |o|o| | |o| |o| |Z|
|Z| |o|o| |o|o|o|o|o| | | | | | | | |o|Z|
|Z| |o| | | |o|o| |o|o| | | |o| | | | |Z|
|Z| |o| |o|o|o| | |o|o| |o| | | |o| |o|Z|
|Z| |o| | |o|o| | | |o| |o|o|o| | | | |Z|
|Z|o|o| | | |o|o|o| |o| |o| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 249

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | |X| | |X| | | | | | | | | | | | |Z|
|Z| | | |X|X| | | | | | | | | | | | | |Z|
|Z|X|X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z|X| | | | | | | | | |o| | | | | | | |Z|
|Z| | | | | | | | | | | | |o|o|X| | |o|Z|
|Z| | | | | | | | | | | |o|o| |o|o|X|o|Z|
|Z| |X| | | | | | | |o|o| | |o|o|o|o|o|Z|
|Z| | | | | | | |X|o|o|o| | |o| |o|o|o|Z|
|Z| | | | | | |o|o|o|o|o|o|o| | |o|o|o|Z|
|Z|o|o|o|X|o|X|o| |o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o| | |o|o|o| | |o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o| |o|o| |o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o| | |o| | | |o|Z|
|Z| |o|o|o|o|o|o|o|o|o|o| | |o| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 250

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | |X|X| |X| | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|X| | | | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | |o| |o| | | | | | |Z|
|Z| | | | | | | | | | |o|o| |o|o| |o| |Z|
|Z| | | | | | | | |o| | |o| |o|X|o|o|o|Z|
|Z| | | | | | | | |o| |o| | | |o| |X|o|Z|
|Z| | | | | | | |o| |o|o|o|o| |o| |o| |Z|
|Z| |o|o| | |o|X|X| |o|o|o| |o|o|o|o|o|Z|
|Z|o|o|o|o| |o| | |o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|X| | |o|o|o|o|o|o|o|o| | |o|Z|
|Z|o|o|o| |X|o|o|o|o|o| |o| |o| | |o|o|Z|
|Z|o|o|o|o| |o|o|o|o| |o|o|o| | |o|o| |Z|
|Z|o|o|o|o|o| |X|o|o|o|o| |o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o| | | |o| |o|o| | | |o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 251

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | |o| | | |o| | | | | |Z|
|Z| | | | | | | | | | | |o| | | | |o| |Z|
|Z| | | | | | | | | | | | | |X|o|o| | |Z|
|Z| | | | | | | |o| | |o| |o| | |o|o|X|Z|
|Z| | | | | | | | |o|o| |o| | |o| |o|o|Z|
|Z| |o| | | | | | |o|o|o|o| |o|o|o| |o|Z|
|Z|o|o|o|o| | |o| |o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o| | | |X| |o|X|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|X| | |o|o|o| |o| | | | | |o|o|Z|
|Z|o|o|o| |o|X|o|o|o| |o|o|o|o| |o|o| |Z|
|Z|o|o|o| | |o| |o|o|o|o| | |o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o|o|o|Z|
|Z|o|o|o|o| |o|o|X|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o| |o|o|o|o| | | | |o| | | |Z|
|Z|o| | | |o|o|o| | |o| |o|o| | |o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 252

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | |o| |Z|
|Z| | | | | | | | |o| | | | | | | | |o|Z|
|Z| | | | | | | | |o|o| | |o|o| |o| | |Z|
|Z| | | | | | | |o|o| |o| |o|o|o| |o|o|Z|
|Z| | | | | | | |o|o|o|o|o|X|o|o|o|o|o|Z|
|Z| | |o| | | |o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o| | | | |o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o| | |o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|X|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 253

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | |o| | |Z|
|Z| | | | | | | | | |o| | | | | | |o| |Z|
|Z| | | | | | | | |o| | | | |o|o| | | |Z|
|Z| | | | | | | |o| |o|o|o| |o|o| |o| |Z|
|Z| | | | | | | |o|o| | | |o|o|o|o|o| |Z|
|Z| |o| | | | | |o|o|o| |X|o|o|o|o|o|o|Z|
|Z|o|o|o| | | |o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| |o|o|o| |o| |o|o|o|o|o|o|o|o| |X|o|Z|
|Z|o|o|o| | | |o|X|o|o|o|o| |o|o|o|o| |Z|
|Z| |o|o|o|o|o| |X|o|o|o|o| |o|o|o|o|o|Z|
|Z|o|X|o|o|o| |o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 254

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | |o| | | | | | |o| |Z|
|Z| | | | | | | | | |o| | | | | |o| | |Z|
|Z| | | | | | | |o| | | | | |o| | | | |Z|
|Z| | | | | | | |o| | |o| | | |o|o| | |Z|
|Z| | | | | | | | |o| | |o|o|o|o|o| |o|Z|
|Z|o| | | | | | |o|o|o| | | |o|o| |o| |Z|
|Z|o|o| |o| | |o|o|o|o|o|o|o|o|o| |o| |Z|
|Z| | | | | |o|o|o| |o|o|o|X|o| |X|o| |Z|
|Z|o|o|o| | | | | |o|o|o|o|o|o|o|o|o|o|Z|
|Z|o| |o|o|o| |X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| |Z|
|Z|o|o| |o|o|o|o| |o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|X|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o| |o|o| |o|o| |o|o|o| | |o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o| |o| | |o| | |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 255

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | |o| |Z|
|Z| | | | | | | | |o|o| | | |o| | |o|o|Z|
|Z| | | | | | |o|o|o|o| | |o|o|o|o| |o|Z|
|Z| | | | | |o| |o|o|o|o| | |o|o|o|o| |Z|
|Z| | | | | | |o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z| |o| | |o| |o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o| |o|o|o|o|o|o|X|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 256

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | |o| |o| | | |o| |Z|
|Z| | | | | | |o|o|o|o| | | | | |o|o|o|Z|
|Z| | | | | | |o| |o| |o|o|o|o|o|o|o| |Z|
|Z| | | | | | |o|o| |o|o|o|o| |o|o|o| |Z|
|Z| |o| | | |o|o|o|o|o|o|o|o|o|o| | |o|Z|
|Z|o|o| |o|o|o|o| |o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o| |o|o|o| |o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|X|X|o|o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o| |o|X|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|X|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 257

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | |o| |o|o| | | |o|o|o|Z|
|Z| | | | | |o| |o| | |o|o|o| | | |o| |Z|
|Z| | | | | |o| |o| |o|o|o|o|o| |o| |o|Z|
|Z| | | | |o| |o| |o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o| |o|o|o|o|o|X|o| | |o|o|o|o|Z|
|Z|o|o|o|o|o| |o|o|o|o|o|o| |o|X|o|o| |Z|
|Z|o| |o|o| |o|o|X| |o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o| | | |o|o| |o|o|o|o|o|o|o|Z|
|Z|o|o|o| | |X|o|o|o|o|o|o|o| |o|o|o| |Z|
|Z|o|o|o|o|o|o|o|X|o|X|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |X|o|o|o|o|o|o|o|Z|
|Z|o|X|o|o| |o| |o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o| |o|o| | |o| | |o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 258

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | |o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| | | | | |o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o| |o| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 259

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | |o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| |o| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o| |o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o| | |o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o| |X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o| | |o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o| |X|o|o|o|o|o|o| |o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 260

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o| |o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o| |o|o|o|o|o|o|o| |X|o| |Z|
|Z|o|o|o|o|o|o|o| |o|o|X| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|X| | |o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|X|o|o|o|o| |X|o|o|o| |o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o| |o| | | |Z|
|Z|o|o|o|o|o| | |o|o|o|o|o| | |o| |o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 261

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 262

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|X|o|o|o| |X|o|o|o| | |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|X|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 263

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o| | |o|o|X|o|o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|X|o|o| |X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o| |X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|X|o|o|X|X|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o| |o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 264

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 265

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o| |o|X|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|X|o|o| |o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 266

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o| |o|X|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o| |o|o|o| |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|X|o|o| |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o| |o|o|o|o|o|X|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|X|o|o|o|o|o|o|o|o|o| |o|o| |o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 267

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 268

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|X|o|o|o|o|X|o| |Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|X|o|o|o|o|o|X|o|o|o|o|o|o| | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 269

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |X|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|o|o| |Z|
|Z|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 270

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|X|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 271

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o| |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o| | |o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 272

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|X|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o| |o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | |o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o| |o|o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 273

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|X|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 274

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o| |X|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o| |o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o| |o|o| |o| |o|o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 275

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X| |o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o| |o|o|X|o| |X|o| |o|Z|
|Z|o|o|o|o|X|o|o| |o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o| |o| |o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o| | |o|X|o| |o|o|o| |Z|
|Z|o|o|o|o|o|o|o| |o|o| |o| |o|o| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 276

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 277

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o| |o| |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|X|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o| |o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o| |o|o|o|o| |o|o|o|o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 278

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o| |o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|X|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |o|o|o|Z|
|Z|o|o|o|X|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o| |o| |X|o|Z|
|Z|o|o|o|o|o| |o|o| |o|o|X|o| | |o|o| |Z|
|Z|o|o|o|o|o| | |o| |o| |o|o| |o| |o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 279

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 280

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|X|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o| |o| |o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|X|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o| | | |o|X|o|o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 281

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| | |Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o| |o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|X| |X|o| |o| | |Z|
|Z|o|o|o|X|o|o|o|o| |o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o| |Z|
|Z|o|o|o|o|o|o|o| | |o| |o|o| |X|o|o|o|Z|
|Z|o|o|o|o|o| |o| |o| |o| |o|X| |o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 282

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 283

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o| |o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o| |o|X|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 284

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|X|o| |X|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X| |o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o| |o|o|o| |o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o| |X| |o|o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |o| |o|Z|
|Z|o|o|o|o|o|o|o|o|X|o| |o|o|o| | |o| |Z|
|Z|o|o|o|o|o|o|o|o| |o|o| |o| |o|X|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 285

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o|X|o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 286

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|X|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o| |o|o|o| |o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X| |o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|o| |Z|
|Z|o|o|o|o|o|o| |o| |o| | |o| |o| | |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 287

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o| |Z|
|Z|o|X|o|o|X|o| |X|o|o|o|o|o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o| |o| |o| |o|o|o|o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o| | |X| | | |o|o|X| |o| |Z|
|Z|o|o|o|o|o| |o| |o| |o|o| |o| |o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 288

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|X|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 289

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|X|o|o|o|o|o|o|o|o| | |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o| |X|X|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o| |X|o|o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|X|X|o|X|o|X|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o| | |o|o| |o| |o|o|o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 290

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o| |o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|X|X|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|X|o|o| | |o| |o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o| |o|X|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o| | | |o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o| |X|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|X|X|o|X|X| |X|o| |o|o|o|Z|
|Z|o|o|o|o|o| | |o|o| |X|o|o|o|o|o|o| |Z|
|Z|o|o|o|o| | |o| | |o| |o| | | |o| |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 291

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o| |X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o| |o|o|o|X| |o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 292

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|X|o| |o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o| |o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o| |o|o| |o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o| |o|o| |X|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | |X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o| |X|o|o|o|o|o|Z|
|Z|o|o|o|o| |o| |o| |X|X| |o|o|o| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 293

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|X|o|o|o|o|o| | |o| |o|o|Z|
|Z|o|o|o|X|o|o|o|o|o| |o|o|X|o| |o|o|o|Z|
|Z|o|o|o|o|o| |o| |o| |o|o|o|o|o|o|o| |Z|
|Z|o|o|o|X|o|o|o|o|o|o|o| |X|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o| |o|o|o|o| |o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |X| | |o|X|o|o| |Z|
|Z|o|o|o|o|o| |o| |X| |X|X|o|o|o| | | |Z|
|Z|o|o| | |o| |o| |o| | | |X|o| |o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 294

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X| |o| |o|o|o|X| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| | |X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| | |X|o|X|o|o|o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 295

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o| |Z|
|Z|o|o|o| |X|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|X|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o| |o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|X|o|X|o|o| |Z|
|Z|o|X|o|o|o|o|o|o|o| |X|o| |o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|o| |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X| |o| | |X|o|X| |Z|
|Z|o|o|o|o|o|o| |o| |o| | |X|o| |o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 296

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|X|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|X|o| |o| |o|Z|
|Z|o| |o|X|o|X|o|o|o| | |o|o|X|o|o|o|o|Z|
|Z|o|o|X|o|o|o|X|o|o|o|o|o|o|o|X|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o| |X| |o| | |o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|X|X|X| |o| |Z|
|Z|o|o|o|o|o|o|o| | |o|o| |o| |X|X|o| |Z|
|Z|o|o|o|o| | |o| |X|X|o| |X|X|o| |X| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 297

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|X|o|o|X|o|X|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|X|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|X|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | | |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|X|X|X| | |X|o|Z|
|Z|o|o|o|o|o|o| |o|o| |X|o|X| |X| | |X|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 298

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|X|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o| |o|o|o|o|o|o|o|o|o| |o|o|o| |Z|
|Z|X|o|o|o|o| |X|o|o|o|o|o| |X|o|o|o|o|Z|
|Z|o|o|o| |o|o|X|o|o|o|X| |o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|X|o|o|o|o|X|o|o| |X|o|o|o|Z|
|Z|X|o|o|o|o|o|o|o|o|o|o|o|X|X|o| |o| |Z|
|Z|o|o|o|o|o|o|o| |o|o|o|o|o| |X|o|o| |Z|
|Z|o|o|o|o|o|o| | | |X| | |X| | |o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|X|o| | | | | |X|Z|
|Z|o|o|o|o|o|o|o| | |o| |X| |X| |X| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 299

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|X|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o| |o|o|o|o|o|o|o|o|o| |o|o|o| |Z|
|Z| |X|o|o| |o|o|o|o|o|o|o| |o|X|o|o|o|Z|
|Z|o|o|o| |o|o|o| |o|o|o| |o| |o|o|o|o|Z|
|Z|o|o|o|o| | |o|X|o|o|o|o|o| | |X|o|o|Z|
|Z|X|o|o|o|X|o|X|o|o| | |X| | |o| |o| |Z|
|Z|o|o|o|o|X|o|o|o|o| |X| |o|o|X| |o|o|Z|
|Z|o|o|o|o|o|o| |o| |X| |X|X| | |X| | |Z|
|Z|o|o|o|o|o|o|o| | |o| |o| | | |X| | |Z|
|Z|o|o|o|o|o|o|o| |X|o|X|X| | |X| | | |Z|
|Z|o|o| |o| | | |o|o| | | | | | | | |X|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 300

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|X|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|X|X|o|o| |o| |X|o|o|o|Z|
|Z|o|X|o|X|o|X|o|o| |o| |o|X|X| | |X|o|Z|
|Z|o|o|o|o|o|o|o|o| |o|X| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|X| | | | | |X| |X|Z|
|Z|o|o|o|o|o|o| |X| | | | |X| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 301

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o| |X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | |o|X|o|o|o|Z|
|Z|X|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| | | |o|X|X|o|o|Z|
|Z|o|o|o|o|o| |o|o|o|X| |o|X|o| |X|o| |Z|
|Z|o|o|o|o|o|o|X|o| |X| |X| | | | |o| |Z|
|Z|X|o|o|X|o|X|o|o|o| | | | | | | | | |Z|
|Z|o|o|o|o|o|o|o| |X| |X| | | | | | | |Z|
|Z|o|o|o|o|o|o| |X|X| | | | | | | | | |Z|
|Z|o|o|o|o| | |o| | | | |X| | | | |X| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 302

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o| |o|Z|
|Z|o|X|o|o|o|o|o|o|o|o|o|o| |o|X| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o| |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o| |o|o| | |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o| |o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o| | |X|o|o| |Z|
|Z|o|X|o|o|o|o|o|o| |X|o| | |X| | |o| |Z|
|Z|o|o|o|o|o|o|o|o|X| | |X| |X| |o| |o|Z|
|Z|o|o|o| |X| |o| | | | | | | | | |X| |Z|
|Z|o|o|X|o|o|o|o|X|X| | | | | | | | | |Z|
|Z|X|o|o|o|o| |X|o| | | | | | | | | | |Z|
|Z|o|o|o|o| | | |X| |X| | | | | | | | |Z|
|Z|o|o| | |o|o| |o| | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 303

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|X|o|o|o|o|o|o|o|o|o|X|o|o|o| | | |o|Z|
|Z|o|o|o|o|o|o|o|X|o| | |o|X| |X|X| | |Z|
|Z|o|o|o|o|o|o|o|o|X| | |X| | | | |o|o|Z|
|Z|X|o|o|X|o|o|X|o|o| | | | | | | | | |Z|
|Z|o|o|o|X|o|o|o|X|o| |X| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o| | | | | | | | | | |Z|
|Z|o|o|o|o| |o| |X| | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 304

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|Z|
|Z|o|X|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|X|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o|o|Z|
|Z|X|o|o|o|o|o|o|o|o|o|o|X|o|X| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X| |X|o| |X|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|X| | | | | |o|Z|
|Z|o|o|o|X|X| |o|X| | | |X| | | |X|X| |Z|
|Z|o|o|o|o|X|o|o|X|X|o| |X| | | | | | |Z|
|Z|o|X|o|o|X|X|X| |X|o| |X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|X|X| | | | | | | | | |Z|
|Z|o|o| | |o| |o| | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 305

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|X| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|X|o|o|o| |Z|
|Z|o|o|X|o|o|o|o|o|o|o|X|X|o|o|o| |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |o|o| |Z|
|Z|o|X|o|o|o|o|o|o|o|o| |o|X| |o|o|o| |Z|
|Z|o|o|o|o|o|o|o| |X|X| |o| | |o|X| | |Z|
|Z|o|o|o|o|o|o|o|X|o|o| |X|o| |X| |o|o|Z|
|Z|o|o|o|o| |X|X| | | |X| |X| | | | |X|Z|
|Z|o|o|o|o|o|o| | | | | | | | | | | | |Z|
|Z| |o|X|X| | |X|o| |X| | |X| | |X| | |Z|
|Z|X|o|o|o| | | | | |X| | | | | | | | |Z|
|Z|o|o|o| |X|X|X| | |X| | | | | | | | |Z|
|Z|o| |o|o| | |X| | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 306

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | |o|X|o|X| |Z|
|Z|o|X|o|o|o|o|o|o|o|o|o|X|o|o|X|o|o| |Z|
|Z|o|o|o|o|o|X|X|o|X|X|o| |X| | | |X|o|Z|
|Z|o|o|o|o|o|o|o| | | | | | | | | | | |Z|
|Z|o|o|X|o|o|X|o| |X|X| | | |X| | | | |Z|
|Z|o|o|o|o|o| | |X| | | | | | |X| | | |Z|
|Z|o|X|X|X| |X| | | | | | | | | | | | |Z|
|Z|o|o|o|o|o|X| |X| | |X| | | | | | | |Z|
|Z|o|o|o|o|o| | | |X| | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 307

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |X|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o|o| |o|o| |X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|X| | |o| |Z|
|Z|o|o|X|o|o|o|o|o|o|o| |o|o| | |X|o| |Z|
|Z|o|o|o|o|X| |X|X|o| |X| |X|X| |X|X| |Z|
|Z|o|o|o|o| |o|o| |o| |X| | | | | | |X|Z|
|Z|o|o|o|o|o| |X| | | |X| | | | | | | |Z|
|Z|o|o|o| | |o|X| | | | | | | | | | | |Z|
|Z|o|X| | |X|o| | |X| | | | | | | | | |Z|
|Z|o|o|o|o| | | |X| |X| | | | | | | | |Z|
|Z|o|X|o|X|X| | | | | | | | | | | | | |Z|
|Z|o|o|o| |X| | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 308

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o| | | |o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|X|o|o|o|o|o| |o|o|X|X| |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o| | | |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o| |o|o|o|o| | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| | |Z|
|Z|o|o|X|o|o|o|o|o|o| |o| | |o| |o|X| |Z|
|Z|o|o|o|o| |X| |X|X| |o|X|X| | | |X| |Z|
|Z|o|o|o|o|o| |o| | |o|X| | | |X| | |X|Z|
|Z|o|o|o|o|o|o| |o| | | | |X|X| | | | |Z|
|Z|o|o| |o| |o| | | | | | | | | | |X| |Z|
|Z| | | |o| |X| | | | | | | | | | | | |Z|
|Z|X|o|o| | |X| | | | | | | | | | | | |Z|
|Z|o|X| |X| | | | | | | | | | | | | | |Z|
|Z|o|o|o|o| |X| | | | | | | | | | | | |Z|
|Z| | |X|o| |X| | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 309

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X| |o|Z|
|Z|o|o|o|o|o|o|o|X|o|o|X|o|o|X| |X| |o|Z|
|Z|o|o|X|o|o|o|o|o| |o|X|o| | | | | | |Z|
|Z|o|o|o|o|X|o|X|o|o| | | | |X| |X| | |Z|
|Z|o|o|o|o|o|o|o|o|o| | | | | | |X|X| |Z|
|Z|o|o|o|o|o|X| | |o| | | |X| | | | | |Z|
|Z|o|o|o| |X|o| | |o| | | | | | | | | |Z|
|Z|o|o|o| | | | | | | | | | | | | | | |Z|
|Z|X|o|o|o| | | | | | | | | | | | | | |Z|
|Z|X|X|X|o|o| |X| | | | | | | | | | | |Z|
|Z| | | | |X| | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 310

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |X| |o|o|o| |Z|
|Z|o|o|o|X|o|o|o|o|o|o|o|o|o|o|o| |o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |X| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |X| | | |Z|
|Z|o|o|o|o|o|o|X|o|o| |X|X|X| | | |o|o|Z|
|Z|o|o|o|X|o|o|o|o| |o|o|X|o| | | | | |Z|
|Z|o|o|o|o|o|X|o|o|o| | | | |o| | |X| |Z|
|Z|o|o|o|o|o|o|o|o| | | | | | | | | | |Z|
|Z|o|o|o|o|o| |X|X|o|o| | | | | | | | |Z|
|Z|o|o|o|o| | |o| | | | | | | | | | | |Z|
|Z|o| | | |o|X| |o| | | | | | | | | | |Z|
|Z| |X| |o| | | | | | | | | | | | | | |Z|
|Z|o|X|X|X| | | | | | | | | | | | | | |Z|
|Z| | | | |X| | | | | | | | | | | | | |Z|
|Z| | | | |o| | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 311

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|X|o|o|o|o|X|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| | |o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |X| |Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|o| |X|X|o|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| | |X| | | | |Z|
|Z|o|o|o|o|o|o| |o|o| | |X|X|o| | | |o|Z|
|Z|o|o|o|o|o|X|o|o| |o| | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| |X| |X|o| |X| |o|Z|
|Z|o|o|o|X|X| |o| | |o| | | | | | | | |Z|
|Z|o|o|o|o|o| | |X| |o| | | | | | | | |Z|
|Z|o|o|o|o| |o|o| |X| | | | | | | | | |Z|
|Z|o|o| | |o| |o|o| |o| | | | | | | | |Z|
|Z| |o|o|o|X| | | | | | | | | | | | | |Z|
|Z| | | |X| | | | | | | | | | | | | | |Z|
|Z|X| |X| | | | | | | | | | | | | | | |Z|
|Z| | |X| | | | | | | | | | | | | | | |Z|
|Z| | | | |X| | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 312

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|X|o|o|o|o|o|o|o|o|o|o|o|X|o|o|X|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|X|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|o|X|X| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o|X|X| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X| | | |o|Z|
|Z|o|o|o|X|X|o|X|o|o| |o|o| |X| | |o|o|Z|
|Z|o|o|o|o|X|X|X|X| |X|o| |X| | | |o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| | | | | | | | | |Z|
|Z|o|o|o|o|X| | |X| | | | | | | | | | |Z|
|Z|o|o|o|X|X| |X|o| | | | | | | | | | |Z|
|Z|o|o|X|X| | |o| | | | | | | | | | | |Z|
|Z|o|X|X|X| | | | | | | | | | | | | | |Z|
|Z| | |X|X| |X| | | | | | | | | | | | |Z|
|Z| | | | |X| | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 313

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|X|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|X|o|o|o|o|o|o|o|o|o| |o|o|o| | |X|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| | |X|o|X|X|X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X| | |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|X| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X| |X| | | | |o|Z|
|Z|o|o|o|X| |o|o| |o|o|o|o|X|X| |X| | |Z|
|Z|o|o|X|o|o|X|o|X|X|o| |X| | | | |o|o|Z|
|Z|o|o|o|X| |o|o|o| |o|X| | | | |o| | |Z|
|Z|o|o|o|o|o|X|o| | |X| | | | | | | | |Z|
|Z|o|o|o|X| |o| | | | | | | | | | | | |Z|
|Z|o|o|X|X| | | | |o|o| | | | | | | | |Z|
|Z|o|o|X| | | | |X| | | | | | | | | | |Z|
|Z| |X| | |X| |X| | | | | | | | | | | |Z|
|Z| | |X| |X|X| | | | | | | | | | | | |Z|
|Z|o| | | | | | | | | | | | | | | | | |Z|
|Z| |X| |X| | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 314

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|X|Z|
|Z|o|o|o|o|o|o|o|o|o| | |X|X| | |X| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o| |X|o|o| |X|Z|
|Z|o|X|o|o|o|o|o|o|o|o|o| | |X| |X| | |Z|
|Z|o|o|o|o|o|o|o|o|o| | |X| | |X| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o| | |X| | |o|Z|
|Z|o|o| |X|o|o|o| | |X|o| |X| | | | | |Z|
|Z|o|o|o|o|o|o| |o|X| |X|X| | | | | | |Z|
|Z|o|o|o|o|X|o| |o| |X| | | |X| | |X| |Z|
|Z|o|X| |o| |X| | | |X| | | | | | | |o|Z|
|Z|o|o| |X| | | |o|X| | | | | |o| | | |Z|
|Z|o|o|X|o| |X|o| | | | | | | | | | | |Z|
|Z| |X|o| | | | | |X| |o| | | | | | | |Z|
|Z|X|X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | |X| | |X| | | | | | | | | | | |Z|
|Z|X| |X|X|X| | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 315

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X|o| | | |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o|X|Z|
|Z|X|o|o|o|o|o|o|o|o|o|o|X|o|o|X|X|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|X|o|X| |X| | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| | |o| | |Z|
|Z|o|o|o|o|o|o|o|o|X|X|o|X| |X| |X|o| |Z|
|Z|o|o|o|o|o|o|o|o| | |X|X| | | | | | |Z|
|Z|o|o|o|o|X|o|o|o| | |X| | | | | | | |Z|
|Z|o|o|o|o|o|X|o|X| | | | | | | | | | |Z|
|Z|X|o|o|X|o|o|o| | | |X| | | | | | |X|Z|
|Z|o|o| |o| |o| |X| | | | | | | |o| | |Z|
|Z|X|o|o|X| | |X| | |X| | | | |o| | | |Z|
|Z|X|o|X| | | | | | |o| | | | | | | | |Z|
|Z| | |X| | | | | | | |o| | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | |X| | | | | | | | | | | | |Z|
|Z|X| | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 316

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | | | |Z|
|Z|X|o|o|o|o|o|o|o|o|o|o| |X|X|X| |X| |Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|X|X| | |X| |Z|
|Z|o|o|o|o|o|o|o|o| | |o|X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|X|X|X| |X| | |X| | |Z|
|Z|o|o|o|o|o|o| | |o| |X|o|X| | | | | |Z|
|Z|o|o|o|o|o|o|o| |o| | | | | | |o| | |Z|
|Z|o|o|o|o|o|o| |X| | | |X| | | | | | |Z|
|Z|o|o| |X| |o|X|o| | | | | | | | | | |Z|
|Z|o|X| |o|X| |X| | | | | | | | | |X| |Z|
|Z|X| | | | |X| | | | |X| | | | | |o| |Z|
|Z|o|X|X| |o| | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | |X| |o| |o| | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 317

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |X|X| | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| | |o|o|X| |X| | |Z|
|Z|o|X|o|o|o|o|o|o|o| |o|X|X| | | | | |Z|
|Z|o|o|o|o|o|o|o|o| |o|X| | | | | |X| |Z|
|Z|o|o|o|o|o|o|o| |X|X| |X| | |X| | | |Z|
|Z|o|o|o|o|o| |o|o|X| | |X| | | | | | |Z|
|Z|o|o|o|o|o| |X| | | | | | | | | |o| |Z|
|Z|o| |X|o| |X|o|o| | | | | | | | | | |Z|
|Z|X| |o| | | |o|X| | | | | | | | | | |Z|
|Z| |o| |X| | | | | | | | | | | | | | |Z|
|Z|o|X| | | | | | | | | | | | | | |X| |Z|
|Z|X| | |X|X| | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | |o| | | |Z|
|Z| | |X| | | | | | |X|o| | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 318

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|X| | |X| | |Z|
|Z|o|o|X|o|o|o|o|o|o|o|o|X|X| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|X| | | | |X| |Z|
|Z|o|o|o|o|o|o|o|X|o|X|X| | |X| | | | |Z|
|Z|o|o|o|o|o|o|o|o| | | | |X| | | | | |Z|
|Z|o|o|o|o|o|o|o|X| | | | |X| | | | | |Z|
|Z|o|o|X|o|o|o|o| | | | | | | | | | | |Z|
|Z|o|o|o|o|o|o|X|X| | | | | | | | |o| |Z|
|Z|o|o|X|o|o| |X| | | | | | | | | |o| |Z|
|Z|o|X| | | | | | | | | | | | | | | |X|Z|
|Z|X| | |X| | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | |o| | |Z|
|Z|X| |X| |X| | | | | | | | | |o| | | |Z|
|Z| | | | | | | | | | |X| | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 319

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|X|o|o|o|o|o|o|o|o|o|X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o| |X| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o| |X|X| |X| | | | | |Z|
|Z|o|o|o|o|o|o|o|o|X|o| |X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|X| | | | | | | | | | |Z|
|Z|o|o|o| |o|o| |o| | | | | | | | | | |Z|
|Z|o|o|o|o|o|X|X| | | | | | | | |o| | |Z|
|Z|o|X| |X|o|X| | | | | | | | | | | | |Z|
|Z| |X|o|o| | | | | | | | | | | | |X| |Z|
|Z|X|o| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | |o| | | | |Z|
|Z| | | |X| | | | | | | | | | | |o| | |Z|
|Z|X| | | | | | | | | | |X| | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 320

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|X|X|X|X| | | | | |Z|
|Z|o|X|o|o|o|o|o| |X|o|X| |X| | | | | |Z|
|Z|o|o|o|o|o|o|o| |o|X| | | | | | | | |Z|
|Z|o|o|o|o|o|o|o|X|X|X| | | | | | | | |Z|
|Z|o|o|o|o|o|o|X|o| |X| | | | | | | | |Z|
|Z|o|o| |o|o|X| |X| | | | | | | | | | |Z|
|Z|X|X|X|X|X| |X| | | | | | | | | | | |Z|
|Z| |o|o|X|X| | | | | | | | | | |o|X| |Z|
|Z| |o| | |X| | | | | | | | | | | | |X|Z|
|Z|X|X| | |o| | | | | | | | | | | | | |Z|
|Z|X| | | | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | |o| |o| | | |Z|
|Z| | | | | | | | | | |X| | | | | | | |Z|
|Z| | | | | | | | | |X| | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 321

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|X|o|o|o|o|o|X|X| |X| | | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|o|X| |X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|o|X| |X| | | | | | | |Z|
|Z|o|o|o|o|o|o|X|o|X| | | | | | | | | |Z|
|Z|o|o|o|o|o|X|o|X|X| | | | | | | | | |Z|
|Z|o|X|o|X|X|X|o| | | | | | | | | | | |Z|
|Z| |o|X|o| | | |X| | | | | | | | | | |Z|
|Z|o|X|X| | |X| | | | | | | | | |X| | |Z|
|Z| |X| |X| | | | | | | | | | | | | | |Z|
|Z| | |X| |X| | | | | | | | | | | |X| |Z|
|Z| | | | | | | | | | | | | |o| | | | |Z|
|Z|X| | | | | | | | | | | | |o| | | | |Z|
|Z| | |X| | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |X| |o| | | | | | |Z|
|Z| | | | | | | | | | | |o| | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 322

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|X|o|o|o|o|o| | |X|X| | | | | | |Z|
|Z|o|o|o|o|o|o|o|X|X| | | | | | | | | |Z|
|Z|o|o|o|o|o| |o|X| |X| | | | | | | | |Z|
|Z|o|o|o| | | |o|X|X|X| |X| | | | | | |Z|
|Z|o|o|X|X|X|o|X| | | | | | | | | | | |Z|
|Z| |o| | | | |X| | | | | | | | | | | |Z|
|Z| |X|o|X|X| | | | | | | | | | | | | |Z|
|Z|X| |X|X| | | |X| | | | | | | | |X| |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | |X| | | | | | | | | | | | | | |Z|
|Z| | | |X|X| | | | | | | |o| | | | | |Z|
|Z| | | | | | | | | | | | | | |o| | | |Z|
|Z| | | |X| | | | | | | | | | | | | | |Z|
|Z| | | | | | | | |X| |o| | | | | | | |Z|
|Z| | | | | | | | | | | | |o| | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 323

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|X|X| | | | | | | | | | |Z|
|Z|o|o|X|o|o| | | | | | | | | | | | | |Z|
|Z|o|o|o| | |o|X|o| | |X| | | | | | | |Z|
|Z|o| |X|o|o|o|X| | | | | | | | | | | |Z|
|Z|o| |X| | |X| |X| | | | | | | | | | |Z|
|Z| |X| | | | | |X| | | | | | | | | | |Z|
|Z| |X|X| | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | |X| |X| | | | | | | | | | | | |X|Z|
|Z| | | | | |X| | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | |o| | |o| | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | |o| | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 324

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|X|o| | | | | | | | | | | |Z|
|Z|o|o|o|o|o|o|X| | | | | | | | | | | |Z|
|Z|o|X|X|o|o|o| |X| | | | | | | | | | |Z|
|Z|o|o|o|X|X|X| | |X| | | | | | | | | |Z|
|Z|X| | | | | |X| | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | |o|o| | |Z|
|Z| | | | | | | | | | | | |o| | | | | |Z|
|Z| | | | | | | | | | | | | |o| | | | |Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o|o| | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 325

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|X| | | | | | | | | | | |Z|
|Z|X|X|o|o| |X| | | | | | | | | | | | |Z|
|Z|o|o| | |X|X| | | | | | | | | | | | |Z|
|Z|X| |X| | | |X| | | | | | | | | | | |Z|
|Z|o| | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|X| | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | |o| |o| | |Z|
|Z| | | | | | | |o| | | | |o| | | | | |Z|
|Z| | | | | | | | |o| | | | |o| | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | |o| | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 326

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|X|o|o|o|X|X| | | | | | | | | | | | |Z|
|Z| |o| |X| | | | | | | | | | | | | | |Z|
|Z|X|X| |X| | | | | | | | | | | | | | |Z|
|Z|o| | | |X| | | | | | | | | | | | | |Z|
|Z| | | | | | |X| | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | |o| |o| | | |Z|
|Z| | | | | | | |o| | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | |o|o| | | |Z|
|Z| | | | | | | |o| | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | |o| | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 327

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o| |X|X| | |X| | | | | | | | | | | |Z|
|Z|o|X| | | | | | | | | | | | | | | | |Z|
|Z| | |X| | | | | | | | | | | | | | | |Z|
|Z|X| | |X| | | | | | | | | | | | | | |Z|
|Z| | | |X| | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | |o|o| | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | |o|o|o|o|o|o| | | | | |Z|
|Z| | | | | | | | |o| | | |o| | | | | |Z|
|Z| | | | | | | | | | | | | | |o| | | |Z|
|Z| | | | | | | | | | | | | |o| | | | |Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | |o| | | | | | | | | | |Z|
|Z| | | | | | | | | | |o|o| | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 328

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|X| | |X|X| | | |X| | | | | | | | | |Z|
|Z|X|X| |X| | | |X| | | | | | | | | | |Z|
|Z|o|X|X| | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | |o| | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | |o| | |o|o| | |o| | | |Z|
|Z| | | | | | | |o| | | | |o|o| | | | |Z|
|Z| | | | | | | |o| |o| | | |o| | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | | | | | | |o| | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | | | | | | |o| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 329

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| |X| | | | | | | |X| | | | | | | | |Z|
|Z| | | |X|X|X| | | | | | | | | | | | |Z|
|Z|X| | | |X| | | | | | | | | | | | | |Z|
|Z|X| |X| | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| |X| | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | |o| | |o| |o| | |Z|
|Z| | | | | | |o| |o| | |o| |o| | | | |Z|
|Z| | | | | | |o| |o| |o| | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | |o| | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | |o| | | | |o| | | | | |Z|
|Z| | | | | | | | | | | |o| | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 330

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | |X| | |X| | | | | | | | | | | | |Z|
|Z| |X|X| | | | | |X| | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | |X| | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|X| | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o|o| | | |o| | | |Z|
|Z| | | | | | | | |o|o|o|o|o|o|o| |o| |Z|
|Z| | | | | |o| |o| | | | |o| | | | |o|Z|
|Z| | | | |o| |o|o|o|o| |o| |o| | | | |Z|
|Z| | | | | |o| |o| | | | | | |o| | | |Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | |o| | | |o| | | | | |Z|
|Z| | | | | | | | |o| |o| |o| | | | | |Z|
|Z| | | | | | | | | | | |o| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 331

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|X| | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | |o| | | |Z|
|Z| | | | | | | |o| |o| | |o| | | | | |Z|
|Z| | | | | |o| | |o| | |o| |o| |o| | |Z|
|Z| | | |o| | |o|o| |o| |o|o| | |o| | |Z|
|Z| | | | | | |o| | | |o| | | | | | |o|Z|
|Z| | | | | | |o| | | | | |o| | |o| | |Z|
|Z| | | | | |o|o|o| | | | | | | | | | |Z|
|Z| | | | | | | |o| | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | |o| | | | |Z|
|Z| | | | | | | | | |o| | |o|o| | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 332

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | |o| | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | |o| | |o| |o| | | | | |Z|
|Z| | | |o| | |o|o| |o|o| |o| | | |o| |Z|
|Z| | | | |o| | | | | |o| | |o|o| | | |Z|
|Z| | | | | | | | |o| | | | | | |o| | |Z|
|Z| | | | | |o|o|o| | |o| | |o| | |o| |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | |o| | |o| | | |o| | | | | |Z|
|Z| | | | | | | |o|o| |o| |o|o| | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 333

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | |o|o| | | | | | | | |Z|
|Z| | | | | | | | | | | | | |o|o| | | |Z|
|Z| | | | | | | | | | | | | |o| | | | |Z|
|Z| | | |o| | |o|o|o| |o|o|o|o| |o|o| |Z|
|Z| | | | |o| | |o|o| |o|o| |o|o| | | |Z|
|Z| | | | | |o| |o| |o| |o|o|o| |o| | |Z|
|Z| | | | | |o|o|o|o| |o| | |o|o| |o| |Z|
|Z| | | | | |o| |o|o|o| | |o| | | |o|o|Z|
|Z| | | | |o|o| |o| | |o| | |o| |o| | |Z|
|Z| | | | |o|o|o| | |o|o| | | |o| | | |Z|
|Z| | | | | | | | | | | | |o|o| | | | |Z|
|Z| | | | | | | |o|o| |o|o|o| | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 334

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | |o| | | |Z|
|Z| | | | | | | | |o| | | | | |o| | | |Z|
|Z| | | | | | | | | |o| | |o| |o| |o| |Z|
|Z| | |o|o| |o|o| | |o| |o| |o|o| | | |Z|
|Z| | | | | | |o|o| |o|o|o|o|o|o| | | |Z|
|Z| | | | | | | | |o| |o| | | |o| | |o|Z|
|Z| | | | |o|o|o| | |o| |o|o| | |o| |o|Z|
|Z| | | | |o|o|o|o|o| | |o|o|o| |o| | |Z|
|Z| | | | | | |o| |o|o| | | | | | | |o|Z|
|Z| | | |o| | | |o|o| | |o| |o| |o| | |Z|
|Z| | | | | |o|o|o| | |o|o| |o| | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | |o| |o| |o| | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 335

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | |o| | | | |o| | | | |Z|
|Z| | | | | | | | | |o| |o| |o| | | |o|Z|
|Z| | | | |o| | |o| | |o| | |o| |o| | |Z|
|Z| | | | | |o| | |o|o|o| |o|o|o|o| | |Z|
|Z| | | |o|o| | | | | |o|o| | |o|o|o| |Z|
|Z| | | | |o|o| |o| | |o|o| | | |o| | |Z|
|Z| | | | |o|o|o| |o| |o| | |o| | | | |Z|
|Z| | | | |o| | |o|o|o| | | | |o| |o| |Z|
|Z| | |o| | |o|o|o| | | |o|o| | | |o| |Z|
|Z| | | | | | | |o| |o| | |o| | | | |o|Z|
|Z| | | | | | | | | | | | |o| | | |o| |Z|
|Z| | | | |o|o| | | |o|o|o|o| | | | | |Z|
|Z| | | | | | | | | | | |o| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 336

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | |o| | | | | |o| | | | | |Z|
|Z| | | | | | | |o| | |o| |o| | | | | |Z|
|Z| | | | | | | | | |o| |o| | |o| | | |Z|
|Z| | | | |o| | | |o|o|o|o| |o|o| | | |Z|
|Z| | | | |o|o| | |o|o|o|o|o|o|o|o|o|o|Z|
|Z| | |o|o| | |o|o| |o|o|o|o|o|o|o|o|o|Z|
|Z| | |o|o|o|o| |o|o|o|o| |o|o|o|o|o| |Z|
|Z| | |o| |o|o|o| |o|o|o|o| |o|o|o| | |Z|
|Z| | | | |o|o|o|o|o|o|o|o| | |o|o|o| |Z|
|Z| | | |o|o|o|o|o|o|o|o| |o| | |o|o|o|Z|
|Z| | | |o|o|o| |o|o|o|o|o| |o|o|o|o|o|Z|
|Z| | | | |o| |o| |o|o|o|o| | | |o|o| |Z|
|Z| | | | | |o|o| | |o|o|o|o|o|o| | | |Z|
|Z| | | | | |o| |o|o| | | |o|o| | | | |Z|
|Z| | | | | | |o| | |o|o| |o|o|o| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 337

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | |o| |o| |o| |o| | | | |Z|
|Z| | | | | | | | |o| | | | | | | | | |Z|
|Z| | | | | | | |o|o| |o|o| |o| |o| | |Z|
|Z| | | |o| |o|o| |o|o|o| |o|o|o|o|o| |Z|
|Z| | | |o|o| |o|o| |o|o| |o|o|o| |o|o|Z|
|Z| | | | | |o| | |o|o|o|o|o|o|o|o| | |Z|
|Z| | | |o|o|o| |o|o|o|o|o|o| |o| | |o|Z|
|Z| |o| |o|o|o|o|o|o|o|o| |o|o|o| |o|o|Z|
|Z| |o| |o|o|o|o|o|o|o|o|o|o| | |o|o|o|Z|
|Z| | | | |o| |o|o|o|o|o|o| |o|o| | |o|Z|
|Z| | |o| |o| |o|o| |o|o| |o|o| |o| |o|Z|
|Z| | |o| | | | |o| |o|o|o|o| |o| | |o|Z|
|Z| | | | |o|o|o| |o| |o|o|o|o|o| | | |Z|
|Z| | | | |o|o| | | |o|o|o| | | | | | |Z|
|Z| | | | | | | | | |o| |o|o| | |o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 338

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | |o| | | | | |Z|
|Z| | | | | | |o| | |o|o| | | | | | | |Z|
|Z| | | | | | | | |o|o| | |o|o| | | | |Z|
|Z| | | | |o| | |o| | |o| |o| |o| | | |Z|
|Z| | | | |o| | |o|o| |o|o|o|o|o| | |o|Z|
|Z| | | | | |o|o|o|o|o|o|o|o|o| |o| | |Z|
|Z| | |o|o|o| |o|o|o|o|o| |o| |o| |o|o|Z|
|Z| | |o|o| |o|o|o|o|o|o|o| |o| |o|o|o|Z|
|Z| | | |o|o|o|o|o|o|o|o| |o| | |o|o| |Z|
|Z|o| |o| | |o|o|o|o|o|o|o|o| |o| |o| |Z|
|Z| | | |o| |o| | |o|o|o| |o|o|o|o|o| |Z|
|Z| | | |o| |o|o| |o|o|o|o|o| |o|o|o| |Z|
|Z| | | |o|o|o|o|o| | |o|o| |o| | |o| |Z|
|Z| | |o| |o| | |o|o|o| | | |o| | | |o|Z|
|Z| | | | | | |o| |o|o| |o| |o|o| |o| |Z|
|Z| | | | |o| | | | | |o|o| | | | | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 339

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | | | | | |o| | | | |Z|
|Z| | | | | | | | | |o|o| | | |o| | | |Z|
|Z| | | | | | | |o|o|o| |o| | |o|o| | |Z|
|Z| | | | |o| |o|o|o|o|o|o|o|o|o| | | |Z|
|Z| | | | | |o|o|o|o|o|o|o|o|o|o| | | |Z|
|Z| | |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| | |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| | |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| | |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o| | |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| | | |o|o|o|o|o|o|o|o|o|o|o| | |o|o|Z|
|Z| | | |o| |o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o| | |o|o| |Z|
|Z| | | |o|o|o| |o|o|o|o|o| |o|o| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 340

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | | |o| | | | | | | | |Z|
|Z| | | | | | | | |o|o|o| | |o|o|o| | |Z|
|Z| | | | | | |o| |o|o|o|o| |o|o|o| | |Z|
|Z| | | |o|o| |o|o|o|o|o|o| |o| | | | |Z|
|Z| | |o|o| |o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| | |o|o|o|o|o|o|o|o| |o| |o|o|o|o| |Z|
|Z| |o| | |o|o|o|o|o|o|o|o|o|o| |o|o| |Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z| | |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o| |o|o|o|o|o|o|o|o|o|o|o| |o|o| |o|Z|
|Z| |o|o|o|o| |o|o|o|o|o|o|o|o|o|o| | |Z|
|Z| |o|o|o|o|o|o|o|o|o| |o|o|o| |o|o| |Z|
|Z| | |o|o| |o|o|o|o|o|o|o| |o|o| | | |Z|
|Z| | |o| |o| |o|o|o| | | |o|o| | |o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 341

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | | | | | | | | | | |Z|
|Z| | | | | | | | |o|o|o|o| |o| | | | |Z|
|Z| | | | | | | | | |o|o| |o| |o| | | |Z|
|Z| | | |o|o|o| |o|o|o|o| | |o|o| |o| |Z|
|Z| | | |o|o| |o|o|o|o|o|o|o|o| |o|o| |Z|
|Z| | | |o|o|o|o|o|o|o|o|o| | |o|o| | |Z|
|Z| |o|o| |o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o| |o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z| |o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o| |o|o|o|o| |o| |o|o|Z|
|Z| | |o|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z| |o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o| |Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o|o| | | | |Z|
|Z| |o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o| |Z|
|Z|o|o| |o|o|o|o|o|o| |o|o| | |o|o| | |Z|
|Z| | |o|o| | |o|o|o|o| |o|o| |o|o|o|o|Z|
|Z| |o| |o| |o| |o| |o|o|o| | |o| | | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 342

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | | | |o|o|o|o|o| | | | |Z|
|Z| | | | | | | |o|o|o|o|o|o|o| | |o| |Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z| | | |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z| |o|o| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 343

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | | | | | | |o|o|o|o|o|o|o|o| | | |Z|
|Z| | | |o|o|o|o|o|o|o| |o|o|o| | | |o|Z|
|Z| | |o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|Z|
|Z| |o|o| |o|o|o|o|o|o| |o|o|o|o|o|o|o|Z|
|Z|o|o|o| |o|o|o|o|o|o|o|o|o|o|o| |o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| | |Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 344

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z| | |o| |o| |o|o|o|o|o|o|o|o| |o| |o|Z|
|Z| | | |o| |o| |o|o|o|o|o|o|o|o| |o| |Z|
|Z| |o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o| |o|o|o|o|o| |o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o| |o|o|o|o|o|o|o|Z|
|Z|o|o|o| |o|o|o|o|o|o| |o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o| | |Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o| |o| | |o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|


generation: 345

|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|o|Z|
|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|Z|

Goodbye World!
[       OK ] Predator.Test (34231 ms)
[----------] 1 test from Predator (34231 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (34232 ms total)
[  PASSED  ] 1 test.
                                                                                                  
build git:(master)  😊 $> 
                                                                                                  
build git:(master)  😊 $> 
                                                                                                  

build git:(master)  😊 $> 
                                                                                                  

build git:(master)  😊 $> 
                                                                                                  

build git:(master)  😊 $> 
                                                                                                  


build git:(master)  😊 $> 
build git:(master)  😊 $> 
build git:(master)  😊 $> 
build git:(master)  😊 $> 
*/
# TDD with C++17 (and beyond) and Google Test

Google test is a framework for writing C++ unit tests. In this short post are given instructions how to set up testing
environtmet on Linux from source:

```shell
sudo apt-get install cmake llvm-ar # we will use clang++ toolchain
git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake ../ -DCMAKE_CXX_COMPILER="clang++" -DCMAKE_CXX_FLAGS="-std=c++17"
# If you opt to go with C++20
# cmake ../ -DCMAKE_CXX_COMPILER="clang++" -DCMAKE_CXX_FLAGS="-std=c++2a"
make
sudo make install

# copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
sudo cp *.a /usr/lib
```

Lets say we now want to test the following simple squareRoot function:

 ```c++
// whattotest.cpp
#include <math.h>
 
double squareRoot(const double a) {
    double b = sqrt(a);
    if(b != b) { // nan check
        return -1.0;
    }else{
        return sqrt(a);
    }
}
```

In the following code, we create two tests that test the function using a simple assertion. There exists many other assertion macros in the framework (see http://code.google.com/p/googletest/wiki/Primer#Assertions). The code contains a small main function that will run all of the tests automatically. Nice and simple!

```c++
// tests.cpp
#include "whattotest.cpp"
#include <gtest/gtest.h>
 
TEST(SquareRootTest, PositiveNos) { 
    ASSERT_EQ(6, squareRoot(36.0));
    ASSERT_EQ(18.0, squareRoot(324.0));
    ASSERT_EQ(25.4, squareRoot(645.16));
    ASSERT_EQ(0, squareRoot(0.0));
}
 
TEST(SquareRootTest, NegativeNos) {
    ASSERT_EQ(-1.0, squareRoot(-15.0));
    ASSERT_EQ(-1.0, squareRoot(-0.2));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

The next step is to compile the code. I’ve set up a small CMakeLists.txt file below to compile the tests. This file locates the google test library and links it with the test application. Note that we also have to link to the pthread library or the application won’t compile.

```cmake
cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
```

Compile and run the tests:

```shell
cmake CMakeLists.txt
make
./runTests
```

## Alternative Way of Running Tests w/o cmake

Assuming your test are placed in **test.cpp** build and run tests with:

```shell
clang++ -O3 -std=c++17 test.cpp -lgtest -lgtest_main  -o test -pthread ; ./test

```
You can hand-craft your *Makefile* from scratch too. Take a look at [Makefile in this project](./Makefile#L179). 
At the end of it you can find hand-crafted targest for the testing of an individual modulese.

## Mocking and Test Doubles

### What Are Test Doubles?

 - Almost all code depends (i.e. collaborates) with other parts of the
system.
 - Those other parts of the system are not always easy to replicate in
the unit test environment or would make tests slow if used directly.
 - Test doubles are objects that are used in unit tests as replacements
to the real production system collaborators.

### Types of Test Doubles

 - **Dummy** - Objects that can be passed around as necessary but do
not have any type of test implementation and should never be used, like:
   ```c++
   class MyDummy : public MyInterface {
   public:
     void SomeFunction(){throw exception("I shouldn’t be called!");}
   };
   ```
   Dummy objects expect to never be used and will generally 
   throw an exception if one of their methods is actually called.

 - **Fake** - These object generally have a simplified functional
implementation of a particular interface that is adequate for testing
but not for production, for example:
   ```c++
   class MyTestDB : public DBInterface {
   public:
     void pushData(int data){ dataItems.push_back(data);}
   protected:
     vector<int> dataItems;
   };
   ```
   Fake objects provide what is usually a simplified implementation of an interface that is functional but not appropriate for production (i.e. an in memory database).
 - **Stub** - These objects provide implementations with canned answers
that are suitable for the test, for example:
   ```c++
   class MyStub : public MyInterface {
   public:
     int SomeFunction(){ return 0;}
   };
   ```
   Stubs are different than dummy test doubles in that they do expect to be called and return canned data.
 - **Spies** - These objects provide implementations that record the values that were passed in so they can be used by the test, for example:
   ```c++
   class MySpy : public MyInterface {
   public:
     int savedParam;
     void SomeFunction(int param1 ){savedParam = param1;}
   };
   ```
   Spy objects save the parameters that were passed into them so they can be analyzed by the test.
 - **Mocks** - These objects are pre-programmed to expect specific calls and parameters
 and can throw exceptions when necessary, for example:
   ```c++
   class MyMock : public MyInterface {
   public:
     void SomeFunction( int param1 ){
       if( 1 != param1 )
         throw exception("I shouldn’t be called!");}
   };
   ```
   Mock objects are the most intelligent test double. They are setup with expectations on how they will be called and will throw exceptions when those expectations are not met.

### Mock Frameworks

 - Most mock frameworks provide easy ways for automatically creating any of these types of test doubles at runtime.
 - They provide a fast means for creating mocking expectations for your tests.
 - They can be much more efficient than implementing custom mock object of your own creation.
 - Creating mock objects by hand can be tedious and error prone.

### Google Mock

 - C++ Mocking Framework from Google
 - Included with and works well with Google Test.
 - Can be used with any C++ Unit Testing Framework.

## References:

 - http://code.google.com/p/googletest/wiki/Documentation
 - http://www.ibm.com/developerworks/aix/library/au-googletestingframework.html

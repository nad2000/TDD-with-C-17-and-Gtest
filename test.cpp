#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;

class User {
	string id;
public:
	User(string _id): id(_id) {}
	string GetId() {return id;}
};

class Incrementor {
	int value;
public:
	Incrementor(int _value) : value(_value) {}
	void IncrementBy(int byValue) {value += byValue;}
	int getValue() {return value;}
};

class Stack {
	std::vector<int> vstack	= {};
public:
	void push(int value) {vstack.push_back(value);}
	int pop() {
		if (vstack.size()  > 0) {
			int value = vstack.back();
			vstack.pop_back();
			return value;
		} else {
			return -1;
		}
	}
	int size() {return vstack.size();}
};

// Fixtures:
struct IncrementorTest : public testing::Test {
	Incrementor *i;
	void SetUp() {
		i = new Incrementor(100);}
	void TearDown() {delete i;}
};

struct StackTest : public testing::Test {
	Stack s;
	void SetUp() {
		for (const auto &v: {1,2,3,4,5,6,7,8,9}) s.push(v);
	}
	void TrearDown() {}
};

TEST_F(StackTest, popTest) {
	auto expected = 9;
	while(expected != 1) ASSERT_EQ(s.pop(), expected--);
}

TEST_F(StackTest, validSize) {
	for(auto sv = s.size(); sv > 0; sv--) ASSERT_NE(s.pop(), -1);
	ASSERT_EQ(s.pop(), -1);
	ASSERT_EQ(s.pop(), -1);
}
// Test w/o fixture:
TEST(IncrementorTestWOFixture, Increment_by_10) {
	
	// Arrangement
	Incrementor i(100);

	// Act
	i.IncrementBy(10);
	auto value = i.getValue();

	// Assert
	ASSERT_EQ(value, 110);
	
}

TEST_F(IncrementorTest, Increment_by_10) {

	i->IncrementBy(10);

	// Assert
	ASSERT_EQ(i->getValue(), 110);
}

TEST(TestUser, UserId) {
	
	// Arrangement
	User root("root");

	// Act
	auto value = root.GetId();

	// Assert
	SCOPED_TRACE("root.GetId() == \"root\"");
	ASSERT_STREQ(value.c_str(), "root");
}
	

TEST(TestName, Subtest_1) {

	ASSERT_TRUE(1 == 1);
	// ASSERT_TRUE(1 == 1);  // FATAL if it fails (Fatal failures)
	// ASSERT_EQ(1, 42);
	// Non-fatal assertion/failure:
	/* EXPECT_EQ(1, 42); */
	/* EXPECT_TRUE(1 == 42); */
	cout << "*** After an assertion..." << endl;

}

TEST(TestName, Subtest_2) {
	ASSERT_FALSE(1 == 42);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

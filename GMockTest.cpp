// RUN:
// clang++ -O3 -std=c++17 GMockTest.cpp $HOME/googletest/build/lib/*.a  -o test -pthread && ./test
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class QueueInterface {
public:
	virtual ~QueueInterface() {}
	virtual void enqueue(int data) = 0;
	virtual int dequeue() = 0;
};

class MockQueue: public QueueInterface {
public:
	MOCK_METHOD0(dequeue, int());
	MOCK_METHOD1(enqueue, void(int));
};

class DataHolder {
protected:
	QueueInterface *queue;
	
public:
	DataHolder(QueueInterface *queue): queue(queue) {}
};

class GMockTests: public ::testing::Test {
public:
	DataHolder dh;
	GMockTests(): ::testing::Test(), dh(&myMockObj) {}
protected:
	MockQueue myMockObj;
};

TEST_F(GMockTests, CanInstatiateDataHolder) {
	// ASSERT_TRUE(dh.queue == &myMockObj);
}

	
int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

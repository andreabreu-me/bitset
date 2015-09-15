#include "bitset.h" 
#include "iterator.h" 
#include "gtest/gtest.h"
#include <algorithm>

using namespace libbitset;

TEST(iterator_test, begin) {
	Bitset<9> bs0(0b111111110);
	Bitset<9> bs1(0b000000001);

	EXPECT_EQ(0, bs0.begin());
	EXPECT_EQ(1, bs1.begin());
}

TEST(iterator_test, increment) {
	Bitset<30> bs(0b101);
	Bitset<30>::iterator it = bs.begin();

	EXPECT_EQ(1, it);
	++it;
	EXPECT_EQ(0, it);
	++it;
	EXPECT_EQ(1, it);
}

struct It{
	public:
		typedef int difference_type;
};

struct IteratorTestCounter {
	IteratorTestCounter() : count(0){}
	void operator()(bool) {
		++count;
	}
	unsigned int count;
};

TEST(iterator_test, for_each) {
	Bitset<39, short> bs(0b1000001);
	IteratorTestCounter counter;
	EXPECT_EQ(39, std::for_each(bs.begin(), bs.end(), counter).count);
}


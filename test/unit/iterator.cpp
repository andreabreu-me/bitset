#include "bitset.h" 
#include "iterator.h" 
#include "gtest/gtest.h"

using namespace libbitset;

TEST(iterator_test, begin) {
	Bitset<9> bs0(0b011111110);
	Bitset<9> bs1(0b100000001);

	EXPECT_EQ(0, *bs0.begin());
}

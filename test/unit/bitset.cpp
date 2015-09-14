#include "bitset.h" 
#include "gtest/gtest.h"

using namespace libbitset;

TEST(bitset_test, size) {
	Bitset<5> bs5;
	Bitset<23> bs3;

	EXPECT_EQ(5, bs5.size());
	EXPECT_EQ(23, bs3.size());
}

TEST(bitset_test, constructor) {
	Bitset<9> bs9(0);	// 000000000
	Bitset<5> bs5(7); // 00111

	EXPECT_EQ(0, bs9.value());
	EXPECT_EQ(7, bs5.value());
}

TEST(bitset_test, test) {
	Bitset<5> bs5(0b101);	// 00101

	EXPECT_EQ(1, bs5.test(0));
	EXPECT_EQ(1, bs5.test(2));

	EXPECT_EQ(5, bs5.value());
}

TEST(bitset_test, base_type) {
	Bitset<20> bsChar;
	Bitset<20,int> bsInt;
	Bitset<20,libbitset::uint64_t> bsLong;

	EXPECT_EQ(sizeof(unsigned char) << 3, bsChar.base_type_size);
	EXPECT_EQ(sizeof(int) << 3, bsInt.base_type_size);
	EXPECT_EQ(sizeof(libbitset::uint64_t) << 3, bsLong.base_type_size);
}


TEST(bitset_test, clearbit) {
	Bitset<20> bs(7);

	bs.clear(0);
	EXPECT_EQ(6, bs.value());

	bs.clear(1);
	EXPECT_EQ(4, bs.value());

	bs.clear(2);
	EXPECT_EQ(0, bs.value());
}

TEST(bitset_test, setbit) {
	Bitset<20> bs(0);

	EXPECT_EQ(0, bs.value());

	bs.set(0);
	EXPECT_EQ(1, bs.value());

	bs.set(1);
	EXPECT_EQ(3, bs.value());

	bs.set(2);
	EXPECT_EQ(7, bs.value());
}

TEST(bitset_test, int64) {
	unsigned long ul = ((unsigned long)1<<33) | (1 << 10);
	Bitset<128, unsigned int> bs128(ul);
	Bitset<256, unsigned long long> bs256(ul);
	
	EXPECT_EQ(ul, bs128.value());
	EXPECT_EQ(ul, bs256.value());
}


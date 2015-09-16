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

TEST(bitset_test, test2) {
	unsigned long long ui = 1 << 1 | 1 << 11 | 1 << 20;
	Bitset<64, unsigned char> bs64c(ui);
	Bitset<64, unsigned short> bs64s(ui);
	Bitset<64, unsigned int> bs64i(ui);

	EXPECT_EQ(0, bs64c.test(0));
	EXPECT_EQ(1, bs64c.test(1));
	EXPECT_EQ(1, bs64c.test(11));
	EXPECT_EQ(1, bs64c.test(20));

	EXPECT_EQ(0, bs64s.test(0));
	EXPECT_EQ(1, bs64s.test(1));
	EXPECT_EQ(1, bs64s.test(11));
	EXPECT_EQ(1, bs64s.test(20));

	EXPECT_EQ(0, bs64i.test(0));
	EXPECT_EQ(1, bs64i.test(1));
	EXPECT_EQ(1, bs64i.test(11));
	EXPECT_EQ(1, bs64i.test(20));
}

TEST(bitset_test, value_type) {
	Bitset<20> bsChar;
	Bitset<20,int> bsInt;
	Bitset<20,libbitset::uint64_t> bsLong;

	EXPECT_EQ(sizeof(unsigned char) << 3, bsChar.value_type_size);
	EXPECT_EQ(sizeof(int) << 3, bsInt.value_type_size);
	EXPECT_EQ(sizeof(libbitset::uint64_t) << 3, bsLong.value_type_size);
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
	Bitset<30> bs(0);

	EXPECT_EQ(0, bs.value());

	bs.set(0);
	EXPECT_EQ(1, bs.value());

	bs.set(1);
	EXPECT_EQ(3, bs.value());

	bs.set(2);
	EXPECT_EQ(7, bs.value());

	bs.set(10);
	bs.set(25);
	unsigned long long ui = 0b10000000000000010000000111;
	EXPECT_EQ(ui, bs.value());
}

TEST(bitset_test, int64) {
	unsigned long ul = ((unsigned long)1<<33) | (1 << 10);
	Bitset<128, unsigned int> bs128(ul);
	Bitset<256, unsigned long long> bs256(ul);
	
	EXPECT_EQ(ul, bs128.value());
	EXPECT_EQ(ul, bs256.value());
}

TEST(bitset_test, value) {
	unsigned long long ui = 1 << 1 | 1 << 11 | 1 << 20 | (unsigned long long)1 << 60;
	Bitset<64, unsigned char> bs24c(ui);
	Bitset<64, unsigned short> bs24s(ui);
	Bitset<64, unsigned int> bs24i(ui);

	EXPECT_EQ(ui, bs24c.value());
	EXPECT_EQ(ui, bs24s.value());
	EXPECT_EQ(ui, bs24i.value());
}

TEST(bitset_test, random_access) {
	unsigned long long ui = 1 << 1 | 1 << 11 | 1 << 20 | ((unsigned long long)1) << 60;
	Bitset<64, unsigned short> bs(ui);

	EXPECT_EQ(0, bs[0]);
	EXPECT_EQ(1, bs[1]);
	EXPECT_EQ(1, bs[11]);
	EXPECT_EQ(1, bs[20]);
	EXPECT_EQ(1, bs[60]);
	
	bs[0] = 1;
	EXPECT_EQ(1, bs[0]);
	bs[60] = 0;
	EXPECT_EQ(0, bs[60]);

	unsigned long ul = 1 | 1 << 1 | 1 << 11 | 1 << 20; 
	EXPECT_EQ(ul, bs.value());
}

TEST(bitset_test, streamreader) {
	unsigned char data[4] = {1,2,4,8};
	unsigned long ui = 1 | 2 << 8 | 4 << 16 | 8 << 24;
	Bitset<32> bsIt(&data[0], &data[sizeof(data)/sizeof(data[0])]);
	Bitset<32> bs;
	StreamRedader reader;

	for (unsigned char i = 0; i < sizeof(data)/sizeof(data[0]); ++i)
		reader(bs, data[i]);

	ASSERT_EQ(ui, bs.value());
	ASSERT_EQ(ui, bsIt.value());
}

class AssertTest : public ::testing::Test {
	protected:
		static void SetUpTestCase() {
			::testing::FLAGS_gtest_death_test_style = "threadsafe";
		}
	public:
		Bitset<3> bs;
};

TEST_F(AssertTest, assert_set) {
	ASSERT_DEATH(bs.set(4), "");
}

TEST_F(AssertTest, assert_test) {
	ASSERT_DEATH(bs.test(4), "");
}

TEST_F(AssertTest, assert_clear) {
	ASSERT_DEATH(bs.clear(4), "");
}

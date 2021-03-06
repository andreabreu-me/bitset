#include "streamreader.h"
#include "gtest/gtest.h"

struct StreamReaderTestStorage {
	typedef unsigned char size_t;
	typedef unsigned char value_type;
	
	size_t on_read_data(const value_type& value, size_t idx){
		data[idx] = value;
		return ++idx;
	}
	value_type data[4];
};

class StreamReaderTest : public ::testing::Test {
public:
	StreamRedader reader;
	StreamReaderTestStorage::value_type test_data[4] = {3,4,5,6}; 
	unsigned char size = sizeof(test_data)/sizeof(test_data[0]);
	StreamReaderTestStorage::value_type *begin = &test_data[0], *end = &test_data[size];
	
};

TEST_F(StreamReaderTest, test1) {
	StreamReaderTestStorage storage;
	while (begin != end) {
		reader(storage, *begin);
		++begin;
	}

	for (unsigned char idx = 0; idx < size; ++idx) {
    ASSERT_EQ(test_data[idx], storage.data[idx])  << "Vectors differ at index " << idx;
	}
}

TEST_F(StreamReaderTest, test2) {
	StreamReaderTestStorage storage;
	reader(begin, end, storage);

	for (unsigned char idx = 0; idx < size; ++idx) {
    ASSERT_EQ(test_data[idx], storage.data[idx])  << "Vectors differ at index " << idx;
	}
}

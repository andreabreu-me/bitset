#ifndef __BITSET_H__

#include <cstring> //memset

namespace libbitset {

typedef unsigned long long size_t;
typedef unsigned long long uint64_t;

template <size_t size_, typename BaseType=unsigned char>
class Bitset{
	public:
		typedef BaseType base_type;
		const size_t base_type_size = sizeof(base_type) << 3;
		const uint64_t base_type_mask = sizeof(base_type)==sizeof(uint64_t) ? (uint64_t)-1 : ((uint64_t)1 << base_type_size) - 1;
		const size_t array_length = size_ / base_type_size + (size_ & base_type_mask ? 1 : 0);

		Bitset(){}
		Bitset(uint64_t rhs) {
			memset(value_, 0, sizeof(value_));
			// TODO: use memcpy instead loop?
			// see also big-endian/little-endian compabilities
			size_t idx = 0;
			while(rhs) {
				// TODO assert(idx out of range)
				// or copy min(sizeof(value_),sizeof(uint_64)) bytes
				value_[idx++]  = rhs & base_type_mask;
				rhs &= ~base_type_mask;	// uint64 >> 64 - undefined behavior http://en.cppreference.com/w/cpp/language/operator_arithmetic#Bitwise_shift_operators
				rhs >>= base_type_size;
			}
		}
		~Bitset(){}

		size_t size() const {return size_;}

		uint64_t value() const {
			// TODO: assert(array_size <= sizeof(uint64_t)
			if (sizeof(base_type) == sizeof(uint64_t))	//TODO: don't use base type uint64_t
				return value_[0];
			uint64_t res = 0;
			size_t idx = array_length;//sizeof(uint64_t)/sizeof(base_type);
			while(idx)
				res = (res << base_type_size) | value_[--idx];
			return res;
		}

		void set(size_t idx) {
			// value[idx/sizeof(BaseType)/8][idx%(sizeof(BaseType)*8)] = 1
			value_[idx >> base_type_size] |= 1 << (idx & base_type_mask );
		}

		void clear(size_t idx) {
			value_[idx >> base_type_size] &= ~(1 << (idx & base_type_mask));
		}

		bool test(size_t idx) const {
			// TODO assert( base_type_size*len(value_) > idx);
			return value_[idx >> base_type_size] & (1 << (idx & base_type_mask));
		}
	private:
		base_type value_[((size_ >> 3) / sizeof(base_type)) + 
			((size_ & ((sizeof(base_type) << 3) - 1)) ? 1 : 0)];
};

};//namespace
#endif//__BITSET_H__

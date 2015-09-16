#ifndef __LIBBITSET_BITSET_H__
#define __LIBBITSET_BITSET_H__

#include <cstring> //memset
#include <cassert>
#include "traits.h"
#include "iterator.h"
#include "streamreader.h"

namespace libbitset {


typedef unsigned long long size_t;
typedef unsigned long long uint64_t;

template <size_t size_, typename BaseType = unsigned char>
class Bitset{
	public:
		typedef libbitset::size_t size_t;
		typedef BaseType value_type;
		typedef Iterator<Bitset> iterator;

		// cached values
		const unsigned char value_type_size = sizeof(value_type) << 3;
		const uint64_t value_type_mask = sizeof(value_type)==sizeof(uint64_t) ? (uint64_t)-1 : ((uint64_t)1 << value_type_size) - 1;
		const size_t array_length = size_ / value_type_size + ((size_ & (value_type_size - 1)) ? 1 : 0);
		

		Bitset(){
			clear_();
		}
	
		Bitset(value_type* begin, value_type* end) {
			size_t idx = 0;
			clear_();
			while(begin != end) {
				idx = do_read_<value_type>(*begin, idx);
				++begin;
			}
		}

		template <typename T>
		Bitset(T r) {
			clear_();	
			do_read_<T>(r);
		}

		~Bitset(){}

		size_t size() const {return size_;}

		// iterator access
		iterator operator [] (size_t idx) {
			return iterator(&value_[idx >> ( sizeof(value_type) + 2)], 
				idx & (value_type_size - 1));
		}
		iterator begin() {return (*this)[0];}
		iterator end() {return (*this)[size_];}
		// --iterator access

		// direct access
		void set(size_t idx) {
			assert(idx < size_);
			value_[idx >> (sizeof(value_type) + 2)] |= 1 << (idx & (value_type_size - 1) );
		}

		void clear(size_t idx) {
			assert(idx < size_);
			value_[idx >> value_type_size] &= ~(1 << (idx & value_type_mask));
		}

		bool test(size_t idx) const {
			assert(idx < size_);
			return value_[idx >> (sizeof(value_type) + 2)] & (1 << (idx & (value_type_size - 1)));
		}
		// --direct access

		// read stream of sizeof(value_type) bytes
		size_t on_read_data(value_type val, size_t idx) {
			// TODO assert( idx < array_length
			value_[idx] = val;
			return ++idx;
		}

		// return the first sizeof(uint_64) bytes
		uint64_t value() const {
			// TODO: assert(array_size <= sizeof(uint64_t)
			if (sizeof(value_type) == sizeof(uint64_t))	//TODO: don't use base type uint64_t
				return value_[0];
			uint64_t res = 0;
			size_t idx = array_length;//sizeof(uint64_t)/sizeof(base_type);
			while(idx)
				res = (res << value_type_size) | value_[--idx];
			return res;
		}
	private:
		void clear_() {
			memset(value_, 0, sizeof(value_));
		}

		template <typename T, typename traits=traits::numeric<T> > 
		size_t do_read_(typename traits::type_name rhs, size_t idx = 0) {
			// TODO: use memcpy instead loop?
			// see also big-endian/little-endian compabilities
			while(rhs) {
				assert(idx < array_length);
				// or copy min(sizeof(value_),sizeof(uint_64)) bytes
				value_[idx++]  = rhs & value_type_mask;
				rhs &= ~value_type_mask;	// uint64 >> 64 - undefined behavior http://en.cppreference.com/w/cpp/language/operator_arithmetic#Bitwise_shift_operators
				rhs >>= value_type_size;
			}
			return idx;
		}

	private:
		value_type value_[(size_ >> (sizeof(value_type) + 2)) + 
			((size_ & ((sizeof(value_type) << 3) - 1)) ? 1 : 0)];
};// Bitset

};// namespace
#endif// __LIBBITSET_BITSET_H__

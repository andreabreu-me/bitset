#ifndef __LIBBITSET_ITERATOR_H__
#define __LIBBITSET_ITERATOR_H__

namespace libbitset {

template <typename T>
class Iterator {
	public:
		Iterator(const typename T::base_type* data, typename T::size_t idx) : data_(data), idx_(idx) {}

		operator bool () const { return this->operator*();}
		bool operator * () const { return data_[0] & (1 << idx_);}
		Iterator<T> operator ++(int) {
			Iterator<T> result(*this);
			++(*this);
			return result;
		} 
		Iterator<T>& operator ++() { 
			++idx_;
			if ( (sizeof(typename T::base_type)<<3) <= idx_) {
				idx_ = 0;
				++data_;
			} 
			return *this;
		}
		
		bool operator == (const Iterator<T>& rhs) {
			return rhs.data_ == data_ && rhs.idx_ == idx_;
		}
		bool operator != (const Iterator<T>& rhs) {
			return !(*this == rhs);
		}
	private:
		const typename T::base_type* data_;
		typename T::size_t idx_;
};

};
#endif//__LIBBITSET_ITERATOR_H__

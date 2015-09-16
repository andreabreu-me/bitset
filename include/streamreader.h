#ifndef __LIBBITSET_STREAM_READER_H__
#define __LIBBITSET_STREAM_READER_H__

class StreamRedader{
	public:
		StreamRedader() : idx_(0) {}

		template <typename Storage, typename It>
		void operator() (It begin, It end, Storage& storage) {
			while(begin != end) {
				(*this)(storage, *begin);
				++begin;
			}
		}

		template <typename Storage, typename T>
		void operator() (Storage& storage, const T& value) {
				idx_ = storage.on_read_data(value, idx_);
		}
	private:
		unsigned long long idx_;
};

#endif// __LIBBITSET_STREAM_READER_H__

#ifndef __KVECTOR__H
#define __KVECTOR__H

#include <cstddef>

template<typename type>
class KVector
{
	public:
		KVector()
			: t_(0)
			, size_(0)
		{
		}

		explicit KVector(size_t count)
		{
			t_ = new type[count];
			size_ = count;
		}

		~KVector()
		{
			if (t_ != NULL)
				delete [] t_;
		}
	private:
		type* t_;
		size_t size_;
	public:
		size_t size()
		{ return size_; }

		type& operator[](size_t index)
		{
			return t_[index];
		}
		const type operator[](size_t index)const
		{
			return t_[index];
		}
};

#endif//__KVECTOR__H

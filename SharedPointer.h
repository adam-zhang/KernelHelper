#ifndef __SHAREDPOINTER__H
#define __SHAREDPOINTER__H

#include <cstddef>

template<typename T>
class SharedPointer
{
	private:
		T* t_;
		size_t* count_;
	public:
		SharedPointer()
			: t_(0)
			  ,count_(0)
		{}

		SharedPointer(T* t)
			: t_(t)
			  , count_(new size_t(1))
		{}

		SharedPointer(const SharedPointer& other)
			: t_(other.t_)
			  , count_(0)
		{
			++*other.count_;
			count_ = other.count_;
		}

		~SharedPointer()
		{
			release();
		}

	public:
		void reset()
		{
			release();
		}

		size_t reference()
		{
			return *count_;
		}
	public:
		T* get()
		{
			return t_;
		}

		T* operator->()
		{
			return t_;
		}

		T& operator*()
		{
			return *t_;
		}
	private:
		void release()
		{
			if (!t_)
				return;
			--(*count_);
			if (*count_ != 0)
				return;
			delete count_;
			delete t_;
		}

};
#endif//__SHAREDPOINTER__H

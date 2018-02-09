#ifndef __KSTIRNG__H
#define __KSTIRNG__H

#include <cstddef>


class KString
{
	public:
		KString();
		KString(const char*);
		KString(const wchar_t*);
		KString(const KString&);
		KString& operator=(const KString&);
		~KString();
	private:
		wchar_t* s_;
		size_t size_;
	public:
		size_t size()const;
		const wchar_t* c_str()const
		{ return s_; }	
		wchar_t operator[](size_t) const;
		bool operator!=(const KString& right);
		friend KString operator+(const KString&, const KString&);
};


//KString operator+=(const KString& left, const KString&);
bool operator==(const KString& left, const KString& right);




#endif//__KSTIRNG__H

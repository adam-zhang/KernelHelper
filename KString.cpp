#include "KString.h"
#include <string.h>


KString::KString()
	: s_(0)
	, size_(0)
{

}



static wchar_t* copy_string(const char* s)
{
	size_t length = strlen(s);
	wchar_t* ws = new wchar_t[length + 1];
	ws[length] = 0;
	for(size_t i = 0; i < length; ++i)
		ws[i] = s[i];
	return ws;
}

static wchar_t* copy_string(const wchar_t* s)
{
	size_t length = wcslen(s);
	wchar_t* ws = new wchar_t[length + 1];
	ws[length] = 0;
	for(size_t i = 0; i < length; ++i)
		ws[i] = s[i];
	return ws;
}

//static const wchar_t* copy_string(const KString& s)
//{
//	return copy_string(s.c_str());
//}


//KString::KString(const KString& value)
//	: s_(copy_string(value)
//	, size_(value.size())
//{
//	
//}



KString::KString(const char* s)
	: s_(copy_string(s))
	  , size_(strlen(s))
{
	
}

KString::KString(const wchar_t* s)
	: s_(copy_string(s))
	  , size_(wcslen(s))
{}

KString::KString(const KString& s)
	: s_(copy_string(s.s_))
	  , size_(s.size())
{
}



size_t KString::size()const
{
	return size_;
}


wchar_t KString::operator[](size_t index)const
{
	return s_[index];
}

KString& KString::operator=(const KString& value)
{
	if (&value == this)
		return *this;
	delete [] s_;
	s_ = copy_string(value.c_str());
	size_ = value.size();
	return *this;
}

KString operator+(const KString& left, const KString& right)
{
	KString temp;// = 
	size_t length = left.size() + right.size();
	temp.s_ = new wchar_t[length + 1];
	temp.size_ = length;
	wcscpy(temp.s_, left.c_str());
	wcscat(temp.s_, right.c_str());
	return temp;
}

//KString operator+=(const KString& left, const KString& right)
//{
//	left = left + right;
//	return left;
//}


KString::~KString()
{
	if (s_ != NULL)
		delete [] s_;
}

bool operator!=(const KString& left, const KString& right)
{
	return left != right;
}

bool operator==(const KString& left, const KString& right)
{
	if (left.c_str() == right.c_str())
		return true;
	if (left.size() != right.size())
		return false;
	for(size_t i = 0; i < left.size(); ++i)
		if (left[i] != right[i])
			return false;
	return true;
}


//KString& KString::operator+(const KString& left, const KString& right)
//{
//	right;
//	return left;
//}

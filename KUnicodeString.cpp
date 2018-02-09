#include "KUnicodeString.h"

void assignZero(UNICODE_STRING* uStr)
{
	uStr->Buffer = 0;
	uStr->Length = 0;
	uStr->MaximumLength = 0;
}

KUnicodeString::KUnicodeString()
	: str_(NULL)
	  , size_(0)
{
	assignZero(&uStr_);
}

KUnicodeString::~KUnicodeString()
{
	if (str_)
		delete [] str_;
	if (uStr_.Buffer)
		delete [] uStr_.Buffer;
}

KUnicodeString::KUnicodeString(const char* s)
{
	size_t length = strlen(s);
	str_ = new wchar_t[length + 1];
	for(size_t i = 0; i < length + 1; ++i)
		str_[i] = s[i];
	size_ = length;
	assignZero(&uStr_);
}

KUnicodeString::KUnicodeString(const wchar_t* s)
{
	size_t length = wcslen(s);
	str_ = new wchar_t[length + 1];
	for(size_t i = 0; i < length + 1; ++i)
		str_[i] = s[i];
	size_ = length;
	assignZero(&uStr_);
}

static void copy_unicode(PWSTR* uString, const KUnicodeString& kString)
{
	wchar_t* temp = new wchar_t[kString.size() + 1];
	for(size_t i = 0; i < kString.size() + 1; ++i)
		temp[i] = kString[i];
	*uString = temp;
}

KUnicodeString::KUnicodeString(const KUnicodeString& s)
{
	copy_unicode(&str_, s);
	size_ = s.size();
	uStr_ = s.uStr_;
}

KUnicodeString& KUnicodeString::operator=(const KUnicodeString& s)
{
	copy_unicode(&str_, s);
	size_ = s.size();
	assignZero(&uStr_);
	return *this;
}

KUnicodeString operator+(const KUnicodeString& left, const KUnicodeString& right)
{
	KUnicodeString temp;
	size_t length = left.size() + right.size();
	temp.str_ = new wchar_t[length + 1];
	//temp.str_[length] = 0;
	wcscpy(temp.str_, left.c_str());
	wcscat(temp.str_, right.c_str());
	temp.size_ = left.size() + right.size();
	assignZero(&temp.uStr_);
	return temp;
}

bool operator==(const KUnicodeString& left, const KUnicodeString& right)
{
	if (&left == &right)
		return true;
	if (left.size() != right.size())
		return false;
	for(size_t i = 0; i < left.size() + 1; ++i)
		if (left[i] != right[i])
			return false;
	return true;
}

bool operator!=(const KUnicodeString& left, const KUnicodeString& right)
{
	return !(left == right);
}

//KUnicodeString& KUnicodeString::operator+=(const KUnicodeString& right)
//{
//	*this = *this + right;
//	return *this;
//}

static void copy_unicodestring(UNICODE_STRING* uStr, PWSTR str)
{
	if (uStr->Buffer)
		delete [] uStr->Buffer;
	size_t length = wcslen(str);
	uStr->Buffer = new wchar_t[length + 1];
	uStr->Length = uStr->MaximumLength = length;
}

const UNICODE_STRING KUnicodeString::toUnicodeString()
{
	copy_unicodestring(&uStr_, str_);
	return uStr_;
}

const UNICODE_STRING* KUnicodeString::getUnicodeString()
{
	copy_unicodestring(&uStr_, str_);
	return &uStr_;
}





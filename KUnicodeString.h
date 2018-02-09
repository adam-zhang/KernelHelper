#ifndef __KUNICODESTRING__H
#define __KUNICODESTRING__H

#include <windows.h>

struct UNICODE_STRING
{
	USHORT Length;
	USHORT MaximumLength;
	PWSTR  Buffer;
};


class KUnicodeString
{
	public:
		KUnicodeString();
		KUnicodeString(const char*);
		KUnicodeString(const wchar_t*);
		KUnicodeString(const KUnicodeString&);
		KUnicodeString& operator=(const KUnicodeString&);
		~KUnicodeString();
	public:
		friend KUnicodeString operator+(const KUnicodeString&, const KUnicodeString&);
		//KUnicodeString& operator+=( const KUnicodeString&);
		friend bool operator==(const KUnicodeString&, const KUnicodeString&);
		friend bool operator!=(const KUnicodeString&, const KUnicodeString&);
	public:
		const UNICODE_STRING toUnicodeString();
		const UNICODE_STRING* getUnicodeString();
	public:
		size_t size()const
		{
			return size_;
		}

		const PWSTR c_str()const
		{ return str_; }
	public:
		wchar_t operator[](size_t index)
		{ return str_[index]; }
		const wchar_t operator[](size_t index)const
		{ return str_[index];}
	private:
		PWSTR str_;
		size_t size_;
	private:
		UNICODE_STRING uStr_;

};

#endif//__KUNICODESTRING__H

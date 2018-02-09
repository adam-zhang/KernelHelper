#include "KString.h"
#include "KVector.h"
#include "SharedPointer.h"
#include "KUnicodeString.h"

#include <iostream>
void testKString()
{
	KString ks("wstring");
	KString kws("WSTRING");
	std::wcout << ks.c_str() << std::endl;
	std::wcout << kws.c_str() << std::endl;
	KString s = ks + kws;
	std::wcout << s.c_str() << std::endl;
}

class Person
{
	public:
		Person()
		{ std::cout << "Constructor" << std::endl;}
		~Person()
		{ std::cout << "Decontructor" << std::endl;}
};

void testVector()
{
	KVector<int> vec(5);
	for(size_t i = 0; i < vec.size(); ++i)
	{
		vec[i] = i + 1;
	}

	for(size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i];
	}
	std::cout << std::endl;
}

void testPointer()
{
	SharedPointer<Person> p1(new Person);
	SharedPointer<Person> p2 = p1;
	SharedPointer<Person> p3 = p2;
	std::cout << "reference:" << p1.reference() << std::endl;
}

void testUnicode()
{
	KUnicodeString ss("abcdefg");
	KUnicodeString ws("ABCDEFG");
	std::wcout << ss.c_str() << std::endl;
	std::wcout << ws.c_str() << std::endl;
	KUnicodeString ws2 = ws;
	std::wcout << ws2.c_str() << std::endl;
	std::wcout << ws2.size() << std::endl;
	KUnicodeString s = ss + ws;
	std::wcout << s.c_str() << std::endl;
	KUnicodeString cs("abcdefg");
	std::wcout << L"compare:" << (cs == ss) << std::endl;
	std::wcout << L"compare:" << (cs != ss )<< std::endl;
	
}

int main(int, char**)
{
	testKString();
	testVector();
	testPointer();
	testUnicode();
	return 0;
}

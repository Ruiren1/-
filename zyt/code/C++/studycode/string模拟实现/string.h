#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<assert.h>
#include<string>
namespace zyt
{
	class string
	{
	 public:
		 typedef char* iterator;
		 typedef const char* const_iterator;
		 string(const char *s="") :_size(strlen(s))
		 {
			 _capacity = _size;
			 char* tmp = new char[_capacity + 1];
			 _str = tmp;
			 strcpy(_str, s);
		 }

		 string(const string& s):_size(s._size)
		 {
			 char* tmp = new char[s._capacity + 1];
			 _str = tmp;
			 strcpy(_str, s._str);
			 _capacity = s._capacity;
		 }

		 ~string()
		 {
			 delete []_str;
			 _str = nullptr;
			 _size = _capacity=0;
		 }

		 void reserve(size_t size = 0)
		 {
			 if (size > _capacity)
			 {
				 char* tmp = new char[size + 1];
				 strcpy(tmp, _str);
				 delete[]_str;
				 _str = tmp;
				 _capacity = size;
			 }
		 }

		 string& operator=(const string&s) 
		 {
			 if (&s != this)
			 {
				 char* tmp = new char[s._capacity + 1];
				 strcpy(tmp, s.c_str());
				 delete[]_str;
				 _str = tmp;
				 _size = s._size;
				 _capacity = s._capacity;
			 }
			 return *this;
		 }

		 char* c_str()
		 {
			 return _str;
		 }

		 const char* c_str() const
		 {
			 return _str;
		 }
		 bool operator >(const string& s)const
		 {
			 return strcmp(_str, s._str)>0;
		 }

		 bool operator==(const string& s)const
		 {
			 return strcmp(_str, s._str)==0;
		 }

		 bool operator<(const string& s)const 
		 {
			 return strcmp(_str, s._str)<0;
		 }

		 bool operator <=(const string& s)const
		 {
			 return !(*this > s);
		 }

		 bool operator >=(const string& s)const
		 {
			 return !(*this < s);
		 }
		 iterator begin()
		 {
			 return _str;
		 }
		 iterator end()
		 {
			 return _str + _size;
		 }
		 const_iterator begin()const 
		 {
			 return _str;
		 }
		 const_iterator end()const
		 {
			 return _str + _size;
		 }
		 char& operator[](int pos)
		 {
			 return _str[pos];
		 }

		 const char& operator[](int pos)const 
		 {
			 return _str[pos];
		 }


		 string& operator+=(const string&s)
		 {
			 if (s._size + 1+_size > _capacity)
			 {
				 reserve(_size + s._size);
			 }
			 strcpy(_str + _size, s._str);

			 _size += s._size;
			 return *this;
		 }
		 string& operator+=(char ch)
		 {
			 if (_size >= _capacity)
			 {
				 reserve((_capacity + 1)*2);
			 }
			 _str[_size++] = ch;
			 _str[_size] = '\0';
			 return *this;
		 }

		 void push_back(char ch)
		 {
			 *this += ch;
		 }
		 void resize(size_t n, char ch = '\0')
		 {
			 reserve(n);
			 _size = n;
			 for (int i = 0; i < n; i++)
			 {
				 _str[i] = ch;
			 }	 
		 }

		 void append(const char* str)
		 {
			 size_t len = strlen(str);
			 if (_size + len > _capacity)
			 {
				 reserve(_size + len);
			 }

			 strcpy(_str + _size, str);
			 _size += len;
		 }

		 void insert(size_t pos ,char ch)
		 {
			 assert(pos <= _size);
			 if (_size +1> _capacity)
			 {
				 reserve((_capacity + 1) * 2);
			 }
			 int end = _size;
			 while (end >= (int)pos)//无符号与有符号比较时，有符号会提升至无符号
			 {
				 _str[end + 1] = _str[end];
				 end--;
			 }
			 _str[pos] = ch;
			 ++_size;
		 }
		 void insert(size_t pos,const char *str)
		 {
			 int len = strlen(str);
			 assert(pos <= _size);
			 if (_size+len >_capacity)
			 {
				 reserve(_size+len);
			 }
			 int end = _size;
			 while (end >= (int)pos)//无符号与有符号比较时，有符号会提升至无符号
			 {
				 _str[end +len] = _str[end];
				 end--;
			 }
			 for (int i = 0; i < len; i++)
			 {
				 _str[pos++] = str[i];
			 }
			 _size+=len;

		 }
		 void erase(size_t pos=0,size_t len=npos)
		 {
			 assert(pos <= _size);
			 if (len == npos || pos + len >= _size)
			 {
				 _str[pos] = '\0';
				 _size = pos;
			 }
			 else
			 {
				 strcpy(_str + pos, _str + pos + len);
				 _size -= len;
			 }

		 }
		 void swap(string& s)
		 {
			 std::swap(_str, s._str);
			 std::swap(_capacity, s._capacity);
			 std::swap(_size, s._size);
		 }
		 size_t find(char ch, size_t pos = 0)
		 {
			 assert(pos < _size);

			 for (size_t i = pos; i < _size; ++i)
			 {
				 if (_str[i] == ch)
				 {
					 return i;
				 }
			 }

			 return npos;
		 }

		 size_t find(const char* str, size_t pos = 0)
		 {
			 assert(pos < _size);

			 
			 char* p = strstr(_str + pos, str);
			 if (p == nullptr)
			 {
				 return npos;
			 }
			 else
			 {
				 return p - _str;
			 }
		 }

		 int Getsize()
		 {
			 return _size;
		 }
		 int Getcapacity()
		 {
			 return _capacity;
		 }


 	 private:
		 char* _str;
		 int _size;
		 int _capacity;	
		 static const size_t npos;
	};

	const size_t string::npos = -1;

	void text1()//测试构造函数和赋值重载是否正确
	{
		std::string s1 = "hello world";
		string s2("hello world");
		string s3(s2);
		std::cout << s2.c_str() <<std:: endl;
		std::cout << s3.c_str() << std::endl;
		const string s4("hello world");
		std::cout << s4.c_str() << std::endl;
		string s5("hello zyt");
		s2 = s5;
		std::cout << s2.c_str() << std::endl;
		s2 += s3;
		s2.reserve(2);
		s2 += 'h';
		s2 += 'l';
		std::cout << s2.c_str() << std::endl;
	}
	void text2()//测试比较是否正确
	{
		string s1 = "hello world";
		string s2 = "hello zyt";
		string s3 = "hello world";
		std::cout << (s1 < s2) << std::endl;
		std::cout << (s1 == s2) << std::endl;
		std::cout << (s1 <= s2) << std::endl;
		std::cout << (s1 > s2) << std::endl;
		std::cout << (s1 == s3) << std::endl;
	}
	void text3()//测试迭代器是否正确
	{
		string s1 = "hello world";
		for (auto &e : s1)
		{
			e++;
			std::cout << e << std::endl;
		}
		const string s2 = "hello world";
		/*for (auto &e : s2)
		{
			e++;
		}*/
		for (auto e : s2)
		{
			std::cout << e << std::endl;
		} 
	}
	void text4()//测试inseret和erase是否正确
	{
		string s1 = "hello";
		std::cout << s1.c_str() << std::endl;
		std::cout << s1.c_str() << std::endl;
		s1.insert(0, "world");
		std::cout << s1.c_str() << std::endl;
		s1.insert(0, "hello world");
		std::cout << s1.c_str() << std::endl;
		s1.erase(0, 11);
		std::cout << s1.c_str() << std::endl;
	}
}
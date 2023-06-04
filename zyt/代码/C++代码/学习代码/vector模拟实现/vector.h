#pragma once


#include<iostream>
#include<assert.h>


namespace zyt
{
	template<typename T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
		{

		}
		vector(size_t n, const T&val= T())
		{
			reserve(n);
			for (int i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}
		vector(int n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		~vector()
		{
			delete[]_start;
			_end_of_storage=_finish=_start = nullptr;
			
		}
		vector(const vector<T>& v)
		{
			int n = v.capacity();
			_start = new T[n];
			//memcpy(_start, v._start, sizeof(T)*v.size());//���ʹ��memcpy�Ļ���ֻ�ǿ�����Ŀ������ݣ���ӦĿ��ҲΪǳ������Ӧ�õ���Ŀ��Ŀ�����������Ϊ���
			for (size_t i = 0; i < v.size(); ++i)
			{
				_start[i] = v._start[i];
			}

			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)//�˴��빹�캯�����ͻ
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
			    T* tmp = new T[n];
				if (_start)
				{
					for (int i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[]_start;
				}

				_start = tmp;
				_finish = tmp + sz;
				_end_of_storage = tmp + n;
			}

		}

		void resize(size_t n,const T& val=T())
		{
			size_t sz = size();
			if (n > sz)
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
			else
			{
				_finish = _start + n;
			}
		}

		void push_back(const T&val)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 4);
			}
			*_finish = val;
			++_finish;
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		iterator insert(iterator pos,const T&val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _end_of_storage)//�˴��е�����ʧЧ����Ϊ����ʹ��_finish��ֵ����
			{
				size_t len = pos - _finish;
				reserve(capacity() == 0 ? 4 : capacity() * 4);
				pos = _finish + len;
			}
			iterator end = _finish-1;
			while (end>=pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = val;
			++_finish; 
			
			return pos;

		}
		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			assert(!empty());
			iterator begin = pos;
			while (begin < _finish)
			{
				*begin = *(begin + 1);
				begin++;
			}
			--_finish;
			return pos;
		}
		iterator begin()const
		{
			return _start;
		}
		iterator end()const 
		{
			return _finish;
		}
		int capacity()const
		{
			return _end_of_storage - _start;
		}
		int size()const
		{
			return _finish - _start;
		}
		bool empty()const
		{
			return _finish == _start;
		}
		
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;

	};

	void text()//���Թ��캯����reserve,resize
	{
		vector<int> v(10, 5);
		for (auto e : v)
		{
			std::cout << e ;
		}
		std::cout << std::endl;
		v.push_back(4);
		v.push_back(4);
		v.push_back(4);
		v.push_back(4);
		for (auto e : v)
		{
			std::cout << e ;
		}
		std::cout << std::endl;
		v.resize(10);
		for (auto e : v)
		{
			std::cout << e;
		}
		std::cout << std::endl;
		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.pop_back();
		for (auto e : v)
		{
			std::cout << e;
		}

	}
	void text2()//���Բ���ɾ��
	{
		vector<int> v(10, 5);
		//for (auto e : v)
		//{
		//	std::cout << e;
		//}
		//std::cout << std::endl;
		//v.insert(v.begin() + 4, 4);
		//v.insert(v.begin() + 4, 4);
		//v.insert(v.begin() + 4, 4);
		//for (auto e : v)
		//{
		//	std::cout << e;
		//}
		//std::cout << std::endl;
		//v.erase(v.begin() + 4);
		//v.erase(v.begin() + 4);
		//v.erase(v.begin() + 4);
		//for (auto e : v)
		//{
		//	std::cout << e;
		//}
		//std::cout << std::endl;
		//vector<int >v1(v);
		//for (auto e : v1)
		//{
		//	std::cout << e;
		//}

		auto itb = v.begin();
		auto ite = v.end();
		std::cout << *(ite-1) << std::endl;

	}
}
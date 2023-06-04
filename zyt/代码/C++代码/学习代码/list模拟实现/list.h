
#pragma once

#include<iostream>
#include<assert.h>
#include"iterator.h"

namespace zyt
{
	template<class T>
	struct list_node
	{
		list_node<T>* _prev;
		list_node<T>* _next;
		T _data;

		list_node(const T& x = T()) :_prev(nullptr), _next(nullptr), _data(x)
		{

		}

	};

	template<class T, class Ref, class Ptr>//Ref指明是否是const类型的数据，Ptr指明
	struct __list_iterator
	{
		typedef list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> self;
		node* _node;
		__list_iterator(node* n) :_node(n)
		{

		}

		Ref operator *()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		self operator++(int)
		{
			self temp(*this);
			_node = _node->_next;
			return temp;
		}

		self& operator--()
		{
			_node = _node->_prev;

			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;

			return tmp;
		}

		bool operator !=(const self& i)
		{
			return _node != i._node;
		}
		bool operator ==(const self& i)
		{
			return _node == i._node;
		}

	};
	template<class T>
	class list
	{

		typedef list_node<T> node;
	     public:

		typedef __list_iterator<T, T&, T*>  iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		typedef ReserveIterator< iterator, T&, T*>  reserve_iterator;
		typedef ReserveIterator< iterator, const T&, const T*>  const_reserve_iterator;


		iterator begin()
		{
			return iterator(_head->_next);
		}
		const_iterator begin()const
		{
			return const_iterator(_head->next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}
		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}
		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;

			node* newnode = new node(x);

			cur->_prev = newnode;
			newnode->_next = cur;
			prev->_next = newnode;
			newnode->_prev = prev;

		}

		void erase(iterator pos)
		{
			node cur = pos->_node;
			node prev = cur->_prev;
			node next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete[]cur;
		}

		void push_back(iterator pos, const T& x)
		{
			insert(pos, x);
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}
	   private:
		node* _head;

	};

		void text()
		{
			list<int> l;
			l.insert(l.begin(), 4);

			for (auto e : l)
			{
				std::cout << e;
			}
		}
	
}
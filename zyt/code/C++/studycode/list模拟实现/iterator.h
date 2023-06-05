#pragma once
namespace zyt
{
	template<class Iterator,class Ref, class Ptr>
	struct ReserveIterator
	{
		typedef reserve_iterator<Iterator,Ref,Ptr> self;

		Iterator _cur;

		Ref operator *()
		{
			Iterator tmp = _cur;
			return *--tmp;
		}

		Ref operator++()
		{
			--_cur;
			return _cur;
		}
		Ref operator--()
		{
			++_cur;
			return _cur;
		}
		bool operator!=(const Self& s)
		{
			return _cur != s._cur;
		}
	};
}




//class A
//{
//private:
//    const int b;
//
//    float*& c;
//
//    const  static char* d;
//
//    static double* e;
//public:
//    A(int b,float* &c):b(b),c(c),d('c')
//    {
//
//    }
//};
//
//class A
//{
//public:
//    A()
//    {
//
//    }
//    A(int a)
//    {
//
//    }
//    void Print()
//    {
//      cout << _a1 << " " << _a2<<" "<<_a3 << " " << endl;
//    }
//
//private:
//
//      int _a2;
//      int _a1;
//      float _a3;
//
//};
//
////A b;
//int main()
//
//{
//
//    
//    /*static A aa;
//    aa.Print();*/
//    A b;
//    b.Print();
//
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//class B
//{
//public:
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	A _aobj; 
//	// 自定义类型没有默认构造函数时才需要使用初始化列表，如果有初始化列表时，就算你不用初始化列表，自定义类型系统会自动用初始化列表来调用默认构造函数
//	int& _ref; // 引用
//	const int _n; // const
//};
//class Date
//{
//public:
//    
//    // 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
//    // explicit修饰构造函数，禁止类型转换---explicit去掉之后，代码可以通过编译
//    explicit Date(int year)
//    :_year(year)
//    {}
//    /*
//    // 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具
//    有类型转换作用
//    // explicit修饰构造函数，禁止类型转换
//    explicit Date(int year, int month = 1, int day = 1)
//    : _year(year)
//    , _month(month)
//    , _day(day)
//    {}
//    */
//    Date& operator=(const Date& d)
//    {
//        if (this != &d)
//        {
//            _year = d._year;
//            _month = d._month;
//            _day = d._day;
//        }
//        return *this;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//void Test()
//{
//    Date d1(2022);
//    // 用一个整形变量给日期类型对象赋值
//    // 实际编译器背后会用2023构造一个无名对象，最后用无名对象给d1对象进行赋值
//    d1=2023;
//    // 将1屏蔽掉，2放开时则编译失败，因为explicit修饰构造函数，禁止了单参构造函数类型转
//}



//class Date
//{
//public:
//	Date()
//	{
//
//	}
//	Date* operator&()
//	{
//		return this;
//	}
//	const Date* operator&()const
//	{
//		return this;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//
//
//void  text(const Date& A)
//{
//	cout << "const" << endl;
//}
//
//int main()
//{
//	Date de1;
//	const Date* pde = &de1;
//	Date de2;
//	const Date de3=de2;
//	text(de1);
//	text(de3);
//}
//
//class A
//{
//public:
//	static int st;
//	int a;
//	static int sta()
//	{
//		return st;
//	}
//	int res()
//	{
//		return st;
//	}
//
//};

//class A
//{
//public:
//	A(int a=0)
//		:_a(a)
//		{
//		
//		}
//		~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//};
//int main()
//{
//	A aa1;
//	// 不能这么定义对象，因为编译器无法识别下面是一个函数声明，还是对象定义
//	//A aa1();
//	// 但是我们可以这么定义匿名对象，匿名对象的特点不用取名字，
//	// 但是他的生命周期只有这一行，我们可以看到下一行他就会自动调用析构函数
//	A();
//	A aa2(2);
//	// 匿名对象在这样场景下就很好用，当然还有一些其他使用场景，这个我们以后遇到了再说
//	Solution().Sum_Solution(10);
//	return 0;
//}



#include <iostream>
using namespace std;

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

int mian()
{
	A a1 = 1;
	return 0;
}



//void f1(A aa)
//{}
//A f2()
//{
//	A aa;
//	return aa;
//}
//int main()
//{
//	// 传值传参
//	A aa1;   //0
//	f1(aa1);  //0 
//	cout << endl;
//	// 传值返回
//	f2();//  0
//	cout << endl;
//	// 隐式类型，连续构造+拷贝构造->优化为直接构造
//	f1(1);
//	// 一个表达式中，连续构造+拷贝构造->优化为一个构造
//	f1(A(2));
//	cout << endl;
//	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
//	A aa2 = f2();
//	cout << endl;
//	// 一个表达式中，连续拷贝构造+赋值重载(此为自定义的)->无法优化
//	aa1 = f2();
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	const int row=5;
//	const int col=4;
//	int** a = new int* [row];
//	for (int i = 0; i < row; i++)
//	{
//		a[i] = new int[col];
//	}
//
//}
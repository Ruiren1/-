

#include <iostream>
using namespace std;

////int main()
////{ 
////    auto a = 10;
////    auto b = 'b';
////    auto c = "abcd";
////    auto d = 1.1;
////    auto pa = &a;
////    auto* pb = &b;
////    auto& ra = a;   
////}
////int TestAuto()
////{
////	return 10;
////}
////int main()
////{
////	int a = 10;
////	auto b = a;
////	auto c = 'a';
////	auto d = TestAuto();
////	cout << typeid(b).name() << endl;
////	cout << typeid(c).name() << endl;
////	cout << typeid(d).name() << endl;
////	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化
////	return 0;
////}
//
////int main()
////{
////	int x = 10;
////	auto a = &x;
////	auto* b = &x;
////	auto& c = x;
////	auto arr[3] = { 1,2,3 };
////	cout << typeid(a).name() << endl;
////	cout << typeid(b).name() << endl;
////	cout << typeid(c).name() << endl;
////	*a = 20;
////	*b = 30;
////	c = 40;
////	return 0;
////}
//
//int main()
//{
//	int a[10]={0,1,2,3,4,5,6,7,8,9};
//	for (int  &e : a)
//	{
//		cout << e;
//	}
//	return 0;
//}

//class A
//{
//public:
//	A(int a=0) :_a(a)
//	{
//		cout <<"A()";
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	const A a1 = 1;
//}
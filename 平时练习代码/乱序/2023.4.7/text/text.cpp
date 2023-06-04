#include"text.h"

// 1、参数类型不同
int &  TestRef()
{
	int a = 10;
	return a;
}
//
//int& TestRef()
//{
//	static int a = 10;
//
//	cout << &a << endl;
//	return a;
//}


int main()
{
	string s = "";

	int& c = TestRef();
	cout << c<< endl;
	return 0;
}





#include <iostream>
using namespace std;
//void Swap(int& left, int& right)
//{
//    int temp = left;
//    left = right;
//    right = temp;
//}
//void Swap(double& left, double& right)
//{
//    double temp = left;
//    left = right;
//    right = temp;
//}
//void Swap(char& left, char& right)
//{
//    char temp = left;
//    left = right;
//    right = temp;
//}
template<typename  T>
void Swap(T& a, T& b)
{
    T temp = b;
    b = a;
    a = temp;
}

template<typename T1,typename T2>
T2 add(const T1& a, const T2& b)
{
    return a + b;
}

int main()
{
    int a1 = 3,a2=4;
    double b1 = 1.1,b2=2.1;
    cout << add(a1,b1)<< endl;
   
    cout << add(a2, b2)<< endl;
}
 
// 
// 
// 
// 
// 
// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2); // 调用编译器特化的Add版本
//}
//
//int main()
//{
//	return 0;
//}





//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//    return left + right;
//}
//
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//    return left + right;
//}
//void Test()
//{
//    Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//    Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函
//
//}


// 动态顺序表
// 注意：Vector不是具体的类，是编译器根据被实例化的类型生成具体类的模具

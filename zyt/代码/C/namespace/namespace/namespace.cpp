
#include <iostream>
using namespace std;
//命名空间只能在全局范围使用（下面是错误代码）
//void text1()
//{
//    namespace zyt
//    {
//        int a = 1;
//    }
//}
//命名空间是开放的,可以随时添加新的成员
namespace zyt
{
    int a;
}
//假设中间有很多代码（
namespace zyt
{
    int b;
}
//命名空间可以嵌套
namespace N1
{
    int a=10;
    namespace N2
    {
        int a=20;
    }
    //std::cout << N1::N2::a << endl;
}
//命名空间的函数的声明和定义可以分开写
namespace N3
{
    void fun();
}
void N3::fun()
{
    std::cout << N1::N2::a << endl;
}
//无命名空间.相当于给变量名添加了static，只可以作为内部链接
//namespace
//{
//    int c;
//}
//int c;
//using namespace N1;
//命名空间可以加别名
namespace longname
{
    int a=10;
}
int main()
{
    namespace shortname = longname;
    std::cout << shortname ::a<<endl;

}   


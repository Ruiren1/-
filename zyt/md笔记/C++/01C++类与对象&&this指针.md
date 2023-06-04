@[TOC](文章目录)

# 前言

从此篇往后，开始了C++的类和对象的篇章，嗯就说这么多，

# 一，类

## 1.类的引入

> C语言结构体中只能定义变量，在C++中，结构体内不仅可以定义变量，也可以定义函数。比如：
> 之前在数据结构初阶中，用C语言方式实现的栈，结构体中只能定义变量；现在以C++方式实现，
> 会发现struct中也可以定义函数 


```c++
#include<iostream>
using namespace std;

typedef int DataType;
struct Stack
{
	void Init(size_t capacity)
	{
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (nullptr == _array)
		{
			perror("malloc申请空间失败");
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
	void Push(const DataType& data)
	{
		// 扩容
		_array[_size] = data;
		++_size;
	}
	DataType Top()
	{
		
			return _array[_size - 1];
	}
	void Destroy()
	{
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
	DataType* _array;
	size_t _capacity;
	size_t _size;
};
int main()
{
	Stack s;
	s.Init(10);
	s.Push(1);
	s.Push(2);
	s.Push(3);
	cout << s.Top() << endl;
	s.Destroy();
	return 0;
}

```


## 2.类的定义

> class为定义类的关键字，ClassName为类的名字，{}中为类的主体，注意类定义结束时后面分
> 号不能省略。
> 类体中内容称为类的成员：类中的变量称为类的属性或成员变量; 类中的函数称为类的方法或者
> 成员函数。  

```c++
class className
{
// 类体：由成员函数和成员变量组成
}; // 一定要注意后面的分号
```

注意，类的声明和定义要分成两个文件，声明在.h的头文件里，定义在.cpp的源文件里，具体实现与C语言的声明与定义分离一样



## 3.类的作用域

> 类定义了一个新的作用域，类的所有成员都在类的作用域中。在类体外定义成员时，需要使用 ::
> 作用域操作符指明成员属于哪个类域。  

![image-20230422155127615](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230422155127615.png)





## 4.类的访问限定符及封装  

### 封装  

> 面向对象的三大特性：封装、继承、多态  
>
> 封装：将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口来
> 和对象进行交互。  
>
> 打个比方：手机就是一个封装而成的东西，手机里有内存卡，CPU等，他们被集合在一起封装成手机
>
> 

### 访问限定符  

> C++实现封装的方式：用类将对象的属性与方法结合在一块，让对象更加完善，通过访问权限选
> 择性的将其接口提供给外部的用户使用  



1. public修饰的成员在类外可以直接被访问
2. protected和private修饰的成员在类外不能直接被访问(此处protected和private是类似的)
3. 访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止
4. 如果后面没有访问限定符，作用域就到 } 即类结束。
5. class的默认访问权限为private，struct为public(因为struct要兼容C)  



### 面试题



C++中struct和class的区别是什么？  

> 解答：C++需要兼容C语言，所以C++中struct可以当成结构体使用。另外C++中struct还可以用来
> 定义类。和class定义类是一样的，区别是struct定义的类默认访问权限是public，class定义的类
> 默认访问权限是private。
>
> 注意：在继承和模板参数列表位置，struct和class也有区别，后序给大家介绍。 





# 二，this指针

## 1.this指针定义

> C++编译器给每个“非静态的成员函数“增加了一个隐藏
> 的指针参数，让该指针指向当前对象(函数运行时调用该函数的对象)，在函数体中所有“成员变量”
> 的操作，都是通过该指针去访问。只不过所有的操作对用户是透明的，即用户不需要来传递，编
> 译器自动完成  

```C++
class Date
{
public:
    Date()
    {
        _year = 1900;
        _month = 1;
        _day = 1;
    }
    int  Get_day()
	{
		return _day;
	}
    //当被调用时系统会转换成以下样子
    //int  Get_day(const Date* this)
	//{
	//	return _day;
	//}
	int Get_month()
	{
		return _month;
	}
	int Get_year()
	{
		return _year;
	}
   
private:
    int _year;
    int _month;
    int _day;
};

void Test()
{
	Date d1;
    int day=d1.Get_day();;//当调用时会变成Get_day(&d1)
}
```



## 2.this指针的特性

> 1.this指针的类型：类型为* const，即成员函数中，不能给this指针赋值。
>
> 2.只能在“成员函数”的内部使用
>
> 3.this指针本质上是“成员函数”的形参，当对象调用成员函数时，将对象地址作为实参传递给
>
> 4.this形参。所以对象中不存储this指针(存储在栈中)
>
> 5.this指针是“成员函数”第一个隐含的指针形参，一般情况由编译器通过ecx寄存器自动传
>
>  递，不需要用户传递  














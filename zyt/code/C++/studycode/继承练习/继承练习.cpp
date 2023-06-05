
#include<iostream>
using namespace std;

//class Person
//{
//public:
//	Person() 
//	{ 
//		cout << " Person() " << endl;
//		++_count;
//	}
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//
//int Person::_count = 0;
//
//class Student:public Person
//{
//public:
//	Student()
//	{
//		cout << "Student()" << endl;
//	}
//protected:
//	int _stuNum; // 学号
//};
//
//class Graduate : public Student
//{
//protected:
//string _seminarCourse; // 研究科目
//};
//
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " 人数 :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	void setage()
//	{
//		_age = 20;
//	}
//private:
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//};
//
//class Student : public Person
//{
//
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher :Person
//{
//protected:
//	int _jobid; // 工号
//};
//
//
//int main()
//{
//	//子类对象可以赋值给父类对象/指针/引用
//	Student s;
//	Person p;
//	Person* ps = &s;
//	Person& rs = s;
//	Person p1 = s;
//	//s = p;基类对象不能赋值给派生类对象
//	Person* pp = &p;
//	Student* pps = (Student*)pp;//基类的指针可以通过强制类型转换赋值给派生类的指针
//	
//
//
//}

//class Person
//{
//public:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//private:
//	string _name;
//};
//void Test()
//{
//	Student s;
//	string s1("张三");
//	s._name = s1;
//}
//
//int main()
//{
//	return 0;
//}

//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};
//int main()
//{
//	Test();
//	return 0;
//}

// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" << i << endl;
//	}
//};
//void Test()
//{
//	B b;
//	b.fun(10);
//	b.A::fun();
//};
//
//
//int  main()
//{
//	Test();
//	return 0;
//}
//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		: Person(name)
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//	Student(const Student& s)
//		: Person(s)//会切片，所以能用派生类赋给基类
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//	Student& operator = (const Student& s)
//	{
//		cout << "Student& operator= (const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator =(s);//会切片，所以能用派生类赋给基类
//			_num = s._num;
//		}
//		return *this;
//	}
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num; //学号
//};
//void Test()
//{
//	Student s1("jack", 18);
//	Student s2(s1);
//	Student s3("rose", 17);
//	s1 = s3;
//}
//
//int  main()
//{
//	Test();
//	return 0;
//}

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}
//
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " 人数 :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
//}
//
//int main()
//{
//	TestPerson();
//	return 0;
//}
//
//class Person
//{
//public:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//void Test()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	//a._name = "peter";未指明是Student还是Teacher的_name
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	Assistant a;
//	a._name = "peter";
//}



class A
{
public:
	int _a;
};
// class B : public A
class B : virtual public A
{
public:
	int _b;
};
// class C : public A
class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}

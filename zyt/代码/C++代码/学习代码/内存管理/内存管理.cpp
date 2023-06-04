
#include <iostream>

using namespace std;

class A
{
public:
	int _a;




	A(int a = 0) :_a(a)
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

};


int main()
{
	
	/*A* pa = new A(10);
	delete pa;
	A* p1 = new A[10];
	delete[]p1;*/

	A* p2 = (A*)malloc(sizeof(A));
	new(p2)A();
	p2->~A();
}
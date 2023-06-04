#include<iostream>
#include"Stack.h"
using namespace std;
typedef int DataType;

class GamePalyer
{
	enum
	{
		NunSize = 5
	};
	int _scores[NunSize];
};

int main()
{
	Stack A;
	cout << A.add(2,3) << endl;
	
	return 0;
}



#include <iostream>
using namespace std;

const int N = 10010;
int a[N];//主串
int b[N];//有序序列的长度
int len=1;
int find(int x)//找第一个大于等于x的数
{
	int left = 1;
	int right = len;
	int mid;
	while (left <= right)
	{
		mid = (left + right) >> 1;
		if (b[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}

	}
	return left;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	b[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		if (a[i] > b[len])
		{
			b[++len] = a[i];
		}
		else
		{
			b[find(a[i])] = a[i];
		}
	}

	cout << len << endl;


}
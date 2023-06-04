
//#include <iostream>
//using namespace std;
//
//const int N = 10010;
//int a[N][N];
//int p[N][N];//记录前驱点的路径，存储的是y的增量,其下方的元素为0,其右上方的元素为1
//int b[N][N];//备份原数组
//int n;
//int main()//数塔逆推法求值
//{
//    int x, y;
//    for (int x = n - 2; x >= 0; x--)//最后一个是行是n-1，倒数第二排是n-2
//    {
//        for (int y = x; y >= 0; y--)
//        {
//            a[x][y] += max(a[x + 1][y], a[x + 1][y + 1]);
//        }
//    }
//    cout << "max=" << a[0][0] << endl;
////}
//int main()
//{
//	int x, y;
//	for (int x = n - 1; x >= 0; x--)
//	{
//		for (int y = x; y >= 0; y++)
//		{
//			b[x][y] = a[x][y];
//		}
//	}
//
//	for (int x = n - 2; x >= 0; x--)
//	{
//		for (int y = x; y >= 0; y--)
//		{
//			if (a[x + 1][y] > a[x + 1][y + 1])
//			{
//				a[x][y] += a[x + 1][y];
//				p[x][y] = 0;
//			}
//			else
//			{
//				a[x][y] += a[x + 1][y + 1];
//				p[x][y] = 1;
//			}
//		}
//	}
//	cout << "max=" << a[0][0] << endl;
//	for (int x = 0,int y=0; x <= n-1; x++)
//	{
//		cout << b[x][y]<<"->";
//		y += p[x][y];
//	}
//
//}

#include<iostream>
using namespace std;

const int N = 1001;
int a[N];
int f[N];
int main()
{
    int n;
    int ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        f[i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])//a[i]>a[j]&&f[j]+1>f[i]
            {
                f[i] = max(f[j] + 1, f[i]);
            }
            ans = max(f[i], ans);
        }
    }

    cout << ans << endl;
}
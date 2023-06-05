# 线性DP

## 数塔（数字三角形）

### 数塔逆推法求max(基础求法)

[[402 线性DP 数字三角形【动态规划】_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1Rk4y1173p/?vd_source=53105e5ee41f3d06bfa98bdcc7d570de)]

![image-20230422213712386](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230422213712386.png)







```c++
#include<iostream>

using namespace std;

const int N=510;

int a[N][N];
int n;

int main()
{
    cin>>n;
    for(int x=0;x<n;++x)
    {
        for(int y=0;y<=x;y++)
        {
            cin>>a[x][y];
        }
    }
    
    
    for(int x=n-2;x>=0;x--)
    {
        for(int y=0;y<=x;y++)
        {
            a[x][y]+=max(a[x+1][y],a[x+1][y+1]);
        }
    }
    
    cout<<a[0][0];
    return 0;
}

```

### 数塔逆推法求max(同时记录max的路径)

```c++
const int N = 10010;
int a[N][N];
int p[N][N];//记录前驱点的路径，存储的是y的增量,其下方的元素为0,其右上方的元素为1
int b[N][N];//备份原数组
int n;

int main()
{
	int x, y;
	for (int x = n - 1; x >= 0; x--)
	{
		for (int y = x; y >= 0; y++)
		{
			b[x][y] = a[x][y];
		}
	}

	for (int x = n - 2; x >= 0; x--)
	{
		for (int y = x; y >= 0; y--)
		{
			if (a[x + 1][y] > a[x + 1][y + 1])
			{
				a[x][y] += a[x + 1][y];
				p[x][y] = 0;
			}
			else
			{
				a[x][y] += a[x + 1][y + 1];
				p[x][y] = 1;
			}
		}
	}
	cout << "max=" << a[0][0] << endl;
	for (int x = 0,int y=0; x <= n-1; x++)
	{
		cout << b[x][y]<<"->";
		y += p[x][y];
	}

}

```

![image-20230422215029037](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230422215029037.png)



##  最长上升子序列

[403 线性DP 最长上升子序列【动态规划】_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1KK4y1e7t7/?vd_source=53105e5ee41f3d06bfa98bdcc7d570de)

### 普通算法



![image-20230423205043378](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230423205043378.png)



```c++
#include<iostream>

using namespace std;

const int N=1001;
int a[N];
int f[N];
int main()
{
    int n;
    int ans=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[i]>a[j])//a[i]>a[j]&&f[j]+1>f[i]
            {
                f[i]=max(f[j]+1,f[i]);
            }
            ans=max(f[i],ans);
        }
    }
    
    cout<<ans<<endl;
}
```



### 二分查找优化



![image-20230428164157299](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230428164157299.png)







```c++


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
```





## 最长公共子序列



![image-20230429110720914](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230429110720914.png)







```c++
#include<iostream>

using namespace std;

const int N=1001;
char a[N];
char b[N];
int f[N][N];


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                f[i][j]=f[i-1][j-1]+1;
            }
            else
            {
                f[i][j]=max(f[i][j-1],f[i-1][j]);
            }
        }
    }
    cout<<f[n][m];
}

```






















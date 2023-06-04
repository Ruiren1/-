# 区间DP

# 石子合并

[428 区间DP 石子合并【动态规划】_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1gz4y1y7Rv/?vd_source=53105e5ee41f3d06bfa98bdcc7d570de)

![image-20230429185329103](C:\Users\ruiren\AppData\Roaming\Typora\typora-user-images\image-20230429185329103.png)

```c++
#include<iostream>
#include<cstring>
using namespace std;

const int N=1010;
int n;
int w[N];//存放每个石碓的重量
int s[N];//石碓的前缀和
int f[N][N];//从区间i到区间j的最优解

int main()
{
    cin>>n;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        s[i]=s[i-1]+w[i];
        f[i][i]=0;
    }
    
    for(int len=2;len<=n;len++)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            for(int k=l;k<r;k++)//等于r和k是一种情况
            {
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
            }
        }
        
    }
    cout<<f[1][n];
}


```


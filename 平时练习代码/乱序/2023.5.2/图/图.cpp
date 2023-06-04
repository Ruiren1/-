
#include <iostream>
using namespace std;
#include<vector>
//const int N = 1001;
//int w[N][N];
//int vis[N];
//int m, n;
//void dfs(int u)
//{
//    vis[u] = true;
//    for (int v = 1; v <= n; v++)
//    {
//        if (w[u][v])
//        {
//            printf("%d%d%d\n", u, v, w[u][v]);
//            if (vis[v])
//            {
//                continue;
//            }
//            dfs(v);
//        }
//    }
//
//}
//
//int main()
//{
//    
//    cin >> m >> n;
//    for (int i = 1; i <= m; i++)
//    {
//        int a, b, c;
//        cin >> a >> b >> c;
//        w[a][b] = c;//有向边
//        w[a][b] = c;//无向边
//    }
//    dfs(1);
//    return 0;
//}


//const int N = 1001;
//int m, n;
//struct edge
//{
//    int u, v, w;
//}e[N];
//
//int vis[N];
//
//void dfs(int u)
//{
//    vis[u] = true;
//    for (int i = 1; i <= n; i++)
//    {
//        if (e[i].u == u)
//        {
//            cout << e[i].u << e[i].v << e[i].w << endl;
//            if (vis[e[i].v])
//            {
//                continue;
//            }
//            dfs(e[i].v);
//        }
//    }
//}
//int main()
//{
//
//    cin >> m >> n;
//    for (int i = 1; i <= m; i++)
//    {
//        int a, b, c;
//        cin >> a >> b >> c;
//        e[i] = { a,b,c };//有向图
//        //e[i] = { b,a,c };//无向图
//        
//        
//    }
//    dfs(1);
//    return 0;
//}


//struct edge
//{
//	int v, w;
//};
//int n, m;
//const int N = 1001;
//vector<edge> e[N];
//
//void dfs(int u,int fa)
//{
//
//	for (auto ed: e[u])
//	{
//		int v = ed.v;
//		int w = ed.w;
//		if (v == fa)
//			continue;
//		printf("%d%d\n", u, w);
//		dfs(u, v);
//
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= m; i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		e[a].push_back({ b,c });
//		e[b].push_back({ a,c });
//
//	}
//}


#include<iostream>

using namespace std;

const int N = 101;
int g[N][N];

int dx[4] = { -1,0,1,0 };//x方向的偏移量
int dy[4] = { 0,1,0,-1 };//y方向的偏移量

int n, m, t;

int sx, sy;
int fx, fy;
int ans;
void dfs(int x,int  y)
{
	if (sx == fx && sy == fy)
	{
		ans++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int a = x + dx[i];
		int b = y + dy[i];
		if (a<1 || b<1 || a>n || b>m)
		{
			continue;
		}
		g[a][b] = 1;
		dfs(a, b);
		g[a][b] = 0;
	}

}
int main()
{
	cin >> n >> m >> t;
	cin >> sx >> sy >> fx >> fy;
	for (int i = 1; i <= t; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a][b] = 1;
	}
	dfs(sx,sy);
	cout << ans;
}






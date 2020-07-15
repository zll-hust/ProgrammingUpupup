#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
// #define LOCAL

struct State
{
	int posId[3]; // 小鬼的位置
	int dis;	  // 步数
	State()
	{
		posId[0] = 0;
		posId[1] = 0;
		posId[2] = 0;
	}
};

struct Node
{
	int x, y;
	int dir[5];
	int d;
} G[500]; // 空格节点

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
const int maxn = 500;
int n, m, g, cnt;
int vis[maxn][maxn][maxn]; //是否经过
char graph[maxn][maxn];	   //原地图
int dest[3], start[3];
int id[maxn][maxn]; //坐标到节点编号

bool conflict(const int a, const int b, const int na, const int nb)
{
	return na == nb || (na == b && nb == a);
}

void solve()
{
	memset(vis, 0, sizeof(vis));
	queue<State> q;
	State s;
	for (int i = 0; i < 3; i++)
		s.posId[i] = start[i];
	q.push(s);
	vis[s.posId[0]][s.posId[1]][s.posId[2]] = 1;
	while (!q.empty())
	{
		State u = q.front();
		q.pop();

		// cout << u.posId[0] <<" "<< u.posId[1] << " " << u.posId[2] << endl;

		if (u.posId[0] == dest[0] && u.posId[1] == dest[1] && u.posId[2] == dest[2])
		{
			cout << u.dis << endl;
			break;
		}
		for (int i = 0; i < G[u.posId[0]].d; i++)
		{
			int na = G[u.posId[0]].dir[i];
			if (g == 1)
			{
				if (vis[na][0][0])
					continue;
				State nu;
				nu.dis = u.dis + 1;
				nu.posId[0] = na;
				q.push(nu);
				vis[na][0][0] = 1;
			}
			else
				for (int j = 0; j < G[u.posId[1]].d; j++)
				{
					int nb = G[u.posId[1]].dir[j];
					if (conflict(u.posId[0], u.posId[1], na, nb))
						continue;
					if (g == 2)
					{
						if (vis[na][nb][0])
							continue;
						State nu;
						nu.dis = u.dis + 1;
						nu.posId[0] = na;
						nu.posId[1] = nb;
						q.push(nu);
						vis[na][nb][0] = 1;
					}
					else
						for (int k = 0; k < G[u.posId[2]].d; k++)
						{
							int nc = G[u.posId[2]].dir[k];
							if (conflict(u.posId[0], u.posId[2], na, nc))
								continue;
							if (conflict(u.posId[2], u.posId[1], nc, nb))
								continue;
							if (vis[na][nb][nc])
								continue;
							State nu;
							nu.dis = u.dis + 1;
							nu.posId[0] = na;
							nu.posId[1] = nb;
							nu.posId[2] = nc;
							q.push(nu);
							vis[na][nb][nc] = 1;
						}
				}
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	while (scanf("%d%d%d", &n, &m, &g) == 3 && n)
	{
		int temp = n;
		n = m;
		m = temp;
		getchar();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				graph[i][j] = getchar();
			getchar();
		}

		memset(dest, 0, sizeof(dest));
		cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (graph[i][j] != '#')
				{
					G[cnt].x = i;
					G[cnt].y = j;
					id[i][j] = cnt;
					if (islower(graph[i][j]))
						start[graph[i][j] - 'a'] = cnt;
					if (isupper(graph[i][j]))
						dest[graph[i][j] - 'A'] = cnt;
					cnt++;
				}

		for (int i = 0; i < cnt; i++)
		{
			G[i].d = 0;
			for (int j = 0; j < 5; j++)
			{
				int nx = G[i].x + dx[j], ny = G[i].y + dy[j];
				if (graph[nx][ny] != '#')
					G[i].dir[G[i].d++] = id[nx][ny];
			}
		}

		solve();
	}
	return 0;
}
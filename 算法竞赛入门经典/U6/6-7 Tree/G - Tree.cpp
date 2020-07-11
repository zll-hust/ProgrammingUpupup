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
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
#define LOCAL

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

//因为各个结点的权值各不相同且都是正整数，直接用权值作为结点编号
const int maxv = 10000 + 10;
int in_order[maxv]; //中序
int post_order[maxv]; //后序
int lch[maxv]; //左子树编号
int rch[maxv]; //右子树编号
int n; //节点数量
bool read_list(int *a)
{
    string line;
    if (!getline(cin, line))
        return false;
    stringstream ss(line);
    n = 0;
    int x;
    while (ss >> x)
        a[n++] = x;
    return n > 0;
}

//把in_order[L1..R1]和post_order[L2..R2]建成一棵二叉树，返回树根
int build(int L1, int R1, int L2, int R2)
{
    if (L1 > R1)
        return 0; //空树
    int root = post_order[R2];
    int p = L1;
    while (in_order[p] != root)
        p++;
    int cnt = p - L1; //左子树的结点个数
    lch[root] = build(L1, p - 1, L2, L2 + cnt - 1);
    rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1);
    return root;
}

int best, best_sum; //目前为止的最优解和对应的权和
void dfs(int u, int sum)
{
    sum += u;
    if (!lch[u] && !rch[u])//叶子，左子树和右子树为空
    { 
        if (sum < best_sum || (sum == best_sum && u < best))
        {
            best = u;
            best_sum = sum;
        }
    }
    if (lch[u])
        dfs(lch[u], sum);
    if (rch[u])
        dfs(rch[u], sum);
}
int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    while (read_list(in_order))
    {
        read_list(post_order);
        build(0, n - 1, 0, n - 1);
        best_sum = 1000000000;
        dfs(post_order[n - 1], 0);
        cout << best << "\n";
    }
    return 0;
}
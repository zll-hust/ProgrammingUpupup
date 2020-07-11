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

//结点类型
struct Node
{
    bool have_value; //是否被赋值过
    int v;           //结点值
    Node *left, *right;
    Node() : have_value(false), left(NULL), right(NULL) {} //构造函数
};
Node *root; //二叉树的根结点
bool failed;

Node *newnode() { return new Node(); }

void addnode(int v, string s)
{
    int n = s.length();
    Node *u = root; //从根结点开始往下走
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            if (u->left == NULL)
                u->left = newnode(); //结点不存在，建立新结点
            u = u->left;             //往左走
        }
        else if (s[i] == 'R')
        {
            if (u->right == NULL)
                u->right = newnode();
            u = u->right;
        } //忽略其他情况，即最后那个多余的右括号
    }
    if (u->have_value)
        failed = true; //已经赋过值，表明输入有误
    u->v = v;
    u->have_value = true; //别忘记做标记
}

void remove_tree(Node *u)
{
    if (u == NULL)
        return;            //提前判断比较稳妥
    remove_tree(u->left);  //递归释放左子树的空间
    remove_tree(u->right); //递归释放右子树的空间
    delete u;              //调用u的析构函数并释放u结点本身的内存
}

bool read_input()
{
    failed = false;
    remove_tree(root); //释放内存
    root = newnode();  //创建根结点

    while (true)
    {
        string str;
        if (!(cin >> str))
            return false;
        if (str == "()")
            return true;
        str = str.substr(1, str.length() - 2);
        str[str.find(',')] = ' ';
        stringstream input(str);
        int id;
        string pos;
        input >> id >> pos;
        addnode(id, pos); //查找逗号，然后插入结点
    }
    return true;
}

bool bfs(vector<int> &ans)
{
    queue<Node *> q;
    ans.clear();
    q.push(root); //初始时只有一个根结点
    while (!q.empty())
    {
        Node *u = q.front();
        q.pop();
        if (!u->have_value)
            return false;    //有结点没有被赋值过，表明输入有误
        ans.push_back(u->v); //增加到输出序列尾部
        if (u->left != NULL)
            q.push(u->left); //把左子结点（如果有）放进队列
        if (u->right != NULL)
            q.push(u->right); //把右子结点（如果有）放进队列
    }
    return true; //输入正确
}

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    while (read_input())
    {
        vector<int> ans;
        if (bfs(ans))
        {
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << endl;
        }
        else
            cout << "not complete" << endl;
    }
    return 0;
}
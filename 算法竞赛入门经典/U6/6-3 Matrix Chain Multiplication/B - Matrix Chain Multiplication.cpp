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

struct Matrix{
    int row;
    int col;
    char id;
    Matrix(){
        id = ' ';
        row = 0;
        col = 0;
    }
    Matrix(int row, int col){
        id = ' ';
        this->row = row;
        this->col = col;
    }
}m[30];

// unordered_map<string, int> id; // 矩阵id向编号的映射

int main()
{
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> m[i].id >> m[i].row >> m[i].col;
    string str;
    stack<Matrix> s;
    end:
    while(cin >> str){
        int times = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '(')
                continue;
            else if(str[i] == ')')
            {
                Matrix m2 = s.top();
                s.pop();
                Matrix m1 = s.top();
                s.pop();
                if(m1.col != m2.row)
                {
                    printf("error\n");
                    goto end;
                }
                else
                {
                    times += m1.row * m1.col * m2.col;
                    s.push(Matrix(m1.row, m2.col));
                }
            }
            else
                s.push(m[str[i] - 'A']);
        }
        printf("%d\n", times);
    }
    
    return 0;
}
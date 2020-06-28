#include <iostream>
#include <algorithm>
using namespace std;

#define LOCAL

struct Node
{
    long long x, y;
    int id;

    Node(){
        id = 0;
        x = 0;
        y = 0;
    }

    bool operator < (Node n){
        if(this->x != n.x)
            return this->x < n.x;
        else
            return this->y < n.y;
    }
}nodes[1005];

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif
	int t;
    scanf("%d", &t);
    
	while(t--)
	{
        int n = 0;
        scanf("%d", &n);
        n *= 3;
        for(int j = 0; j < n; j++){
            cin >> nodes[j].x >> nodes[j].y;
            nodes[j].id = j + 1;
        }

        sort(nodes, nodes + n);

		for (int j = 0; j < n; j += 3)
			printf("%d %d %d\n", nodes[j].id, nodes[j + 1].id, nodes[j + 2].id);
	}

	return 0;
}
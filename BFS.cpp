#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define INF 1000000000

int n, m, dist[MAX + 5];
vector<int>gr[MAX + 5];

void bfs(int src)
{
    ///init
    queue<int>Q;
    Q.push(src);
    for(int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[src] = 0;

    ///simulate
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(auto v : gr[u])
        {
            if(dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
}
int main()
{
    printf("BFS\n");
    return 0;
}


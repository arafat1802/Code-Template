#include <bits/stdc++.h>
using namespace std;

bool vis[100][100];
int grid[100][100];
int dx[] = {+0,+1,+0,-1};
int dy[] = {-1,+0,+1,+0};
int n, m;

void dfsg(int x, int y)
{
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && grid[nx][ny] != -1)
        {
            dfsg(nx, ny);
        }
    }
}
vector<int>gr[100010];
bool visited[100010];

void dfs(int u)
{
    visited[u] = 1;

    for(int v : gr[u]) /// u --> v
    {
        if(!visited[v])
        {
            dfs(v);
        }
    }
}
int main()
{
    memset(vis,0,sizeof vis);
    memset(visited,0,sizeof vis);
    printf("DFSG\n");
    printf("DFS\n");
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define left st, (st + en) / 2, nd + nd
#define right (st + en) / 2 + 1, en, nd + nd + 1
#define ll long long

ll tree[4 * MAX + 5];
ll lazy[4 * MAX + 5];

void update(int st, int en, int nd, int L, int R, int v)
{
    if(lazy[nd] != 0) /// not query specific
    {
        tree[nd] += (en - st + 1) * lazy[nd];
        if(st != en)
        {
            lazy[nd + nd] += lazy[nd];
            lazy[nd + nd + 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }
    if(en < L || R < st) return;
    if(L <= st && en <= R) /// query specific
    {
        tree[nd] += (en - st + 1) * v;
        if(st != en)
        {
            lazy[nd + nd] += v;
            lazy[nd + nd + 1] += v;
        }
        return;
    }
    update(left, L, R, v);
    update(right, L, R, v);
    tree[nd] = tree[nd + nd] + tree[nd + nd + 1];
}

ll query(int st, int en, int nd, int L, int R)
{
    if(en < L || R < st) return 0;
    if(lazy[nd] != 0) /// not query specific
    {
        tree[nd] += (en - st + 1) * lazy[nd];
        if(st != en)
        {
            lazy[nd + nd] += lazy[nd];
            lazy[nd + nd + 1] += lazy[nd];
        }
        lazy[nd] = 0;
    }
    if(L <= st && en <= R) return tree[nd]; /// if the query segment is completely overlapping our tree segment/node.
    return query(left, L, R) + query(right, L, R);
}
int main()
{
    printf("SegmentTreeLazy\n");
    return 0;
}

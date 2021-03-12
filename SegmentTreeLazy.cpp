#include<bits/stdc++.h>
#define ll  long long
#define mxN 100007
#define left st, (st+en)/2, nd + nd
#define right (st+en)/2+1,en,nd+nd+1
using namespace std;
int a[mxN];
struct info
{
    int sum;
    int prop;
} tree[4 * mxN];
void build(int st,int en,int nd)
{
    if(st == en)
    {
        tree[nd].sum = a[st];
        tree[nd].prop = 0;
        return;
    }
    build(left);
    build(right);
    tree[nd].sum = tree[nd+nd].sum + tree[nd+nd+1].sum;
}
void update(int st,int en,int nd,int L, int R,int x)
{
    if(L > en || R < st)
    {
        return;
    }
    if(st >= L and en <= R)
    {
        tree[nd].sum += ((en-st+1)*x);
        tree[nd].prop += x;
        return;
    }
    update(left,L,R,x);
    update(right,L,R,x);
    tree[nd].sum = tree[nd+nd].sum + tree[nd+nd+1].sum + (en - st) * tree[nd].prop;
}
ll query(int st, int en, int nd, int L, int R, int carry = 0)
{
    if(L > en || R < st)
    {
        return 0;
    }
    if(st >= L and en <= R)
    {
        return tree[nd].sum + carry * (en - st + 1);
    }
    return query(left,L,R,carry + tree[nd].prop) + query(right, L, R, carry + tree[nd].prop);

}
int main()
{
    printf("SEGMENTTREELAZY\n");

    return 0;
}

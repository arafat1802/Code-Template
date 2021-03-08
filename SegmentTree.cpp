#include<bits/stdc++.h>
#define mxN 100000 + 7
#define left st, (st + en) / 2, nd + nd
#define right (st + en) / 2 + 1, en, nd + nd + 1
#define ll long long
using namespace std;
int a[mxN];
int tree[4*mxN];
void build(int st, int en,int nd){
	if(st == en){
		tree[nd] = a[st];
		return;
	}
	build(left);
	build(right);
	tree[nd] = tree[nd + nd] * tree[nd+nd+1];
}
string s;
int query(int st,int en,int nd,int L,int R){

    if(L <= st && en <= R) return tree[nd];
    if(en < L || R < st) return 1;
    return query(left, L, R) * query(right, L, R);
}
void update(int st,int en,int nd,int idx,int v){
    if(en < idx || idx < st) return;
    if(st == en)
    {
        if(v > 0)tree[nd] = 1;
        else if(v < 0)tree[nd] = -1;
        else tree[nd] = 0;
        return;
    }
    update(left, idx, v);
    update(right, idx, v);
    tree[nd] = tree[nd + nd] * tree[nd + nd + 1];
}
int main(){
    printf("SegmentTree\n");
    return 0;
}

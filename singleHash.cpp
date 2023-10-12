#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cerr << x << " "; cerr << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define scan(a)        for(auto &it : a){cin >> it;}


template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cerr.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
#define ll long long
const int N = 200005;

vector<int> suf, b;
int mod;

void SingleHash(string &s, int32_t base = 153, int32_t _mod = 1000000009) {
    suf.clear();
    int n = s.length();
    suf.assign(n + 2, 0); // suf[n] = 0
    b.assign(n + 2, 0);
    b[0] = 1;
    b[1] = base;
    mod = _mod;
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = (s[i] - 'A' + 1LL + (ll)suf[i + 1] * b[1]) % mod;
    }
    for (int i = 2; i <= n; ++i) {
        b[i] = (ll)b[i - 1] * b[1] % mod;
    }
}

int32_t substr(int l, int r)  { // [l, r]
    ll v = suf[l] - (ll)suf[r + 1] * b[r - l + 1];
    v %= mod;
    v += mod;
    v %= mod;
    return v;
}

void solve() {
    string s;
    cin >> s;
    int32_t n = s.length();
    suf.clear();
    SingleHash(s);

    int32_t max_len = 0;
    for(int32_t len = 1; len <= n/2; len++){
        for(int32_t pos = 0; pos < n; pos++){
            int32_t cnt = 1;
            int sub = 0;
            if(pos+len-1 < n)sub = substr(pos, pos+len-1);
           
            for(int32_t j = pos + len; j < n; j += len){
                if(j+len-1 < n and sub == substr(j,j+len-1)){
                    cnt++;

                }
                else{
                    break;
                }
            }
            if(cnt > 1){
                max_len = max(max_len, cnt*len);
            }
        }
    }
    cout << max_len << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int32_t t = 1;
    cin >> t;
    while (t--) solve();

    
    return 0;
}

/*
EXPLAINATION:
  FIRST I THOUGH OF DOING RANGE UPDATING FROM  TOP TO DOWN MEANS WE ARE DETECTION FROM EVERY NODE IF THERE IS A PATH THAT IS GOING DOWN BUT DOING THAT
  AFFECT OTHER NODES ON THE PATH TRY WITH AN EXAMPLE
  
  INSTEAD WE DETECT PATHS FROM DOWN TO UP , WE WON'T BE CONFLICTING BECAUSE TREE DIVERGES IN BOTTOM AND CONVERGES AT TOP AND THEREFORE WE NEED TO KEEP THING SEPERATE
  AT THE BOTTOM

*/



/*
IN FUTURE , I WILL DEFINITELY BE PROUD OF THE CURRENT ME
JAI SHRI KRISHNA !!!
*/
 

/*
 
WORK ON COMING UP WITH NICE TESTCASES LIKE I WAS PROVIDED WITH ONE IN CONDEFORCES
DISCUSS SECTION
 
BEFORE GOING FORWARD WITH AN OBSERVATION , TRY VALIDATING IT WITH A COUNTER EXAMPLE
*/
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
 
#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int>  pi;
 
/***************************************************************************************/
//access keywords
#define F first
#define S second
#define PB push_back
#define inf INT_MAX
#define INF 1e18
 
// #define MP make_pair
// // ***********************************************************************************
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define REV_REP(i,a,b) for(int i=a;i>=b;i--)
#define inputVectori(v) for(auto &x:v) cin>>x;
#define printVectori(v) for(auto &x:v) cout<<x<<" ";
#define all(a) a.begin() , a.end()
/*****Remember inbuilt c++ functions*************************/
 
// next_permutation(), __builtin_popcount()
 
/***********************************************************/
const int mod  = 1e9 + 7 ;
 
inline void newLine() {
    cout << "\n";
}
 
void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
}
 
 
vector<ll> factorial;
void preprocess(int n) {
    factorial.push_back(1);
    for (int i = 1; i <= n; i++) {
        ll curr = (factorial.back() * i) % mod;
        factorial.push_back(curr);
    }
}
 
ll binaryExp(ll x , ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}
 
ll nCr(ll n, ll r) {
    if (n < r) return 0;
    ll fac1 = factorial[n];
    ll fac2 = binaryExp(factorial[n - r], mod - 2);
    ll fac3 = binaryExp(factorial[r], mod - 2);
    ll ans = (fac1 * fac2) % mod;
    ans = (ans * fac3) % mod;
    return ans;
}
 
 
vector<vector<int>> adj;
 
int timer, l, n;
vector<int> tin, tout;
vector<vector<int>> up;
 
void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
 
    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }
 
    tout[v] = ++timer;
}
 
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
 
 
void preprocess() {
 
    // dfs(0, 0);
}
 
 
 
void solve() {
 
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    int ans =  a * n;
 
 
    if (b >= 0) ans += n * b;
    else {
 
        int cnt[2] {0};
        cnt[s[0] - '0']++;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                cnt[s[i] - '0']++;
            }
        }
 
        ans += b * ( min(cnt[0], cnt[1]) + 1);
    }
 
    cout << ans << "\n";
 
}
 
int32_t main() {
    checkjudge();
    /*********************************************************************/
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*************************************************************************************/
    int t = 1;
    cin >> t;
    preprocess();
    for (int z = 1; z <= t; z++) {
        solve();
    }
 
}
 
 
 

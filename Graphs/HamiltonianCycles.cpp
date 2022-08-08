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
#define MP make_pair
/*************************************************************************************/
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define inputVectori(v) for(auto &x:v) cin>>x;
#define printVectori(v) for(auto &x:v) cout<<x<<" ";
#define all(v) v.begin(),v.end()
/*****Remember inbuilt c++ functions*************************/

// next_permutation(), __builtin_popcount()

/***********************************************************/
const int mod  = 1e9 + 7;

inline void newLine() {
    cout << "\n";
}

void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
}

int dp[(1 << 20) + 10][20];

int helper(int u , vi adj[] , int mask , int n) {

    //n can only be the last flight
    if (u == n and (mask != ((1 << n) - 1))) {
        return 0;
    }

    if (mask == ((1 << n) - 1)) {
        if (u == n) return 1;
    }

    if (dp[mask][u] != -1) {
        return dp[mask][u];
    }

    ll ans = 0;
    for (int v : adj[u]) {
        int shift = v - 1;
        if ((mask & (1 << shift)) == 0) {

            ans = (ans + helper(v , adj , mask | (1 << shift) , n)) % mod;

        }
    }

    return dp[mask][u] = ans;
}

void solve() {
    int n, m; cin >> n >> m;

    vi adj[n + 1];
    int a, b;


    while (m--) {
        cin >> a >> b;
        adj[a].PB(b);
    }


    int mask = 1;
    ll ans;
    memset(dp , -1 , sizeof(dp));
    ans = helper(1 , adj , mask , n);
    cout << ans;
}





int32_t main() {
    checkjudge();

    /*********************************************************************/

    ios::sync_with_stdio(0);
    cin.tie(0);

    /*************************************************************************************/
    int t = 1;
    // cin >> t;
    for (int z = 1; z <= t; z++) {
        solve();
    }
    return 0;
}

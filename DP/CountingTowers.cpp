
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


ll dp[1000005][2];
void solve() {
    int n; cin >> n;


    dp[n + 1][0] = dp[n + 1][1] = 1;

    for (int i = n; i >= 2; i--) {
        dp[i][0] = (dp[i + 1][1] + dp[i + 1][0] + dp[i + 1][0] + 2 * dp[i + 1][0]) % mod;
        dp[i][1] = (dp[i + 1][1] + dp[i + 1][0] + dp[i + 1][1]) % mod;
    }

    cout << (dp[2][0] + dp[2][1]) % mod; newLine();

}

int32_t main() {
    checkjudge();

    /*********************************************************************/

    ios::sync_with_stdio(0);
    cin.tie(0);

    /*************************************************************************************/
    int t = 1;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        solve();
    }
    return 0;
}

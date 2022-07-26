
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



void solve() {

    int n, m; cin >> n >> m;
    vi arr(n); inputVectori(arr);

    vector < vector<ll> > dp(n  , vector<ll>(m + 1));

    if (arr[0] == 0) {
        for (int j = 1; j <= m; j++) dp[0][j] = 1;
    } else {
        dp[0][arr[0]] = 1;
    }


    for (int i = 1; i < n; i++ ) {
        if (arr[i] == 0) {

            for (int j = 1; j <= m; j++) {
                dp[i][j] += dp[i - 1][j];
                if (j - 1 >= 1) dp[i][j] += dp[i - 1][j - 1];
                if (j + 1 <= m) dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= mod;
            }

        } else {
            dp[i][arr[i]] += dp[i - 1][arr[i]];
            if (arr[i] - 1 >= 1) dp[i][arr[i]] += dp[i - 1][arr[i] - 1];
            if (arr[i] + 1 <= m) dp[i][arr[i]] += dp[i - 1][arr[i] + 1];
            dp[i][arr[i]] %= mod;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[n - 1][i]) % mod;
    }

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

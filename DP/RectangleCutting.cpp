
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

ll dp[501][501];
void solve() {
    ll a, b; cin >> a >> b;



    ll ans  , res;

    for (int row = 1 ; row <= a ; row++ ) {

        for (int col = 1 ; col <= b; col++) {

            ans = INT_MAX;

            if (row == col) {
                dp[row][col] == 0;
                continue;
            }

            for (int cut = 1 ; cut < row ; cut++) {
                res = 1 +  dp[cut][col] + dp[row - cut][col];
                ans = min(ans, res);
            }

            for (int cut = 1 ; cut < col; cut++) {
                res = 1 + dp[row][cut] + dp[row][col - cut];
                ans = min(ans, res);
            }

            dp[row][col] = ans;

        }

    }

    cout << dp[a][b];

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

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

const int N = 1e5 + 1;


void solve() {
    int n, x; cin >> n >> x;
    vi v(n);
    inputVectori(v);

    vector<pair<int, int> > dp(1 << n, {INT_MAX, INT_MAX});
    dp[0] = {0, 0};

    for (int s = 1; s < (1 << n); s++ ) {

        for (int i = 0; i < n; i++) {

            if ((s >> i) & 1) {
                auto prev = dp[s ^ (1 << i)];

                if (prev.S + v[i] <= x ) {
                    prev.S += v[i];
                } else {
                    prev.F++ , prev.S = v[i];
                }

                dp[s] = min(dp[s], prev);

            }

        }

    }

    cout << dp[(1 << n) - 1].F + 1;

    newLine();

}

int32_t main() {
    checkjudge();

    /*********************************************************************/

    ios::sync_with_stdio(0);
    cin.tie(0);

    /*************************************************************************************/
    int t = 1;
    for (int z = 1; z <= t; z++) {
        solve();
    }
    return 0;
}

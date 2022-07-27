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

int dp[1001][1 << 12];

void get_next_masks(int mask , vector<int> &next_masks , int i , int n, int new_mask = 0) {
    if (i == n + 1) {
        next_masks.push_back(new_mask);
        return;
    }

    if ((mask & (1 << i)) != 0)
        get_next_masks(mask, next_masks , i + 1 , n , new_mask);

    if ((mask & (1 << i)) == 0) {
        get_next_masks(mask , next_masks , i + 1 , n , new_mask | (1 << i));
    }

    if (i + 1 <= n and (mask & (1 << i)) == 0 and ( mask & (1 << (i + 1))) == 0 ) {
        get_next_masks(mask, next_masks, i + 2 , n , new_mask);
    }

}

int helper(int col , int mask , const int m , const int n) {
    //base case
    if (col == m + 1) {
        if (mask == 0) return 1;
        return 0;
    }

    if (dp[col][mask] != -1) return dp[col][mask];

    vector<int> next_masks;
    get_next_masks(mask, next_masks , 1 , n);

    ll ans = 0;
    for (auto next_mask : next_masks) {
        ans = ( ans + helper(col + 1 , next_mask , m, n)) % mod;
    }

    return dp[col][mask] = ans;
}

void solve() {
    int n, m; cin >> n >> m;
    memset(dp, -1, sizeof(dp));

    ll ans = helper(1 , 0 , m , n);
    cout << ans << endl;
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

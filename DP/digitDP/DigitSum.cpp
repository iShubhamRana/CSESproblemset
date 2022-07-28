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

pair<ll, ll> dp[20][2];

pair<ll, ll> helper(string &s , int index , bool tight ) {
    if (index == s.length() - 1) {
        int n = (tight) ? s[index] - '0' : 9;
        ll cnt = n + 1;
        ll sum = n * (n + 1) / 2;
        return {sum, cnt};
    }

    if (dp[index][tight].first != -1 and dp[index][tight].second != -1 ) return dp[index][tight];

    int ub = (tight) ? s[index] - '0' : 9;

    ll ans = 0, cnt = 0;

    for (int dig = 0; dig <= ub; dig++) {
        auto next = helper(s, index + 1 , tight & (dig == ub));

        ll count = next.second , sum = next.first;

        ans += (dig * count + sum);
        cnt += count;
    }

    return dp[index][tight] = {ans , cnt};
}

void solve() {
    ll l, r;
    cin >> l >> r;

    string s1 = to_string(l - 1) , s2 = to_string(r);


    memset(dp , -1 , sizeof(dp));
    auto ans1 = helper(s1 , 0 , 1 );

    memset(dp , -1 , sizeof(dp));
    auto ans2 = helper(s2, 0, 1);

    cout << ans2.first - ans1.first;
    newLine();
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
        // cout << "Case #" << z << ": ";
        solve();
    }
    return 0;
}

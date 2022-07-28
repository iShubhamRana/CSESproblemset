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

ll dp[20][2][2][2];

ll helper(string &s , int index , bool tight , bool leading, bool even) {
    if (index == s.length()) return 1;


    if (dp[index][tight][leading][even] != -1) return dp[index][tight][leading][even];

    if (even) {

        vector<int> digs = {0, 2, 4, 6, 8};

        int ub = (tight) ? s[index] - '0' : 9;

        ll ans = 0;
        for (int dig : digs)
            if (dig <= ub)
                ans += helper(s, index + 1 , tight & (dig == ub), 0 , 0);
        return dp[index][tight][leading][even] = ans ;
    } else {

        vector<int> digs = {1, 3, 5, 7, 9};

        int ub = (tight) ? s[index] - '0' : 9;

        ll ans = 0;

        if (leading == 1) ans += helper(s , index + 1 , 0  , 1 , 0);

        for (int dig : digs)
            if (dig <= ub)
                ans += helper(s , index + 1 , tight & (dig == ub) , 0 , 1);


        return dp[index][tight][leading][even] = ans;
    }


}

void solve() {
    ll l, r;
    cin >> l >> r;

    string s1 = to_string(l - 1) , s2 = to_string(r);


    memset(dp , -1 , sizeof(dp));
    ll ans2 = helper(s2, 0, 1,  1, 0);

    memset(dp , -1 , sizeof(dp));
    ll ans1 = helper(s1 , 0 , 1 , 1, 0);

    cout << ans2 - ans1;
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
        cout << "Case #" << z << ": ";
        solve();
    }
    return 0;
}

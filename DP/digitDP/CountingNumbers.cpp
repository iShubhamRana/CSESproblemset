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

ll dp[20][11][2][2];

ll digitDP(string num , int index , int tight , int prev , int n, int zeroes) {

    //base case
    if (index == n) {
        return 1;
    }

    if (prev != -1 and dp[index][prev][tight][zeroes] != -1)
        return dp[index][prev][tight][zeroes];

    int ub = (tight) ? num[index] - '0' : 9;

    ll ans = 0;

    for (int dig = 0; dig <= ub; dig++) {

        if (zeroes == 0 and dig == prev) continue;

        ans += digitDP(num , index + 1 , tight & (dig == ub) , dig , n, zeroes & (dig == 0));

    }


    return dp[index][prev][tight][zeroes] = ans;
}

void solve() {
    ll n1 , n2; cin >> n1 >> n2;
    n1--;
    if (n2 == 0) {
        cout << 1 << endl;
        return;
    }
    string s1 = to_string(n1), s2 = to_string(n2);

    memset(dp, -1, sizeof(dp));

    ll ans1 = digitDP(s1, 0, 1 , -1, s1.length(), 1);

    memset(dp, -1, sizeof(dp));
    ll ans2 = digitDP(s2, 0, 1 , -1 , s2.length(), 1);
    cout << ans2 - ans1 << endl;
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

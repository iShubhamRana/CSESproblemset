#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<bool> vb;
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

void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
}

inline void newLine() {
    cout << "\n";
}

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<char> > v(n , vector<char> (n));

    REP(i, 0, n - 1) {
        REP(j, 0, n - 1) {
            cin >> v[i][j];
        }
    }

    vector<vector<ll> > prefix(n + 1 , vector<ll> (n + 1));

    REP(i, 0, n - 1) {
        REP(j, 0, n - 1) {
            prefix[i + 1][j + 1] = (v[i][j] == '*') + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
        }
    }
    int x1, y1, x2, y2;

    REP(i, 1, q) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1-- , x2-- , y1-- , y2--;

        ll ans = prefix[x2 + 1][y2 + 1] - prefix[x1][y2 + 1] - prefix[x2 + 1][y1] + prefix[x1][y1];
        cout << ans << "\n";
    }


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

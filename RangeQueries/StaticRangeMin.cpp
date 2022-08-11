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

void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
}

inline void newLine() {
    cout << "\n";
}

/***********************************************************/
/*

Preprocessing:
1 2 3 4 5 6 7 8 9 10 11
- - - - - - - -             power 8 can be divided into
- - - -
        - - - -             two ranges of power 4 , rest can be calculated


Answering queries:

1 2 3 4 5 6 7 8 9 10 11
    - - - -
        - - - -

from l take highest power of 2 range on
from r take highest power of 2 range
overlap doesn't affect the answer

*/

const int MAX_N = 2 * 1e5 + 10;
const int LOG = 20;
int a[MAX_N];
int m[MAX_N][LOG];

void solve() {

    int n, q; cin >> n >> q;

    //input
    REP(i, 0, n - 1) {
        cin >> a[i];
        m[i][0] = a[i];
    }

    //preprocessing

    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i + (1 << k) - 1 < n; i++) {
            m[i][k] = min(m[i][k - 1], m[i + (1 << k - 1)][k - 1]);
        }
    }


    //answering queries
    int l, r;
    while (q--) {
        cin >> l >> r;
        l-- , r--;
        int length = r - l + 1;
        //calculate highest power of 2
        int k = 0;
        while ((1 << (k + 1)) <= length) {
            k++;
        }

        int ans = min(m[l][k], m[r - (1 << k) + 1][k]);
        cout << ans;
        newLine();
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

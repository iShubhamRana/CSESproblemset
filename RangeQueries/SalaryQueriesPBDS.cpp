/*
In segment trees always think in terms of what info about range can help me tell that my ans is part
 of this range

IN this question we will maintain a range of minimum and maximum for each range, it will help us to know
if one of our answers is there in this range

use less_equal in pbds for multivalues

*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;

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

ll INF = 1e18;

void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
}

inline void newLine() {
    cout << "\n";
}

struct treeNode {
    ll minVal , maxVal, cnt;
};



void solve() {
    int n, m; cin >> n >> m;
    vi v(n);
    inputVectori(v);

    char ch;
    int a , b;
    indexed_set s;

    REP(i, 0, n - 1) {
        s.insert(v[i]);
    }

    REP(i, 1, m) {
        cin >> ch >> a >> b;
        if (ch == '?') {
            cout << s.order_of_key(b + 1) - s.order_of_key(a) << "\n";
        } else {
            // find the val at the index prev and then remove using that values position in set
            s.erase(s.find_by_order(s.order_of_key(v[a - 1])));
            v[a - 1] = b;
            s.insert(b);
        }
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

/*
Counting for each number is giving TLE in one case 
Preprocessing takes : nlogn time
We can use that
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


void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
}

inline void newLine() {
    cout << "\n";
}

ll INF = 1e18;
ll mod = 1e9 + 7;
const int N = 1e6 + 10;

ll get_pow(ll x , ll y, ll md) {
    ll res = 1;
    while (y) {
        if (y & 1) res = (res * x) % md;
        x = (x * x) % md;
        y >>= 1;
    }
    return res;
}

ll cnt[N];

void preprocess() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            cnt[j]++ ;
        }
    }
}

void solve() {

    ll x; cin >> x;
    cout << cnt[x] << "\n";
}




int32_t main() {
    checkjudge();

    /*********************************************************************/

    ios::sync_with_stdio(0);
    cin.tie(0);

    /*************************************************************************************/
    int t = 1;
    cin >> t;
    preprocess();
    for (int z = 1; z <= t; z++) {
        solve();
    }



    return 0;
}

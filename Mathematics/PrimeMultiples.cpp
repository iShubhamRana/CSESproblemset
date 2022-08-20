/*
Use Inclusion-Exclusion principle , 
if (size of elements included is odd) add
else subtrac
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


void solve() {

    ll n,  k;
    cin >> n >> k;

    vector<ll> v(k);
    inputVectori(v);

    ll ans = 0;

    for (ll i = 1; i < (1LL << k); i++) {
        ll cnt = 0 , prod = 1;

        for (ll j = 0; j < k; j++) {
            if ((i >> j) & 1) {
                cnt++;
                if (prod > n / v[j]) {
                    prod = n + 1 ;
                    break;
                }
                prod *= v[j];
            }
        }

        ll multiples = n / prod;
        if (cnt & 1) {
            ans += multiples;
        } else {
            ans -= multiples;
        }
    }


    cout << ans << " ";

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

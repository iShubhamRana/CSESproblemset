
/*
Exponentiation property of mod
(A^B)%C = ((A%C)^B)%C;


For product
x = 2^2 * 3^1
{ 1 , 2 , 4}
{ 1, 3}

each factor will repeat number of other divisors time
Therefore we will at each step multiply prev res to number of current divisors in current number
and multiply product of current number with all divisors encountered till now.
This is similar to multiplying them with left over divisors

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

ll getPower(ll x, ll y, ll md) {
    ll res = 1;
    while (y) {
        if (y & 1) res = (res * x) % md;
        y >>= 1;
        x = (x * x) % md;
    }
    return res;
}

void solve() {

    ll n; cin >> n;
    vector<ll> val(n), pwr(n);

    REP(i, 0, n - 1) {
        cin >> val[i] >> pwr[i];
    }

    /*count*/
    vector<ll> choice(n);
    ll tot = 1;
    REP(i, 0, n - 1) {
        choice[i] = 1 + pwr[i];
        tot = (tot * choice[i]) % mod;
    }
    cout << tot << " ";

    /*sum*/
    ll sum = 1;
    REP(i, 0, n - 1) {
        ll curr = getPower(val[i] , pwr[i] + 1, mod) - 1;
        ll modInverse = getPower(val[i] - 1 , mod - 2, mod);
        ll res = (curr * modInverse) % mod;
        sum = (sum * res) % mod;
    }
    cout << sum << " ";

    /*product*/
    ll prod = 1, div_cnt = 1;

    REP(i, 0, n - 1) {
        ll curr = getPower(prod, pwr[i] + 1 , mod);
        ll temp = getPower(val[i], pwr[i] * (pwr[i] + 1) / 2, mod);
        temp = getPower(temp , div_cnt, mod);

        prod = (curr * temp) % mod;

        div_cnt = (div_cnt * (pwr[i] + 1)) % (mod - 1);
    }

    cout << prod << " ";

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

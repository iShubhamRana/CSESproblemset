/*
 a^(b^c)  %mod

 What we think? calculate x=  (b^c)%mod and then a ^ (x) % mod
 This is wrong as ,
 2 ^ (1e9 ^1)    %mod 1e9  =>   1e9%1e9 = 0 => 2^0 = 1

So we need to reduce the power in some other way

Fermat little theorem a^(p-1) % p = 1;

let b^c =  q (p-1) + r

a ^ (b^c) = a ^(q * (p-1)) * a^r  (mod p)
using fermat's little

a^ (b^c) = a^r (mod p)

r is nothing but b^c mod (p-1);

We can simply calculate  x= b^c mod (p-1)

and then a^x %p;

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
ll mod = 1e9 + 7;

void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
}

inline void newLine() {
    cout << "\n";
}


ll get_pow(ll x , ll y, ll md) {

    ll res = 1;
    while (y) {
        if (y & 1) res = (res * x) % md;
        x = (x * x) % md;
        y >>= 1;
    }

    return res;
}

void solve() {
    ll a, b, c; cin >> a >> b >> c;

    ll x = get_pow(b, c, mod - 1);

    ll ans = get_pow(a, x, mod);

    cout << ans << "\n";
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
        solve();
    }



    return 0;
}

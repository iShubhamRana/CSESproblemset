/*
V good concept:

For each divisor lets count the number of times it occurs in the whole range
each divisor occurs n/i times
So our ans = summation((n/i)*i) for all 1<=i<=n

This would give TLE , lets find the best way to calculate the given value
We will calculate n/i for each i and then  multiply by i

for n = 20 , n/i for all 1<=i<=20 is given below

[20,10,6,5,4,3,2,2,2,2,1,1,1,1,1,1,1,1,1,1]

As i is increasing , n/i will definitely decrease but it can take at most 2* root(n) distinct values

Proof:  let k = n/i;
1. if k<= root(n) , total values it can take is root(n);
2. if k>=root(n) , means i <= root(n) which means for root(n) different values of i we will get root(n) different
k values

SO total diff values = 2 * root(n);


So from the above observations , we can see we will have 2*root(n) different values in a non increasing
order , therefore we can skip the repeating part for each n/i and iterate for distinct values


let l  be first n/l having value x
let r be last n/r having value x

we want , x *l + x*(l+1)+ .................
x * (l + (l+1) +......);

We can calculate that using standard summation formulas


for finding first and last same value we can see code



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

ll TWO_INVERSE = 500000004;

ll total_sum(ll start , ll end) {

    ll sum = (( (end + start) % mod ) * ((end - start + 1) % mod) % mod);
    sum = (sum * TWO_INVERSE) % mod ;
    return sum;
}

void solve() {

    ll n; cin >> n;

    ll total = 0;
    ll at =  1; //stores the current number we are at

    while (at <= n) {
        ll divisor = n / at;

        ll last_same = n / divisor; //last element having same divisor

        total = (total + divisor * total_sum(at , last_same)) % mod;

        at = last_same + 1;
    }

    cout << total << "\n";
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

/*
Concept of Difference array:
let arr = {a1,a2,a3,a4,a5};

diff arr = {d1,d2,d3,d4,d5};

d1 = a1;
d2 = a2 - a1
d3 = a3 - a2 so on

then:
a2 = d2 + a1 = d2 + d1
a3 = d3 + a2 = d3 + d2 + d1

Basically for each index i , a[i] =d[1] ..... d[i];

for range to [l,r]
simple do:  d[l]+val , d[r+1]-val;

For getting element at pos i , we can use BIT to get addition of first i elements and updation.

This concept is similar to range sum kind in which we have to tell the res of queries at the end , and there
we can simply store in array and then apply operations in the end
But here we have to answer the queries simultaneously , that's why we need this concept.

Since each element is represented as addition of first i elements , we can increase or decrease in desired range

*/









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

class BIT {
    int n;
    vector<long long>  v;
public:

    BIT(int sz) {
        n = sz;
        v.resize(n + 1);
    }

    long long sum(int k) {
        long long sum = 0;
        while (k > 0) {
            sum += v[k];
            k -= k & -k;
        }
        return sum;
    }

    void add(int k , int x) {
        while (k <= n) {
            v[k] += x;
            k += k & -k;
        }
    }

};


void solve() {

    int n, q; cin >> n >> q;

    vector<ll> diff;

    int prev = 0 , curr = 0;
    REP(i, 1, n) {
        cin >> curr;
        diff.PB(curr - prev);
        prev = curr;
    }

    //because we will be performing operations on r+1
    diff.PB(0);


    BIT t(diff.size());


    REP(i, 0, n) {
        t.add(i + 1 , diff[i]);
    }

    REP(i, 1, q) {
        int type; cin >> type;
        if (type == 1) {
            int a, b , u; cin >> a >> b >> u;
            t.add(b + 1 , -u);
            t.add(a, u );

        } else {
            int pos; cin >> pos;
            cout << t.sum(pos) << "\n";
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

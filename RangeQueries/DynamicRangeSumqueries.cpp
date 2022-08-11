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
    vector<long long> v;
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

    long long add(int k , int x) {

        while (k <= n) {
            v[k] += x;
            k += k & -k;
        }

    }

};

void solve() {
    int n, q; cin >> n >> q;

    BIT t(n);

    int a;
    REP(i, 1, n) {
        cin >> a;
        t.add(i, a);
    }

    int x, y, z;
    vi ans;
    while (q--) {
        cin >> x >> y >> z;
        // cout << x << " " << y << " " << z;
        if (x == 1) {
            ll element = t.sum(y) - t.sum(y - 1);
            t.add(y, z - element);
        } else {
            ll ans = t.sum(z) - t.sum(y - 1);
            cout << ans;
            newLine();
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

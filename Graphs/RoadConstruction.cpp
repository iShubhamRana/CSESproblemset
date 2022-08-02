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

/***********************************************************/
const int mod  = 1e9 + 7;

inline void newLine() {
    cout << "\n";
}

void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
}

const int N = 1e5 + 1;
ll par[N];
ll rnk[N];
ll sz[N];
ll maxi , components;
int findPar(int i) {
    if (par[i] == i) return i;
    return par[i] = findPar(par[i]);
}

int _union(int u , int v) {
    u = findPar(u) , v = findPar(v);

    if (rnk[u] < rnk[v]) {
        par[u] = v;
        sz[v] = sz[u] + sz[v];
        maxi = max(maxi , sz[v]);
    } else if (rnk[u] > rnk[v]) {
        par[v] = u;
        sz[u] = sz[u] + sz[v];
        maxi = max(maxi, sz[u]);
    } else {
        rnk[u] += 1;
        par[v] = u;
        sz[u] = sz[u] + sz[v];
        maxi = max(maxi , sz[u]);
    }
}

void solve() {

    int n, m; cin >> n >> m;
    maxi = 1; components = n;
    REP(i, 1, n) {
        par[i] = i;
        sz[i] = 1;
        rnk[i] = 1;
    }


    int a , b;



    while (m--) {
        cin >> a >> b;

        int u = findPar(a) , v = findPar(b);

        if (u != v) {
            components--;
            _union(u, v);
        }
        cout << components << " " << maxi;
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

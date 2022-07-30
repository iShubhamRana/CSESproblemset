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




void solve() {

    int n , m, a, b , c; cin >> n >> m;

    ll dis[n + 1];
    int par[n + 1];

    REP(i, 0, n + 2) dis[i] = 1e18;

    dis[1] = 0;
    par[1] = 0;

    vector<pair<pi, int>> edges;

    while (m--) {
        cin >> a >> b >> c;
        edges.PB({{a, b}, c});
    }


    int x ;

    REP(i, 0, n - 1) {
        x = 0;
        for (auto &edge : edges) {
            int u = edge.F.F , v = edge.F.S , c = edge.S;
          
            //don't put condition on dis[u] as negative cycle must contain -ve weight and we need to relax each edge
            //unlike normal bellman where we are relaxing from the node , here we can start relaxing from anywhere
          
            if (dis[v] > dis[u] + c) {
                dis[v] = dis[u] + c;
                par[v] = u;
                x = v;
            }
        }
    }



    if (x == 0) {
        cout << "NO";
        return;
    }

    cout << "YES";
    newLine();

    REP(i, 0, n - 1) {
        x = par[x];
    }

    int node = x;
    vector<int> cycle;

    do {
        cycle.PB(node);
        node = par[node];
    } while (node != x);

    cycle.PB(node);
    reverse(all(cycle));
    printVectori(cycle);

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

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

const int N = 2502;
ll dis[N];
vector<int> adj1[N], adj2[N];
vector<vector<ll>> edges;
vector<bool> vis1(N) , vis2(N);


void dfs1(int node) {
    vis1[node] = true;
    for (auto v : adj1[node]) {
        if (!vis1[v]) {
            dfs1(v);
        }
    }
}

void dfs2(int node) {
    vis2[node] = true;
    for (auto v : adj2[node]) {
        if (!vis2[v]) {
            dfs2(v);
        }
    }
}

void solve() {
    
    //just check if we can follow the order      src   --> positive cycle  -- > destination

    ll n , m , a , b , c; cin >> n >> m;

    while (m--) {
        cin >> a >> b >> c;
        adj1[a].PB(b);
        adj2[b].PB(a);
        edges.PB({a, b, -c});
    }



    dfs1(1); dfs2(n);

    for (auto &x : dis) x = 1e18;

    dis[1] = 0;



    REP(i, 0, n - 1) {
        for (auto &edge : edges) {
            a = edge[0] , b = edge[1] , c = edge[2];
            if (dis[a] + c < dis[b] ) {
                dis[b] = dis[a] + c;
                if (i == n - 1 and vis1[b] and vis2[b]) {
                    cout << -1; newLine();
                    return;
                }
            }
        }
    }

    cout << -dis[n];

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

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

const int N = 1e5 + 2;


void shortestPath(int src , ll dis[] , vector<pi> adj[], int n) {
    dis[src] = 0;
    priority_queue<pair<ll, int> > pq;

    vector<bool> visited(n + 2);
    pq.push({0, src});


    while (pq.size()) {
        int u = pq.top().S; pq.pop();

        if (visited[u]) continue;
        visited[u] = 1;

        for (auto &to : adj[u]) {
            if (dis[to.F] > dis[u] + to.S) {
                dis[to.F] = dis[u] + to.S;
                pq.push({ -dis[to.F] , to.F});
            }
        }

    }

}



void solve() {

    int n , m , a , b , c; cin >> n >> m;

    vector<pi> adj1[n + 2] , adj2[n + 2];
    ll dis1[n + 2] , dis2[n + 2];

    vector<pair<pi, int>> edges;


    REP(i, 0, n + 1) {
        dis1[i] = dis2[i] = 1e18;
    }

    while (m--) {
        cin >> a >> b >> c;
        adj1[a].PB(MP(b, c));
        adj2[b].PB(MP(a , c));
        edges.PB({{a, b}, c});
    }

    shortestPath(1 , dis1 , adj1, n);
    shortestPath(n, dis2 , adj2, n);

    ll ans = 1e18;

    for (auto &edge : edges) {
        ll cost = edge.S;
        int u = edge.F.F  , v = edge.F.S;
        cost /= 2;
        ll cand = cost + dis1[u] + dis2[v];
        if ( cand < ans) {
            ans = cand;
        }
    }

    cout << ans;

    newLine();

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

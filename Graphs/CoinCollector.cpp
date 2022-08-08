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

const int N = 1e5 + 10;

vector<int> adj1[N], adj2[N];
int component[N];
vector<pair<int, int> > edges;
vi v;
bool visited[N];
ll comp_cost[N];

void dfs1(int node , vi &order) {
    visited[node] = 1;
    for (auto v : adj1[node]) {
        if (!visited[v])
            dfs1(v, order);
    }
    order.PB(node);
}

void dfs2(int node , int comp) {
    component[node] = comp;
    comp_cost[comp] += v[node];
    for (auto v : adj2[node]) {
        if (component[v] == 0) {
            dfs2(v , comp);
        }
    }
}

void getComponents(int n) {

    memset(visited , false , sizeof(visited));

    vector<int> order;
    REP(i, 1, n) {
        if (!visited[i])
            dfs1(i , order);
    }

    reverse(all(order));


    int comp = 1;
    REP(i, 0, order.size() - 1) {
        if (component[order[i]] == 0) {
            dfs2(order[i], comp);
            comp++;
        }
    }

}



void solve() {

    int n, m; cin >> n >> m;
    v.resize(n + 1);

    REP(i, 1, n) {
        cin >> v[i];
    }

    int a , b;

    while (m--) {
        cin >> a >> b;
        edges.PB(MP(a, b));
        adj1[a].PB(b);
        adj2[b].PB(a);
    }

    getComponents(n);

    int maxC = 0;
    REP(i, 1, n) {
        maxC = max(maxC , component[i]);
    }

    maxC++;
    vector<int> comp_adj[maxC];
    vi indgree(maxC);

    for (auto &edge : edges) {
        int u = edge.F , v = edge.S;
        u = component[u] , v = component[v];

        if (u == v) continue;
        comp_adj[u].PB(v);
        indgree[v]++;
    }

    queue<int> q;
    REP(i, 1, maxC - 1) {
        if (indgree[i] == 0) {
            q.push(i);
        }
    }

    vi toposort;

    while (q.size()) {

        int node = q.front(); q.pop();
        toposort.PB(node);

        for (int v : comp_adj[node]) {
            indgree[v]--;
            if (indgree[v] == 0) {
                q.push(v);
            }
        }

    }


    vector<ll> dp(maxC);
    ll ans = 0;

    REP(i, 0, toposort.size() - 1) {
        dp[i] = comp_cost[i];
    }

    REP(i, 0, toposort.size() - 1) {
        int u = toposort[i];
        for (int v : comp_adj[u]) {
            if (comp_cost[v] + dp[u] > dp[v]) {
                dp[v] = comp_cost[v] + dp[u];
            }
        }
        ans = max(ans , dp[u]);
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

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

const int N = 501;
ll capacity[N][N];
vector<int> adj[N];

ll bfs(int s , int t , vi &parent) {
    fill(all(parent), -1);
    parent[s] = -2;

    queue<pi> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 and capacity[cur][next]) {
                parent[next] = cur;
                ll newFlow = min(flow, (ll)capacity[cur][next]);
                if (next == t) return newFlow;
                q.push({next, newFlow});
            }
        }

    }

    return 0;

}

ll maxFlow(int s , int t, int n) {
    ll flow = 0;
    vi parent(n, -1);
    ll newFlow;

    while (newFlow = bfs(s, t, parent)) {
        flow += newFlow;
        ll curr = t;
        while (curr != s) {
            ll prev = parent[curr];
            capacity[prev][curr] -= newFlow;
            capacity[curr][prev] += newFlow;
            curr = prev;
        }
    }

    return flow;
}

void solve() {
    int n, m; cin >> n >> m;

    int a, b, wt;
    while (m--) {
        cin >> a >> b >> wt;
        a-- , b--;
        capacity[a][b] += wt;
        adj[a].PB(b);
        adj[b].PB(a);
    }


    cout << maxFlow(0 , n - 1, n);
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

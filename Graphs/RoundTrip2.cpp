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

const int N  = 1e5 + 10;
bool visited[N];
bool dfsVisited[N];
vector<int> adj[N];
int par[N];
bool cycle = false;

void dfs(int node ) {
    visited[node] = 1;
    dfsVisited[node] = 1;


    for (int v : adj[node]) {

        if (!visited[v]) {
            par[v] = node;
            dfs(v);
            if (cycle) return;
        } else if (dfsVisited[v]) {
            cycle = true;
            vi cyc;
            int head = v , curr = node;

            cyc.PB(head);

            while (curr != head) {
                cyc.PB(curr);
                curr = par[curr];
            }

            cyc.PB(head);
            reverse(all(cyc));

            cout << cyc.size() << endl;
            for (auto &x : cyc) cout << x << " ";

            return ;
        }
    }

    dfsVisited[node] = 0;
}

void solve() {
    int n , m , k, a,  b , c; cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        adj[a].PB(b);
    }

    REP(i, 1, n) {
        if (!visited[i]) {
            dfs(i);
            if (cycle) return;
        }
    }

    cout << "IMPOSSIBLE";

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

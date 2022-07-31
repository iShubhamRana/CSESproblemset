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

    //in DAG TOPOsorts can be used for DP like problems

    int n , m, a , b; cin >> n >> m;
    vector<int> adj[n + 1];
    int indegree[n + 1] = {0};

    while (m--) {
        cin >> a >> b;
        adj[a].PB(b);
        indegree[b]++;
    }

    vector<int> toposort;
    queue<int> q;
    //kahns algo
    REP(i, 1, n) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }


    while (q.size()) {
        int u = q.front(); q.pop();
        toposort.PB(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    // printVectori(toposort);
    // newLine();


    vector<ll> ways(n + 1 , 0);
    ways[1] = 1;

    int mod = 1e9 + 7;
    int idx = -1;
    REP(i, 0, n - 1) {
        if (toposort[i] == 1) idx = i;
    }

    REP(i, idx, n - 1) {
        int u = toposort[i];
        for (int v : adj[u]) {
            ways[v] = ( ways[v] +  ways[u]) % mod;
        }
    }

    cout << ways[n] % mod;

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

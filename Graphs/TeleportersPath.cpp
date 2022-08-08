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

int indegree[N];
int outdegree[N];
stack<int> adj[N];
vi path;

void helper(int n, int node) {
    auto &s = adj[node];
    while (s.size()) {
        auto v = s.top();
        s.pop();
        helper(n, v);
    }
    path.PB(node);
}

void solve() {

    int n, m; cin >> n >> m;
    int a, b;

    while (m--) {
        cin >> a >> b;
        adj[a].push(b);
        indegree[b]++ , outdegree[a]++;
    }

    bool flag = true;

    REP(i, 1, n) {
        if (abs(indegree[i] - outdegree[i]) > 1) {
            flag = false;
            break;
        } else if ( i != 1 and i != n and abs(indegree[i] - outdegree[i]) == 1) {
            flag = false;
            break;
        } else if (i == 1 and outdegree[i] != indegree[i] + 1) {
            flag = false;
            break;
        } else if (i == n and indegree[i] != outdegree[i] + 1) {
            flag = false;
            break;
        }
    }

    if (!flag) {
        cout << "IMPOSSIBLE";
        return;
    }

    helper(n, 1);
    REP(i, 1, n) {
        if (adj[i].size() != 0) {
            cout << "IMPOSSIBLE";
            return;
        }
    }

    reverse(all(path));
    printVectori(path);

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

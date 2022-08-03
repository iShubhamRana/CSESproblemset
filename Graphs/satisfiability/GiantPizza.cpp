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
const int N = 1e6 + 1;

vector<int> adj[N] , adj_t[N];
vector<bool> assignment, visited;
vector<int> order, component;
bool flag = true;
int nodes;


void dfs1(int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    order.PB(u);
}

void dfs2(int u , int c) {
    component[u] = c;
    for (int v : adj_t[u]) {
        if (component[v] == -1) {
            dfs2(v, c);
        }
    }
}




void solve2sat() {
    order.clear();
    visited.assign(nodes, false);

    REP(i, 0,  nodes - 1) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    component.assign(nodes, -1);

    int j = 0;
    reverse(all(order));

    REP(i, 0, nodes - 1) {
        int v = order[i];
        if (component[v] == -1) {
            dfs2(v, j++);
        }
    }

    assignment.assign(nodes / 2, false);

    for (int i = 0; i < nodes; i += 2) {
        if (component[i] == component[i + 1]) {
            cout << "IMPOSSIBLE";
            flag = false;
            return;
        }

        assignment[i / 2] = component[i] > component[i + 1] ;
    }


}


void add_disjunction(int a, bool na , int b , bool nb) {


    a = 2 * a ^ na;
    b = 2 * b ^ nb;


    int neg_a = a ^ 1;
    int neg_b = b ^ 1;


    adj[neg_a].PB(b);
    adj[neg_b].PB(a);

    adj_t[b].PB(neg_a);
    adj_t[a].PB(neg_b);
}


void solve() {

    int n ,  m;
    cin >> n >> m;

    nodes = 2 * m;


    while (n--) {
        char  s1 , s2;
        int a, b;
        bool sign1 = false , sign2 = false;
        cin >> s1 >> a >> s2 >> b;
        if (s1 == '-') sign1 = true;
        if (s2 == '-') sign2 = true;
        add_disjunction(a - 1, sign1, b - 1, sign2);
    }



    solve2sat();

    if (!flag) return;

    REP(i, 0, m - 1) {
        if (assignment[i] == 1) cout << "+";
        else cout << "-";
        cout << " ";
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

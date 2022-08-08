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

    int n, m; cin >> n >> m;

    set<int> adj[n + 1];
    int degree[n + 1] = {0};

    int a, b;
    REP(i, 1, m) {
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
        degree[a]++ , degree[b]++;
    }

    int oddCnt = 0 , startPt = 1;
    // REP(i, 1, n) {
    //     if (degree[i] % 2) {
    //         oddCnt++;
    //         startPt = i;
    //     }
    // }

    // if (oddCnt > 2) {
    //     cout << "IMPOSSIBLE";
    //     return;
    // }

    REP(i , 1 , n) {
        if (degree[i] & 1) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }


    stack<int> s;
    vector<int> path;
    int curr = 1;


    while (curr != -1) {
        if (adj[curr].size() == 0) {
            path.PB(curr);
            if (s.size()) {curr = s.top(); s.pop();}
            else curr = -1;
        } else {
            s.push(curr);
            int next = *adj[curr].begin();
            adj[next].erase(curr);
            adj[curr].erase(next);
            curr = next;
        }
    }


    if (path.size()  != m + 1 or path.back() != 1) {
        cout << "IMPOSSIBLE";
    } else {
        printVectori(path);
    }

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

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

    int n, q , a; cin >> n >> q;
    vector<int> adj;
    adj.PB(0);

    REP(i, 0, n - 1) {
        cin >> a;
        adj.PB(a);
    }

    int table[n + 1][32];

    REP(i, 1, n) {
        table[i][0] = adj[i];
    }

    REP(jump, 1, 31) {
        REP(i, 1 , n) {
            table[i][jump] = table[table[i][jump - 1]][jump - 1];
        }
    }

    int u , k ;
    REP(query , 1 , q) {
        cin >> u >> k;
        for (int jump = 31 ; jump >= 0 ; jump--) {
            if ((1LL << jump) <= k) {
                k -= (1LL << jump);
                u = table[u][jump];
            }
        }

        cout << u;
        newLine();
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

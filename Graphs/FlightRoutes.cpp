//only one change , instead of max distance we compare with  k max distance


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
    int n , m , k; cin >> n >> m >> k;
    vector<pi> adj[n + 1];
    int a , b , c;
    while (m--) {
        cin >> a >> b >> c;
        adj[a].PB({b, c});
    }


    priority_queue<ll> best[n + 1];
    priority_queue<pair<ll, int> , vector<pair<ll, int> >  , greater < pair<ll, int> >> pq;

    best[1].push(0);
    pq.push(MP(0, 1));

    while (pq.size()) {
        auto node  = pq.top(); pq.pop();
        int u = node.S; ll dis = node.F;

        //this statement is imp this tells that this distance is now out of the priority queue
        //can optimise the ans
        if (dis > best[u].top()) continue;

        for (auto to : adj[u]) {
            int v = to.F , cost = to.S;
            if (best[v].size() < k) {
                best[v].push(dis + cost);
                pq.push({dis + cost , v});
            } else if (cost + dis < best[v].top()) {
                best[v].pop();
                best[v].push(cost + dis);
                pq.push({dis + cost , v});
            }
        }

    }

    vector<ll> ans;
    while (best[n].size()) {
        ans.PB(best[n].top());
        best[n].pop();
    }

    reverse(all(ans));

    printVectori(ans);

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

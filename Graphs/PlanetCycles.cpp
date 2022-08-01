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


    int n; cin >> n;
    vector<int> next(n);

    vector<vector<int> > before(n);
    vector<int> connected_to(n, -1);


    REP(i, 0, n - 1) {
        cin >> next[i];
        next[i]--;
        before[next[i]].PB(i);
    }

    vector<int> cycle_id(n, -2);
    vector<int> cycles;

    REP(i, 0, n - 1) {

        //create cycles

        if (cycle_id[i] != -2) continue;

        vector<int> path{i};
        int at = i;
        cycle_id[at] = -3;

        while (cycle_id[next[at]] == -2) {
            at = next[at];
            cycle_id[at] = -3;
            path.PB(at);
        }

        bool incycle = false;
        int id = cycle_id[next[at]];

        int cnt = 0;
        // if (i == 2) cout << endl << "for i=3" << id;
        for (int p : path) {
            incycle = incycle || p == next[at];

            if (incycle) {
                cnt++;
                cycle_id[p] = cycles.size();
            } else {
                cycle_id[p] = -1;
                if (id == -1) {
                    connected_to[p] = connected_to[next[at]];
                } else if (id >= 0) {
                    connected_to[p] = cycle_id[next[at]];
                } else {
                    connected_to[p] = cycles.size();
                }
            }

        }

        cycles.PB(cnt);
    }

    //cycle dis can also be calculated using dfs but we are using stack
    vector<int> cycle_dis(n);
    REP(i, 0, n - 1) {
        if (cycle_id[next[i]] == -1 or cycle_id[i] != -1) {
            continue;
        }

        cycle_dis[i] = 1;
        vector<int> s(before[i]);

        while (!s.empty()) {
            int curr = s.back(); s.pop_back();
            cycle_dis[curr] = 1 + cycle_dis[next[curr]];
            s.insert(s.end() , before[curr].begin() , before[curr].end());
        }
    }


    REP(i, 0, n - 1) {
        // cout << cycle_id[i] << " " << connected_to[i] << " ";
        if (cycle_dis[i] == 0) {

            cout << cycles[cycle_id[i]];
        } else {
            // cout << connected_to[i];
            cout << cycle_dis[i] + cycles[connected_to[i]];
        }
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

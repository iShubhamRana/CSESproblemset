
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
#define inf INT_MAX
#define INF 1e18

// #define MP make_pair
// // ***********************************************************************************
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define REV_REP(i,a,b) for(int i=a;i>=b;i--)
#define inputVectori(v) for(auto &x:v) cin>>x;
#define printVectori(v) for(auto &x:v) cout<<x<<" ";
#define all(a) a.begin() , a.end()
/*****Remember inbuilt c++ functions*************************/

// next_permutation(), __builtin_popcount()

/***********************************************************/
const int mod  = 1e9 + 7 ;

inline void newLine() {
    cout << "\n";
}

void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
}



void preprocess() {
}

int block_size = 330;
struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

int cnt[111111] , n1;
int a[100000];
int fin;
void remove(int index) {
    int num = a[index];
    if (num <= n1) {
        cnt[num]--;
        if (cnt[num] == num - 1) {
            fin--;
        }
        else if (cnt[num] == num) {
            fin++;
        }
    }
}

void add(int index) {
    int num = a[index];
    if (num <= n1) {
        cnt[num]++;
        if (cnt[num] == num) {
            fin++;
        }
        else if (cnt[num] == num + 1) {
            fin--;
        }
    }
}

int get_answer() {
    return fin;
}

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = -1;

    for (Query &q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }


    return answers;
}

void solve() {

    int n, m; cin >> n >> m;
    n1 = n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<Query> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l-- , queries[i].r--;
        queries[i].idx = i;
    }


    auto ans = mo_s_algorithm(queries);
    for (auto &x : ans) {
        cout << x << endl;
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
    preprocess();
    for (int z = 1; z <= t; z++) {
        solve();
    }

}


/*

*/

//Hare Krishna !! Hare Ram



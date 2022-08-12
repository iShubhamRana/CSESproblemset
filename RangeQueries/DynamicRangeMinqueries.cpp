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

void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
}

inline void newLine() {
    cout << "\n";
}

struct segmentTree
{
    int n;
    vector<int> st;
    segmentTree(int N) {
        this->n = N;
        st.resize(4 * N, INT_MAX);
    }
    void build(int start, int end, int node, vector<int> &v) {
        if (start == end) {
            st[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        //build left subtree
        build(start, mid, 2 * node + 1, v);
        //build right subtree
        build(mid + 1, end, 2 * node + 2 , v);
        st[node] = min(st[2 * node + 1], st[2 * node + 2]);
    }

    int query(int start, int end , int l , int r, int node) {
        //no overlapp
        if (start > r or end < l) return INT_MAX;

        //complete overlapp
        if (start >= l and end <= r) return st[node];

        //partial overlapp
        int mid = (start + end) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, end, l, r, 2 * node + 2 );
        return min(q1, q2);
    }

    void update(int start, int end , int node , int index , int value) {

        if (start == end) {
            st[node] = value;
            return;
        }

        int mid = (start + end) / 2;
        if (index <= mid) {
            update(start, mid, 2 * node + 1, index, value);
        } else {
            update(mid + 1, end, 2 * node + 2, index, value);
        }
        st[node] = min(st[2 * node + 1], st[2 * node + 2]);
    }

    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }

    int query(int l , int r) {
        return query(0, n - 1, l, r, 0);
    }

    void update(int index, int value) {
        update(0, n - 1, 0, index, value);
    }
};

void solve() {

    int n, q; cin >> n >> q;
    vi v(n); inputVectori(v);

    segmentTree T(n);
    T.build(v);

    int type;
    while (q--) {
        cin >> type;
        if (type == 1) {

            int k, u; cin >> k >> u;
            k--;
            T.update(k, u);

        } else {

            int l, r ; cin >> l >> r;
            l-- , r--;
            cout << T.query(l, r) << "\n";

        }
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

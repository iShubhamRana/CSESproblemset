/*
For each position maintain the number of elements in that range, and then further is easy.
Always remember indexing can always be linked with number of elements

*/


#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<bool> vb;
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
        st.resize(4 * N, 0);
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
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    int query(int start, int end , int pos, int node) {

        if (start == end) {
            // cout << st[node] << " " << start << " " << end << " " << pos << endl;
            return start;
        }

        // cout << st[node] << " " << start << " " << end << " " << pos << endl;

        int left = 2 * node + 1 , right = 2 * node + 2;
        //partial overlapp

        int mid = (start + end) / 2;
        if ( pos <= st[left]) {
            return query(start, mid, pos, 2 * node + 1);
        } else {
            return query(mid + 1, end, pos - st[left], 2 * node + 2 );
        }

        return 1;
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
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }

    int query(int pos) {
        return query(0, n - 1, pos, 0);
    }

    void update(int index, int value) {
        update(0, n - 1, 0, index, value);
    }
};

void solve() {
    int n; cin >> n;
    vi arr(n);
    inputVectori(arr);

    vi v(n, 1);

    vi pos(n);
    inputVectori(pos);

    segmentTree T(n);
    T.build(v);


    REP(i, 1, n) {
        ll idx = T.query(pos[i - 1]);
        T.update(idx, 0);
        cout << arr[idx] << " ";
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

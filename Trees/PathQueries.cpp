/*
we only want sum of parents , means sum of node having 

intime <= intime[node] and outtime>=outtime[node]

 A  & B = total - (~A | ~B) = total - (~A + ~B - ~A&~B)

*/

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


class BIT {
    int n;
    vector<long long> v;
public:
    BIT(int sz) {
        n = sz;
        v.resize(n + 1);
    }
    long long sum(int k) {
        //sum till index k
        long long sum = 0;
        while (k > 0) {
            sum += v[k];
            k -= k & -k;
        }

        return sum;
    }

    void add(int k , int x) {

        while (k <= n) {
            v[k] += x;
            k += k & -k;
        }
    }
};

const int N = 5 * 1e5;
int timer = 0;
int intime[N] , outtime[N] , val[N];
long long total = 0;
vector<int> adj[N];

void dfs(int node , int p , BIT &t1 , BIT &t2) {
    total += val[node];
    intime[node] = ++timer;
    t1.add(intime[node], val[node]);


    for (auto v : adj[node]) {
        if (v == p) continue;
        dfs(v, node, t1, t2);
    }


    outtime[node] = ++timer;
    t2.add(outtime[node], val[node]);
}

void solve() {
    int n, m; cin >> n >> m;
    BIT t1(N) , t2(N);

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a , b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1 , t1 , t2);


    for (int i = 0; i < m; i++) {
        int type; cin >> type;
        if (type == 1) {
            int node , newVal; cin >> node >> newVal;
            //change total
            ll prevVal = val[node];
            val[node] = newVal;
            total = total - prevVal + newVal;

            //update in trees
            t1.add(intime[node] , newVal - prevVal);
            t2.add(outtime[node], newVal - prevVal);

        } else {
            int node; cin >> node;
            ll ans = t1.sum(N) - t1.sum(intime[node]);
            ans += t2.sum(outtime[node] - 1);
            ans -= t1.sum(outtime[node] - 1) - t1.sum(intime[node]);

            cout << total - ans << endl;
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
    preprocess();
    for (int z = 1; z <= t; z++) {
        solve();
    }
}




//Hare Krishna !! Hare Ram

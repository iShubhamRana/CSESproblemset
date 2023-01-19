/*
IN FUTURE , I WILL DEFINITELY BE PROUD OF THE CURRENT ME
JAI SHRI KRISHNA !!!
*/


/*

WORK ON COMING UP WITH NICE TESTCASES LIKE I WAS PROVIDED WITH ONE IN CONDEFORCES
DISCUSS SECTION

BEFORE GOINF FORWARD WITH AN OBSERVATION , TRY VALIDATING IT WITH A COUNTER EXAMPLE
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


vector<ll> factorial;
// void preprocess(int n) {
//     factorial.push_back(1);
//     for (int i = 1; i <= n; i++) {
//         ll curr = (factorial.back() * i) % mod;
//         factorial.push_back(curr);
//     }
// }
void preprocess() {

}
ll binaryExp(ll x , ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

ll nCr(ll n, ll r) {
    if (n < r) return 0;
    ll fac1 = factorial[n];
    ll fac2 = binaryExp(factorial[n - r], mod - 2);
    ll fac3 = binaryExp(factorial[r], mod - 2);
    ll ans = (fac1 * fac2) % mod;
    ans = (ans * fac3) % mod;
    return ans;
}

const int N = 2 * 1e5 + 1;
class BIT {
    int n;
    vector<long long> v;
public:
    BIT(int sz) {
        n = sz;
        v.resize(n + 1);
    }

    //110100 stores sum from  110000 + 1 to 110100
    //k & -k is efficient way to get last set bit
    long long sum(int k) {
        //sum till index k
        long long sum = 0;
        while (k > 0) {
            sum += v[k];
            k -= k & -k;
        }

        return sum;
    }

    //110100 -> we need to add in all ranges that after removing last set bit contain this number
    //so we increase the the val of number by increasing the left bit and make current bit 0 so that
    // after removing the last bit number is smaller than current , and this way current lies
    //between a smaller and a greater number

    void add(int k , int x) {

        while (k <= n) {
            v[k] += x;
            k += k & -k;
        }

    }

};


vector<int> adj[N];
int intime[N] , outtime[N];
int timer;
int values[N];

void dfs(int u , int p , BIT &t) {
    intime[u] = ++timer;
    t.add(timer, values[u]);

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, t);
    }
    outtime[u] = timer;
}

void solve() {
    BIT t(N + 1);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int val; cin >> val;
        values[i] = val;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    dfs(1, 0, t);

    for (int i = 0; i < m; i++) {
        int type; cin >> type;
        if (type == 1) {
            int node , newValue; cin >> node >> newValue;
            t.add(intime[node] , -values[node]);
            values[node] = newValue;
            t.add(intime[node] , values[node]);
        } else {
            int node;
            cin >> node;
            cout << t.sum(outtime[node]) -  t.sum(intime[node] - 1) << endl;
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

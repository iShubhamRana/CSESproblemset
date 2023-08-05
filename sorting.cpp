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
#define MP make_pair

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
const int mod  = 998244353;

inline void newLine() {
    cout << "\n";
}

void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
}



// const int N = 1e6;
// int v[N][N];
// vector<ll> factorial;
// vector<ll> mod_inverse;
// vector<bool> prime;

// ll binaryExp(ll x , ll y) {
//     ll res = 1;
//     while (y) {
//         if (y & 1) res = (res * x) % mod;
//         y >>= 1;
//         x = (x * x) % mod;
//     }
//     return res;
// }




// ll nCr(ll n, ll r) {
//     if (n < r) return 0;
//     ll fac1 = factorial[n];
//     ll fac2 = binaryExp(factorial[n - r], mod - 2);
//     ll fac3 = binaryExp(factorial[r], mod - 2);
//     ll ans = (fac1 * fac2) % mod;
//     ans = (ans * fac3) % mod;
//     return ans;
// }





/*



n = total empty seats
k = required subarrays
selected = if current length can be selected

*/




void preprocess() {
    // memset(cnt, 0, sizeof(cnt));
}


// void merge(vector<int> &arr , int l , int h , int mid) {
//     vector<int> curr = arr;
//     int k = l, p = l , q = mid + 1;

//     while (p <= mid && q <= h) {
//         if (arr[p] < arr[q]) {
//             curr[k++] = arr[p++];
//         } else {
//             curr[k++] = arr[q++];
//         }
//     }

//     while (p <= mid) curr[k++] = curr[p++];
//     while (q <= h) curr[k++] = curr[q++];

//     for (int i = l; i <= h; i++) {
//         arr[i] = curr[i];
//     }
// }

// void mergesort(vector<int> &arr , int l , int h) {
//     if (l < h) {
//         int mid = (l + h) / 2;
//         mergesort(arr , l , mid);
//         mergesort(arr , mid + 1 , h);
//         merge(arr , l , h , mid);
//     }
// }

int partition(vector<int> &arr , int l , int h) {
    int pivot = arr[l];
    int i = l + 1 ,  j = h;

    while (i <= j) {

        while (i <= j && arr[i] <= pivot) i++;
        while (i <= j && arr[j] > pivot) j--;

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    if (j <= h) {
        swap(arr[j] , arr[l]);
    }
    return j;

}

void quicksort(vector<int> &arr , int l , int h) {
    if (l < h) {
        int pi = partition(arr , l , h);
        quicksort(arr , l , pi - 1);
        quicksort(arr , pi + 1 , h);
    }
}

void solve()
{
    int n ; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    quicksort(arr , 0 , n - 1);
    printVectori(arr);
}

// cout << ans << endl;



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
        preprocess();
        solve();
    }

}



//Hare Krishna !! Hare Ram]


/*

a1 b1
a2 b2
a3 b3
a4 b4



*/

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
/*****Remember inbuilt c++ functions*************************/

// next_permutation(), __builtin_popcount()

/***********************************************************/
inline void newLine() {
	cout << "\n";
}

void checkjudge() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
}

bool check(ll mid , vi &v , int k) {
	int n = v.size() , cnt = 0;
	ll sum = 0;

	for (int i = 0; i < n; i++) {
		sum += v[i];
		if (sum > mid) {
			cnt++;
			sum = v[i];
		}
	}

	if (sum <= mid) cnt++;

	return cnt <= k;
}

void solve() {

	int n, k; cin >> n >> k;
	vi v(n);

	inputVectori(v);

	ll h = 0 , l = 0;
	for (auto &x : v) {
		h += x ;
		if (x > l) l = x;
	}

	ll ans = -1;

	while (l <= h) {
		ll mid = (l + h) / 2;
		bool res = check(mid , v , k);
		if (res) {
			ans = mid;
			h = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	cout << ans; newLine();
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

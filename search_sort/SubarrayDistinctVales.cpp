/*
I had the approach to remove common part by moving two pointers , but the below approach is also very nice as we try to make subarrays by fixing the start point
and for each start point we find the number of subarrays startingn from it
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



void solve() {

	int n, k; cin >> n >> k;
	vi v(n);

	inputVectori(v);

	ll ans = 0 , i = 0 , j = 0, cnt, c = 0;
	map<int, int> m;

	while (i < n) {
		while (j < n and m.size() + (m.count(v[j]) == 0) <= k) {
			m[v[j]]++;
			j++;
		}

		ans += j - i;
		m[v[i]]--;
		if (m[v[i]] == 0) m.erase(v[i]);
		i++;
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

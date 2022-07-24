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

	map<ll, pi> m;
	ll sum = 0;

	REP(i, 0, n - 1) {
		REP(j, i + 1, n - 1) {
			sum = v[i] + v[j];
			m[sum] = MP(i, j);
		}
	}

	REP(i, 0, n - 1) {
		REP(j, i + 1, n - 1) {

			sum = v[i] + v[j];

			auto it = m.find(k - sum);
			if (it == m.end()) continue;

			auto x = it->S.F , y = it->S.S;
			if (i != x and i != y and j != x and j != y) {
				cout << i + 1 << " " << j + 1 << " " << x + 1 << " " << y + 1;
				newLine();
				return;
			}

		}
	}

	cout << "IMPOSSIBLE";
	newLine();
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

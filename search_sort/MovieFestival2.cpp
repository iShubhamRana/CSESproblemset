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
#define all(v) v.begin(),v.end()
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

	int n, k, i, j; cin >> n >> k;

	vector <pi> v;
	REP(i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		v.PB(MP(a, b));
	}


	sort(all(v), [&](pi a, pi b) {
		return a.S < b.S;
	});

	int ans = 0;

	multiset<int> s;

	REP(i, 0, n - 1) {

		int x = -v[i].F , y = -v[i].S;
		if (s.size() == 0) {s.insert(y); ans ++;}
		else {

			auto z = s.lower_bound(x);
			if (z == s.end()) {
				if (s.size() < k) {
					s.insert(y);
					ans++;
				}
			} else {
				s.erase(z);
				s.insert(y);
				ans++ ;
			}

		}
	}

	cout << ans;
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

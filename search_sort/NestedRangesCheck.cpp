#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int>  pi;
/****************************************************************************************/
//access keywords
#define F first
#define S second
#define PB push_back
#define MP make_pair
/*************************************************************************************/
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define inputVectori(v) for(auto &x:v) cin>>x;

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
	int n; cin >> n;
	vector<pair<pair<int, int> , int > > v;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back(MP(MP(a, b), i));
	}

	sort(v.begin(), v.end() , [&](pair<pair<int, int> , int> a , pair<pair<int, int> , int>b ) {
		auto a1 = a.F , b1 = b.F;
		if (a1.F != b1.F) return a1.F < b1.F;
		return a1.S > b1.S;
	});

	set<int> s;

	vector<int> ans1(n) , ans2(n);

	for (int i = n - 1; i >= 0; i--) {
		int endTime = v[i].F.S;
		auto it = s.upper_bound(endTime);
		int ans = (it == s.begin()) ? 0 : 1;
		ans1[v[i].S] = ans;
		s.insert(endTime);
	}

	s.clear();

	for (int i = 0; i < n; i++) {
		int endTime = v[i].F.S;
		auto it = s.lower_bound(endTime);
		int ans = (it == s.end()) ? 0 : 1;
		ans2[v[i].S] = ans;
		s.insert(endTime);
	}


	for (int i = 0; i < n; i++) {
		cout << ans1[i] << " ";
	}
	newLine();

	for (int i = 0; i < n; i++) {
		cout << ans2[i] << " ";
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

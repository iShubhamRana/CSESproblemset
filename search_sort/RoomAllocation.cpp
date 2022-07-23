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

	vector<pi> v;
	vi idx;
	for (int i = 0; i < n; i++) {
		int a , b; cin >> a >> b;
		v.PB(MP(a, b));
		idx.push_back(i);
	}

	priority_queue<pi , vector<pi> , greater<pi> > pq;
	int ans = 0, rooms = 0;

	sort(idx.begin(), idx.end() , [&](int idx1 , int idx2) {
		auto p1 = v[idx1] , p2 = v[idx2];
		return p1.F < p2.F;
	});

	vi res(n);

	for (int i = 0; i < n; i++) {
		auto index = idx[i];
		auto entryTime = v[index].F, exitTime = v[index].S;
		int roomNo = -1;

		if (pq.size() == 0 or pq.top().F >= entryTime) {
			//new room
			roomNo = ans + 1;
		} else {
			auto p = pq.top();
			roomNo = pq.top().S;
			pq.pop();
		}

		pq.push({exitTime , roomNo});
		int sz = pq.size();
		ans = max(ans , sz);
		res[index] = roomNo;
	}


	cout << ans; newLine();
	REP(i, 0, n - 1) {
		cout << res[i] << " ";
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

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
	int n, m; cin >> n >> m;
	vi v(n);
	inputVectori(v);

	vector<pi> arr;

	for (int i = 0; i < n; i++) arr.push_back(MP(v[i], i));

	sort(arr.begin(), arr.end());

	arr.push_back(MP(INT_MAX , -1));


	vi index(n, -1);

	int rounds = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].S  > arr[i + 1].S) rounds++;
		index[arr[i].S] = i;
	}


	while (m--) {
		int a , b; cin >> a >> b;
		int pos1 = index[a - 1], pos2 = index[b - 1];

		if (pos1 > pos2) {
			swap(pos1 , pos2);
		}

		//the element which is in order is saving a round , so increase the round
		if (arr[pos1 + 1].S > arr[pos1].S) rounds++;
		if (pos1 - 1 >= 0 and arr[pos1 - 1].S < arr[pos1].S) rounds++;

		if (pos2 + 1 < n and arr[pos2 + 1].S > arr[pos2].S) rounds++;
		if (arr[pos2 - 1].S < arr[pos2].S) rounds++;

		swap(arr[pos1].S , arr[pos2].S) ;

		//if the element is in order it will save so decrease
		if (arr[pos1 + 1].S > arr[pos1].S) rounds--;
		if (pos1 - 1 >= 0 and arr[pos1 - 1].S < arr[pos1].S) rounds--;

		if (pos2 + 1 < n and arr[pos2 + 1].S > arr[pos2].S) rounds--;
		if (arr[pos2 - 1].S < arr[pos2].S) rounds--;

		//adjacent position leads to repeating count so adjust them
		if (pos2 - pos1 == 1) {
			if (arr[pos2].S > arr[pos1].S) rounds++;
			else rounds--;
		}

		index [arr[pos1].S] = pos1;
		index[arr[pos2].S] = pos2;
		cout << rounds << endl;
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

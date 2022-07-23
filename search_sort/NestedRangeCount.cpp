/****VARIATION OF LEETCODE 315. Count of Smaller Numbers After Self*****************/

/****MERGE SORT IS VERY USEFUL AND CAN SOMETIMES OVERCOME POLICY BASED DATASRUCTURES****************************************/

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

vector<int> inv , inv2;

void merge(vector<pair<int, int> > &v , int low , int mid , int high) {
	vector<pair<int, int> > A(high - low + 1);

	int i = low, j = mid + 1, k = 0, curr = 0;
	while (i <= mid and j <= high) {
		if (v[i].first < v[j].first) {
			inv[v[i].second] += curr;
			A[k++] = v[i++];
		} else {
			curr++;
			inv2[v[j].second] += mid - i + 1;
			A[k++] = v[j++];
		}
	}

	while (i <= mid) {
		inv[v[i].second] += curr;
		A[k++] = v[i++];
	}
	while (j <= high) {
		A[k++] = v[j++];
	}
	for (int m = low; m <= high; m++) {
		v[m] = A[m - low];
	}
}

void mergeSort(vector<pair<int, int> > &v , int low , int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		mergeSort(v , low , mid );
		mergeSort(v, mid + 1 , high);
		merge(v, low , mid , high);
	}
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

	vector<pi> arr;
	inv.assign(n, 0);
	inv2.assign(n, 0);

	for (int i = 0; i < n; i++) {
		arr.PB(MP(v[i].F.S , v[i].S));
	}

	mergeSort(arr , 0 , n - 1);
	for (int i = 0; i < n; i++) cout << inv[i] << " ";
	cout << endl;
	for (int i = 0; i < n ; i++) cout << inv2[i] << " ";

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

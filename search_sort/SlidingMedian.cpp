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
	int n, k, i, j; cin >> n >> k;
	vi v(n); inputVectori(v);

	if (k == 1) {
		printVectori(v);
		return ;
	}



	priority_queue <int> left;
	priority_queue<int, vector<int> , greater<int> > right;
	map<int, int> leftMap , rightMap;
	int leftSize = 0 , rightSize = 0;

	REP(i, 0, n - 1) {

		int val = v[i];

		//insert

		if (left.empty() or left.top() > val) {
			left.push(val);
			leftMap[val]++;
			leftSize++;
		} else {
			right.push(val);
			rightMap[val]++;
			rightSize++;
		}

		//remove
		if (i >= k) {
			int x = v[i - k];
			if (leftSize and  x <= left.top()) {
				leftSize--;
				leftMap[x]--;
			} else {
				rightSize--;
				rightMap[x]--;
			}
		}


		//balance
		if (leftSize > rightSize + 1) {
			int x = left.top();
			left.pop(); right.push(x);

			leftMap[x]-- , rightMap[x]++;

			leftSize-- , rightSize++;

		}

		if (rightSize > leftSize + 1) {
			int x = right.top();
			right.pop(); left.push(x);

			leftMap[x]++ , rightMap[x]--;

			leftSize++, rightSize--;
		}



		//ans
		if (i >= k - 1) {
			while (left.size() and leftMap[left.top()] == 0) left.pop();
			while (right.size() and rightMap[right.top()] == 0) right.pop();

			if (leftSize >= rightSize) cout << left.top();
			else cout << right.top() ;
			newLine();
		}

	}

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

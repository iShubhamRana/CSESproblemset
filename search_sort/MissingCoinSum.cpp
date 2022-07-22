void solve() {
	int n; cin >> n;
	vi v(n);
	inputVectori(v);
 
	sort(v.begin(), v.end());
 
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		if (ans < v[i]) {
			cout << ans; newLine();
			return;
		}
		ans += v[i];
	}
 
	cout << ans; newLine();
}

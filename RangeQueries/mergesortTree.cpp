class mergeSortTree {
  vector<vector<int>> st;
  int N;

public:
  mergeSortTree(int n) {
    this->N = n;
    st.resize(4 * n);
  }

  void build(vector<int> &v, int i, int l, int r) {
    if (l == r) {
      st[i].pb(v[l]);
      return;
    }

    int mid = (l + r) / 2;

    build(v, 2 * i + 1, l, mid);
    build(v, 2 * i + 2, mid + 1, r);

    // cerr << l << " " << r << endl;
    // print(st[i]);
    // cerr << endl;

    merge(st[2 * i + 1].begin(), st[2 * i + 1].end(), st[2 * i + 2].begin(),
          st[2 * i + 2].end(), back_inserter(st[i]));
  }

  int query(int i, int l, int r, int k, int start, int end) {
    if (start > r or end < l)
      return 0;

    if (start >= l and end <= r) {
      int res = upper_bound(st[i].begin(), st[i].end(), k - 1) - st[i].begin();
      return res;
    }

    int mid = (start + end) / 2;
    int left = query(2 * i + 1, l, r, k, start, mid);
    int right = query(2 * i + 2, l, r, k, mid + 1, end);
    return left + right;
  }
  void build(vector<int> &v) { build(v, 0, 0, v.size() - 1); }

  int query(int l, int r, int k) { return query(0, l, r, k, 0, N - 1); }
};

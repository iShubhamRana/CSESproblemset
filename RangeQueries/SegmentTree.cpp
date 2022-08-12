struct segmentTree
{
	int n;
	vector<int> st;
	segmentTree(int N) {
		this->n = N;
		st.resize(4 * N, 0);
	}
	void build(int start, int end, int node, vector<int> &v) {
		if (start == end) {
			st[node] = v[start];
			return;
		}
		int mid = (start + end) / 2;
		//build left subtree
		build(start, mid, 2 * node + 1, v);
		//build right subtree
		build(mid + 1, end, 2 * node + 2 , v);
		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}

	int query(int start, int end , int l , int r, int node) {
		//no overlapp
		if (start > r or end < l) return 0;

		//complete overlapp
		if (start >= l and end <= r) return st[node];

		//partial overlapp
		int mid = (start + end) / 2;
		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, end, l, r, 2 * node + 2 );
		return q1 + q2;
	}

	void update(int start, int end , int node , int index , int value) {

		if (start == end) {
			st[node] = value;
			return;
		}

		int mid = (start + end) / 2;
		if (index <= mid) {
			update(start, mid, 2 * node + 1, index, value);
		} else {
			update(mid + 1, end, 2 * node + 2, index, value);
		}
		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}

	void build(vector<int> &v) {
		build(0, n - 1, 0, v);
	}

	int query(int l , int r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(int index, int value) {
		update(0, n - 1, 0, index, value);
	}
};

#include<bits/stdc++.h>

using namespace std;
struct segmentTree
{
	int n;
	vector<int> st;
    vector<int> lazy;
	segmentTree(int N) {
		this->n = N;
		st.resize(4 * N, 0);
        lazy.resize(4 * N , 0);
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
        
        if(lazy[node]!=0){
            //some pending updates
            
            //update the segment tree nodes
            st[node] += lazy[node] * (end-start+1);
            
            //push the changes
            if(start!=end){
                //not a leaf node
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
            }
            lazy[node]=0;
        }

		//complete overlapp
		if (start >= l and end <= r) return st[node];

		//partial overlapp
		int mid = (start + end) / 2;
		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, end, l, r, 2 * node + 2 );
		return q1 + q2;
	}

	void update(int start, int end , int node , int l , int r , int value) {
        
        //non overlaping
        if(start > r || end < l) return ;
        
        
         //update the lazy part
         if(lazy[node]!=0){
            //some pending updates
            
            //update the segment tree nodes
            st[node] += lazy[node] * (end-start+1);
            
            //push the changes
            if(start!=end){
                //not a leaf node
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
            }
            lazy[node]=0;
        }
        
        if(start >=l and end <=r){
            st[node] += value * (end - start+1);
            if(start!=end){
                //not a leaf node
                lazy[2*node+1] += value;
                lazy[2*node+2] += value;
            }
            return ;
        }
        
        int mid = (start+end)/2;
        update(start,mid,2*node+1 , l , r,value);
        update(mid+1,end,2*node+2 , l , r,value);
	
	}

	void build(vector<int> &v) {
		build(0, n - 1, 0, v);
	}

	int query(int l , int r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(int l , int r, int value) {
		update(0, n - 1, 0, l , r ,  value);
	}
};

int main(){
    vector<int> v = {1,1,1,1,1};
    int n = v.size();
    segmentTree t(n);
    
    t.build(v);
    
    cout<<t.query(1,2)<<endl;
    //1 1 1 3 3
    //1 41  6 6
    t.update(3,4,2);
    t.update(2,4,3);
    
    cout<<t.query(1,3);
    
    
    return 0;
}

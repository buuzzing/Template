struct tr {
	int tr[maxn<<2],lazy[maxn<<2];
	void add(int x,int l,int r,int newval) {
		tr[x]=(r-l+1)*newval;
		lazy[x]+=newval;
	}
	void pushup(int x) {
		tr[x]=tr[lc]+tr[rc];
	}
	void pushdown(int x,int l,int r) {
		if(lazy[x]) {
			int mid=(l+r)>>1;
			add(lc,l,mid,lazy[x]);
			add(rc,mid+1,r,lazy[x]);
			lazy[x]=0;
		}
	}
	void build(int x,int l,int r) {
		if(l==r) {
			tr[x]=read();
			return;
		}
		int mid=(l+r)>>1;
		build(lc,l,mid);
		build(rc,mid+1,r);
		pushup(x);
	}
	void update(int x,int l,int r,int L,int R,int newval) {
		if(L<=l&&R>=r) return add(x,l,r,newval);
		pushdown(x,l,r);
		int mid=(l+r)>>1;
		if(L<=mid) update(lc,l,mid,L,R,newval);
		if(R>mid) update(rc,mid+1,r,L,R,newval);
		pushup(x);
	}
	int query(int x,int l,int r,int L,int R) {
		if(L<=l&&R>=r) return tr[x];
		pushdown(x,l,r);
		int mid=(l+r)>>1,ans=0;
		if(L<=mid) ans+=query(lc,l,mid,L,R);
		if(R>mid) ans+=query(rc,mid+1,r,L,R);
		return ans;
	}
} T;

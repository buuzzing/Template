// This one is aimed at calculating interval addition and subtraction
class BUG {
#define lc (x << 1)
#define rc (x << 1 | 1)
    static const int maxn = 1e5 + 10;

  public:
    void add(int x, int l, int r, int addval)
    {
        tree[x] += (r - l + 1) * (int)addval;
        lazy[x] += addval;
    }
	
    void pushup(int x)
    {
        tree[x] = tree[lc] + tree[rc];
    }
	
    void pushdown(int x, int l, int r)
    {
        if (lazy[x]) {
            int mid = (l + r) >> 1;
            add(lc, l, mid, lazy[x]);
            add(rc, mid + 1, r, lazy[x]);
            lazy[x] = 0;
        }
    }
	
    void build(int x, int l, int r)
    {
        if (l == r) {
            cin >> tree[x];
            return;
        }
        int mid = (l + r) >> 1;
        build(lc, l, mid);
        build(rc, mid + 1, r);
        pushup(x);
    }
	
    void update(int x, int l, int r, int L, int R, int addval)
    {
        if (L <= l && r <= R)
            return add(x, l, r, addval);
        pushdown(x, l, r);
        int mid = (l + r) >> 1;
        if (L <= mid)
            update(lc, l, mid, L, R, addval);
        if (R > mid)
            update(rc, mid + 1, r, L, R, addval);
        pushup(x);
    }
	
    int query(int x, int l, int r, int L, int R)
    {
        if (L <= l && r <= R)
            return tree[x];
        pushdown(x, l, r);
        int ans = 0, mid = (l + r) >> 1;
        if (L <= mid)
            ans += query(lc, l, mid, L, R);
        if (R > mid)
            ans += query(rc, mid + 1, r, L, R);
        return ans;
    }

  private:
    int tree[maxn << 2] = {0};
    int lazy[maxn << 2] = {0};
};

class ST {
public:
	void read() {
		for (int i = 1; i <= N; ++i) {
			cin >> f_max[i][0];
			f_min[i][0] = f_max[i][0];
		}
	}
	void init() {
		logn[1] = 0;
		for (int i = 2; i <= N; ++i) logn[i] = logn[i >> 1] + 1;
		for (int j = 1; j <= logn[N] + 1; ++j)
			for (int i = 1; i + (1 << j) - 1 <= N; ++i) {
				f_max[i][j] = max(f_max[i][j - 1], f_max[i + (1 << (j - 1))][j - 1]);
				f_min[i][j] = min(f_min[i][j - 1], f_min[i + (1 << (j - 1))][j - 1]);
			}
	}
	int Get_min(int l, int r) {
		int s = logn[r - l + 1];
		return min(f_min[l][s], f_min[r - (1 << s) + 1][s]);
	}
	int Get_max(int l, int r) {
		int s = logn[r - l + 1];
		return max(f_max[l][s], f_max[r - (1 << s) + 1][s]);
	}

private:
	static const int maxn = 1e6 + 10;
	static const int Logn = 22;
	int f_max[maxn][Logn];
	int f_min[maxn][Logn];
	int logn[maxn];
	int N;
};

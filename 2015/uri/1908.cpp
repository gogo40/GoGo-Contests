#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

using lint = long long;

class MyBitSet {
	static const int CHUNCK_SIZE = 64;
public:
	MyBitSet(MyBitSet&& v) { 
		size_ = v.size_;
		data_ = v.data_;
	}
	MyBitSet(int size = 1) : size_(size), data_((size / CHUNCK_SIZE) + 1, 0) {}
	~MyBitSet() {}

	void set(int pos, bool value) {
		data_[pos / CHUNCK_SIZE] |= (value << (pos % CHUNCK_SIZE));
	}

	bool operator[](int pos) {
		return (data_[pos / CHUNCK_SIZE] & (1 << (pos % CHUNCK_SIZE))) != 0;
	}

	void set(MyBitSet&& v) {
		this->data_ = v.data_;
		this->size_ = v.size_;
	}


private:
	int size_;
	vector<lint> data_;
};


int main() 
{
	static const int INF = 1 << 30;
	int N, K;

	scanf("%d%d", &N, &K);

	vector<vector<bool>> marked(K);
	
	vector<bool> vis(K, false);
	vector<bool> final_point(K, false);
	
	vector<int> d(K, INF);
	vector<vector<int>> line(K);
	vector<vector<int>> campus(N+1);

	vector<int> q(K + 1);
	int ini = 0, fin = 0;
	
	for (int i = 0; i < K; ++i) {
		int L;
		scanf("%d", &L);

		marked[i].resize(K);

		for (int k = 0; k < L; ++k) {
			int c;
			scanf("%d", &c);

			for (int l: campus[c]) {
				if (marked[i][l]) continue;
				
				line[i].push_back(l);
				line[l].push_back(i);
				
				marked[i][l] = true;
				marked[l][i] = true;
			}

			campus[c].push_back(i);

			if (c == 1) {
				q[fin++] = i;
				d[i] = 1;
				vis[i] = true;
			}
			
			if (c == N) {
				final_point[i] = true;
			}
		}
	}

	int ans = INF;

	while (ini < fin) {
		int u = q[ini++];
		
		if (final_point[u]) {
			ans = d[u];
			break;
		}

		for (int v: line[u]) {
			if (!vis[v]) {
				vis[v] = true;
				d[v] = d[u] + 1;
				q[fin++] = v;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}


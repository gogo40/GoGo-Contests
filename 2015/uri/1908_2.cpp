#include <set>
#include <tuple>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	static const int INF = 1 << 30;
	using point = tuple<int, int>;
	using points = vector<point>;
	using graph = vector<points>;
	using heap = tuple<int, point>;

	int N, K;
	scanf("%d%d", &N, &K);
	
	graph g(N + 1);
	map<point, int> d;	
	
	for (int i = 0; i < K; ++i) {
		int L;
		scanf("%d", &L);
		int prev = -1;
		for (int k = 0; k < L; ++k) {
			int c;
			scanf("%d", &c);
			if (prev != -1) {
				g[c].push_back(point(i, prev));
				g[prev].push_back(point(i, c));
			}

			prev = c;		
		}
	}

	int ans = INF;
	set<tuple<int, point> > q;

	point s(-1, 1);
	q.insert(heap(0, s));
	d[s] = 0;

	while (!q.empty()) {
		heap h = *q.begin();
		point p = get<1>(h);

		int c = get<0>(h);
		int u = get<1>(p);
		int l = get<0>(p);

		if (u == N) {
			ans = d[p];
			break;		
		}

		q.erase(h);

		for (point pv: g[u]) {
			int v = get<1>(pv);
			int lv = get<0>(pv);
			bool ok = d.find(pv) == d.end();
			if (lv != l) {
				if (d[pv] > c + 1 || ok) {
					d[pv] = c + 1;
					q.insert(heap(c + 1, pv));				
				}
			} else {
				if (d[pv] > c || ok) {
					d[pv] = c;
					q.insert(heap(c, pv));				
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}


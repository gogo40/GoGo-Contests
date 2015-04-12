#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int gogo40 = 1; gogo40 <= T; ++gogo40) {
		int D;
		cin >> D;

		priority_queue<int> Q;
		for (int i = 0; i < D; ++i) {
			int P;
			cin >> P;
			Q.push(P);
		}

		int ans = 0;

		while (!Q.empty()) {
			int v = Q.top(); Q.pop();

			if (v <= 2) {
				ans += v;
				break;
			}

			int m = v / 2;
			int cm = v - m;

			int cost = 0;

			int w = v;

			priority_queue<int> aux;
			while (!Q.empty()) {
				if (Q.top() > cm) {
					aux.push(Q.top());
					++cost;
					Q.pop();
				} else break;
			}

			while (!aux.empty()) {
				Q.push(aux.top()); aux.pop();
			}

			if (cost + cm + 1 < v) {
				Q.push(m);
				Q.push(cm);
			} else {
				Q.push(v);
				while (!Q.empty()) {
                                        if (Q.top()  >  1) aux.push(Q.top() - 1); 
					Q.pop();
				}
				while (!aux.empty()) {
					Q.push(aux.top()); aux.pop();
				}
			}

			++ans;
		}

		cout << "Case #" << gogo40 << ": " << ans << "\n";
	}
	return 0;
}


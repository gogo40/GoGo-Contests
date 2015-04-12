#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve(priority_queue<int> Q)
{
	int v = Q.top();
	if (v <= 2) return v;

	
	priority_queue<int> Q2;
	while (!Q.empty()) {
		if (Q.top() > 1) {
			Q2.push(Q.top() - 1); 
			Q.pop();
		} else break;
	}

	int sol2 = 1 + solve(Q2);

	while (!Q2.empty()) {
		Q.push(Q2.top() + 1);
		Q2.pop();
	}

	Q.pop();	
	int m = v / 2;
	int cm = v - m;

	Q.push(m); 
	Q.push(cm);
	int sol1 = 1 + solve(Q);


	return sol1 < sol2 ? sol1 : sol2;
}

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

		int ans = solve(Q);

		cout << "Case #" << gogo40 << ": " << ans << "\n";
	}
	return 0;
}


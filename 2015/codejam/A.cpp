#include <string>
#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int gogo40 = 1; gogo40 <= T; ++gogo40) {
		int Smax;
		cin >> Smax;
		
		string audience;
		cin >> audience;
		
		int ans = 0;
		int acc = 0;

		for (int i = 0; i < audience.size(); ++i) {
			int d = static_cast<int>(audience[i] - '0');
			if (acc < i) {
				ans += i - acc;
				acc += i - acc + d;
			} else {
				acc += d;
			}
		}
		cout << "Case #" << gogo40 << ": " << ans << "\n";
	}

	return 0;
}

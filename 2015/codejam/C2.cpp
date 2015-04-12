#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
map<int, map<int, int> > mul;

int mult(int a, int b)
{
	if (a == 0 || b == 0) {
		return 0;
	}

	if (a < 0 && b < 0) {
		return mul[-a][-b];
	}

	if (a < 0) {
		return -mul[-a][b];
	}

	if (b < 0) {
		return -mul[a][-b];
	}

	return mul[a][b];
}

int pow(const string& v, int n)
{
        if (n == 0) return int('1');
        if (n == 1) {
                int acc = v[0];
                for (int i  = 1; i < v.size(); ++i) {
                        acc = mult(acc, v[i]);
                }
                return acc;
        }

        int r = n % 2;
        int a1 = pow(v, n/2);
        int res = mult(a1, a1);

        if (r > 0) {
                res = mult(res, pow(v, 1));
        }

        return res;
}


int main() 
{
	mul['1']['1'] = '1';
	mul['1']['i'] = 'i';
	mul['1']['j'] = 'j';
	mul['1']['k'] = 'k';

	mul['i']['1'] = 'i';
	mul['i']['i'] = -1 * int('1');
	mul['i']['j'] = 'k';
	mul['i']['k'] = -1 * int('j');


	mul['j']['1'] = 'j';
	mul['j']['i'] = -1 * int('k');
	mul['j']['j'] = -1 * int('1');
	mul['j']['k'] = 'i';


	mul['k']['1'] = 'k';
	mul['k']['i'] = 'j';
	mul['k']['j'] = -1 * int('i');
	mul['k']['k'] = -1 * int('1');

	int T;
	cin >> T;

	for (int gogo40 = 1; gogo40 <= T; ++gogo40) {
		int L, X;
		cin >> L >> X;
		string s;
		cin >> s;

		int r = max(X % 8, 7);

		r = min(r, X);

		int total = pow(s, X);

		vector<int> posI, posJ;

		//r = X;
		int p = 0;
		string v;
		for (int i = 0; i < r; ++i) v += s;
	
		int acc = pow(s, X - r);
		
		while (acc != '1' && acc != 'i' && p < v.size()) {
			acc = mult(acc, v[p]);
			++p;
		}

		if (acc == 'i') posI.push_back(p);


		for (int i = p; i < v.size(); ++i) {
			acc = mult(acc, v[i]);

			if (acc == 'i') {
				posI.push_back(i);
			}

			if (acc == 'k') {
				if (posI.size() > 0) {
					posJ.push_back(i);
				}
			} 
		}

		if (total == -1 * int('1')) {
			if (posJ.size() > 0)  {
				cout << "Case #" << gogo40 << ": YES\n";
			} else {
				cout << "Case #" << gogo40 << ": NO\n";
			}
		} else {
			cout << "Case #" << gogo40 << ": NO\n";
		}
	}
 
	return 0;
}


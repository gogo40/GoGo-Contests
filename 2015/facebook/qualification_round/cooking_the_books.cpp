#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int c = 1; c <= T; ++c) {

        string n;
        string min_n;
        string max_n;

        cin >> n;

        min_n = max_n = n;

        int p_min = 0, p_max = 0;
        char c_min = n[0], c_max = n[0];
        int pi;
        for (pi = 1; pi < n.size() and n[pi] == n[0]; ++pi);
        int p = pi - 1;
        for (int i  = pi; i < n.size(); ++i) {
            if (n[i] <= c_min and n[i] != '0') {
                p_min = i;
                c_min = n[i];
            }

            if (n[i] >= c_max) {
                p_max = i;
                c_max = n[i];
            }
        }

        min_n[p_min] = n[p];
        min_n[p] = c_min;

        max_n[p_max] = n[p];
        max_n[p] = c_max;

        cout << "Case #" << c << ":";

        cout << " " << min_n << " " << max_n << "\n";
    }

    return 0;
}

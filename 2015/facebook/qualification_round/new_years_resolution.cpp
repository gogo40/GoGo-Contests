#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>

#define INF 1<<30

using namespace std;

struct food {
    int GP, GC, GF, i;
    food(int GP = 0, int GC = 0, int GF = 0, int i = 0) 
        : GP(GP), GC(GC), GF(GF), i(i) {}
};

bool operator<(const food& food1, const food& food2) {
    if (food1.GP > food2.GP) return false;
    if (food1.GC > food2.GC) return false;
    if (food1.GF > food2.GF) return false;
    return food1.i < food2.i;
}
int main()
{
    int T;
    cin >> T;


    for (int case_ = 1; case_ <= T; ++case_) {
        food target;

        cin >> target.GP >> target.GC >> target.GF;

        int N;
        cin >> N;
        vector<food> foods(N);
        for (int i = 0; i < N; ++i) {
            cin >> foods[i].GP >> foods[i].GC >> foods[i].GF;
        }

        queue<food> Q;
        Q.push(food(0, 0, 0, -1));

        bool ok = false;
        while (!Q.empty()) {
            food u = Q.front();
            Q.pop();
            
            for (int i = u.i + 1; i < N; ++i) {
                food v(u.GP + foods[i].GP, u.GC + foods[i].GC, u.GF + foods[i].GF, i);

                if (v.GP <= target.GP and v.GC <= target.GC and v.GF <= target.GF) {
                    Q.push(v);

                    if (v.GP == target.GP and v.GC == target.GC and v.GF == target.GF) { 
                        ok = true; 
                        goto solution; 
                    }

                }
            }
        }


        solution:
        cout << "Case #"<< case_ << ": " << ((ok)?  ("yes\n"):("no\n"));
    }

    return 0;
}



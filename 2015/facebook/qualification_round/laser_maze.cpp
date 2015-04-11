#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>

#define INF 1<<30

using namespace std;

struct point {
    int dist;
    int x, y;
    int r;

    point(int dist = 0, int x = 0, int y = 0, int r = 0)
    : dist(dist), x(x), y(y), r(r) {}

     point(int x, int y)
    : x(x), y(y) {}
};

bool operator<(const point& p1, const point& p2) {
    if (p1.dist < p2.dist) return false;
    if (p1.x < p2.x) return false;
    if (p1.y < p2.y) return false;
    return p1.r > p2.r;
}

int main()
{
    int T;
    cin >> T;

    static char f[666];

    f['^'] = '>';
    f['>'] = 'v';
    f['v'] = '<';
    f['<'] = '^';
    f['.'] = '.';
    f['S'] = 'S';
    f['G'] = 'G';
    f['#'] = '#';

    static int dx[] = {-1,  0,  1, 0};
    static int dy[] = { 0, -1,  0, 1};

    for (int case_ = 1; case_ <= T; ++case_) {

        std::vector<string> mazes[4];

        int M, N;

        cin >> M >> N;
        int sx, sy;
        int tx, ty;
        for (int i = 0; i < M; ++i) {
            string row;
            cin >> row;
            mazes[0].push_back(row);
        }


        //rotaciona o maze
        for (int r = 1; r < 4; ++r) {
            for (int i = 0; i < M; ++i) {
                mazes[r].push_back("");
                mazes[r][i].resize(N);
                for (int j = 0; j < N; ++j) {
                    mazes[r][i][j] = f[mazes[r-1][i][j]];

                    if (mazes[r-1][i][j] == 'S') { sx = i; sy = j; }
                    if (mazes[r-1][i][j] == 'G') { tx = i; ty = j; }
                }
            }
        }
        //elimina rotas
        for (int r = 0; r < 4; ++r) {
            //encontra lasers
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (mazes[r][i][j] == '<') {
                        for (int k = j - 1; k > -1; --k) {
                            if (!(mazes[r][i][k] == '.'  or  mazes[r][i][k] == 'S' or mazes[r][i][k] == 'G')) break; 
                            mazes[r][i][k] = '#';
                        }
                    }

                    if (mazes[r][i][j] == '^') {
                        for (int k = i - 1; k > -1; --k) {
                            if (!(mazes[r][k][j] == '.' or  mazes[r][k][j] == 'S' or mazes[r][k][j] == 'G')) break;
                            mazes[r][k][j] = '#';
                        }
                    }

                    if (mazes[r][i][j] == '>') {
                        for (int k = j + 1; k < N; ++k) {
                            if (!(mazes[r][i][k] == '.' or  mazes[r][i][k] == 'S' or mazes[r][i][k] == 'G')) break;
                            mazes[r][i][k] = '#';
                        }
                    }

                     if (mazes[r][i][j] == 'v') {
                        for (int k = i + 1; k < M; ++k) {
                            if (!(mazes[r][k][j] == '.' or  mazes[r][k][j] == 'S' or mazes[r][k][j] == 'G')) break;
                            mazes[r][k][j] = '#';
                        }
                    }
                }
            }
        }

        map<int, map<int, int> > D[4];
        priority_queue<point> Q;

        Q.push(point(0, sx, sy, 0));

        int dist = INF;

        while (!Q.empty()) {
            point p = Q.top();
            Q.pop();

            D[p.r][p.x][p.y] = p.dist;

            if (p.x == tx and p.y == ty) {
                dist = p.dist;                
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int vx = p.x + dx[i];
                int vy = p.y + dy[i];
                int r = (p.r + 1) % 4;

                if (vx > -1 and vx < M and vy > -1 and vy < N)
                if (mazes[r][vx][vy] == '.' or mazes[r][vx][vy] == 'S' or mazes[r][vx][vy] == 'G') {

                    if (D[r][vx].find(vy) == D[r][vx].end()) {
                        D[r][vx][vy] = p.dist + 1;
                        Q.push(point(p.dist + 1, vx, vy, r));
                    } else if (D[r][vx][vy] > p.dist + 1) {
                        D[r][vx][vy] = p.dist + 1;
                        Q.push(point(p.dist + 1, vx, vy, r));
                    }
                }
            }
        }

        if (dist < INF) {
            cout << "Case #" << case_ << ": " << dist << "\n";
        } else {
            cout << "Case #" << case_ << ": impossible\n";
        }
        
    }

    return 0;
}

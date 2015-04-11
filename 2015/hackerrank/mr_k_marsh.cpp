#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>

static int left[501][501];
static int up[501][501];
static int right[501][501];
static int down[501][501];

int main()
{
	int m, n;
	
	std::iostream::sync_with_stdio (false);
	
	std::cin >> m >> n;
	
	std::vector<std::string> grid;
	
	for (int i = 0; i < m; ++i) {
		std::string l;
		std::cin >> l;
		grid.push_back(l);
	}
	
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			left[i][j] = right[i][j] = 0;
			up[i][j] = down[i][j] = 0;
		}
	}
	
	for (int i = 0; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (grid[i][j] == '.' && grid[i][j - 1] == '.') {
				right[i][j] = right[i][j - 1] + 1;
			}
		}
		
		for (int j = n - 2; j > -1; --j) {
			if (grid[i][j] == '.' && grid[i][j + 1] == '.') {
				left[i][j] = left[i][j + 1] + 1;
			}
		}
	}
	
	for (int j = 0; j < n; ++j) {
		for (int i = 1; i < m; ++i) {
			if (grid[i][j] == '.' && grid[i - 1][j] == '.') {
				down[i][j] = down[i - 1][j] + 1;
			}
		}
		
		for (int i = m - 2; i > -1; --i) {
			if (grid[i][j] == '.' && grid[i + 1][j] == '.') {
				up[i][j] = up[i + 1][j] + 1;
			}
		}
	}
	
	int sol = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int u = up[i][j];
			int l = left[i][j];
			
			if (2 * u + 2 * l <= sol) continue;
			
			for (int k = i + u; k > i; --k) {
				int m_l = k - i;
				
				if (2 * m_l + 2 * l <= sol) break;
				
				for (int p = j + l; p > j; --p) {
					int m_h = p - j;
					
					if (2 * m_l + 2 * m_h <= sol) break;
					
					int d = down[k][p];
					int r = right[k][p];
					
					if (k - d <= i && p - r <= j) {
						int per = 2 * (k - i) + 2 * (p - j);
						if (per > sol) sol = per;
						else break;
					}
				}
			}
		} 
	}
	
	if (sol > 0) {
		std::cout << sol << std::endl;
	} else {
		std::cout << "impossible" << std::endl;
	} 
	
	return 0;
}

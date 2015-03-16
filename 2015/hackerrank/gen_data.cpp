#include <cstdlib>
#include <ctime>
#include <cstdio>

int main() 
{
	int m, n;
	m = 500;
	n = 500;

	srand(time(NULL));
	printf("%d %d\n", m, n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (rand() % 100 < 90) {
				printf(".");
			} else {
				printf("x");
			} 
		}
		printf("\n");
	}
	return 0;
}